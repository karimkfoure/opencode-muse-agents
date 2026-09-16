# Muse Code Multi-Agent Teardown — 1.3.0-R3057.1

Target: document how Muse Code implements multi-agent natively, for reuse with Muse Spark in OpenCode and other harnesses.
No account used. No authenticated run. All evidence from static binaries, installer scripts, embedded MSP schema, SDK source, and public docs.

## 0. Artifacts collected

All under `research/artifacts/`:

- `bin/install.sh` (9.1 KB) — from `https://dev.meta.ai/install.sh`
- `bin/muse-launcher.sh` (33,118 B, sha256 `21c66e55…`, launcher v2) — identical to `https://api.meta.ai/muse-launcher.sh`
- `bin/muse-bin-1.3.0-R3057.1` (304,744,664 B, ELF x86-64 static, stripped, BuildID `3b091b0932ff0dbd9bd7d243bd14d0e7c27042c1`, sha256 `5187dfc9…`)
- `bin/manifest-1.3.0-R3057.1.json` — channel `muse-stable`, urgency `none`
- `bin/all-platforms/` — all 7 release artifacts for this version, checksum-verified:
  - `x86_macos-1.3.0-R3057.1.bin` 306,213,072 B `8b34d5d2…`
  - `aarch64_macos-1.3.0-R3057.1.bin` 281,354,448 B `677d71f8…`
  - `x86_linux-1.3.0-R3057.1.bin` 304,744,664 B `5187dfc9…`
  - `aarch64_linux-1.3.0-R3057.1.bin` 273,815,632 B `e2557a9e…`
  - `universal_macos_pkg-1.3.0-R3057.1.pkg` 217,163,112 B `9df3bda3…`
  - `x86_windows-1.3.0-R3057.1.exe` 351,667,960 B `cfbc38a5…`
  - `aarch64_windows-1.3.0-R3057.1.exe` 320,467,192 B `75620b1d…`
- `schema/stable/msp.schema.json` (238 KB, 232 `$defs`, 47 methods, 30 notifications, 31 errors, fingerprint `sha256:ab69549a…`)
- `schema/experimental/msp.schema.json` (247 KB, 240 `$defs`, 51 methods, 32 notifications, same 31 errors, fingerprint `sha256:3ebfa825…`)
- `sdk-tarball/muse-code-sdk-0.1.1.tgz` (134.6 KB packed, 38 files) — `https://registry.npmjs.org/@muse-code/sdk/-/sdk-0.1.1.tgz`
- `muse-sdk-multiagent-report.md` (961 lines) — full SDK source teardown (clone `meta-models/muse-code-sdk@fbce769`)
- SDK clone retained at `/tmp/opencode/muse-teardown/muse-code-sdk` for grep; tarball copy in artifacts is the durable record.

Regenerate schema offline any time (no network, no auth):

```sh
MUSE_NO_AUTO_UPDATE=1 muse schema generate-json-schema --out /tmp/schema-stable
MUSE_NO_AUTO_UPDATE=1 muse schema generate-json-schema --out /tmp/schema-exp --experimental
```

## 1. Distribution chain

```
curl -fsSL https://dev.meta.ai/install.sh | bash
  -> downloads https://api.meta.ai/muse-launcher.sh to ~/.local/bin/muse (chmod 0755)
  -> MUSE_LAUNCHER_INSTALL=1 muse
    -> GET https://api.meta.ai/muse-code/channels/muse-stable (channel.json)
    -> GET <manifest_url> retargeted to https://lookaside.facebook.com/... (release.json)
    -> GET artifacts.<platform>.url, verify size + sha256, chmod 0755, mv to muse-bin-<version>
    -> write .muse-version, .muse-release-info.json, .muse-update-notice (from\tto)
```

Key launcher facts (`muse-launcher.sh`, 1138 lines, `bash -euo pipefail`):

- Channel defaults: `channel=muse-stable`, `MUSE_CHANNEL_URL`, `MUSE_DOWNLOAD_HOST=lookaside.facebook.com`, `MUSE_AUTH_URL=https://auth.meta.com`, `MUSE_CLIENT_ID=1031625952748946`, `User-Agent: muse-code/launcher-2`.
- Version gate: `^[0-9]+\.[0-9]+\.[0-9]+-R[0-9]+(\.[0-9]+)?$`.
- Credential store is read-only: `MUSE_AUTH_PATH` or `$XDG_CONFIG_HOME/muse/auth.json` or `~/.config/muse/auth.json`, expects `providers.meta.{mechanism==oauth, access_token}`. Device-login token stays in memory, never written by launcher.
- Hourly self-update: `MUSE_UPDATE_INTERVAL_SECONDS=3600` via `.muse-update-checked-at`; background `{update_launcher; update_binary} &` unless `MUSE_SYNC_UPDATE=1` (foreground). Pin with `MUSE_NO_AUTO_UPDATE=1`. Override channel/host/launcher with `MUSE_CHANNEL_URL`, `MUSE_DOWNLOAD_HOST` (empty disables retarget), `MUSE_LAUNCHER_URL`. `MUSE_LOGIN=0` disables interactive device login; non-tty disables unless `MUSE_LOGIN=1`.
- Handoff: `exec muse-bin-$(cat .muse-version) "$@"`, exports `MUSE_RELEASE_INFO` when version matches. Update notice only on tty, claimed atomically via rename.
- Installer hard-checks only `curl` + `mktemp`. Binary is statically linked. No Node/Python/Homebrew. `git` required at runtime only for worktree features. Native Windows unsupported (WSL2 only); Windows exes ship but installer rejects non-Darwin/Linux.

## 2. Runtime model (MSP)

MSP = Muse Session Protocol. JSON-RPC 2.0 over stdio. Client spawns `muse serve`, completes `initialize`, then issues commands. One host = one stdio connection (v1 refuses a second). One loaded session = one writer lease on disk (OS releases on death). Two hosts contending for one session → typed `sessionInUse (-32021)`, not a generic failure.

Three ideas carry the protocol (docs `guides/msp-concepts/`):

1. **The log is the session.** All client state = fold of durable event log since `viewCursor`. Never parse `ForkProvenance.cutCursor` — display-only.
2. **An ack is not an outcome.** Every command returns `CommandAcceptedResult {commandId, status: "accepted"}` (only `session/compact` may answer `"noop"`). Facts arrive as view events (`turn/started`, `item/started|delta|completed`, `turn/completed`, `approval/requested|resolved`, etc.).
3. **Requests carry no authority.** Server `approval/request` + `userInput/request` are presentations; decision travels as idempotent `approval/decide` / `userInput/answer` commands.

IDs: `sessionId` UUIDv7 (wire identity = stream id = on-disk dir name). `commandId` client-minted UUIDv7, required on every command, echoed in ack; value-identical replay returns same result (e.g. `session/start` replays same `session` + `viewCursor`; `session_id_conflict` → `commandRejected`). `turnId`, `subagentId` (opaque durable child id from the parent's subagent item), `viewCursor` (opaque per-session position; anchors `view/page|subscribe`, `session/resume.cursor`).

Turn lifecycle: `turn/start {sessionId, input: TurnInputPart[], ifBusy?: queue|steer|replace (default queue)}` → ack `{status: accepted, disposition: started|queued|steered (open set), startedNewTurn: bool, turnId}` → `turn/started` (never for steered joins) → `item/*` stream → `turn/completed {terminal: completed|cancelled|failed (open set)}`. Queued turn reclaimed before launch ends as `turn/unqueued` with no `turn/completed` — a waiter folding only `completed` hangs. Two stop lanes fold the same `cancelled` terminal: `turn/interrupt` (user gesture, priority lane, optional retract) vs `turn/cancel` (programmatic). Neither kills background tasks (`task/stop`, `task/stopAll` are separate).

## 3. Multi-agent: two levels (this is the core)

### Level A — Coordinator fan-out (what Spark in OpenCode wants)

There is **no `subagent/spawn` wire method**. True parallelism = N independent sessions on one host (or N hosts), driven concurrently by the coordinator client.

SDK facade path (`clients/sdk-ts/src/`, exact locations in `muse-sdk-multiagent-report.md`):

```
spawnMspConnection({command: museBin, args: ["serve"], cwd, env})  // spawn.ts:643
  -> MspHandshake.initialize({clientInfo})                        // handshake
  -> MuseClient.spawn(...)                                        // facade/client.ts:219
    -> N x startSession({workspaceRoot, approvalMode, ...})       // :278, SessionStartParams msp.d.ts:1130
    -> N x sendUserTurn(sessionId, input)                         // facade/session.ts:721, turn-submit.ts:223
    -> Promise.all over TurnHandle.completed                      // facade/turn-handle.ts:252
```

`subagent/*` appears zero times in `clients/*/src` (negative evidence logged). The facade holds `Connection` private; child steering needs raw `connection.command("subagent/...")`.

Why this matters for Spark: each Spark agent = one `session/start` + `turn/start` with its own `commandId` (UUIDv7 mint via `createUuidV7Mint`), its own `viewCursor` subscription, its own approval router. Sessions are isolated by design (separate logs, separate leases). Concurrency limit is yours (m8 `tools/lab.py` uses 4 workers; MSP has no worker cap — backpressure surfaces as `overloaded (-32001, retryable)` / `backpressured (-32031, retryable)`).

### Level B — In-session subagents (model-spawned children, owner-steered)

Children are spawned by the **model** via tools (`subagent_spawn`, `subagent_send_message`, `subagent_wait`, `subagent_read_result`, `subagent_status`, `subagent_cancel` in `native-basic`/`miniswe` preset blobs; `workflow.agent.native`, `workflow-subagent` strings). The wire client never creates them — it only steers already-existing children through 8 owner commands, all admission-only acks:

| Method | Params | Meaning |
|---|---|---|
| `subagent/sendMessage` | `SubagentInputParams {sessionId, subagentId, body, commandId}` | Queue user note into running child |
| `subagent/followupTask` | `SubagentInputParams` | Queue follow-up task for child |
| `subagent/interrupt` | `SubagentOwnerReasonParams {sessionId, subagentId, reason?, commandId}` | Ask child to yield at next boundary |
| `subagent/stop` | `SubagentOwnerReasonParams` | Stop running child |
| `subagent/close` | `SubagentOwnerReasonParams` | Owner-close child (terminal folding SS4.5.7/SS3.16) |
| `subagent/resume` | `SubagentTargetParams {sessionId, subagentId, commandId}` | Resume paused/recoverable child |
| `subagent/reopen` | `SubagentTargetParams` | Reopen stopped/closed child as durable later attempt |
| `subagent/readResult` | `SubagentTargetParams` | Consume ready result (state-changing; content already in subagent item's `result` field) |

Result envelope (`SubagentResult`): `{summary (<=512 chars, runtime-enforced), text (<=32 KiB), artifactRefs[], evidenceRefs[], structuredData?, errorKind?}`. Outcomes fold to the **parent's** subagent item (`item/updated|completed`), not as command results.

Related but distinct surfaces in the binary schema (absent from the public docs site, present in `muse schema` export):

- `session/fork {sessionId, cutPoint?: {lastTurnId}, excludeItems?, commandId}` → new session id copying log through cut point, `forkedFrom: ForkProvenance {sessionId, commandId, cutCursor (opaque, MUST NOT parse), cutExplicit}`. History branching, not worker spawn. Use for variant exploration / rewind-then-retry.
- `workflow/childControl`, `workflow/cancel`, `WorkflowChild {childId, attempt, status, phase?, label?, durationMs?, resultRef?, terminal?, usage?}` — Workflow API v2 (`workflow.v2.journal.record`, `workflow-script-engine-v8`, `tbh-script-v8`, `v8_dependency_disabled|live_network_disabled`). Higher-level run orchestrator above subagents.
- `task/background`, `task/stop`, `task/stopAll` — background tasks a turn leaves behind (survive `turn/interrupt|cancel`).
- `goal/set|edit|pause|resume|clear`, `session/goalChanged` — goal tracking folded into snapshot.
- `skill/list`, `skill/changed` — skill catalog.
- `session/message` does **not** exist on the wire. Cross-session notes are `muse session-message send --target <uuid-or-name>` (local mailbox CLI, `MUSE_EXPERIMENTAL_LOCAL_SESSION_MESSAGING`, `tbh.local.session_mailbox`), or `send_session_message` / `list_peer_sessions` tools inside presets. Do not confuse with `turn/start` (the user-message path) or `session/userShell` (the `!`-escape capability-gated shell).

## 4. Isolation, policy, determinism knobs

- **Worktree isolation:** `-w/--worktree [off|create|existing]`, `--worktree-base HEAD`, `--worktree-existing PATH` on root + `exec`. `SessionWorktreeMode off|create`, `SessionWorktreeCleanupPolicy`, `managed_worktree`, `subagent worktree placement failed`, `subagent worktree cleanup lost its active lease`. `--subagent-worktree-isolation` is a compatibility flag — capability defaults on; only an affirmative per-child request asks for isolation; rejects when capability/provider/Git prerequisites missing. For Spark: one worktree per parallel session (m8 already mandates separate worktrees for overlapping changes).
- **Approval inheritance:** `session/start.approvalMode` (optional/null = server default) is the only policy declaration for a non-interactive run. Mid-run switch via `session/setApprovalMode` (next-action only). Folded as `EffectiveApprovalModeState {mode, source: startup|replay|approvalReconfigure, lastCommandId}` on `Session` + `SnapshotState`, broadcast as `session/approvalModeChanged`. Forks inherit by log-copy. `--approval-mode untrusted|on-request|never`, `--permission-profile ID` (once-only), `--approval-judge off|on`. `--yolo` disables approval + sandbox.
- **Model routing:** `--provider echo|meta`, `--model ID`, `--reasoning-effort none|minimal|low|medium|high|xhigh|max|ultra (default high)`, `session/setModel`, `session/setReasoningEffort`, `session/modelChanged`, `--parallel-tool-calls/--no-parallel-tool-calls` (Meta API parallel calls, distinct from multi-session parallelism), `--preset native-basic|miniswe`, `--agents <JSON>` ephemeral agent-definition overlay (root flag, not subcommand).
- **Sandbox (host-lifetime, fixed at `serve`, not negotiable on wire):** `--disable-sandbox`, `--sandbox-network restricted|enabled|proxy-only (default proxy-only)`, `--disable-write`, `--disable-shell`, `--trust-workspace`, `--enable-shell-tool` (legacy shell). Linux `bwrap`, `FileSystemSandboxPolicy`, `NetworkSandboxPolicy`.
- **Durability:** `sessionDurability` in `initializeResult`; `--no-session-log` (memory-only, path = `""` — never hand to filesystem); `session/list|read|resume`, `session/compact`, `view/page|subscribe|unsubscribe`, `muse export` (`export_schema_version 1`, includes fork/subagent lineage, `--redacted` for share-safe).
- **Stability gating:** stable fingerprint `ab69549a…` vs experimental `3ebfa825…`. Diff = only `account/*` (loginStart/loginCancel/logout/read + `account/changed|loginCompleted`); zero delta for subagent/workflow/session/turn. SDK warns, never errors, on fingerprint mismatch.

## 5. Reuse recipe for Spark in OpenCode / other harnesses

Map directly to m8 (`tools/lab.py` detached supervisor + 4 workers; `.opencode/agents/lab-coordinator|research|implement|review.md`; `scripts/opencode-lab` background agents):

1. **One Spark worker = one MSP session.** `session/start` per task with `{workspaceRoot: <per-agent worktree>, approvalMode, commandId: uuidv7()}`. Never share a session between concurrent agents (single `activeTurnId`, single lease).
2. **Fan out with `Promise.all` over `turn/start`, fold per-session streams independently.** Ack `disposition` (`started|queued|steered`) + `startedNewTurn` tells what happened without folding. Accumulate `item/delta`, treat `item/completed` text as authoritative, terminate on `turn/completed` terminal (`completed|cancelled|failed`, open set — treat unknown as terminal). Handle `turn/unqueued` as terminal for reclaimed queued turns.
3. **Do not use `subagent/*` for coordinator fan-out.** Those 8 methods steer only model-spawned children inside one session. If the model spawns children, steer them with `sendMessage`/`followupTask` (same `SubagentInputParams.body`, trimmed, non-empty) and `interrupt`/`stop`/`close` (with `reason`), `resume`/`reopen`/`readResult` for lifecycle. Read results from the parent's folded subagent item, not from the ack.
4. **Variants = `session/fork`.** Copy through `cutPoint {lastTurnId}` (default: all completed turns), get new id + `ForkProvenance`. Use for speculate-and-compare (m8 `lab_compare` analog) without disturbing the source.
5. **Cross-agent notes = mailbox, not wire.** No `session/message` method exists. Use `muse session-message send --target <uuid-or-name>` out-of-band, or coordinator-relayed `turn/steer` with `IfBusy: steer`. Keep evidence paths per agent (m8 rule: raw logs in run dirs, findings with paths).
6. **Idempotency everywhere.** Mint UUIDv7 per command, persist `(commandId → ack + viewCursor)`, retry joins original instead of duplicating. Classify exits (`guides/msp-concepts/exit-classification/`; code 5 = experimental tier off) and errors (`-32021 sessionInUse` = lease contention → back off; `-32023 forkBoundaryInvalid` = bad cut; `-32031/-32001` = retryable backpressure; `-32040/-32042` = page/gap → `view/page` from `earliestCursor`/`latestBoundaryCursor`).
7. **Policy at spawn, worktree per agent.** Fix `approvalMode` + `permissionProfile` + sandbox posture at `serve`/`session/start`; never expect per-turn policy override. Give each Spark agent its own Git worktree (`--worktree create`, `--worktree-base HEAD`) with one integration owner (m8 AGENTS.md §9-10).
8. **Pin and verify.** Record `muse --version` (here `1.3.0-R3057.1`), channel manifest, artifact sha256, and schema fingerprint (`ab69549a…` stable) in run provenance. Set `MUSE_NO_AUTO_UPDATE=1` + `MUSE_SYNC_UPDATE` explicitly in harnesses; hourly auto-update otherwise moves the binary under you.

## 6. Reverse-engineering entry points

- `strings -n 8 muse-bin-* | grep -i -E "subagent|fork|worktree|workflow|parallel-tool|approval-mode|permission-profile|native-basic|miniswe"` → 2377 unique lines (x86_linux). Start with `subagent worktree placement failed`, `hydrate retained subagent state`, `failed to append subagent steering intake record`, `native subagent child session attestation is invalid`, `Workflow API v2`, `workflow.v2.journal.record`, `managed_worktree`, `SessionWorktreeMode`, `ForkProvenance fork_session_id|source_session_id|source_cut_cursor`, `MUSE_EXPERIMENTAL_LOCAL_SESSION_MESSAGING`.
- Preset blobs: `native-basic` = `read_file search write_file edit_file … subagent_spawn subagent_status subagent_send_message subagent_wait subagent_read_result …`; `miniswe` adds `bash_input … muse.code_exec` + `subagent_cancel`.
- Ghidra: ELF static stripped; import via `muse schema` + `strings` anchors first (function names lost). Prioritize `session/fork` materialization (`session.fork.materialization|compaction|model_prefix`), subagent steering intake, worktree placement/cleanup lease, `bundle_surface_parity.rs` (`register_names` owned deferral register — authoritative method list = exported table + register).
- Wire conformance: `schema/msp/` transcripts (~48 scenarios, NDJSON with direction marks) replayable against any client; `muse export` gives `ses_/trajectory_` ids + fork/subagent lineage for offline diff.

## 7. What the quickstart docs do not tell you

`meta-models.github.io/muse-code-sdk/guides/quickstart/` covers single-session happy path (spawn → handshake → `session/start` → `turn/start` → `approval/decide` → `turn/cancel` → `close` → `session/resume`). It omits all of §3–§5: no `subagent/*`, no `session/fork`, no `workflow/childControl`, no `task/background`, no `session-message` mailbox, no worktree isolation, no `--agents` overlay, no `IfBusy`/`disposition` queue-steer-replace semantics, no `turn/unqueued` terminal trap. Use the quickstart for connection setup only; use this teardown + the embedded `muse schema` export + `muse-sdk-multiagent-report.md` for coordination design.
