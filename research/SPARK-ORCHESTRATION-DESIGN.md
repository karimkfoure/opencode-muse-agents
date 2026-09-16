# Spark Orchestration on OpenCode — System Design from Muse Code Teardown

Goal: orchestrate one Muse Spark chat plus subagents in OpenCode with Muse Code quality (coordination, communication, isolation, policy, durability).

## 1. What OpenCode allows (extension surface)

Use a **bundle**, not a single file. The proven shape (kdco/workspace, oh-my-opencode) is 10–20 components installed as one profile:

- **Agents** (`.opencode/agents/*.md` + `opencode.json:agent`): `mode: primary|subagent|all`, `description` (dispatch key), `model`, `temperature`, `steps`, `permission.*` (allow|ask|deny, glob patterns per tool, `bash` per-command), `permission.task` (which subagents this agent may call; last match wins; `deny` removes from Task description), `hidden`, `color`. Built-ins: `build|plan` (primary), `general|explore|scout` (subagent). m8 already has `lab-coordinator|research|implement|review.md`. Keep that split: coordinator never writes, workers never integrate.
- **Task tool = delegation primitive.** Primary calls `task(subagent_type|category, prompt, run_in_background)`. oh-my-opencode adds `background_output(task_id)` / `background_cancel`, tmux panes via `opencode attach <url> --session <id>`, per-provider `background_task.defaultConcurrency`. `scripts/opencode-lab` already enables `OPENCODE_EXPERIMENTAL_BACKGROUND_SUBAGENTS=true`. This is the Level-A fan-out carrier.
- **Session tree (server/SDK):** `POST /session` (`{parentID?, title?}`), `GET /session/:id/children`, `POST /session/:id/message` (sync) vs `/prompt_async` (204, no wait), `POST /session/:id/abort`, `POST /session/:id/fork {messageID?}`, `GET /session/:id/diff`, `POST /revert|unrevert|summarize`, `GET /session/status`, `GET /event` (SSE, first `server.connected`). SDK: `client.session.create|prompt|promptAsync|children|abort|fork`, `client.event.subscribe()`. m8 `lab-notify.ts` already walks `parentID` to the coordinator and injects synthetic completion prompts; `lab-autonomy.ts` already gates auto-continuation on idle + claim/generation + `experimental.session.compacting` context. Reuse both as the notification + continuation layer.
- **Plugins** (`.opencode/plugins/*.ts`, `(ctx:{project,client,$,directory,worktree}) => Hooks`): events `session.created|idle|status|error|updated|compacted|deleted|diff`, `tool.execute.before|after`, `permission.asked|replied`, `question.asked|rejected`, `file.edited|watcher.updated`, `tui.*`, `shell.env`, `experimental.session.compacting`. Custom tools via `tool({description, args: zod, execute(args,ctx)})`; filename = tool name; plugin tool shadows built-in on collision. m8 `lib/lab.ts` shows the bounded pattern (32 KB cap, `compactResult`, `execFile python3 tools/lab.py`, `context.ask` before run).
- **Custom tools** (`.opencode/tools/*.ts` → any language via `Bun.$`): context `{agent, sessionID, messageID, directory, worktree}`. This is where Muse-grade tools live: `spark_send` (mailbox), `spark_fork` (variant), `spark_worktree` (isolation), `spark_result` (bounded envelope). m8 `tools/lab_{submit,status,result,cancel,compare,accept}.ts` are the template.
- **Server mode:** `opencode serve --port --hostname` + OpenAPI at `/doc`. One TUI = one server; IDE/tmux attach to the same port. Required for visual multi-agent (oh-my-opencode tmux panes) and for external Spark drivers.

## 2. Reference projects to copy (not to admire)

- **oh-my-opencode / Oh My OpenAgent** (11 agents): `Prometheus (plan) → Momus (review) → /start-work → Atlas (conduct) → Sisyphus-Junior (execute, no re-delegation)`. Category routing (`visual-engineering|ultrabrain|deep|quick|writing`) picks model+prompt; `task(category)` vs `task(subagent_type)` are mutually exclusive. Copy: plan-then-conduct split, Junior cannot delegate (stops loops), per-category model routing for Spark (reasoning vs cheap workers), `background_output` retrieval pattern.
- **kdcokenny/opencode-workspace** (16 components, 583 stars): `plan|build` orchestrators (read-only, delegate via task) + `explore|researcher|coder|scribe|reviewer` specialists with permission boundaries (`webfetch: deny` globally, researcher = MCP-only, coder = full, scribe = write-no-bash). Plus `workspace-plugin` (plan mgmt), `background-agents`, `worktree`, `notify`, DCP. Copy: the permission matrix file-for-file for Spark roles.
- **kdcokenny/opencode-background-agents + opencode-worktree + opencode-pty**: async delegation + context persistence, zero-friction worktrees, PTY for long runs. Copy: worktree-per-agent + PTY for `tools/lab.py` long jobs.
- **@openspoon/subtask2**: turns `/commands` into orchestration with flow control. Copy if coordinator needs conditionals beyond linear plan.
- **opencode-conductor / micode / opencode-goal-plugin**: `Context→Spec→Plan→Implement` lifecycle, session continuity, `/goal` auto-continue. m8 `lab-autonomy` already does goal-continue; align vocab (`goal` string, `generation` claim) so the two do not fight.
- **Support libs**: `opencode-skillful` (lazy skill injection), `opencode-supermemory` (cross-session memory), `opencode-dynamic-context-pruning` (token trim), `opencode-scheduler` (cron), `opencode-sentry-monitor` (trace agents).

## 3. What the teardown contributes (reuse map)

From `TEARDOWN.md` + `artifacts/schema/stable/msp.schema.json` + `muse-sdk-multiagent-report.md`:

| Muse Code mechanism | OpenCode reimplementation |
|---|---|
| Level-A fan-out: N `session/start` + `turn/start`, `Promise.all` over `TurnHandle.completed` | Coordinator `task(..., run_in_background=true)` per Spark worker, or `POST /session {parentID}` + `prompt_async` per worker; fold each stream independently; `background_output(task_id)` = `subagent/readResult` analog |
| Level-B children: model-spawned, owner steers via 8 `subagent/*` (admission-only ack, facts on parent item stream) | Same rule: workers spawn helpers via `task`; coordinator only steers via mailbox/steer, never edits worker state directly; results read from folded child session, not from ack |
| `SubagentResult {summary<=512, text<=32KiB, artifactRefs[], evidenceRefs[]}` | Enforce in `spark_result` tool + `lib/lab.ts:bounded` (already 32 KB): summary + evidence paths mandatory, raw logs stay in `.lab/runs/<id>/` |
| `session/fork {cutPoint:{lastTurnId}}` + `ForkProvenance` (opaque `cutCursor`, never parse) | `POST /session/:id/fork {messageID?}` for speculate-and-compare; record `(source, messageID, newID)` in provenance, never parse cursor |
| `turn/start {ifBusy: queue|steer|replace}` + `disposition: started|queued|steered` + `turn/unqueued` terminal trap | Coordinator default `queue`; `steer` only to inject constraint into running worker; `replace` forbidden (silent mutation); waiter must handle `unqueued` as terminal (same bug class as `lab-notify` 250 ms batch + 1 s fallback covers) |
| `commandId` UUIDv7 idempotency, `viewCursor` opaque anchor | Mint UUIDv7 per `lab_submit`/prompt; persist `(commandId→ack+cursor)`; retry joins, never duplicates; cursors opaque |
| `session/start.approvalMode` fixed at spawn, `session/setApprovalMode` next-action only; `EffectiveApprovalModeState` folded | `permission.*` fixed in agent defs at `session.create`; mid-run change = new session or explicit `permission.replied` flow; never expect per-turn override |
| `--subagent-worktree-isolation` (capability on, per-child affirmative) + `managed_worktree` lease | `opencode-worktree` per Spark worker (`create`, base `HEAD`), one integration owner (m8 AGENTS.md §9–10); prune on completion; record lease loss like Muse (`cleanup lost its active lease`) |
| `session-message send --target` local mailbox (`tbh.local.session_mailbox`) | `spark_send` tool: append-only mailbox file per session under `.lab/mailbox/<sessionID>.jsonl` + `session.prompt({noReply:true})` ping; `spark_send --in-reply-to` mirrors `--in-reply-to <reply-token>` |
| `task/background|stop|stopAll`, `goal/*`, `skill/list`, presets `native-basic|miniswe` toolsets | `prompt_async` + `abort` + `lab_cancel`; goal string in autonomy state; skills lazy-loaded (`skillful` pattern); preset = agent `permission` matrix, not a flag |
| Exit/error taxonomy (`sessionInUse`, `forkBoundaryInvalid`, `backpressured|overloaded` retryable, `viewTruncated|boundaryPruned` → re-page) | Map to lab states (`completed|passed|failed|timed_out|cancelled|error` in `lab-notify.ts:7`): lease contention → back off; retryable → requeue; gap → `session.messages` re-page from cursor |

## 4. Proposed Spark bundle (concrete files)

```
.opencode/agents/spark-coordinator.md  # primary, read-only, delegates via task; owns plan + integration
.opencode/agents/spark-worker.md       # subagent, hidden, per-task worktree, cannot delegate (Junior rule)
.opencode/agents/spark-reviewer.md     # subagent, read-only + git (reviewer matrix)
.opencode/tools/spark_send.ts          # mailbox append + noReply ping (body trimmed, non-empty, byte-intact)
.opencode/tools/spark_fork.ts          # POST /session/:id/fork wrapper with provenance record
.opencode/tools/spark_result.ts        # bounded envelope {summary<=512w, evidenceRefs[], artifactRefs[]}
.opencode/tools/spark_worktree.ts      # create|existing|prune worktree, base HEAD
.opencode/plugins/spark-notify.ts      # extend lab-notify: background task completion → coordinator synthetic prompt
.opencode/plugins/spark-policy.ts      # tool.execute.before: enforce worker matrices, .env-style guards
.opencode/plugins/spark-compact.ts     # experimental.session.compacting: inject goal + pending run IDs + next step
opencode.json:agent.spark-*            # models per category (reasoning vs cheap), permission.task gating
```

Coordinator loop (Atlas pattern): plan (`Prometheus` interview) → `/start-work` → fan out `task(spark-worker, run_in_background)` per unit with `{question, inputs, worktree, budget, expected evidence}` → `background_output`/notify → verify (`spark-reviewer`, `lab_compare`, checks) → integrate in one owner session → `lab_accept`.

## 5. Ghidra slices — STATUS: DONE (assimilated into the new repo)

All 7 ranked slices were completed at function level; results live in
`re-tracks/07–20` + ~35 annotated functions in `ghidra/muse.gpr`.
Corrections vs the ranking as written: worktree isolation is a tri-state
MODE (not a flag); commit sizing is adaptive; fence breach traps;
registry/prover/validator are one engine. The per-slice rule list below
is superseded by `opencode-muse-agents/docs/OVERVIEW.md`.

Do not load the 304 MB binary blind. Targeted slices, highest value first:

1. **Subagent steering intake** (`failed to append subagent steering intake record`, `hydrate retained subagent state`): exact validation of `body` (trim, empty-reject, multibyte-intact) + `subagentId` durability across resume/reopen. Copies verbatim into `spark_send` validation.
2. **Result envelope enforcement** (`SubagentResult`, `<=512 chars`, `<=32 KiB`): where truncation happens (admission vs fold) and what `errorKind` vocab is. Copies into `spark_result`.
3. **Worktree placement + cleanup lease** (`subagent worktree placement failed`, `cleanup lost its active lease`, `managed_worktree`, `SessionWorktreeCleanupPolicy`): who owns the worktree on crash, when prune runs. Copies into `spark_worktree` + lab runner policy.
4. **Fork materialization** (`session.fork.materialization|compaction|model_prefix`, `ConversationRewindForkKindV1`): copy-vs-rederive cost, compaction interaction. Decides when `spark_fork` is cheap enough for speculative branches.
5. **Approval gate** (`EffectiveApprovalModeState`, `approval-judge on`, `escalated execution requires an unrestricted permission profile`): enforcement point (tool call vs admission) and judge inputs. Copies into `spark-policy` hook.
6. **Mailbox delivery** (`tbh.local.session_mailbox`, `reply_context_unavailable`, `--display-context` validation): ordering + durability of `session-message`. Copies into mailbox file format.
7. **Workflow v2 journal** (`workflow.v2.journal.record`, `workflow-script-engine-v8`, `v8_dependency_disabled`): only if coordinator needs more than linear plan (else defer to `subtask2`).

Each slice: seed Ghidra with the `strings` anchor → xref → decompile 1–3 functions → extract struct/validation → port rule to the corresponding `spark_*` file. Stop after the rule ports; no full-binary analysis.
