# 06 — Flow & Goal Orchestration: subtask2, conductor, micode, goal-plugin

Sources cloned `--depth 1` into `/tmp/opencode/ref-study/flow/` on 2026-09-15:
`subtask2` (spoons-and-mirrors), `opencode-conductor` (derekbar90),
`micode` (vtemian), `OpenCode-goal-plugin` (willytop8).
All `file:line` refs below are relative to each repo root. `/home/karim/dev/m8`
was NOT read per task constraint; §4 describes the goal-plugin side only.

---

## 1. subtask2 — `/commands` become orchestration with granular flow control

Thesis (README:1-13): a better opencode `/command` handler — chain prompts /
commands / subagents, relay results, loop or parallelize, override params inline.

### 1.1 Command file format (markdown + YAML frontmatter)

- Canonical shape is a standard opencode command file: YAML frontmatter, then
  `$ARGUMENTS` / `$TURN[n]` template body. Examples at README:49-54,
  README:115-122, README:168-178.
- Manifest builder scans `~/.config/opencode/command/**/*.md` and
  `./.opencode/command/**/*.md`, keys by filename and by subfolder path
  (`subtask2/src/commands/manifest.ts:14-63`).
- Frontmatter keys parsed into `CommandConfig`
  (`subtask2/src/types.ts:17-26`, `manifest.ts:31-48`):
  `return: string[]` (single value coerced to array), `parallel:
  ParallelCommand[]`, `agent`, `description`, `template` (body after `---`),
  `loop: LoopConfig`, `model`, `auto` (`fm.subtask2 === "auto"`).
- File loader resolves subfolder commands by direct path then `**/<name>.md`
  glob (`subtask2/src/commands/loader.ts:7-37`); return-chain executor
  re-resolves `pathKey` the same way (`features/returns.ts:186-191`).

Minimal example (README:49-54):

```yaml
subtask: true
return: Look again, challenge the findings, then implement the valid fixes.
---
Review the PR# $ARGUMENTS for bugs.
```

Multi-step chain (README:58-65) uses `return:` as an ordered string array;
command entries starting with `/` execute immediately as full commands with
their own `parallel` + `return` (README:67-88).

### 1.2 Flow-control primitives

| Primitive | Frontmatter | Inline `{...}` override | Parser |
|---|---|---|---|
| sequence (`return`) | `return: [a, b]` | `return:a \|\| b` | `parsing/overrides.ts:45-50` (`\|\|` split) |
| fan-out (`parallel`) | list or `/a, /b` string | `parallel:/a \|\| /b` | `parsing/parallel.ts:73-88`, `overrides.ts:51-56` |
| loop w/ condition | `loop: {max, until}` or `loop: 5` | `{loop:10 && until:...}` | `parsing/parallel.ts:10-27`, `overrides.ts:32-44` |
| named result | — (runtime `as:` on parallel/return items) | `{as:name}` + `$RESULT[name]` | `overrides.ts:57-59`, `features/results.ts:22-48` |
| context inject | `$TURN[n]` in body/args | same | `features/turns.ts`, README:240-286 |
| model/agent swap | `model:`, `agent:` | `{model:p/m && agent:x}` | `overrides.ts:28-31` |
| ad-hoc subtask | n/a | `/subtask {…} prompt` | `parsing/commands.ts:23-38,89-107` |
| auto workflow | `subtask2: auto` (`manifest.ts:47`) | `{auto:true}` (`overrides.ts:60-62`) | `utils/prompts.ts:73-108` |

Separator contract (`parsing/overrides.ts:13-17`): `&&` between params,
`||` between multi-values; `|`-style pipe args `cmd main || pipe1 || pipe2`
map chronologically main → parallels → return-commands (README:188-227).

### 1.3 Conditionals / loops / branches — the orchestrator-decides pattern

- `LoopConfig = { max: number; until: string }` (`types.ts:1-4`).
- Inline `{loop:N}` with empty `until` = unconditional fixed iterations;
  main session just yields between runs (`utils/prompts.ts:62-67`,
  README:99-105).
- `{loop:N && until:"..."}` = conditional loop (README:107-156):
  1. subtask runs; 2. main session gets `loopEvaluationPrompt(condition,
     iteration, max)` (`utils/prompts.ts:31-56`) as a return; 3. main LLM
     verifies against reality (read files, git diff, run tests — prompt
     explicitly forbids writing: `prompts.ts:48`); 4. verdict is a marker:
     `<subtask2 loop="break"/>` or continue-by-default
     (`loop.ts:30-33`); 5. `session.idle` hook advances iteration or resumes
     deferred returns (`hooks/session-idle-hook.ts:30-44` imports,
     `loop.ts:66-91` iteration/max bookkeeping).
- Loop state is per-session in-memory: `activeLoops`, `pendingLoopEvaluation`
  maps (`loop.ts:13-17`); deferred post-loop returns ride `LoopState.deferredReturns`
  (`loop.ts:3-11`) / `core/state.ts:432-453`.
- Priority: inline `{loop:…}` beats frontmatter `loop:` (README:155).
- Branching = `parallel:` fan-out + parent `return:` fan-in. Parallels are
  forced to subtasks, their own `return`s ignored, depth flattened at max 5
  (README:168-186,225). Per-command args via `{command, arguments}` objects
  or `/cmd args` syntax (`types.ts:6-15`, `parallel.ts:30-71`).

### 1.4 State passing

- Session-scoped in-memory maps in `core/state.ts`: `returnState`,
  `returnStack` (nested chains, `state.ts:150-250`), `pendingReturns`,
  `pipedArgsQueue` (`state.ts:302-321`), `pendingPromptReturn`
  (`state.ts:522-552`), `subtaskParentSession` + race-safe
  `pendingParentByPrompt` (`state.ts:562-579`), `OPENCODE_GENERIC` constant
  (`state.ts:71-72`).
- Named results: `subtaskResults: Map<parentSession, Map<name, output>>`
  (`state.ts:49,594-764`); `captureSubtaskResult` on subtask completion,
  `storeSubtaskResult` for main-session `as:` captures,
  `$RESULT[name]` substituted at return-build time (`features/results.ts:22-48`;
  unresolved → `[Result 'name' not found]`).
- Execution: `executeReturn()` (`features/returns.ts:34-273`) — `/…` items go
  through `parseCommandWithOverrides` (`parsing/commands.ts:16-72`) then
  `client.session.command` or `promptAsync({parts:[{type:"subtask",…}]})` for
  inline subtasks (`returns.ts:156-176`); prompt items become real user
  messages via `promptAsync({parts:[{type:"text"}]})` (`returns.ts:258-272`).
  Dedup by `sessionID:item` (`returns.ts:72-74`).
- Advancement signal: `session.idle` handler (`hooks/session-idle-hook.ts:44`)
  is "the authoritative signal to advance return chains and loop iterations"
  (line 40-43); it maps subtask→parent by first-message prompt content
  (lines 50-80) before draining return state.

---

## 2. conductor — Context→Spec→Plan→Implement lifecycle enforcement

Slogan (README:1-8): "Measure twice, code once" — control code by controlling
context; project requirements/plans are managed artifacts grounding every
agent interaction.

### 2.1 Stage gates and who advances

| Stage | Command / artifact gate | Who advances |
|---|---|---|
| 0. Setup (once per project) | `/conductor:setup` writes `conductor/product.md`, `tech-stack.md`, `workflow.md`, code styleguides, `setup_state.json`; `StateManager` tracks `last_successful_step` (`src/utils/stateManager.ts:4-37`); `setup.json` resumes from that step (`setup.json` §1.2: `STEP` → next section jump) | agent interviews user; user answers; agent writes files + commits |
| 1. Context check | every command opens with SETUP CHECK: resolve Product/Tech/Workflow (and Tracks Registry) via Universal File Resolution Protocol; missing → HALT with "run `/conductor:setup`" (`src/index.ts:58-64`, `newTrack.json` §1.1, `implement.json` §1.1, `status.json` §1.1) | agent (halts, user must run setup) |
| 2. Spec (`spec.md`) | `/conductor:newTrack "desc"` → 3-5 targeted questions (`ask_user`, batched ≤4, choice/text/yesno, additive-vs-exclusive classification) → draft spec (Overview / Functional / Non-Functional / Acceptance / Out-of-scope) → **user Approve/Revise gate** (`newTrack.json` §2.2) | user must Approve; Revise loops until confirmed |
| 3. Plan (`plan.md`) | only after spec approved: generate Phase→Task→Sub-task hierarchy with `[ ]` markers per task, TDD-shaped, plus injected `Task: Conductor - User Manual Verification '<Phase>'` meta-task per phase → **user Approve/Revise gate** (`newTrack.json` §2.3) | user must Approve |
| 4. Track registration | write `<tracks>/<id>/spec.md`, `plan.md`, `metadata.json` (`{track_id,type,status,created_at,…}`), `index.md`; append `- [ ] **Track: …**` + link to Tracks Registry; commit `chore(conductor): Add new track` (`newTrack.json` §2.4) | agent; user runs `/conductor:implement` next |
| 5. Implement | `/conductor:implement [track]` → parse registry by `---` sections, match track, confirm via `ask_user`, then execute `plan.md` checklist sequentially: `[ ]`→`[~]`→work (TDD red/green)→verify→commit→git-notes summary→`[x]+sha` (`workflow.md:14-68`, `implement.json` §2.0) | agent task-by-task; user only at phase checkpoints |
| 6. Phase checkpoint | after a phase-closing task: coverage check, ≤2 auto-fix attempts then STOP, manual verification plan, **PAUSE for explicit user yes**, checkpoint commit + git-notes report, record `[checkpoint: <sha>]` (`workflow.md:69-135`) | user must confirm; agent checkpoints |
| 7. Status / revert | `/conductor:status` parses registry + plans into phases/tasks/completed% (`status.json` §2.0); `/conductor:revert` undoes task/phase/track via git (`tools/commands.ts:61-72`) | agent reports; user selects revert target |

Mechanism notes: commands are tool-returned directive prompts, not code —
`createConductorCommand` loads `src/prompts/conductor/*.json` (fallback
`legacy/…/*.toml`), substitutes `{{args}}`/`{{track_name}}`/
`{{strategy_section}}`, returns `{directives: prompt}` JSON
(`utils/commandFactory.ts:18-109`); slash commands registered in plugin
`config` hook inject file hierarchy + setup flag into templates
(`src/index.ts:66-127`). Execution strategy swaps `manual.md` vs
`delegate.md` on OMO activity (`commands/implement.ts:16-33`,
`tools/commands.ts:29-53`). Setup gate is file-existence
(`index.ts:58-61`); all other gates are prompt-protocol + `ask_user` —
no programmatic state machine beyond `setup_state.json`.

### 2.2 Artifact per stage

- Setup: `conductor/product.md`, `product-guidelines.md`, `tech-stack.md`,
  `workflow.md` (`src/templates/workflow.md`), `code_styleguides/*.md`,
  `setup_state.json`.
- Track: `conductor/tracks/<shortname_YYYYMMDD>/{spec.md, plan.md,
  metadata.json, index.md}` + Tracks Registry entry.
- Implement: per-task commits + `git notes` task summaries, per-phase
  checkpoint commits + verification-report notes, `plan.md` status flips with
  short SHAs (`workflow.md:52-68,118-133`).
- Quality gates before any task-done (`workflow.md:137-149`): tests pass,
  >80% coverage, style/docs/types/lint/security/mobile checks.

---

## 3. micode — Brainstorm→Plan→Implement with session continuity

Pipeline (README:20-38): `Brainstorm → Plan → Implement`, each stage firing
research subagents; `/ledger` preserves session state.

### 3.1 Stage handoffs (agent prompts are the state machine)

- **Brainstormer** (`src/agents/brainstormer.ts`, `mode:"primary"`):
  understanding (parallel locator/analyzer/pattern-finder via Task tool,
  lines 99-112) → exploring (2-3 approaches, decide-don't-ask, 114-121) →
  presenting (all sections one message, 123-134) → finalizing (write
  `thoughts/shared/designs/YYYY-MM-DD-{topic}-design.md`, git-commit it,
  immediately spawn planner, never ask "ready?", 136-147) → handoff
  (planner done → immediately spawn executor, 149-160). Output sections fixed:
  Problem/Constraints/Approach/Architecture/Components/DataFlow/Errors/Testing/
  OpenQuestions (lines 241-258).
- **Planner** (`src/agents/planner.ts`, subagent): read design + mandatory
  `mindmodel_lookup` first (122-134), minimal research (≤3-5 subagent calls,
  36-61), emit micro-task plan (one file + its test per task, exact paths,
  copy-paste code, TDD, verify cmd + commit msg per task) grouped into
  parallel batches with explicit `depends:` annotations + Dependency Graph
  header, written to `thoughts/shared/plans/YYYY-MM-DD-{topic}.md`
  (161-174,205-279). Never runs git/ls (336-347).
- **Executor** (`src/agents/executor.ts`, subagent): batch-first fan-out —
  parse ALL tasks first, then per batch fire ALL implementers in ONE message
  (10-20 parallel `spawn_agent` calls), then ALL reviewers in ONE message;
  fix-cycle max 3 then BLOCKED; next batch only when current is DONE/BLOCKED
  (50-68,123-140,142-150). Implementer does one file+test; reviewer
  (`src/agents/reviewer.ts:1-56`) verifies file/test/pass/plan-match with
  concrete fixes. Never sequential per-task, never self-implement
  (238-250). Worktree isolation per README:35.

### 3.2 Continuity record format

- Path: `thoughts/ledgers/CONTINUITY_{session-name}.md`
  (`ledger-creator.ts:69`, `utils/config.ts:64-68`: `ledgerDir`,
  `ledgerPrefix`).
- Creator agent (`src/agents/ledger-creator.ts:4-116`): `temperature: 0.2`,
  `edit/task` tools off; modes initial vs iterative (preserve-then-merge,
  never lose info, 34-41); input for updates = previous ledger + deterministic
  file-ops lists (43-58); exact output template (71-111):

```md
# Session: {session-name}
Updated: {ISO timestamp}
## Goal — one-sentence success criterion
## Constraints — requirements, patterns, avoid-list
## Progress — Done [x] / In Progress [ ] / Blocked
## Key Decisions — **Decision**: rationale
## Next Steps — ordered list
## File Operations — Read / Modified paths (merged previous+new)
## Critical Context — data, examples, findings to resume
## Working Set — Branch + key files
```

- Loader hook (`src/hooks/ledger-loader.ts:38-94`): on `chat.params`, pick
  latest `CONTINUITY_*.md` by mtime, inject as
  `<continuity-ledger session="…">…</continuity-ledger>` + "resume from Now"
  prefix into system prompt. Auto-compact at ~50-70% context
  (`config.ts:23-31`, README:84) and artifact auto-index / file-ops tracker
  hooks keep the record fresh (README:80-89).

---

## 4. goal-plugin — session-scoped `/goal` workflow (plugin side only)

Install (README:62-75): npm plugin pin + `command.goal: {template:
"$ARGUMENTS", agent: "build"}`. No m8 internals described here per constraint.

### 4.1 Lifecycle states and transitions

- States surfaced by `/goal status` (README:123-130,
  `src/goal-plugin.js:850,868-893`): `active` (can continue), `paused`
  (user intervention, safety limit, audit rejection, recovery…), `blocked`
  (assistant recorded a concrete blocker). Goal object carries
  `stopped: boolean` + `stopReason: string` plus `blockedReason`
  (`goal-plugin.js:3200-3260` shape: `turnCount, startedAt, pausedAt,
  totalTokens, usage, options, noProgressTurns, noToolCallTurns,
  blockedReason, budgetWrapupSent, stopped, stopReason, promptFailures,
  history[], checkpoints[]…`).
- Commands: `/goal <objective> [--max-turns/--max-minutes/--max-tokens/
  --budget/--success/--constraints/--mode]` replaces focused goal; `/goal add`
  backgrounds current + focuses new; `/goal list|focus|sequence|edit|pause|
  resume|clear|status|history` manage the set (README:91-198). Only the
  focused goal auto-continues; ordered `sequence` (split on `;`/newlines)
  auto-promotes on completion (README:177-198).
- Pause triggers: own human message (aborts accepted continuation),
  Plan/restricted agent active (held, `stopped:true,
  stopReason:"plan agent active"`, zero auto-continues — README:459-474),
  any safety limit, no-progress / no-tool-call stall, prompt failures,
  audit rejection, restart recovery (loaded paused, README:287), lease loss
  (passive mode, README:289-291). `/goal resume` reopens a fresh budget
  window without losing objective/history (README:293).
- Transition-only lifecycle notices via log/toast or `lifecycleMessenger`;
  no per-idle spam (README:393-399).

### 4.2 Keeping objectives in context + auto-continue until complete

1. Set stores per-session state and rewrites the command turn into a
   plugin-generated work instruction; `experimental.chat.system.transform`
   reinforcement is defense-in-depth only (README:224).
2. Every idle event re-verifies idleness (no human msg, newer turn, agent
   switch, rejected permission, abort, provider error — README:225) then sends
   a continuation prompt with remaining budget + completion audit, preserving
   the initiating agent/provider/model (README:225). Durable claim on the
   source turn prevents double-send (README:228).
3. Stop only on substantiated terminal marker, blocker, or safety limit
   (README:226). Compaction injects a deterministic summary (objective,
   status, budget, checkpoints, lifecycle events) rebuilt from persisted
   record, and suppresses the host generic post-compaction continue to avoid
   races (README:227).
4. User message mid-run pauses + aborts the accepted continuation
   (README:228).

### 4.3 Evidence-gated completion (claim / generation / pause comparison surface)

- Canonical end-of-response markers, own final line
  (README:230-246, `goal-plugin.js:934-938`):
  `[goal:evidence] <what was run/verified>` immediately followed by
  `[goal:complete]`; or concrete-blocker line + `[goal:blocked]`. Bare
  `goal:complete/blocked/evidence` accepted; "goal complete" prose ignored
  (README:247).
- **Claim**: assistant asserts completion via the marker pair (or
  `goal_complete` tool with structured `summary` + criterion/evidence pairs +
  checks + files + limitations — README:387). Malformed claims rejected and
  re-prompted (README:226).
- **Generation** (audit text): always-on local evidence gate checks adjacency
  + non-empty evidence; optional independent verifier — `completionAudit:true`
  child session (`[audit:approved|rejected]`) or custom `auditor()` —
  fail-closed, timeout-capped (README:407-431).
- **Pause model**: rejection (missing/stale evidence, failed check, empty
  criterion evidence — `completion-claim.js:25-104`, `serializeCompletionClaim`
  caps at `completion-claim.js:1-8`) pauses with `stopReason: audit rejected`,
  preserving reason in status for `/goal resume` (README:414). Terminal ledger
  write precedes state write so outcome survives crashes (fail-closed,
  README:285). Audit start/result messages announced separately from lifecycle
  notices (README:401-405).
- Programmatic surface mirrors commands: `goal_status/set/pause/resume/block/
  complete` canonical JSON-envelope tools + legacy aliases
  (README:378-391); `agentGoalAuthority:"status"` can forbid agents from
  replacing/editing/clearing the objective (README:387).

### 4.4 Persistence & safety limits (for the comparison)

- Project-local `.opencode/goals/state.json` + per-session SHA shard +
  append-only `<shard>.ledger.jsonl` (0600), capped in-memory history,
  ledger-driven reconstruction of still-active goals as paused, terminal-first
  writes, single-owner lease with passive mode for second processes
  (README:272-291; paths/rotation/recovery at `goal-plugin.js:625-850,
  1401-1470`).
- Defaults (`goal-plugin.js:73-83`, README:248-271): 10 turns, 15 min,
  200k context tokens, cost off, 1.5s cooldown, <50-token stall floor with
  2-turn grace, 2 tool-free turns, 80% wrap-up threshold, 3 prompt failures;
  one wrap-up prompt on limit stop, then `/goal resume` for a fresh window.

---

## 5. Recommendation for a Spark coordinator needing conditionals

Need: retry-worker, fan-in gate (all-workers-done), reviewer-reject loop.
Judged purely on the four patterns above:

- **subtask2 fits best.** It is the only one with first-class, in-band flow
  control: `return:` sequencing, `parallel:` fan-out with parent-`return:`
  fan-in, `{loop:max && until:"…"}` conditional retry driven by an
  orchestrator-evaluates-marker protocol, and `$RESULT[name]` state passing
  between steps — exactly retry-worker + fan-in gate + reviewer-reject-loop.
  Enforcement is hook-level (`session.idle` advancement, generic-message
  removal), not just prompt text, so it survives real runs.
- conductor contributes the **stage-gate discipline** (spec-approve →
  plan-approve → implement → phase-checkpoint) but gates are human `ask_user`
  approvals over file artifacts, with no programmatic loop/branch — wrong
  shape for autonomous retry/fan-in.
- micode contributes **batch-first executor + reviewer cycle cap (3) +
  ledger continuity format** — good worker topology and resume record, but
  phases advance by agent obedience, no conditional primitive.
- goal-plugin contributes the **safety/audit shell**: session-scoped objective
  persistence, evidence-gated completion (`[goal:evidence]`+`[goal:complete]`
  adjacency), stall/limit pauses, fail-closed ledger. Use it around the loop,
  not as the loop.

**Minimal flow-control addition if the lab runner lacks it** (no m8 claim
made — sized from the subtask2/goal-plugin mechanics):

1. Add `loop: {max, until}` + `until`-evaluation prompt with a break-marker
   contract (`<lab loop="break"/>`), evaluated by the coordinator on idle,
   mirroring `utils/prompts.ts:31-56` + `loop.ts:30-91`. This covers both
   retry-worker and reviewer-reject-loop with one primitive.
2. Add `parallel:` fan-out with main-`return:` fan-in barrier (ignore child
   returns, cap nesting), mirroring README:225 + `parallel.ts:73-88`.
3. Add `$RESULT[name]` capture/substitution for fan-in synthesis, mirroring
   `core/state.ts:594-764` + `features/results.ts:22-48`.
4. Wrap the whole run in a goal-plugin-style evidence gate + stall/limit
   pauses (adjacent evidence requirement, no-progress/no-tool-call counters,
   wrap-up prompt) rather than inventing a new terminator.

Adopt subtask2's control plane, conductor's artifact gates at phase
boundaries, micode's ledger fields for resume, goal-plugin's evidence/stall
shell for termination.
