# 05 — kdco Workspace Bundle (build reference)

Source clones (2026-09-15, `--depth 1`, workdir `/tmp/opencode/ref-study/kdco`):
- `opencode-workspace` — https://github.com/kdcokenny/opencode-workspace.git — OK
- `opencode-background-agents` — https://github.com/kdcokenny/opencode-background-agents.git — OK
- `opencode-worktree` — https://github.com/kdcokenny/opencode-worktree.git — OK
- `ocx` — https://github.com/kdcokenny/ocx.git — OK (monorepo, registry source of truth)

Canonical registry: `ocx/workers/kdco-registry/registry.jsonc` (416 lines). Facade repos (`opencode-workspace`, `opencode-background-agents`, `opencode-worktree`) are synced copies of `ocx/workers/kdco-registry/files/*` — verified: `diff -q` on `background-agents.ts` and `worktree.ts` standalone vs workspace copy shows **no differences**.

---

## 1. Bundle layout — "16 components"

Claim verbatim from `opencode-workspace/README.md:24-33`:

> A **bundle** — a curated collection of 16 components that work together as a complete AI development harness. Installing `kdco/workspace` gives you:
> - 4 plugins (delegation, planning, notifications, worktrees)
> - 2 npm plugins (DCP, markdown table formatter)
> - 3 MCP servers (Context7, Exa, GitHub Grep)
> - 4 agents (researcher, coder, scribe, reviewer)
> - 4 skills (plan protocol, code review, code philosophy, frontend philosophy)
> - 1 command (/review)
> - Orchestrator configurations for plan/build/explore agents
> - Permission boundaries (webfetch deny, agent sandboxing)

Arithmetic note: 4+2+3+4+4+1 = 18 listed items; "16" = 4 plugins + 4 agents + 4 skills + 1 command + 3 MCP = 16, with 2 npm plugins counted as external (not registry `components`). Registry `workspace` bundle deps (`registry.jsonc:321-332`) list 10: `workspace-plugin, plan-protocol, researcher, scribe, coder, reviewer, review, notify, worktree, philosophy` + `philosophy` expands to 2 more skills. `kdco-primitives` is a transitive dependency (shared utils), not counted in the "4 plugins".

### 1.1 Registry component inventory (`ocx/workers/kdco-registry/registry.jsonc`)

| # | name | type | files | deps / notes |
|---|------|------|-------|--------------|
| 1 | `kdco-primitives` | plugin | 10 files (`registry.jsonc:23-33`) | shared utils, no deps |
| 2 | `workspace-plugin` | plugin | `plugins/workspace-plugin.ts` (`:40`) | deps `background-agents, kdco-primitives`; npm `zod@4.3.5` |
| 3 | `background-agents` | plugin | `plugins/background-agents.ts` (`:48`) | deps `kdco-primitives`; npm `unique-names-generator@4.7.1`; sets `permission.task=deny` (`:51-56`) |
| 4 | `notify` | plugin | 5 files `plugins/notify.ts, notify/backend.ts, notify/cmux.ts, notify/status.ts, notify/title.ts` (`:62-68`) | deps `kdco-primitives`; npm `node-notifier@10.0.1, detect-terminal@2.0.0` |
| 5 | `worktree` | plugin | 4 files `plugins/worktree.ts, worktree/state.ts, worktree/terminal.ts, worktree/launch-context.ts` (`:76-81`) | deps `kdco-primitives`; npm `jsonc-parser@3.3.1, zod@4.3.5` |
| 6 | `plan-protocol` | skill | `skills/plan-protocol/SKILL.md` (`:94`) | dep `workspace-plugin` |
| 7 | `code-philosophy` | skill | `skills/code-philosophy/SKILL.md` (`:100-101`) | — |
| 8 | `frontend-philosophy` | skill | `skills/frontend-philosophy/SKILL.md` (`:106-107`) | — |
| 9 | `code-review` | skill | `skills/code-review/SKILL.md` (`:114`) | — |
| 10 | `plan-review` | skill | `skills/plan-review/SKILL.md` (`:121`) | — |
| 11 | `researcher` | agent | `agents/researcher.md` (`:134`) | dep `background-agents` + MCP + permission block (`:136-211`) |
| 12 | `scribe` | agent | `agents/scribe.md` (`:217`) | permission block (`:219-235`) |
| 13 | `coder` | agent | `agents/coder.md` (`:241`) | dep `background-agents` + permission block (`:243-264`) |
| 14 | `reviewer` | agent | `agents/reviewer.md` (`:270`) | deps `code-review, plan-review` + permission block + `temperature: 0.1` (`:272-297`) |
| 15 | `review` | command | `commands/review.md` (`:308`) | dep `reviewer` |
| 16 | `workspace` | bundle | no files (`:320`) | deps 10 listed above + `opencode.plugin` (2 npm) + `opencode.permission` + `opencode.agent` (plan/build/explore) (`:333-403`) |
| 17 | `philosophy` | bundle | `tools/philosophy.md` (`:409`) | deps `code-philosophy, frontend-philosophy`; injects via `opencode.instructions: ["./tools/philosophy.md"]` (`:411-413`) |

External (not registry-built):
- npm plugin `@tarquinen/opencode-dcp@3.1.3` — `registry.jsonc:335`
- npm plugin `@franlol/opencode-md-table-formatter@0.0.6` — `registry.jsonc:335`
- MCP `context7: https://mcp.context7.com/mcp`, `exa: https://mcp.exa.ai/mcp`, `gh_grep: https://mcp.grep.app` — `registry.jsonc:138-142`

### 1.2 Every file path + role (facade `opencode-workspace`, `find … -not -path "*/.git/*" | sort`)

```
opencode-workspace/README.md                              — bundle pitch, arch diagram, components table (:35-82), permissions table (:84-97)
opencode-workspace/LICENSE                                — MIT
opencode-workspace/src/agent/coder.md                     — coder subagent prompt (151 lines; tools table, philosophy checklist, FORBIDDEN)
opencode-workspace/src/agent/researcher.md                — researcher subagent prompt (218 lines; citation + code-snippet output contract)
opencode-workspace/src/agent/reviewer.md                  — reviewer subagent prompt (128 lines; severity + philosophy checklists, output format)
opencode-workspace/src/agent/scribe.md                    — scribe subagent prompt (93 lines; docs/prose only, no bash)
opencode-workspace/src/command/review.md                  — /review slash command (21 lines; delegates to reviewer; $ARGUMENTS scope)
opencode-workspace/src/philosophy/AGENTS.md               — repo-level philosophy pointer (facade copy)
opencode-workspace/src/skill/*/SKILL.md (×5, singular)    — OCX install target path variant
opencode-workspace/src/skills/*/SKILL.md (×5, plural)     — registry source path variant (plan-protocol, code-philosophy, frontend-philosophy, code-review, plan-review)
opencode-workspace/src/plugin/workspace-plugin.ts         — plan_save/plan_read tools + PLAN_RULES/BUILD_RULES + 3 hooks (707 lines)
opencode-workspace/src/plugin/background-agents.ts        — delegate/delegation_read/delegation_list + DelegationManager (1983 lines)
opencode-workspace/src/plugin/notify.ts                   — OS/cmux notifications, session.idle/error/permission/question handlers (1026 lines)
opencode-workspace/src/plugin/notify/backend.ts           — alerter/node-notifier router + cmux-fallback (134 lines)
opencode-workspace/src/plugin/notify/cmux.ts              — cmux notify/set-status/clear-status builders + trust-gated resolution (206 lines)
opencode-workspace/src/plugin/worktree.ts                 — worktree_create/worktree_delete + session.idle auto-commit cleanup (1280 lines)
opencode-workspace/src/plugin/worktree/state.ts           — bun:sqlite sessions + pending_operations singleton (502 lines)
opencode-workspace/src/plugin/worktree/terminal.ts        — tmux/cmux/macOS/Linux/Windows/WSL spawners (1411 lines)
opencode-workspace/src/plugin/worktree/launch-context.ts  — plain vs ocx launch argv (plain: opencode --session; ocx: <ocxBin> opencode -p <profile> --session) (153 lines)
opencode-workspace/src/plugin/kdco-primitives/*.ts (×9)  — get-project-id, mutex, shell, temp, log-warn, with-timeout, terminal-detect, cmux, types + index.ts re-export (33 lines)
```

Standalone facades are subsets (verified identical content):
- `opencode-background-agents`: `src/plugin/background-agents.ts` + `src/plugin/kdco-primitives/*` + `registry.json` (points at `src/plugin/kdco-background-agents.ts` — stale name, actual file is `background-agents.ts`) + `README.md`
- `opencode-worktree`: `src/plugin/worktree.ts` + `src/plugin/worktree/*` + `src/plugin/kdco-primitives/*` + `README.md`
- `ocx/workers/kdco-registry/files/*`: authoritative source (`plugins/`, `agents/`, `skills/`, `commands/`, `tools/philosophy.md`), plus `schemas/worktree.json`, `tests/*.test.ts` (13 test files), `scripts/build.ts` (`buildRegistry({source:".", out:"dist"})`)

Profile wiring: `ocx/workers/ocx-kit/files/profiles/ws/opencode.jsonc` (model routing: plan/build/coder → `opencode/big-pickle`; explore/researcher/scribe/reviewer → `opencode/gpt-5-nano`) + `ocx.jsonc` (registries, renameWindow, exclude rules).

---

## 2. Permission matrix (verbatim)

### 2.1 Bundle-level (`registry.jsonc:333-341`, `workspace` bundle `opencode` block)

```jsonc
"opencode": {
  // External npm plugin for diff/patch support
  "plugin": ["@tarquinen/opencode-dcp@3.1.3", "@franlol/opencode-md-table-formatter@0.0.6"],
  "permission": {
    // Disable webfetch globally for security
    "webfetch": "deny",
    // Worktree tools restricted to primary orchestrator agents
    "worktree_*": "deny"
  },
```

### 2.2 Orchestrators — plan | build read-only, delegate via task (`registry.jsonc:343-362`)

```jsonc
  // Configure orchestrator agents with appropriate permissions
  "agent": {
    "plan": {
      "permission": {
        "edit": "deny",
        "write": "deny",
        "bash": { "*": "deny" },
        "task": "allow",
        "worktree_*": "allow"
      }
    },
    "build": {
      "prompt": "You are a **build orchestrator**. You coordinate implementation through delegation - you do NOT implement directly.\\\\n\\\\n## Your Role\\\\n- Delegate implementation to `coder`\\\\n- Delegate documentation to `scribe`\\\\n- Delegate codebase analysis to `explore`\\\\n- Delegate external research to `researcher`\\\\n- Interpret results and decide next steps\\\\\\\\n\\\\\\\\n## Critical Constraint\\\\\\\\nYou CANNOT edit files or run commands directly. For ALL implementation and verification, delegate to `coder`.",
      "permission": {
        "edit": "deny",
        "write": "deny",
        "bash": { "*": "deny" },
        "task": "allow",
        "worktree_*": "allow"
      }
    },
```

`explore` specialist (`registry.jsonc:363-401`):

```jsonc
    "explore": {
      "permission": {
        "edit": "deny",
        "write": "deny",
        // Deny plan and todo access - context via delegation prompts
        "plan_read": "deny",
        "todoread": "deny",
        "bash": {
          "*": "deny",
          // Allow read-only filesystem exploration
          "ls *": "allow",
          "tree *": "allow",
          "pwd": "allow",
          "cat *": "allow",
          "head *": "allow",
          "tail *": "allow",
          "wc *": "allow",
          "file *": "allow",
          "stat *": "allow",
          "grep *": "allow",
          "rg *": "allow",
          "find *": "allow",
          // Allow git read commands
          "git status*": "allow",
          "git log*": "allow",
          "git diff*": "allow",
          "git show*": "allow",
          "git blame*": "allow",
          "git branch*": "allow",
          "git ls-files*": "allow",
          // Allow system info commands
          "uname*": "allow",
          "hostname": "allow",
          "whoami": "allow",
          "which *": "allow",
          "realpath *": "allow"
        }
      }
    }
```

### 2.3 background-agents plugin — native task disabled (`registry.jsonc:51-56`)

```jsonc
"opencode": {
  // Disable native task tool since this plugin provides delegation
  "permission": {
    "task": "deny"
  }
}
```

Note the layering: plugin sets global `task: deny`; `plan`/`build` agents re-allow `task: allow` so orchestrators can drive **write-capable** subagents via native `task`, while read-only subagents go via `delegate` (see §4).

### 2.4 researcher — MCP-only + read-only + webfetch allow (`registry.jsonc:143-211`)

```jsonc
// Deny MCP tools globally, only allow for researcher agent
"permission": {
  "context7_*": "deny",
  "exa_*": "deny",
  "gh_grep_*": "deny",
  "kagi_*": "deny"
},
"agent": {
  "researcher": {
    "permission": {
      // Allow MCP tools for researcher
      "context7_*": "allow",
      "exa_*": "allow",
      "gh_grep_*": "allow",
      "kagi_*": "deny",
      // Allow web fetching for external research
      "webfetch": "allow",
      // Researcher is read-only - no file modifications
      "write": "deny",
      "edit": "deny",
      // Deny plan and todo access - context via delegation prompts
      "plan_read": "deny",
      "todoread": "deny",
      "bash": {
        "*": "deny",
        // Allow read-only git and package info commands
        "gh repo view*": "allow",
        "gh pr view*": "allow",
        "gh pr list*": "allow",
        "gh issue view*": "allow",
        "gh issue list*": "allow",
        "gh release view*": "allow",
        "gh release list*": "allow",
        "gh run view*": "allow",
        "gh run list*": "allow",
        "gh workflow list*": "allow",
        "gh search *": "allow",
        "gh api *": "allow",
        "npm view*": "allow",
        "npm info*": "allow",
        "npm show*": "allow",
        "pip show*": "allow",
        "pip index*": "allow",
        "cargo search*": "allow",
        "cargo info*": "allow",
        "man *": "allow",
        "tldr *": "allow",
        "dig *": "allow",
        "nslookup *": "allow",
        "whois *": "allow",
        "host *": "allow",
        // Filter/transform commands for piped output
        "jq *": "allow",
        "head *": "allow",
        "tail *": "allow",
        "base64 *": "allow",
        "grep *": "allow",
        "rg *": "allow",
        "wc *": "allow",
        "sort *": "allow",
        "uniq *": "allow",
        "cut *": "allow",
        "awk *": "allow",
        "tr *": "allow"
      }
    }
  }
}
```

### 2.5 coder — full file + bash, no MCP, no plan/todo (`registry.jsonc:245-261`)

```jsonc
"coder": {
  "permission": {
    // Coder cannot use research MCPs
    "context7_*": "deny",
    "exa_*": "deny",
    "gh_grep_*": "deny",
    // Full access to file operations and bash
    "read": "allow",
    "write": "allow",
    "edit": "allow",
    "glob": "allow",
    "grep": "allow",
    "bash": "allow",
    // Deny plan and todo access - context via delegation prompts
    "plan_read": "deny",
    "todoread": "deny"
  }
}
```

### 2.6 scribe — write, no bash (`registry.jsonc:221-232`)

```jsonc
"scribe": {
  "permission": {
    // Scribe writes docs but cannot run commands
    "bash": { "*": "deny" },
    "edit": "allow",
    "glob": "allow",
    "read": "allow",
    "write": "allow",
    // Deny plan and todo access - context via delegation prompts
    "plan_read": "deny",
    "todoread": "deny"
  }
}
```

### 2.7 reviewer — read-only + git, plan/delegation read allowed (`registry.jsonc:274-294`)

```jsonc
"reviewer": {
  // Low temperature for consistent, deterministic reviews
  "temperature": 0.1,
  "permission": {
    // Reviewer is read-only - analysis only
    "edit": "deny",
    "write": "deny",
    "bash": {
      "*": "deny",
      // Allow git inspection commands for reviewing changes
      "git diff*": "allow",
      "git log*": "allow",
      "git show*": "allow",
      "git blame*": "allow",
      "rg *": "allow"
    },
    // Plan and delegation access for citation verification
    "plan_read": "allow",
    "delegation_read": "allow",
    "delegation_list": "allow"
  }
}
```

### 2.8 Human-readable summary (verbatim `opencode-workspace/README.md:84-97` + `ocx/docs/integrations/workspace.mdx:72-85`)

| Scope | Setting |
|-------|---------|
| Global | `webfetch: deny` — no direct web fetching |
| plan | Read-only orchestrator, delegates via `task` tool |
| build | Read-only orchestrator, delegates via `task` tool |
| explore | Read-only specialist, filesystem + git inspection only |
| researcher | Read-only, MCP tools only (Context7, Exa, GitHub Grep) |
| coder | Full file + bash access |
| scribe | File write only, no bash |
| reviewer | Read-only + git inspection |

---

## 3. workspace-plugin — plan management + rule injection

File: `opencode-workspace/src/plugin/workspace-plugin.ts` (707 lines; registry source `ocx/workers/kdco-registry/files/plugins/workspace-plugin.ts`).

### 3.1 Tools

- `plan_save(content: string)` (`workspace-plugin.ts:548-578`): validates via `parsePlanMarkdown` (Zod `PlanSchema`: frontmatter `status/phase/updated`, `goal ≥10 chars`, phases with hierarchical `N.M` task IDs + `ref:word-word-word` citations; single-CURRENT + single-IN-PROGRESS business rules, `:229-251`), writes to `~/.local/share/opencode/workspace/<projectId>/<rootSessionID>/plan.md` (`:520-562`). Project ID = git root commit SHA via `getProjectId` (cross-worktree stable; see §primitives).
- `plan_read(reason: string)` (`:580-601`): reads same path scoped to **root session** (walks `parentID` chain ≤10 deep, `getRootSessionID`, `:526-544`); `ENOENT` → `"No plan found."`.

### 3.2 Rule injection — how rules enter prompts (hooks, verbatim)

**Hook 1 — `experimental.chat.system.transform`** (`workspace-plugin.ts:605-620`):

```ts
// Targeted Rule Injection
"experimental.chat.system.transform": async (input: SystemTransformInput, output) => {
  const agent = input.agent

  // Universal date awareness (all agents) - Law 2: Parse intent, not just data
  const today = new Date().toISOString().split("T")[0]
  output.system.push(`<date-awareness>
Today is ${today}. When searching for documentation, APIs, or external resources, use the current year (${new Date().getFullYear()}). Do not default to outdated years from training data.
</date-awareness>`)

  // Agent-specific rules
  if (agent === "plan") {
    output.system.push(PLAN_RULES)
  } else if (agent === "build") {
    output.system.push(BUILD_RULES)
  }
},
```

- `PLAN_RULES` (`:318-419`): `<workspace-routing>` strict INTERNAL (`explore`) vs EXTERNAL (`researcher`) table + 3 routing examples; `<philosophy>` skill-load directives (plan-protocol REQUIRED, code/frontend-philosophy conditional); `<plan-format>` markdown schema; `<instruction name="plan_persistence">` — plan_save is REQUIREMENT before exit.
- `BUILD_RULES` (`:421-513`): `<delegation-mandate>` orchestrator-only, coder-as-bash-proxy; `<workspace-routing>` (+coder/scribe rows); `<build-workflow>` (plan_read → delegation_list once → delegation_read → load philosophy → delegate to coder → verify → scribe → update plan); `<code-review-protocol>` (delegate to reviewer before reporting done, non-optional).

**Hook 2 — `tool.execute.before`** (`:623-632`): tracks `task` calls with `subagent_type === "coder"` into `activeCoderCalls: Map<callID, {startTime}>` for review triggering; 60 s stale sweep, `unref`'d (`:296-312`).

**Hook 3 — `tool.execute.after`** (`:635-665`): appends `<system-reminder>` —
- after `plan_save`: "MUST now delegate to the reviewer … NON-BLOCKING" (`:641-647`);
- when last tracked coder call completes: "Coder task complete. Proceed to code review" (`:658-664`).

**Hook 4 — `experimental.session.compacting`** (`:668-703`): reads `plan.md`, extracts `← CURRENT` snippet, pushes:

```
<workspace-context>
## Current Plan
${planContent}

## Resume Point
${currentTask ? `Current task: ${currentTask}` : "No task marked as CURRENT"}

## Verification
To verify any cited decision, use `delegation_read("ref:id")`.
</workspace-context>
```

### 3.3 Plan schema (skill contract)

`src/skills/plan-protocol/SKILL.md` (259 lines): frontmatter `status/phase/updated`, `## Goal`, `## Context & Decisions` table with `` ref:delegation-id `` citations, phases `[COMPLETE]/[IN PROGRESS]/[PENDING]/[BLOCKED]`, tasks `N.M` with exactly one `← CURRENT`. Delegation flow: `delegate` → readable ID (`swift-amber-falcon` style) → cite as `` ref:id ``. Troubleshooting table + pre-save checklist (`SKILL.md:237-259`).

---

## 4. background-agents plugin — async delegation API + persistence + notifications

File: `opencode-workspace/src/plugin/background-agents.ts` (1983 lines).

### 4.1 Public API (3 tools)

| Tool | Signature | Behavior |
|------|-----------|----------|
| `delegate` | `(prompt: string, agent: string) → "Delegation started: <id>\nAgent: <agent>…You WILL be notified…Do NOT poll."` (`:1578-1633`) | Validates agent exists; **rejects write-capable agents** (`parseAgentWriteCapability`, `:340-370` — read-only = edit+write+bash all denied) with "Use `task` instead of `delegate`"; creates isolated child session (`parentID`), fires `session.prompt({agent, parts, tools: {task:false, delegate:false, todowrite:false, plan_save:false}})`, finalizes async (`:1142-1163`) |
| `delegation_read` | `(id: string) → full markdown artifact` (`:1635-1650` → `readOutput`, `:1306-1374`) | **Blocking retrieval**: immediate artifact hit → return; else `waitForTerminal` up to `timeoutAt + 10 s grace`, timeout → `handleTimeout`; then `waitForPersistedArtifact`; terminal-no-artifact → deterministic `buildDeterministicTerminalReadResponse`; still-running → "still running… you will receive a <task-notification>" |
| `delegation_list` | `() → "## Delegations\n- **<id>** | <title> [<status>]…"` (`:1652-1678` → `listDelegations`, `:1379-1450`) | Merges in-memory + filesystem (`<dir>/*.md`), parses `# title`, `**Agent:**`, `**Status:**` from markdown; sorts by id; `unread` = terminal + notified + not-yet-retrieved (`hasUnreadCompletion`, `:854-861`) |

Supporting constants (`:235-239`): `DEFAULT_MAX_RUN_TIME_MS = 15 min`, `TERMINAL_WAIT_GRACE_MS = 10 s`, `READ_POLL_INTERVAL_MS = 250 ms`, `ALL_COMPLETE_QUIET_PERIOD_MS = 50 ms`, `PARENT_NOTIFICATION_TIMEOUT_MS = 5 s`.

### 4.2 Context persistence format

- Base: `~/.local/share/opencode/delegations/<projectId>/<rootSessionID>/` (`:1835-1836`; `ensureDelegationsDir`, `:471-475`).
- ID: `unique-names-generator` `adjectives-colors-animals` (`generateReadableId`, `:25-32`, e.g. `elegant-blue-tiger`); collision-checked vs memory + `<id>.md` on disk, 20 attempts (`:885-899`).
- Artifact `persistence-before-notify` (`finalizeDelegation`, `:1006-1032`): resolve result from last assistant text parts (`getResult`, `:1205-1257`) → `generateMetadata` via `small_model` (title 2-5 words/30 chars, description 2-3 sentences/150 chars; JSON-only prompt, fallback = first-line truncation, `:47-147`) → `persistOutput` writes header + content (`:1262-1301`):

```markdown
# {title}

{description}

**ID:** {id}
**Agent:** {agent}
**Status:** {status}
**Session:** {sessionID}
**Started:** {iso}
**Completed:** {iso}

---

{result body}
```

- Record (`DelegationRecord`, `:208-233`): `id/rootSessionID/sessionID/parentSessionID/parentMessageID/parentAgent/prompt/agent/notificationCycle(+Token)/status/createdAt/startedAt/completedAt/updatedAt/timeoutAt/progress{toolCalls,lastUpdateAt,lastHeartbeatAt,lastMessage,lastMessageAt}/notification{terminalNotifiedAt,terminalNotificationCount}/retrieval{retrievedAt,retrievalCount,lastReaderSessionID}/artifact{filePath,persistedAt,byteLength,persistError}/error/title/description/result`.
- Lifecycle: `registered → running → complete|error|cancelled|timeout` (`isTerminalStatus`, `:375-379`); terminal-state protection (`markTerminal` no-op if terminal, `:614-646`); `handleTimeout` deletes session + finalizes `timeout` (`:1169-1189`).

### 4.3 Notification on completion (vs m8 lab-notify pattern)

Per-delegation terminal notification (`buildTerminalNotification`, `:911-927`):

```
<task-notification>
<task-id>{id}</task-id>
<status>{status}</status>
<summary>Background agent {status}: {title || id}</summary>
<title>{title}</title>            (if present)
<description>{description}</description>  (if present)
<error>{error}</error>            (if present)
<artifact>{filePath}</artifact>
<retrieval>Use delegation_read("{id}") for full output.</retrieval>
<remaining>{n}</remaining>        (if >0)
</task-notification>
```

All-complete (cycle-token watermarked, quiet-period debounced, `:713-765` + `:929-947`):

```
<task-notification>
<type>all-complete</type>
<status>completed</status>
<summary>All delegations complete.</summary>
<parent-session-id>{parentSessionID}</parent-session-id>
<cycle>{n}</cycle>
<cycle-token>{parentSessionID}:{n}</cycle-token>
</task-notification>
```

Delivery: `sendParentNotification` via `session.promptAsync({noReply: true, agent: parentAgent, parts: [notification]})` with 5 s race-timeout; on throw → queued in `pendingNotifications` and injected at next `chat.message` (`injectPendingNotificationsIntoChatMessage`, `:825-844` + hook `:1895-1901`). Terminal notify sets `markNotified` then schedules all-complete only when every delegation in the cycle has `terminalNotifiedAt` (`areCycleTerminalNotificationsComplete`, `:694-711`).

Comparison with m8 `lab-notify.ts` pattern (per task brief — **no m8 files were touched**; contrast is architectural): kdco notifies **in-conversation** via `promptAsync(noReply)` + `<task-notification>` XML the orchestrator parses, with persistence-first + blocking-read + compaction carry-forward semantics. A `lab-notify.ts`-style pattern (name suggests lab/OS-level notify script) would notify **out-of-band** (OS/desktop webhook). kdco covers the out-of-band half separately in the **notify plugin** (§below: cmux `notify`/`set-status` + alerter/node-notifier + focus/quiet-hours suppression), i.e. kdco splits "model-facing completion signal" (background-agents) from "human-facing ping" (notify).

### 4.4 background-agents hooks (verbatim essentials)

```ts
"tool.execute.before": async (input: { tool: string }, output: { args?: { subagent_type?: string } }) => {
  if (input.tool !== "task") return
  const agentName = output.args?.subagent_type
  if (!agentName) return
  const { isSubAgent } = await parseAgentMode(client, agentName, log)
  if (!isSubAgent) return
  const { isReadOnly } = await parseAgentWriteCapability(client, agentName, log)
  if (!isReadOnly) return
  throw new Error(
    `❌ Agent '${agentName}' is read-only and should use the delegate tool for async background execution.\n\n` +
    `Read-only agents have: edit="deny", write="deny", bash={"*":"deny"}\n` +
    `Use delegate for read-only sub-agents.\n` +
    `Use task for write-capable sub-agents.`,
  )
},
"experimental.chat.system.transform": async (_input, output) => {
  output.system.push(DELEGATION_RULES)   // delegate/delegation_read/delegation_list routing table + NEVER poll + NEVER idle
},
"experimental.session.compacting": async (input, output) => {
  // running + unread-completed (≤10) → formatDelegationContext → output.context.push(...)
},
event: async ({ event }) => {
  // session.status:idle | session.idle → manager.handleSessionIdle(sessionID) → finalizeDelegation(complete)
  // message.updated → handleMessageEvent (progress/heartbeat tracking)
}
```

(`background-agents.ts:1853-1972`; `DELEGATION_RULES` full text at `:1684-1724`; `formatDelegationContext` at `:1747-1813`.)

---

## 5. worktree plugin — create / delete / prune, base ref, auto-cleanup, session binding

File: `opencode-workspace/src/plugin/worktree.ts` (1280 lines) + `state.ts` (502) + `terminal.ts` (1411) + `launch-context.ts` (153).

### 5.1 Tools (only 2 — no separate prune command)

- `worktree_create(branch: string, baseBranch?: string)` (`worktree.ts:1075-1202`):
  1. Zod `branchNameSchema` validation (no leading `-`, no `//`/`@{`/`..`, no `~^:?*[]\;&|`$()` + control chars, ≤255, `:98-123`).
  2. `parseActiveLaunchContext(process.env)` → `ensureLaunchContextExecutable` (resolves `ocxBin` via `Bun.which`, rejects CWD/tmp-roots, checks X_OK) → `ensureLaunchContextProfile` (`ocx profile show <profile> --global --json`, `:220-302`).
  3. `loadWorktreeConfig` (`.opencode/worktree.jsonc` → `~/.config/opencode/worktree.jsonc`, `:995-1042`; auto-creates project default if neither exists).
  4. `createWorktree(repoRoot, branch, baseBranch, worktreePath)`: path `getWorktreePath` = `<basePath ?? ~/.local/share/opencode/worktree>/<projectId>/<branch>` (`state.ts:99-109`); existing branch → `git worktree add <path> <branch>`; new → `git worktree add -b <branch> <path> <base>` where **base ref defaults to `HEAD`** (`worktree.ts:635-658`).
  5. Sync: `copyFiles` (relative-only, symlink-escape-checked, `:778-824`) + `symlinkDirs` (`:830-873`) + `runHooks(postCreate)` (`:878-898`).
  6. **worktree→session binding**: `forkWithContext` — `session.fork({path:{id:sessionId}})` + copy `~/.local/share/opencode/workspace/<projectId>/<rootID>/plan.md` and `delegations/<projectId>/<rootID>/` into forked-session dirs (`:407-514`); build launch argv (`launch-context.ts:98-119`); `finalizeWorktreeLaunch` opens terminal and `addSession(db, {id:forkedSession.id, branch, path, createdAt, launchMode, profile, ocxBin})` (`:373-401`).
- `worktree_delete(reason: string)` (`:1204-1224`): looks up `getSession(db, sessionID)`; **no immediate delete** — `setPendingDelete(db, {branch, path})` singleton row; returns "marked for cleanup… removed when this session ends."

No `prune`/`existing`/`list` tools. State inspection is via SQLite directly (`getAllSessions`, `state.ts:331-340`).

### 5.2 Auto-cleanup (event, verbatim flow `worktree.ts:1227-1263`)

```ts
event: async ({ event }) => {
  if (event.type !== "session.idle") return
  const pendingDelete = getPendingDelete(database)
  if (pendingDelete) {
    const { path: worktreePath, branch } = pendingDelete
    // preDelete hooks
    // git add -A + git commit -m "chore(worktree): session snapshot" --allow-empty
    // git worktree remove --force
    // clearPendingDelete + removeSession(branch)
  }
}
```

Commit message is fixed: `chore(worktree): session snapshot` (`:1246`). Add/commit failures only warn, removal continues.

### 5.3 Session binding + launch argv

- SQLite: `~/.local/share/opencode/plugins/worktree/<projectId>.sqlite` (`state.ts:115-127`), WAL + `busy_timeout=5000`, tables `sessions(id, branch, path, created_at, launch_mode, profile, ocx_bin)` + `pending_operations(id=1 singleton, type, branch, path, session_id)` (`:158-188`). `setPendingDelete`/`setPendingSpawn` are last-write-wins with `logWarn` on replacement (`:437-469`).
- Launch context (`launch-context.ts:36-60, 98-119`): `OCX_CONTEXT=1` + `OCX_BIN` + `OCX_PROFILE` → `{mode:"ocx"}` else `{mode:"plain"}`; argv plain = `["opencode","--session",id]`; ocx = `[ocxBin,"opencode","-p",profile,"--session",id]`.
- Terminal priority (`terminal.ts:289-300`): `tmux` (if inside) > `cmux` (if `canUseCmuxWorkflow`) > platform (macOS Ghostty/iTerm2/Kitty/WezTerm/Alacritty/Warp/Terminal.app; Linux kitty/wezterm/alacritty/ghostty/foot/gnome/konsole/yakuake/xfce/xdg/xterm; Windows wt.exe→cmd; WSL wt.exe interop). cmux path = `cmux new-workspace --cwd <path> --command <argv>` (`:395-410`); tmux = mutex-protected `new-window -n <branch> -c <path>` + self-deleting trap script (`:334-389`).
- DB lifecycle: `initStateDb` per plugin init, retry ×3/100 ms (`:563-590`), `SIGTERM/SIGINT/beforeExit` WAL-checkpoint + close (`:538-554`).

### 5.4 Config (`schemas/worktree.json` + `worktree.ts:129-150, 910-948`)

```jsonc
{
  "$schema": "https://registry.kdco.dev/schemas/worktree.json",
  "sync": { "copyFiles": [], "symlinkDirs": [], "exclude": [] },
  "hooks": { "postCreate": [], "preDelete": [] }
  // + optional "worktreePath": "~/my-worktrees"
}
```

Precedence: project `.opencode/worktree.jsonc` wins unless it is an auto-generated default (marker `// Generated by OCX: default worktree configuration`) while a global config exists — then global wins; never merged (`:995-1042`, `docs/integrations/worktree.mdx:64-94`).

---

## 6. MCP wiring + DCP plugin role

### 6.1 MCP servers (researcher-gated)

Registry shorthand (`registry.jsonc:137-142`):

```jsonc
"mcp": {
  "context7": "https://mcp.context7.com/mcp",
  "exa": "https://mcp.exa.ai/mcp",
  "gh_grep": "https://mcp.grep.app"
},
```

Expands to `{type:"remote", url, enabled:true}` per `ocx/docs/reference/mcp.mdx:119-131`. Deny-by-default globally (`context7_*/exa_*/gh_grep_*/kagi_* = deny`, `:144-149`), allow only inside `agent.researcher.permission` (`:153-157`), with `webfetch: allow` as the sole webfetch exception in the bundle. Roles (`README.md:80-82`, `workspace.mdx:70`): **context7** = library docs lookup; **exa** = web search; **gh_grep** = GitHub code search. Researcher prompt reinforces: library resolver → topic query; `gh` CLI preferred over MCP for full implementations (`researcher.md:26-46`).

### 6.2 DCP plugin role

`@tarquinen/opencode-dcp@3.1.3` in `workspace` bundle `opencode.plugin` (`registry.jsonc:335`), comment: `// External npm plugin for diff/patch support`. It is **not** a registry-built component (no `files/`, no local source in any clone) — installed verbatim from npm by OCX at profile/bundle install. Pair: `@franlol/opencode-md-table-formatter@0.0.6` (markdown table formatting). DCP = "Differential Context Protocol" (per `README.md:65`). No further config in the bundle; permission surface untouched (no `dcp_*` deny/allow entries).

### 6.3 notify plugin (human-facing half of completion)

`notify.ts` (1026 lines): `session.idle → "Ready for review"`, `session.error → "Something went wrong"`, `permission.updated/asked → "Waiting for you"`, `question → "Question for you"`; parent-session-only by default (`isParentSession`, `:239-248`); focus suppression via `osascript` frontmost-app check (macOS) + quiet-hours window (`~/.config/opencode/kdco-notify.json`, `:114-148`); transport `cmux notify/set-status/clear-status` first (1500 ms timeout, trust-gated path resolution rejecting CWD/tmp, `notify/cmux.ts:75-123`), fallback alerter (macOS) / node-notifier (other) (`notify/backend.ts:107-134`); per-session animated busy spinners (80 ms Braille frames) over both OSC-title and cmux status (`notify.ts:274-460, 600-913`); 1500 ms dedupe windows per question/ready/permission key (`:269-401`).

### 6.4 Shared primitives (`kdco-primitives`, `index.ts:11-33`)

`get-project-id` (git root-commit SHA → 40-hex, path-hash 16-hex fallback, `.git/opencode` cache, worktree `commondir` resolution, 5 s `rev-list` timeout — `get-project-id.ts:59-172`); `Mutex`; `shell` (escapeBash/Batch/AppleScript + assertShellSafe); `temp` (getTempDir); `terminal-detect` (isInsideTmux); `cmux` (canUseCmuxWorkflow/detectCmuxContext); `types` (OpencodeClient); `with-timeout` (TimeoutError); `log-warn`.

---

## Appendix — agents / skills / command one-liners (source refs)

- `coder` (`src/agent/coder.md:8-16`): must load `code-philosophy`/`frontend-philosophy` BEFORE implementing; full read/write/edit/glob/grep/bash; NEVER commit/test-write/research-prose/delegate; returns Changes + Philosophy Compliance + Verification block.
- `researcher` (`src/agent/researcher.md:8-20`): external-only, text-output persisted by delegation system; full code + `owner/repo/path:Lx-Ly` or `[title](url)` citations; "Completed Staff Work" — no approval-seeking partials; NEVER write files.
- `scribe` (`src/agent/scribe.md:6-29`): docs/commit/PR/changelog prose; write allowed, bash denied; conventional commits; no AI attribution, no emojis.
- `reviewer` (`src/agent/reviewer.md:10-33`): loads `code-review` (+ philosophy per target; `plan-review` + `code-philosophy` for plans); 4 layers, severity 🔴🟠🟡🟢, ≥80% confidence, fixed output format with Philosophy Compliance table; read-only + git/rg.
- `/review` (`src/command/review.md:5-11`): delegates `$ARGUMENTS` scope to reviewer (default `git diff --cached`; `recent` = `git diff HEAD~1`).
- `philosophy` bundle tool (`ocx/.../files/tools/philosophy.md:1-16`): MANDATORY skill-load gate injected via `opencode.instructions`.
- Skills: `plan-protocol` (259-line format/state-machine/citation contract); `code-review` (methodology + severity); `code-philosophy` (5 Laws: Early Exit, Parse Don't Validate, Atomic Predictability, Fail Fast, Intentional Naming); `frontend-philosophy` (5 Pillars: Typography, Color, Motion, Composition, Atmosphere); `plan-review` (plan quality criteria).

Build/serve: `ocx/workers/kdco-registry/scripts/build.ts` → `buildRegistry({source:".", out:"dist"})` + schemas copy; profiles served via `ocx-kit` (`kit/ws` → `https://ocx-kit.kdco.dev`), registry at `https://registry.kdco.dev`.
