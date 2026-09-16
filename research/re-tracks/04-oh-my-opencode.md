# 04 — oh-my-opencode / Oh My OpenAgent orchestration (Spark-on-OpenCode build reference)

Source: `https://github.com/code-yeongyu/oh-my-opencode.git`, cloned `--depth 1` into `/tmp/opencode/ref-study/omo` on 2026-09-15.
Note: two harnesses share the repo — **omo-opencode** (OpenCode plugin, `call_omo_agent`/`background_task` tools) and **omo-senpi** (Senpi/`task`-tool edition, `docs/guide/orchestration.md`). Both are cited; harness is called out per item. Legacy name "Sisyphus" = main orchestrator agent; current Senpi docs call the same role "main agent".

---

## 1. Agent roster — mode, tool boundaries, model fallback chains

### 1.1 Mode semantics

`packages/omo-opencode/src/agents/types.ts:60-65`:

```ts
/**
 * Agent mode determines UI model selection behavior:
 * - "primary": Respects user's UI-selected model (sisyphus, atlas)
 * - "subagent": Uses own fallback chain, ignores UI selection (oracle, explore, etc.)
 * - "all": Available in both contexts (OpenCode compatibility)
 */
export type AgentMode = "primary" | "subagent" | "all";
```

Per-agent `MODE` constants (verbatim grep hits):

| Agent | Mode | Declared at |
|---|---|---|
| sisyphus | primary (via factory; `general-agents.ts:77` treats `source.mode === "primary"` as UI-model-respecting; sisyphus + atlas + hephaestus + sisyphus-junior are excluded from the generic loop and built by dedicated `maybeCreate*Config`) | `packages/omo-opencode/src/agents/builtin-agents/sisyphus-agent.ts`, `general-agents.ts:56-59` |
| atlas | `primary` | `packages/omo-opencode/src/agents/atlas/agent.ts:38` (`const MODE: AgentMode = "primary"`) |
| oracle | `subagent` | `packages/omo-opencode/src/agents/oracle.ts:6` |
| explore | `subagent` | `packages/omo-opencode/src/agents/explore.ts:5` |
| librarian | `subagent` | `packages/omo-opencode/src/agents/librarian.ts:5` |
| prometheus | planner agent (system prompt in `packages/omo-opencode/src/agents/prometheus/system-prompt.ts`; hook `prometheus-md-only` restricts it to `.md` plan files only) | `packages/omo-opencode/src/hooks/prometheus-md-only/constants.ts:6,20` |
| metis | `subagent` | `packages/omo-opencode/src/agents/metis.ts:7` |
| momus | `subagent` | `packages/omo-opencode/src/agents/momus.ts:7` |
| sisyphus-junior | `subagent` | `packages/omo-opencode/src/agents/sisyphus-junior/agent.ts:37` |

Senpi mirror (curated read-only set + reviewer trio), `packages/senpi-task/src/agents/builtin/index.ts:14-27`:

```ts
export const CURATED_READONLY_AGENT_DEFAULTS: readonly AgentDefinition[] = [
  EXPLORE_AGENT, LIBRARIAN_AGENT, PLAN_CONSULTANT_AGENT, PLAN_REVIEWER_AGENT,
] as const
// The ulw-loop reviewer trio writes report artifacts, so it stays out of the curated read-only
// set (which pins the restricted read-only bash broker) while still shipping as builtins.
export const ULW_REVIEWER_AGENT_DEFAULTS: readonly AgentDefinition[] = [
  CODE_REVIEWER_AGENT, QA_EXECUTOR_AGENT, GATE_REVIEWER_AGENT,
] as const
```

Senpi canonical ids rename metis→`plan-consultant`, momus→`plan-reviewer` (see `fallback-chains.ts:3-5`).

### 1.2 Tool boundaries (who cannot write / delegate)

`createAgentToolRestrictions([...])` = deny-list merged over user permission (see `sisyphus-junior/agent.ts:126-141`).

| Agent | Denied tools | Source |
|---|---|---|
| oracle | `write, edit, apply_patch, task` — "You are read-only. You advise; others execute. You cannot write, edit, patch, or delegate further work." | `packages/omo-opencode/src/agents/oracle.ts:412-417`, prompt `ORACLE_GPT_5_5_PROMPT` line 251 |
| explore | `write, edit, apply_patch, task, call_omo_agent` — cannot delegate at all | `packages/omo-opencode/src/agents/explore.ts:28-29` |
| librarian | `write, edit, apply_patch, task` (+ surrounding list at lines 25-29; `call_omo_agent` allowed for remote-research broker use — contrast explore) | `packages/omo-opencode/src/agents/librarian.ts:25-29` |
| metis | `write, edit, apply_patch` (may spawn explore/librarian via `call_omo_agent` — prompt shows `call_omo_agent(subagent_type="explore", …)`) | `packages/omo-opencode/src/agents/metis.ts:392-396`, prompt lines 88-90 |
| momus | `write, edit, apply_patch` (read-only reviewer; no `task` in deny list → can still read via tools, verdict is text `[OKAY]`/`[REJECT]`) | `packages/omo-opencode/src/agents/momus.ts:283-286` |
| sisyphus-junior | `task` denied, `call_omo_agent = allow` — research-only delegation | `packages/omo-opencode/src/agents/sisyphus-junior/agent.ts:39-41, 133-138` |

```ts
// packages/omo-opencode/src/agents/sisyphus-junior/agent.ts:39-41
// Core tools that Sisyphus-Junior must NEVER have access to
// Note: call_omo_agent is ALLOWED so subagents can spawn explore/librarian
const BLOCKED_TOOLS = ["task"]
```

Junior no-redelegation rule (prompt-level, `sisyphus-junior/gpt-5-5.ts:64`, `glm-5-2.ts:34`):

> "You do not delegate implementation to other categories or agents; your `task()` access is restricted to research sub-agents only (`explore`, `librarian`, `oracle`)."
> "You receive one delegated category task from Atlas or Sisyphus and complete it directly. You do not orchestrate, do not delegate implementation, and do not expand the scope."

Depth backstop (harness-agnostic): `packages/senpi-task/src/manager/depth-policy.ts:14-31` — child admitted iff `childDepth <= maxDepth` (default `maxDepth: 1`, `task.ts:49`) unless its type is in the parent's `allowed_subagents` allow-list. Junior ships with no `allowed_subagents` → depth 1 terminates redelegation even if the prompt is jailbroken.

### 1.3 Model fallback chains

Source of truth: `packages/model-core/src/agent-model-requirements.ts` (OpenCode) mirrored for Senpi in `packages/senpi-task/src/agents/builtin/fallback-chains.ts` (parity test `#8259`).

```ts
// packages/model-core/src/agent-model-requirements.ts:4-24 (sisyphus)
sisyphus: { fallbackChain: [
  { providers: ["anthropic","github-copilot","opencode"], model: "claude-opus-5", variant: "max" },
  { providers: ["opencode-go","kimi-for-coding","moonshotai","opencode","bailian-coding-plan","moonshotai-cn","firmware","ollama-cloud","aihubmix"], model: "kimi-k3" },
  { providers: ["openai","openai-codex","github-copilot","opencode"], model: "gpt-5.6-sol", variant: "medium" },
  { providers: ["zai-coding-plan","opencode","bailian-coding-plan"], model: "glm-5.2" },
  { providers: ["opencode"], model: "big-pickle" } ], requiresAnyModel: true },
```

Full table (agent → ordered rungs; `variant` = reasoning effort):

| Agent | Chain (providers → model : variant) |
|---|---|
| sisyphus | anthropic/copilot/opencode → claude-opus-5:max; kimi-lane → kimi-k3; openai-lane → gpt-5.6-sol:medium; zai-lane → glm-5.2; opencode → big-pickle |
| atlas | anthropic-lane → claude-sonnet-5; opencode-go → kimi-k3; openai-lane → gpt-5.6-sol:medium; opencode-go → minimax-m3; minimax-lanes → MiniMax-M3; opencode-go → minimax-m2.7 (`agent-model-requirements.ts:136-149`) |
| sisyphus-junior | = atlas chain + trailing opencode → big-pickle (`:150-164`) |
| oracle | openai-lane → gpt-5.6-sol:xhigh; copilot → gpt-5.6-sol:high; google-lane → gemini-3.1-pro:high; anthropic-lane → claude-opus-5:max; opencode-go → glm-5.2 (`:36-52`) |
| librarian / explore | openai-lane → gpt-5.6-luna-fast:low; deepseek → deepseek-v4-flash:max; opencode-go/bailian → qwen3.7-plus; opencode-go → minimax-m3; minimax-lanes → MiniMax-M3; opencode-go → minimax-m2.7; anthropic-lane → claude-haiku-4-5; openai-lane → gpt-5.4-nano (`:53-76`) |
| prometheus | anthropic-lane → claude-fable-5-1:xhigh; kimi-lane → kimi-k3:max (`:85-98`) |
| metis (= plan-consultant) | anthropic-lane → claude-fable-5-1:max; → claude-opus-5:max; kimi-lane → kimi-k3:max (`:99-117`) |
| momus (= plan-reviewer) | openai-lane → gpt-6-astra:xhigh; copilot → gpt-6-astra:high; openai-lane → gpt-6-astra:high; anthropic-lane → claude-opus-5:max; google-lane → gemini-3.1-pro:high; opencode-go → glm-5.2 (`:118-135`) |
| hephaestus | openai-lane → gpt-5.6-sol:medium, requiresProvider openai-lane (`:25-35`) |

Resolution order (`packages/delegate-core/src/model-selection.ts:82-279` `resolveModelForDelegateTask`): explicit user model → user-configured category model (bypass validation) → fuzzy-match category default → user `fallback_models` → built-in `fallbackChain` (via connected providers on cold cache, fuzzy match on warm cache) → system default. User `agents.<name>.model`/`models[]` override the chain; schema at `packages/omo-config-core/src/schema/agent.ts:16-35` (`model`, `models[]`, `reasoning`, `tools{}`, `execution_mode`, `background`, `max_depth`, `allowed_subagents`, `disallowed_tools`, `max_turns`, `temperature`, `disable`).

---

## 2. Delegation semantics — task(category) vs task(subagent_type)

### 2.1 Mutual exclusion (typed, both harnesses)

Senpi `task` params, `packages/senpi-task/src/tools/task/params.ts:7-30`:

```ts
category: … "Category name routed to the category worker (…). Mutually exclusive with subagent_type; required unless category is given."
subagent_type: … "Agent name to invoke directly (…). Mutually exclusive with category; required unless category is given."
model: … "Only valid with subagent_type; mutually exclusive with category — category-routed tasks take their model from omo.json (categories.<name>.models)."
run_in_background: … "true (the standard spawn) returns the task id now and delivers the child's result later as a message; false blocks this turn until the child finishes. Omitted counts as false."
```

Validator, `packages/senpi-task/src/tools/task/validation.ts:74-80,97-113`:

```ts
const BOTH_TARGETS_MESSAGE = "Provide EITHER category OR subagent_type, not both. Remove one and retry."
const CATEGORY_WITH_MODEL_MESSAGE = "Provide EITHER category OR model, never both. … Remove model and retry, or use subagent_type … or configure categories.<name>.models in omo.json."
const NO_TARGET_MESSAGE = 'You MUST provide EITHER category OR subagent_type. … Example: task(category="quick", prompt="...") or task(subagent_type="plan-reviewer", prompt="...").'
```

Tool description contract, `packages/senpi-task/src/tools/task/description.ts:52,61-62`:

> "Each spawn MUST provide EITHER category OR subagent_type after inheritance. DO NOT provide both."
> "model is an explicit override for subagent_type spawns ONLY. NEVER combine model with category."

Batch: `tasks[1..16]` inherit top-level target/model/skills; "An inherited model is rejected when the item's effective target is a category" (`description.ts:50`); `run_in_background` is batch-wide, disagreement → `invalid_arguments` (`validation.ts:88-89,133-151`).

OpenCode side: Sisyphus-Junior is category-spawned; orchestrators (Sisyphus/Atlas/Hephaestus) call `task()`/`call_omo_agent`; researchers use `call_omo_agent(subagent_type="explore"|"librarian")`.

### 2.2 Category → model routing table

Categories carry the `models` chain the worker is built from (`docs/guide/orchestration.md` "Categories + Skills"). Built-in chains (`packages/model-core/src/category-model-requirements.ts`):

| Category | Fallback chain |
|---|---|
| `quick` | kimi-for-coding-highspeed; openai-codex gpt-5.6-luna-fast:low; deepseek-v4-flash:off; qwen3.6-flash:low; minimax-m3:max; minimax-m2.7:max; grok-4.20 non-reasoning; claude-haiku-4-5:off (`:66-85`) |
| `unspecified-low` | grok-4.6:xhigh; gpt-5.6-terra:high; claude-sonnet-5:low; qwen3.8-max-preview:max; deepseek-v4-pro:max; mimo-v2.5-pro:max (`:86-107`) |
| `unspecified-high` | gpt-6-astra:high; claude-opus-5:xhigh; glm-5.3:max; kimi-k3:max (`:108-127`) |
| `deep` | gpt-6-astra:high; gpt-5.6-sol:medium (`:33-46`) |
| `ultrabrain` | gpt-6-astra:max; gpt-5.6-sol:max (×openai/codex, copilot, +opencode lanes) (`:23-32`) |
| `visual-engineering` | claude-fable-5-1:max; claude-opus-5:max; kimi-k3:max (`:4-22`) |
| `artistry` | claude-fable-5-1:max; kimi-k3:max; claude-opus-5:xhigh (`:47-65`) |
| `writing` | claude-fable-5-1:medium; kimi-k3:max (`:128-141`) |

Delegation router (`docs/guide/orchestration.md`):

| Category | Route here |
|---|---|
| `quick` | mechanical, single-file, boilerplate, config/copy; default for every splittable piece |
| `unspecified-low` | small tasks fitting no other category |
| `unspecified-high` | standard features across a few files with known patterns |
| `visual-engineering` | frontend, UI/UX, styling, animation |
| `writing` | documentation and prose |
| `deep` | hairy debugging, research-heavy / subtle cross-module work |
| `ultrabrain` | one genuinely hard logic-heavy problem; hand it the goal, not steps |
| `architect` | consult lane: module boundaries, decomposition, trade-offs (advisory, read-only) |

Gating: `ultrabrain`/`deep` need a GPT flagship in registry; unavailable category = reported, never silently rerouted. `architect`+`ultrabrain` double as background advisory lanes during planning (spawned `run_in_background:true`, advisory-only prompts).

---

## 3. Background agents

### 3.1 Two surfaces (do not conflate)

- **Senpi `task(run_in_background=...)`** — `packages/senpi-task/src/tools/task/params.ts:26-28`; continue with `task_send(to="st_…")`, peek with `task_output`, end with `task_cancel` (`description.ts:63`). Concurrency config = `task:` block in `omo.json`: `default_concurrency: 5`, `global_concurrency: 8`, per-`provider_concurrency` / `model_concurrency` maps, `0` = unlimited (`packages/omo-config-core/src/schema/task.ts:43-64,116-127`; residency cap `residency_max_children` default `min(16, max(8, cores*2))`).
- **OpenCode `background_task` / `background_output` / `background_cancel` tools** — `packages/omo-opencode/src/tools/background-task/`.

### 3.2 Background API (OpenCode harness)

Descriptions (`packages/omo-opencode/src/tools/background-task/constants.ts`):

```ts
export const BACKGROUND_TASK_DESCRIPTION = `Run agent task in background. Returns a background task ID (\`bg_...\`) immediately and notifies on completion.
Do NOT poll for results. The system delivers a <system-reminder> when the task finishes.
Prompts MUST be in English.`
export const BACKGROUND_OUTPUT_DESCRIPTION = `Get output from background task. Use full_session=true to fetch session messages with filters. System notifies on completion, so block=true rarely needed. - Timeout values are in milliseconds (ms), NOT seconds.
IMPORTANT: ONLY call this tool AFTER receiving a <system-reminder> notification for the task. Do NOT call immediately after launching a background task - wait for the notification first.`
export const BACKGROUND_CANCEL_DESCRIPTION = `Cancel running background task(s). Use all=true to cancel ALL before final answer.`
```

Args (`packages/omo-opencode/src/tools/background-task/types.ts`):

```ts
export interface BackgroundTaskArgs { description: string; prompt: string; agent: string }
export interface BackgroundOutputArgs { task_id: string; block?: boolean; timeout?: number;
  full_session?: boolean; include_thinking?: boolean; message_limit?: number;
  since_message_id?: string; include_tool_results?: boolean; from_end?: boolean; thinking_max_chars?: number }
export interface BackgroundCancelArgs { taskId?: string; all?: boolean }
```

Launch returns `Task ID: bg_xxxxxxxx / Session ID … / Description / Agent / Status` plus "Do NOT call background_output now. Wait for `<system-reminder>` notification first" (`create-background-task.ts:112-120`). Task ids match `/^bg[_-]/`, session ids `/^ses[_-]/` (`create-background-output.ts:50-56`).

### 3.3 Concurrency limits (OpenCode harness)

Schema `packages/omo-opencode/src/config/schema/background-task.ts:9-13`:

```ts
export const BackgroundTaskConfigSchema = z.object({
  defaultConcurrency: z.number().min(0).optional(),
  providerConcurrency: z.record(z.string(), z.number().min(0)).optional(),
  modelConcurrency: z.record(z.string(), z.number().min(0)).optional(),
  …staleTimeoutMs (≥60s, def 180s), taskTtlMs (≥300s, def 1800s), maxToolCalls (≥10, def 200)…
})
```

Precedence (`features/background-agent/concurrency.ts:28-45`): `modelConcurrency[model]` → `providerConcurrency[provider]` → `defaultConcurrency` → hardcoded `5`; `0` = `Infinity`. Keying uses the most-specific configured level (`getConcurrencyKey`).

### 3.4 tmux pane spawn + server requirement

Attach command (`packages/tmux-core/src/tmux-utils/pane-command.ts:14-19`):

```ts
export function buildTmuxAttachCommand(serverUrl: string, sessionId: string, directory: string = process.cwd()): string {
  …
  return `${TMUX_COMMAND_SHELL} -c "opencode attach ${escapedUrl} --session ${escapedSessionId} --dir ${escapedDirectory}"`
}
```

Spawn guards (`packages/tmux-core/src/tmux-utils/pane-spawn.ts:58-90`): skip unless `config.enabled`, inside tmux/cmux-compat, **server reachable** (`isServerRunning(serverUrl)`), tmux binary found. Session-created handler waits for child registration before spawning, else `opencode attach` exits and the pane auto-closes (`features/tmux-subagent/session-created-handler.ts:108-112`, issue #3505). Server requirement (`src/create-managers.ts:76-88`): a vanilla `opencode` session (no `opencode serve` / `opencode web`) leaves `ctx.serverUrl` undefined; marking it running would let `createTeamLayout` spawn panes whose `opencode attach` fails on the fallback port (issue #3894) — so `markServerRunningInProcess` runs only when `tmuxConfig.enabled && ctx.serverUrl`. **Build rule for Spark: tmux attach panes require a live server (`serve`/`web`, `--port`); never assume one from tmux presence alone.**

---

## 4. Plan → conduct flow (Prometheus interview → plan file → Momus verdict → start-work → Atlas)

State machine (`docs/guide/orchestration.md`):

```
[*] --> Explore: /ulw-plan --> Verdict --> Interview(CLEAR) / Defaults(UNCLEAR)
--> Brief --> Approval(user "okay") --> GapAnalysis(plan-consultant)
--> WritePlan(.omo/plans/<slug>.md) --> Review(plan-reviewer round)
--> WritePlan(REJECT, fix cited) / Done(APPROVE) --> [*] (handoff to /ulw-execute)
```

| Step | Actor | Rule |
|---|---|---|
| `/ulw-plan` | Ultrawork Planner (= Prometheus role; `prometheus-md-only` hook pins the planner agent to `.md` files) | Opens with exactly `ULW-PLAN MODE ENABLED!`; sticky plan mode ("do X" = "plan X"); never implements (`packages/omo-senpi/skills/ulw-plan/SKILL.md`) |
| Explore | planner | parallel `explore`/`librarian` (+ `architect`/`ultrabrain` advisory lanes when available) before any question |
| Verdict | planner | announces `Intent: CLEAR/UNCLEAR` + `review_required`; CLEAR = outcome known → ask surviving owner-decisions with WHY; UNCLEAR = adopt+announce best-practice defaults, auto high-accuracy review; fence-sitters = CLEAR + exactly 1 question; "ask me" forces interview |
| Brief → approval | user | plan is written only after explicit okay; approval authorizes writing only |
| Gap analysis | `plan-consultant` (Metis) | pre-write; hidden intent, ambiguity, scope creep, acceptance gaps |
| Write | planner via `scaffold-plan.mjs` | draft `.omo/drafts/<slug>.md` (resume point: `intent`, `review_required`, decisions, approval gate) → plan `.omo/plans/<slug>.md`; APPEND batches, never rewrite headers |
| Review | `plan-reviewer` (Momus) | 1 round = 1 pass; approval-biased; REJECT only verified blockers; fix-all-cited → resubmit; cap 5 rounds |
| Conduct | `/ulw-execute [plan-name]` (= start-work; template `features/builtin-commands/templates/ulw-execute.ts`) | select plan → register goal+todos → write `.omo/boulder.json` → Atlas-style orchestration: main agent never writes product code, every unit delegated to category workers, 5 verification gates per checkbox, ledger `.omo/ulw-execute/ledger.jsonl` |

Momus verdict format (`packages/omo-opencode/src/agents/momus.ts`, `MOMUS_DEFAULT_PROMPT` output section):

```
**[OKAY]** or **[REJECT]**
**Summary**: 1-2 sentences explaining the verdict.
If REJECT — **Blocking Issues** (max 3): numbered, each specific + actionable + blocking.
```

Plan-gate (`description.ts:40-41`, orchestration.md): `plan-consultant`/`plan-reviewer` spawnable only after explicit ulw-plan request + touched `.omo/plans/*.md` this session + no `/ulw-execute` yet; bare `ulw` self-reviews in notepad; `/ulw-execute`-bootstrapped plans skip gap/review explicitly. Spawn contract: harness replaces the `plan-reviewer` prompt with the canonical contract (one `.omo/plans/*.md` path; anything else discarded); `task_send` to plan-reviewer always refused (one-shot).

### Plan markdown format

Scaffold: `packages/omo-senpi/skills/ulw-plan/scripts/scaffold-plan.mjs` (`scaffold()`, `buildPlanSkeleton()`). Producer contract (`ulw-plan/SKILL.md`): implementation rows column-zero `- [ ] N. <title>` (positive int), final-verifier rows `- [ ] F<number>. <title>`; every implementation row carries nested `Recommended task executor category:` (verifiers default `unspecified-high`); validator hook enforces `## TODOs` rows `- [ ] N. …` and `## Final Verification Wave` rows `- [ ] F…. …` (`hooks/plan-format-validator/hook.ts:9-14`). Skeleton body (`scaffold-plan.mjs:253+`):

```markdown
## Todos
> Implementation + Test = ONE todo. Never separate.
<!-- APPEND TASK BATCHES BELOW THIS LINE WITH edit/apply_patch - never rewrite the headers above. -->
- [ ] 1. <title>
  What to do / Must NOT do: <...>
  Parallelization: Wave <N> | Blocked by: <...> | Blocks: <...>
  References (executor has NO interview context - be exhaustive): <src/path:lines>
  Acceptance criteria (agent-executable): <exact command or assertion>
  QA scenarios (name the exact tool + invocation): happy + failure, Evidence <attemptDir>/task-1-${slug}.<ext>
  Commit: <Y/N> | <type>(<scope>): <summary>

## Final verification wave
> Runs in parallel after ALL todos. ALL must APPROVE. Surface results and wait for the user's explicit okay before declaring complete.
- [ ] F1. ...
```

Full skeleton also includes TL;DR, Evidence/Change/Verification sections (see checked-in example `.omo/plans/beta8-publish-rpc-parity-xdg.md`), execution strategy (5–8 todos/wave, dependency matrix), commit + success-criteria sections. Invariants: decision-complete (zero interview context for executor), full scope default (no invented MVP), agent-executable QA (tool + steps + expected result + evidence path; "verify it works" fails review).

---

## 5. Skills injection, compaction override, ultrawork trigger

### 5.1 `load_skills` injection

Senpi (`packages/senpi-task/src/tools/task/skills.ts:17-36` `buildSkillPrepend`): each resolved `SKILL.md` wrapped in `<skill name="…" location="…">` (+ "References are relative to …"), joined, **prepended before the child prompt**; empty input = prompt untouched. Search dirs: `<cwd>/.senpi/skills`, ancestor `.agents/skills` up to git root, `.pi/skills`, agent dir (`skills.ts:37-61`). Usage: `task({ category: "visual-engineering", load_skills: ["frontend"], prompt: "…" })`; main-agent skills (`ulw-plan`, `ulw-execute`, `ulw-loop`, `mass-ulw`, `hyperplan`, `ultrawork`, `ulw-research`) invoked by name, workers get skills only via `load_skills` (orchestration.md). OpenCode side: `resolveAgentSkills()` wires git-master/browser/team skills per agent (`builtin-agents/general-agents.ts:120`).

### 5.2 Compaction prompt override

`session-compacting.ts` runs ordered steps with per-hook failure isolation (`runCompactionStep`). Override prompt (`hooks/compaction-context-injector/compaction-context-prompt.ts`, `COMPACTION_CONTEXT_PROMPT`): 8 terse-continuation sections — 1 user requests, 2 final goal, 3 work completed, 4 remaining tasks, 5 active working context (files/code/refs/state), 6 explicit constraints verbatim-only, **7 agent verification state (current agent — momus/oracle/etc. — progress, pending, rejections, acceptance status; "CRITICAL for reviewer agents")**, 8 delegated agent sessions. Sibling hooks: `compaction-todo-preserver` (capture/restore todos across compaction), `compaction-aware-message-resolver` (background-task notifications).

### 5.3 Ultrawork trigger

Keyword detector (`hooks/keyword-detector/constants.ts:33-38, detector.ts:54`):

```ts
{ type: "ultrawork", pattern: /\b(ultrawork|ulw)\b/i, message: getUltraworkMessage }
```

Typing `ulw`/`ultrawork` injects `<ultrawork-mode>` (LIGHT/HEAVY tier triage, evidence-driven, first line `ULTRAWORK MODE ENABLED!`; skill `packages/omo-senpi/skills/ultrawork/SKILL.md`). Combos: `hyperplan±ultrawork` in either order (strict adjacency regex, `:15`) injects hyperplan-ultrawork banner + forces `skill(name="hyperplan")`. Mid-task upgrade rule: unsure → HEAVY; HEAVY fact surfacing mid-task upgrades immediately, never downgrades.

---

## Appendix — config shapes worth copying for Spark

`omo.json` delegation surfaces (orchestration.md "Configuration"):

```jsonc
{
  "agents": {
    "plan-consultant": { "models": ["anthropic/claude-opus-5"] },
    "plan-reviewer":   { "models": ["openai/gpt-5.6-sol"], "reasoning": "high" },
    "explore": { "disable": false }
  },
  "categories": {
    "quick":   { "models": ["anthropic/claude-haiku-4-5"] },
    "writing": { "models": ["anthropic/claude-opus-5"] }
  }
}
```

Agent entry keys: `model | models[] | reasoning | tools{} | allowed_subagents | disallowed_tools | max_turns | temperature | disable` (+ `execution_mode | background | max_depth`); category entries: `models` chain + `reasoning/temperature/top_p/max_tokens/provider_options/tools/prompt_append/max_prompt_tokens` (`schema/agent.ts`, `schema/category.ts`).
