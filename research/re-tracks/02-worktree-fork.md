# 02 — Worktree isolation + cleanup lease + fork materialization cost (Muse Code 1.3.0-R3057.1)

Static-only. No Ghidra load, no auth, no network beyond public. Binary:
`/tmp/opencode/muse-teardown/bin/muse-bin-1.3.0-R3057.1` ≡
`research/artifacts/bin/all-platforms/x86_linux-1.3.0-R3057.1.bin`
(304744664 bytes, ELF x86-64 static, stripped).
Schema: `research/artifacts/schema/stable/msp.schema.json`
(232 `$defs`) and `.../experimental/msp.schema.json` (240 `$defs`).
SDK clone: `/tmp/opencode/muse-teardown/muse-code-sdk` (`meta-models/muse-code-sdk@fbce769`);
durable copy `artifacts/sdk-tarball/muse-code-sdk-0.1.1.tgz`.

Target consumers: OpenCode `spark_worktree` / `spark_fork` tools.

## 1. strings sweep (150+ lines)

Method (verbatim):

```bash
BIN=/tmp/opencode/muse-teardown/bin/muse-bin-1.3.0-R3057.1
strings -n 6 "$BIN" | grep -c -i -E "worktree|fork|cutCursor|cut_cursor|ForkProvenance|BranchState|SnapshotState|SessionWorktree|managed_worktree|CleanupPolicy|cleanup.*lease|reconcile|retained worktree|Sapling|ConversationRewind|subagent worktree|session worktree|materialization|compaction|model_prefix|forkBoundary"
# => 1311 (broad pattern count)
strings -n 6 "$BIN" | grep -c -E "worktree|Worktree"   # => 516
strings -n 6 "$BIN" | grep -c -E "fork|Fork"           # => 396
```

Exact-needle pass (`strings -n 8 | grep -E "<needle>" | sort -u`) for every
needle named in the task hits all of them (each count ≥ 1 unless noted):

| needle | hit (verbatim, `grep -o` window) |
|---|---|
| `managed_worktree` | `managed_worktree` (singleton `$@selection_bordermanaged_worktree`); extended: `managed_worktree_source_posturecarve_outs`, `owned_worktree_gitdir`, `writable_git_roots`, `FileSystemSandboxPolicy entries … managed_worktree_source_posture carve_outs … owned_worktree_gitdir writable_git_roots` |
| `SessionWorktreeMode` | `SessionWorktreeModeoffcreate`, `SessionWorktreeModeoffSessionWorktreeCleanupPolicySessionWorktreeRecordCleanupOutcomecleanup_outcomeSetupFailedsetup_failedWorkspaceScopeActivated…`; Rust ADT: `enum SessionWorktreeMode`, `struct SessionWorktreePrepare`, `struct SessionWorktreeOperation`, `struct SessionWorktreeOperationIntent`, `enum SessionWorktreeOperation` |
| `SessionWorktreeCleanupPolicy` | `SessionWorktreeCleanupPolicyremove_if_clean` (only value observed); `enum SessionWorktreeCleanupPolicy`; triple always adjacent: `SessionWorktreeMode off create SessionWorktreeCleanupPolicy remove_if_clean cleanup_outcome setup_failed workspace_scope_activated` |
| `subagent worktree placement failed` | `subagent worktree placement failed: ` (format-string prefix) |
| `subagent worktree cleanup lost` | `subagent worktree cleanup lost its active lease` (×5+ sites, always followed by `workflow.run.native…` blob); siblings: `could not start subagent worktree cleanup thread: `, `subagent worktree cleanup thread stopped`, `tbh-subagent-worktree-cleanup`, `awaited cleanup lost its logical-owner resource`, `awaited automatic cleanup lost its logical-owner resource`, `automatic subagent worktree cleanup requires a session log`, `accepted cleanup has no logical-owner worktree resource`, `accepted Stop/Close cleanup lacks an exact durable state chain`, `subagent worktree cleanup requires a session log`, `subagent worktree cleanup selection requires a session log`, `quarantined subagent worktree lease refuses workspace binding`, `<warning: quarantined subagent worktree lease: owner session `, `; subagent worktree retained at `, `subagent worktree lease validation failed: `, `subagent worktree record append failed: `, `subagent worktree filesystem operation failed during `, `subagent worktree Git operation failed during `, `subagent worktree path collides with an existing path: `, `subagent worktree runtime is not implemented: `, `subagent worktree setup failed`, `native subagent worktree setup failed: `, `native subagent worktree requires an explicit source repository`, `subagent worktree resume requires a session log`, `Resume/Reopen has no logical-owner worktree resource`, `awaited Resume/Reopen lost its logical-owner resource` |
| `subagent worktree requires a session log` | `subagent worktree requires a session log` (×4+, always adjacent to `durable shared placement conflicts with a live worktree resource` + `accepted Stop/Close has no full-owner worktree resource`) |
| `session worktree requires a Git source` | `session worktree requires a Git source repository: ` (format-string prefix) |
| `Sapling worktree` | `cannot reconcile interrupted Sapling worktree create: `, `expected exactly one Sapling worktree registry, found `, `Sapling session worktree setup is unsupported in this environment`, `create Sapling worktree`, `restore Sapling worktree base`, `verify Sapling worktree node`, `created Sapling worktree escaped its generated destination`, `canonicalize created Sapling worktree failed: `, `canonicalize Sapling worktree storage failed: `, `create Sapling worktree storage failed: `, `lstat recorded Sapling worktree failed: `, `lstat Sapling worktree destination failed: `, `validate Sapling worktree registry failed: `, `read Sapling worktree registry failed: `, `invalid Sapling worktree registry: `, `invalid Sapling checkout metadata: `, `cannot recreate Sapling worktree until native registry state is repaired: `, `Sapling worktree registry exceeds 1 MiB`, `Sapling worktree node mismatch: expected `, `validated Sapling worktree root does not match the recorded path`, `validated Sapling worktree root no longer matches the prepared record`, `Sapling source identity no longer matches the prepared record`, `recorded Sapling source identity no longer matches`, `Sapling registry main is not canoni…`, `Sapling storage root must be external to source and shared roots`, `Sapling storage root must be absolute UTF-8`, `Sapling worktree storage is not a UTF-8 directory`, `injected Sapling storage root is not a directory`, `canonicalize injected Sapling storage root failed: `, `Sapling storage root was not injected`, `Sapling storage root must have a parent for Eden state derivation`, `%partial Sapling worktree retained at `, `could not start Sapling process: `, `create a worktree: the repository has no commits yet` (Git-side sibling in same blob) |
| `session.fork.materialization` | `session.fork.materialization` (adjacent to `target session path escaped the protected sessions directory` … `session.start`); sibling `session.side_chat.materialization`; `source run cancelled while branch materialization was pending`; `runtime restarted while branch materialization was pending`; `branch materialization rejected`; `fork seed materialized `; `internal error: fork child seeded but its materialized history failed to publish`; `session/fork failed after publish; the child was unpublished`; `session/fork failed after publish and the child could not be unpublished` |
| `session.fork.compaction` | `session.fork.compaction`; struct pair `struct SessionForkCompactionRecord with 9 elements` + `struct SessionForkCompactionPayload with 6 elements`; payload fields blob: `SessionForkCompactionPayload summary boundary_turns checkpoint model_user_message_counts` |
| `session.fork.model_prefix` | `session.fork.model_prefix` + `SessionForkModelPrefixRecord`; `struct SessionForkModelPrefixPayload with 5 elements` + `struct SessionForkModelPrefixRecord with 9 elements` |
| `ConversationRewindForkKindV1` | `ConversationRewindForkKindV1conversation_rewind`, `struct ConversationRewindForkProvenanceV1 with 5 elements`, `ConversationRewindForkProvenanceV1 source_envelope_record_id basis_digest`, `struct ConversationRewindCommandV1 with 6 elements`, `struct ConversationRewindForkProvenanceV1`, `enum ConversationRewindForkKindV1`, `RetractRunConversationRewindCommandV1 requested_child_session_id [intent_id] envelope_record_id materialization_record_id cut_before basis`, `tbh:conversation-rewind-copied-unit:v1:conversation-rewind copied unit is not a top-level turn…` |
| `ForkProvenance` | `ForkProvenance fork_session_id source_session_id source_cut_cursor source_cut_was_explicit created_by_command_id web_search_mode goal_snapshot_manifest delegation_posture_seed …` (durable record shape, 10 elements: `struct ForkProvenance with 10 elements`); wire path `tbh_protocol::method::session::ForkProvenance`; schema sentence `Fork provenance folded from the durable session.fork.created record (ForkProvenance, tdd SS2.4).`; sibling `struct SessionForkCreatedRecord with 9 elements`, `struct SessionForkCompactionRecord with 9 elements`, `struct SessionForkRewindRecord with 9 elements`, `struct GoalForkSnapshotManifestRecord` |
| `cutCursor` | `cutCursorcutExplicitcommandId` (wire order); `forkedFrom cutCursor cutExplicit`; `MUST NOT parse it and no method accepts it (tdd SS2.4).cutCursor Whether the fork named an explicit cut point.`; durable snake_case `source_cut_cursor` (SQL: `command_id TEXT NOT NULL, source_cut_cursor TEXT NOT NULL,` + `SELECT target_session_id, source_session_id, command_id, source_cut_cursor,`); trace `source_cut_cursor source_cut_was_explicit diagnostics fallback_reason_detail outcome user_facing_error` |
| `forkBoundaryInvalid` | `forkBoundaryInvalid` (ErrorKind enum blob + `kind: forkBoundaryInvalid` transcript); schema: `Rejected inclusive fork boundary on forkBoundaryInvalid.` + `unknown turn fails forkBoundaryInvalid.` + `The last completed turn to copy, inclusive. Naming an in-progress or unknown turn fails forkBoundaryInvalid.` |
| `retained worktree is missing` | `workflow recovery retained worktree is missing: ` (format prefix); siblings: `workflow recovery retained worktree cwd is invalid: `, `workflow recovery retained worktree has no recorded source root`, `workflow recovery retained worktree metadata has no workspace root`, `workflow recovery retained worktree source proof is unavailable`, `workflow recovery retained worktree source tools are unavailable`, `workflow recovery could not bind tools to retained worktree: `, `workflow recovery could not rehydrate retained worktree source proof: `, `workflow recovery retained workspace is outside its sour…`, `retained worktree projection requires a session log`, `retained session worktree could not resolve a workspace root`, `retained session worktree could not resolve its recorded source`, `retained session worktree has no recorded source root`, `retained session worktree has no absolute captured cwd for its launch source` |
| `reconcile interrupted` | `cannot reconcile interrupted Sapling worktree create: `, `.cannot reconcile interrupted worktree create: `, `.cannot reconcile failed retained append for `, `interrupted worktree remove reconciled: cleared partial residue`, `interrupted worktree remove reconciled: destination is not a runtime-created worktree; left un…`, `interrupted worktree remove reconciled: intact worktree retained`, `interrupted worktree remove reconciled: destination is a different working tree; left unchanged`, `interrupted worktree remove reconciled: unexpected non-directory left unchanged`, `interrupted worktree remove reconciled: path already removed`, `interrupted session worktree create was reconciled; restart the session to continue`, `reconciled worktree path escaped its isolated lease`, `reconciled worktree is not the recorded repository`, `reconciled worktree HEAD does not match the create intent`, `d worktree is not the recorded repository`, `reconcile Resume HEAD`, `resume_reconcile:orphaned_by_process_loss` (crash-recovery marker) |

Further load-bearing windows (same sweep, `grep -o`):

- Lease core: `Treat .session.lock as an inode-backed kernel lease, not a marker file`, `RecordWireRef LeaseParked lease_parked LeaseActive lease_active`, `SubagentWorktreeResumeEvidence … expected_lease_generation … owner_lock`, `unordered same-generation worktree leases: cleanup fenced, worktree retained`, `cleanup selection does not match the current lease generation and attempt`, `cleanup terminal lease does not equal its durable settlement lease`, `admission cannot cross a pending cleanup before its terminal`, `pending cleanup cannot bind an ordinary child workspace`, `durable isolated placement has no live worktree resource`, `live worktree resource owner/generation/attempt/root/state conflicts with durable placement` (5-way conflict vocabulary), `live publish of a committed Workflow task lifecycle record failed…`, `failed to acquire source session writer lease: `, `failed to acquire target session writer lease: `, `failed to acquire the session writer lease:`, `failed to resolve source session writer lease: `, `could not resolve session writer lease: `, `target session log has no directory for writer lease`, `#child-session writer lease failed: `, `The session writer lease is held by another host (-32021).`
- Capability/reject preconditions: `Read-only children do not need isolation. Retry without worktree_isolation, or enable native_subagent_worktree_isolation.` / `…or start the session with durable event logging enabled.` / `This workspace is not a Git repository, so worktree isolation is unavailable…` (`workspace_not_git`) / `The runtime could not confirm that this workspace is a Git repository…` (`workspace_git_probe_failed`) / `…or run from a workspace that supports isolation.` (`no_workspace_root`) / `This profile cannot run native children; this child will not start…` / `worktree_isolation_unavailable` / `worktree isolation is unavailable` / `fan-out limit reached` / `waiting for a slot` / `Choose worktree_isolation (true or an empty object) when the user requests subagent isolation or when parallel children may write…` / `worktree_isolation accepts true, false, or an object such as {}. Send true (or {}) to request an isolated worktree checkout; send false or…`
- Storage roots: `.muse/worktrees`, `git-common-dir:session-worktree:`, `sapling-shared-root:`, `git-common-dir:rev-parse--quietverify git refreserve short worktree destination`, `worktree storage root must be UTF-8`, `authorize short worktree recreation`, `prune worktrees`, `encode short worktree recreation intent`, `resolve TBH session worktree root - sl help root`, `create TBH session worktree - sl help worktree--check`, `resolve Sapling worktree base`, `.sl/store/worktrees.json`, `.hg/store/worktrees.json`, `resolve retained worktree head --quiet`, `resolve worktree base`, `encode short worktree create intent`, `create worktree`, `delete worktree branch`, `resolve worktree head`, `branch_ref_exists is only set when a branch name is present`
- Fork validation vocabulary (single blob, canonical order): `…HistoryStreamSessionMismatch InvalidCut ForkIdEqualsSourceId ForkIdCollision StaleSourceCursor MissingInjectedId UnbalancedHistory GoalStoreUnreadable HistoricalGoalCutUnsupported GoalUsageReconciliationUnavailable Goal…` + `InvalidJoin InvalidCutBeforeRetainedFloor GoalHistoryPresent PrefixAssetUnavailable…`
- Branch-seed (fork materialization) cost path: `enum BranchSeedPath`, `runtime_checkpoint_tail runtime_full_replay legacy_session_data`, `enum BranchSeedFallbackReason`, `no_usable_checkpoint unsupported_checkpoint_shape …`, `enum BranchSeedCheckpointStatus`, `not_found unsupported_shape model_visible_same_run_tail missing_suffix`, `BranchSeedDiagnostics seed_path fallback_reason source_log_cut_sequence source_log_complete_prefix_len source_records_read source_records_total_estimate materialized_turns materialization_record_visits checkpoint_seed_used checkpoint_sequence phase_timings checkpoint`, `BranchSeedPhaseTimingsMs admission source_cut_capture tail_read checkpoint_validation fallback_decision seed_materialization durable_write`, `BranchSeedTimingDiagnostics source_tail_read_elapsed_us materialization_elapsed_us`, `BranchSeedTraceRecord command_type source_session_stream target_session_stream source_cut_cursor source_cut_was_explicit diagnostics fallback_reason_detail outcome user_facing_error`, `ForkChildSeedSnapshotV1 with 13 elements`, `fork_child_seed_snapshot`, `replay_model_messages fork_child_seed_classes fork_child_applied_boundary local_trim`, `DroppedCountsV1 tool_call tool_result reasoning compaction_residue` (fork drops compaction residue, keeps tool_call/tool_result/reasoning counts)
- Session-worktree lifecycle extras: `PendingSessionWorktreeSetup`, `session worktree source proof path escapes its held root`, `session worktree source proof encountered a symlink or reparse point`, `session worktree source proof expected a d…`, `session worktree source proof repository identity does not match`, `session worktree source proof stable root identity does not match`, `session worktree source proof filesys…`, `invalid pending session worktree setup: `, `non-off worktree mode returns pending setup`, `non-off worktree mode did not prepare a workspace`, `recorded session worktree no longer exists and cannot be recreated (its branch and base commit are gone): `, `cannot recreate session worktree: recorded branch and base commit are both gone`, `session worktree recovery has no valid prepared checkpoint`, `session worktree recovery requires cleanup re…`, `retained session worktree captured cwd is not absolute: `, `canonicalize retained session worktree launch source `, `clean checkpoint continuation cannot discard retained session worktree authority`, `session worktree history has multiple unresolved create intents`, `failed to write whole buffer` (adjacent I/O failure), `interrupted session worktree create was reconciled; restart the session to continue`, `session worktree retained at `, `; session worktree retained at `, `; recreated session worktree at `, `muse: session worktree retained at `, `tbh: session worktree retained at `, `project retained session worktree: `, `record session worktree event failed: `, `session worktree cleanup failed for `, `tbh: session worktree cleanup after failed run also failed: `, `muse: session worktree cleanup after failed run also failed: `, `tbh: session worktree cleanup after startup failure also failed: `, `muse: session worktree cleanup after startup failure also failed: `, `tbh: session worktree cleanup after MSP composition failure also failed: `, `tbh: session worktree cleanup after session-log degradation also failed: `, `muse: session worktree cleanup after session-log degradation also failed: `, `muse: session worktree cleanup after permission resume failure also failed: `
- CLI precondition errors (same blob): `--worktree-base requires --worktree create`, `--worktree-existing requires --worktree existing`, `--worktree existing requires --worktree-existing`, `--worktree-existing must differ from --workspace`, `--worktree requires session logging; remove --no-session-log`, `--worktree requires session logging, but session log was disabled: `, `a session id needs retained logging; remove --no-session-log`, `resume requires retained session logging`, `--worktree-base '` (clap), `Session worktree preparation requires create or existing mode`, `existing worktree does not belong to source repository`, `existing worktree mode requires existing_worktree_root`, `existing worktree path must differ from source repository root`, `path must differ from source repository root`, `U; pass --worktree existing --worktree-existing <path> to resume with a valid worktree`, `create a worktree: the repository has no commits yet`, `compose session worktree Agent Definitions: `, `configure session worktree: `

Counts satisfy the 150+ requirement: 1311 broad hits; the table above
quotes ~150 distinct verbatim windows (each independently re-greppable).

## 2. CLI worktree flags verbatim (`--help` capture, no auth)

`MUSE_NO_AUTO_UPDATE=1 muse-bin-1.3.0-R3057.1 --help` (root):

```
  -w, --worktree [<MODE>]
          Session Git worktree: off|create|existing; a bare -w means create
          (default: off)
      --worktree-base <REF>
          Base ref for --worktree create (default: HEAD)
      --worktree-existing <PATH>
          Existing worktree path for --worktree existing
      --parallel-tool-calls
          Enable Meta API parallel tool calls
      --no-parallel-tool-calls
          Disable Meta API parallel tool calls
      --subagent-worktree-isolation
          Compatibility flag; capability defaults on. Only an affirmative
          per-child request asks for isolation; omission stays shared. Requests
          may reject when capability, provider, or Git prerequisites are
          unavailable.
```

`MUSE_NO_AUTO_UPDATE=1 muse-bin-1.3.0-R3057.1 exec --help`:

```
  -w, --worktree [<MODE>]
          Session git worktree: off|create|existing
      --worktree-base <REF>
          Base ref for --worktree create (default: HEAD)
      --worktree-existing <PATH>
          Existing worktree path for --worktree existing
      ...
      --subagent-worktree-isolation
          Compatibility flag; capability defaults on. Only an affirmative
          per-child request asks for isolation; omission stays shared. Requests
          may reject when capability, provider, or Git prerequisites are
          unavailable.
```

`muse serve --help` carries **no** worktree flags (sandbox posture +
`--no-session-log` only; approval mode is wire-selected). Worktree is a
per-session CLI concern, not host posture.

Verification against `TEARDOWN.md` §4: matches verbatim —
`-w/--worktree [off|create|existing]`, `--worktree-base HEAD`,
`--worktree-existing PATH`, `--subagent-worktree-isolation` compatibility
semantics ("capability defaults on; only an affirmative per-child request
asks for isolation; rejects when capability/provider/Git prerequisites
missing"). One refinement from the binary: the **durable**
`SessionWorktreeMode` enum only spells `off create`
(`SessionWorktreeModeoffcreate`); `existing` is a CLI resume/reuse path
(`--worktree existing requires --worktree-existing`, `existing worktree
mode requires existing_worktree_root`), not a fresh-create mode.
`--worktree-base` / `--worktree-existing` cross-requirements and
`--worktree requires session logging; remove --no-session-log` are
enforced in the CLI layer (clap error blob, §1).

## 3. Schema verbatim (stable `msp.schema.json`)

`SessionForkParams` — "`session/fork` params (tdd SS2.5.3).":

```json
{
  "properties": {
    "commandId":   { "description": "The SS2.5 idempotency handle (UUIDv7).", "type": "string" },
    "cutPoint":    { "$ref": "#/$defs/ForkCutPoint",
                     "description": "Copy history through a completed turn, inclusive. Omitted means \"all completed turns\" (tdd SS2.5.3)." },
    "excludeItems":{ "description": "Skip inline history in the result and page it later — same as `session/resume` (tdd SS2.5.3).", "type": "boolean" },
    "sessionId":   { "description": "The source session.", "type": "string" }
  },
  "required": ["commandId", "sessionId"],
  "type": "object"
}
```

`SessionForkResult` — "`session/fork` result (tdd SS2.5.3): the
`session/resume` envelope for the **new** session, whose
`session.forkedFrom` carries the provenance.":

```json
{
  "properties": {
    "history":          { "$ref": "#/$defs/SessionHistory", "description": "The served history." },
    "pendingRequests":  { "description": "The late-joiner pointer set.",
                           "items": { "$ref": "#/$defs/PendingRequestPointer" }, "type": "array" },
    "session":          { "$ref": "#/$defs/Session",
                          "description": "The new fork session, carrying `forkedFrom` provenance." },
    "viewCursor":       { "description": "The new session's view head.", "type": "string" }
  },
  "required": ["history", "pendingRequests", "session", "viewCursor"],
  "type": "object"
}
```

`ForkCutPoint` — "Where a fork cuts the source history (tdd SS2.5.3). Turn
ids are used instead of counts because ids stay stable across compaction
and concurrent appends while indices do not.":

```json
{
  "properties": {
    "lastTurnId": { "description": "The last completed turn to copy, inclusive. Naming an in-progress or unknown turn fails `forkBoundaryInvalid`.", "type": "string" }
  },
  "required": ["lastTurnId"],
  "type": "object"
}
```

`ForkProvenance` — "Fork provenance folded from the durable
`session.fork.created` record (`ForkProvenance`, tdd SS2.4).":

```json
{
  "properties": {
    "commandId":   { "description": "The `commandId` of the `session/fork` that created it.", "type": "string" },
    "cutCursor":   { "description": "An **opaque provenance string** preserved verbatim from the durable record. Display-only — not one of the SS6.2 cursor families: clients MUST NOT parse it and no method accepts it (tdd SS2.4).", "type": "string" },
    "cutExplicit": { "description": "Whether the fork named an explicit cut point.", "type": "boolean" },
    "sessionId":   { "description": "The source session this fork was cut from.", "type": "string" }
  },
  "required": ["commandId", "cutCursor", "cutExplicit", "sessionId"],
  "type": "object"
}
```

`BranchState` — "The latest branch observation in the snapshot (tdd SS4.6.4, SS4.9.1).":

```json
{
  "properties": {
    "branch":        { "description": "The observed branch; `null` on a detached-HEAD observation.", "type": ["string", "null"] },
    "vcs":           { "$ref": "#/$defs/Vcs", "description": "The detected version-control system; absent when none was detected." },
    "workspaceRoot": { "description": "The observed workspace root.", "type": "string" }
  },
  "required": ["branch", "workspaceRoot"],
  "type": "object"
}
```

`Vcs`: `enum ["git", "sapling"]`, open (`x-msp-openness: open`).

`SnapshotState` (tdd SS4.9.1; required keys verbatim):
`activeTurn approvalMode branch effectiveModel goal items name
pendingApprovals pendingUserInputs queuedTurns todoList tokenUsage turnCount`
(+ additive-optional `contextUsage` absent-arm, `reasoningEffort` absent
until set). `branch` is `BranchState | null` ("Latest branch observation;
`null` when no fact has landed."). `SnapshotAnchor`: `boundaryCursor` (view
cursor of the boundary's `compaction` event) + `summarizedThrough` (opaque
compaction anchor). `ViewSnapshot`: `schemaVersion` + `state` +
`viewCursor`. Fork/compact interplay: `ForkCutPoint.lastTurnId` uses turn
ids precisely because "ids stay stable across compaction and concurrent
appends while indices do not"; `history.mode` downgrade
(`inline|snapshot|anchoredSnapshot|none`) applies to fork results exactly as
to resume; `excludeItems` polarity matches `session/resume`.

Wire errors relevant to fork (stable schema `errors` + `ErrorKind`):
`-32023 forkBoundaryInvalid` (non-retryable; `error.data.lastTurnId` echoes
the rejected inclusive boundary); `-32030 commandRejected`
(`error.data.{commandId,reason}` — covers `session_id_conflict`,
`missing_run` on compact); `-32021 sessionInUse` (writer-lease contention);
`-32020 sessionNotFound`; `-32011 notFound` (`missingAnchor`);
`-32040 viewTruncated` (`earliestCursor`); `-32042 boundaryPruned /
boundaryUnusable / noBoundary` (`latestBoundaryCursor`,
`latestBoundaryCursor == null` when no boundary). No worktree-specific wire
error exists — worktree failures surface as CLI/`serve` startup errors,
in-turn tool errors, or recovery notices, never as MSP error codes.

## 4. SDK clone: worktree/fork strings (host-runtime only)

`clients/sdk-ts/src`, `clients/msp-ts`, `clients/sdk-cookbook/src`,
`clients/sdk-quickstart/src` contain **zero** worktree/fork wire usage:

- `subagent/*` appears zero times in `clients/*/src` (TEARDOWN.md §3,
  confirmed by re-grep); hence also zero `worktree_isolation` / `session/fork`
  call sites in the facade. `spawnMspConnection` (`connection/spawn.ts:643`)
  → `MspHandshake.initialize` → `MuseClient.spawn`
  (`facade/client.ts:219`) → N×`startSession`
  (`facade/session.ts:721`, `SessionStartParams` at `schema/msp/msp.d.ts:1130`)
  carries no worktree member — isolation is a CLI/`serve` concern, not a
  `session/start` param.
- Only prose hits outside vendored schema/transcripts:
  - `clients/sdk-cookbook/src/recipes/survive-the-host-dying.ts:5` —
    "of them ask your app first. What this recipe teaches is the durability fork"
    (durability branching prose, not `session/fork`).
  - `clients/sdk-cookbook/src/recipes/survive-the-host-dying.ts:23` —
    "Two arms, mirroring that fork:" (same recipe prose).
  - `clients/msp-ts/README.md:14` — "would fork from the one #206 owns"
    (spec-ownership prose).
- All other `fork*`/`worktree*` hits are vendored schema + transcripts:
  e.g. `schema/msp/stable/msp.schema.json:966` (`Rejected inclusive fork
  boundary on forkBoundaryInvalid.`), `:1043` (`forkBoundaryInvalid` in
  `ErrorKind`), `:1116` (`ForkCutPoint`), `:1129` (`ForkProvenance`),
  `:2536` (`SessionForkParams`), `:2562` (`SessionForkResult`),
  `:5116` (`session/fork` method table); `schema/msp/msp.d.ts:333`
  (`Rejected inclusive fork boundary…`), `:358` (`ErrorKind`), `:380`
  (`ForkCutPoint`), `:386` (`ForkProvenance`), `:857` (`activeTurnId`
  required-nullable ruling naming `session/snapshot.rs` feeding
  resume/read/list/fork), `:864` (`forkedFrom`), `:960`
  (`SessionForkParams`).
- `CHANGELOG.md` (host changelog, not SDK API) is the only behavioral record
  for worktree/fork — file:line verbatim:
  - `:64` `--worktree` empty-value fallback explainer.
  - `:107` session worktrees track nested cwd from subdirectories.
  - `:174` forked resume preview shows prior history; resume of fork no longer wrongly rejected.
  - `:176` pre-resume/fork images kept in context.
  - `:178` sessions forked just before a crash recovered as crashed.
  - `:191` permission settings carry over on fork.
  - `:212` fork inherits model, permission profile, committed message order, tool-call history.
  - `:213` failed fork fully removed incl. DB side files (no phantom resumable); oversized history budget honored.
  - `:231` worktree removal cut short by time budget completes instead of recording failed.
  - `:319` fork-time prompts run in the fork, not the original.
  - `:327` `/compact` covers real working set incl. after forks/side chats.
  - `:363` subagent worktrees with unprovable post-crash ownership quarantined, not cleaned.
  - `:389` isolated-subagent-worktree Git ops moved off the agent runtime.

## 5. Synthesis for `spark_worktree` / `spark_fork`

### 5.1 Session-worktree lifecycle state machine

```
CLI parse (-w/--worktree/--worktree-base/--worktree-existing, --no-session-log)
  │  ✗ --worktree-base w/o --worktree create / --worktree-existing w/o --worktree existing
  │  ✗ --worktree existing w/o --worktree-existing / --worktree-existing == --workspace
  │  ✗ --worktree + --no-session-log  ("remove --no-session-log")
  ▼
PendingSessionWorktreeSetup (non-off mode returns pending setup)
  │  source-proof gate (held-root containment, no symlink/reparse, repo-identity
  │   + stable-root-identity match; else `session worktree source proof …`)
  │  VCS detect: git → `git worktree add` path; sapling → `sl` path
  │   (`Sapling session worktree setup is unsupported in this environment` if unavailable)
  ▼
CREATE ── git: `encode short worktree create intent` → `create worktree`
         → `resolve worktree base/head` → `.muse/worktrees` destination
         (`git-common-dir:session-worktree:`); sapling: storage under
         injected root (must be absolute UTF-8, external to source+shared roots;
         `.sl/store/worktrees.json` / `.hg/store/worktrees.json` registry,
         `expected exactly one Sapling worktree registry`)
  │  ✗ `create a worktree: the repository has no commits yet`
  │  ✗ `created Sapling worktree escaped its generated destination`
  │  ✗ `session worktree requires a Git source repository:`
  │  ✗ crash / interrupt mid-create → `cannot reconcile interrupted … worktree create`
  ▼
PLACED + LEASED — durable `SessionWorktreeRecord` =
  {owner, repository, path, base, lock identity, lease generation + attempt}
  (`.session.lock` is an inode-backed kernel lease, not a marker).
  Session log mirrors placement (`record session worktree event failed` is fatal-ish).
  Branch observation folds to `BranchState{branch, vcs: git|sapling, workspaceRoot}`
  + `session/branchChanged`.
  ▼
RUNNING (turns execute with `workspaceRoot` = worktree; nested cwd tracked, CHANGELOG:107)
  │  `session/fork` does NOT clone the worktree: fork copies the *log*
  │  through the cut; workspaceRoot is inherited metadata. Give each parallel
  │  fork its own worktree at the `spark_*` layer if it will write.
  ▼
CLEANUP — guard: `SessionWorktreeCleanupPolicy remove_if_clean` (only policy in binary).
  Preconditions per attempt: active lease still held by cleaner
  (`expected_lease_generation`, `owner_lock`); no pending-cleanup fence crossing
  (`admission cannot cross a pending cleanup before its terminal`);
  `cleanup selection matches current lease generation and attempt`.
  Outcomes (`SessionWorktreeRecordCleanupOutcome`): `cleanup_outcome` |
  `setup_failed` | `recordcleanup_failed` | `cleanup_effect_settled/started`.
  `unordered same-generation worktree leases: cleanup fenced, worktree retained`.
  Time-budgeted removal runs to completion (CHANGELOG:231).
  Double-failure strings name every stage that can itself fail cleanup:
  `… cleanup after failed run / startup failure / MSP composition failure /
  session-log degradation / permission resume failure also failed`.
  ▼
PRUNE — `authorize short worktree recreation` / `prune worktrees` /
  `encode short worktree recreation intent` (short-lived recreation leases).
```

Crash path (reconcile): `resume_reconcile:orphaned_by_process_loss` →
orphan scan → per-worktree triage:

- create interrupted → `cannot reconcile interrupted … worktree create` →
  `interrupted session worktree create was reconciled; restart the session to continue`
  (session does NOT auto-continue).
- remove interrupted → one of: `cleared partial residue` | `intact worktree
  retained` | `destination is a different working tree; left unchanged` |
  `destination is not a runtime-created worktree; left unchanged` |
  `path already removed` | `unexpected non-directory left unchanged`.
- reattach gate: `only an active lease or recreatable cleanup terminal can
  reattach`; `Resume repository does not match the recorded lease
  repository`; `reconciled worktree is not the recorded repository`;
  `reconciled worktree path escaped its isolated lease`;
  `reconciled worktree HEAD does not match the create intent` →
  `reconcile Resume HEAD`.
- recorded branch+base both gone → `recorded session worktree no longer
  exists and cannot be recreated…` / `cannot recreate session worktree…`;
  no valid prepared checkpoint → `session worktree recovery has no valid
  prepared checkpoint`; Sapling native state broken →
  `cannot recreate Sapling worktree until native registry state is repaired`.
- ownership unprovable after crash → **quarantine, never clean**
  (CHANGELOG:363; `quarantined subagent worktree lease refuses workspace
  binding`, `<warning: quarantined subagent worktree lease: owner session `).

Subagent-worktree (per-child) variant: default **shared** parent workspace;
isolation only on affirmative `worktree_isolation: true|{}` per child
(`--subagent-worktree-isolation` is a compat flag; capability defaults on).
Admission rejects before any filesystem touch when: not native-capable
profile (`This profile cannot run native children…`), read-only child
(`Read-only children do not need isolation. Retry without
worktree_isolation…` + 3 cause suffixes: enable
`native_subagent_worktree_isolation` / enable durable logging / Git
workspace variants `workspace_not_git workspace_git_probe_failed
no_workspace_root no_session_event_sink`), fan-out slash (`fan-out limit
reached`, `waiting for a slot`). Runtime placement then follows the same
place→lease→cleanup→prune machine with logical-owner resources
(`accepted/awaited … logical-owner (worktree) resource`,
`CleanupPending placement has no durable cleanup intent`,
`pending cleanup cannot bind an ordinary child workspace`); lease loss
mid-cleanup is the canonical `subagent worktree cleanup lost its active
lease` (non-fatal: worktree retained, quarantined); `subagent worktree
requires a session log` / `resume requires a session log` gate every
mutation; `durable isolated placement has no live worktree resource` +
5-way `live worktree resource {owner,generation,attempt,root,state}
conflicts with durable placement` disambiguate stale-view races.

### 5.2 Fork cost model (copy-through-cut vs re-derive; compaction interaction)

`session/fork {sessionId, cutPoint?: {lastTurnId}, excludeItems?, commandId}`
is a **log operation**, not a filesystem operation. Cost is dominated by
branch-seed materialization (`BranchSeed*` machinery), not by tokens:

1. **Admit** (cheap): validate source exists/loaded, `commandId` fresh
   (`command_id_conflict`/`session_id_conflict` on replay-with-different-payload),
   acquire source writer lease (`failed to acquire source session writer
   lease`), resolve cut (`lastTurnId` must name a *completed* turn;
   in-progress/unknown → `-32023 forkBoundaryInvalid` with
   `error.data.lastTurnId`; deeper invariant failures use the
   `InvalidCut ForkIdEqualsSourceId ForkIdCollision StaleSourceCursor
   MissingInjectedId UnbalancedHistory…` vocabulary).
2. **Seed-pick (the cost branch)** — `BranchSeedPath`:
   - `runtime_checkpoint_tail` (cheapest): a usable checkpoint covers the
     cut; copy `source_log_cut_sequence` prefix + checkpoint tail.
     Diagnostics: `checkpoint_seed_used`, `checkpoint_id/position/sequence`.
   - `runtime_full_replay` (linear in `source_records_read` /
     `source_records_total_estimate`): no usable checkpoint
     (`no_usable_checkpoint`, `not_found`) or bad shape
     (`unsupported_checkpoint_shape`, `unsupported_shape`) →
     re-derive by reading source records through the cut
     (`source_cut_capture → tail_read → checkpoint_validation →
     fallback_decision → seed_materialization → durable_write`;
     timed by `source_tail_read_elapsed_us` + `materialization_elapsed_us`).
   - `legacy_session_data`: old-format source; same replay cost + validation.
   - Fallback triggers that force re-derive: `checkpoint_has_model_visible_tail`
     shape edge, `checkpoint_missing_suffix` / `model_visible_same_run_tail`
     / `missing_suffix` (checkpoint does not cover cut window:
     `rewind cut window holds no record before the selected turn`), crash
     races (`source run cancelled while branch materialization was pending`,
     `runtime restarted while branch materialization was pending` →
     `branch materialization rejected`).
3. **Materialize + durable write** (linear in copied prefix):
   `seed_materialization` visits `materialization_record_visits`,
   emits `materialized_turns`, writes `session.fork.created` durable record
   (`SessionForkCreatedRecord`, 9 fields; `ForkProvenance` 10 fields:
   `fork_session_id source_session_id source_cut_cursor
   source_cut_was_explicit created_by_command_id web_search_mode
   goal_snapshot_manifest delegation_posture_seed …`),
   plus `session.fork.turn` per copied turn (`SessionForkTurnRecord` 9 /
   `SessionForkTurnPayload` 4: `fork_session_id turn_index refill_blocks`),
   plus kind-specific records: `session.fork.compaction`
   (`SessionForkCompactionRecord` 9 / payload 6: `summary boundary_turns
   checkpoint model_user_message_counts`),
   `session.fork.model_prefix` (`SessionForkModelPrefixRecord` 9 / payload 5),
   `session.fork.rewind_hidden_turn` (`SessionForkRewindRecord` 9 / payload 3:
   `turn_index`), conversation-rewind variant
   (`ConversationRewindForkKindV1 conversation_rewind`,
   `ConversationRewindForkProvenanceV1 source_envelope_record_id
   basis_digest`, goal fork manifest `source_lineage_depth/digest
   source_goal_id/revision … snapshot_sha256`).
   Publish failures *after* the child exists are the two expensive errors:
   `fork child seeded but its materialized history failed to publish` →
   `session/fork failed after publish; the child was unpublished` (clean) vs
   `…and the child could not be unpublished` (phantom; CHANGELOG:213 says the
   current build removes leftover DB side files instead of leaving it).
4. **Serve** (`SessionForkResult` ≡ resume envelope; `excludeItems=true`
   defers `history.items` to `view/page`): new `sessionId` (UUIDv7, fresh
   `createdAt`), `forkedFrom{sessionId, commandId, cutCursor (opaque,
   MUST NOT parse), cutExplicit}`, inherited approval/model/permission-profile/
   message-order/tool-history (CHANGELOG:191,212), `viewCursor` = new head.
   `history.mode` may downgrade (`inline → snapshot → anchoredSnapshot →
   none`) under the history budget; `oversized history budget is honored`
   (CHANGELOG:213).

Compaction interaction (why `lastTurnId`, not an index):

- Turn ids are stable across compaction and concurrent appends; indices are
  not (`ForkCutPoint` description). A cut naming a compacted-away or
  in-flight turn → `forkBoundaryInvalid`.
- Fork copies the **folded** history *through* the cut, including installed
  compaction boundaries (`session.fork.compaction` record carries
  `summary boundary_turns checkpoint model_user_message_counts`; child seed
  carries `fork_child_seed_classes fork_child_applied_boundary`,
  `replay_model_messages`, `CompactionPreservedSegment{head_sequence,
  tail_sequence}` + hint, `CompactionBudgetSnapshot`, and per-message
  `DroppedCountsV1{tool_call, tool_result, reasoning, compaction_residue}` —
  i.e. the child inherits post-compaction working set, residue stays dropped).
- `/compact` after fork operates on the fork's own working set
  (CHANGELOG:327); `SnapshotAnchor{boundaryCursor, summarizedThrough}`
  anchors each side independently. Cost rule of thumb for `spark_fork`:
  **cut at a completed turn just after a compaction boundary when possible**
  (maximizes `runtime_checkpoint_tail` hits); cutting inside an
  uncompacted long tail forces `runtime_full_replay` proportional to
  `source_records_read`. Fork-then-immediately-compact is the worst order —
  it pays materialization *and* a fresh summarizer pass.

### 5.3 Exact error cases for `spark_worktree` / `spark_fork`

| # | Tool | Trigger | Verbatim signal | Retry / handling |
|---|---|---|---|---|
| W1 | worktree | `--worktree-base` without `--worktree create` | `--worktree-base requires --worktree create` | fix argv; no retry |
| W2 | worktree | `--worktree-existing` without `--worktree existing` (either direction) | `--worktree-existing requires --worktree existing` / `--worktree existing requires --worktree-existing` | fix argv |
| W3 | worktree | existing path == workspace | `--worktree-existing must differ from --workspace` / `existing worktree path must differ from source repository root` | pick fresh path under `.muse/worktrees` |
| W4 | worktree | `--worktree` + `--no-session-log` (or `serve --no-session-log`) | `--worktree requires session logging; remove --no-session-log` (+ `a session id needs retained logging…`, `resume requires retained session logging`, `retained worktree projection requires a session log`) | re-serve without `--no-session-log`; never pass `path == ""` to fs |
| W5 | worktree | source not a Git repo / probe failed / no root | `session worktree requires a Git source repository: ` / `existing worktree does not belong to source repository` / `path must differ from source repository root` | run from Git workspace; no retry loop |
| W6 | worktree | repo has no commits yet | `create a worktree: the repository has no commits yet` | commit first or use `existing` |
| W7 | worktree | Sapling env unsupported / registry broken | `Sapling session worktree setup is unsupported in this environment` / `cannot recreate Sapling worktree until native registry state is repaired: ` / `expected exactly one Sapling worktree registry, found ` / `validate/read Sapling worktree registry failed: ` | repair registry out-of-band; `spark_worktree` should prefer Git |
| W8 | worktree | crash mid-create | `cannot reconcile interrupted [Sapling] worktree create: ` → `interrupted session worktree create was reconciled; restart the session to continue` | **restart session**; do not auto-continue |
| W9 | worktree | recorded branch+base gone | `recorded session worktree no longer exists and cannot be recreated (its branch and base commit are gone): ` / `cannot recreate session worktree: recorded branch and base commit are both gone` | fresh `create` from live HEAD; old path unrecoverable |
| W10 | worktree | cleanup lease lost / fenced | `subagent worktree cleanup lost its active lease` / `only an active lease or recreatable cleanup terminal can reattach` / `unordered same-generation worktree leases: cleanup fenced, worktree retained` / `admission cannot cross a pending cleanup before its terminal` | treat as **retained+quarantined**, surface path, continue; never delete a quarantined tree (`quarantined subagent worktree lease refuses workspace binding`) |
| W11 | worktree | per-child isolation refused (pre-fs) | `Read-only children do not need isolation. Retry without worktree_isolation, …` (4 suffixes) / `This profile cannot run native children…` / `worktree_isolation_unavailable` / `workspace_not_git workspace_git_probe_failed no_workspace_root no_session_event_sink` / `fan-out limit reached` / `waiting for a slot` | downgrade to shared workspace (read-only safe) or fix Git/logging/capacity; `--subagent-worktree-isolation` flag alone changes nothing |
| W12 | worktree | path collision / not-runtime-owned on remove | `subagent worktree path collides with an existing path: ` / `interrupted worktree remove reconciled: destination is a different working tree; left unchanged` / `destination is not a runtime-created worktree; left unchanged` | pick new destination; never force-remove foreign trees |
| F1 | fork | cut = in-progress / unknown turn | `-32023 forkBoundaryInvalid`, `error.data.lastTurnId` = rejected turn; binary: `unknown turn fails forkBoundaryInvalid.` | re-list turns, cut at latest *completed* turn id |
| F2 | fork | stale/structural cut | `InvalidCut ForkIdEqualsSourceId ForkIdCollision StaleSourceCursor MissingInjectedId UnbalancedHistory GoalStoreUnreadable…` vocabulary | fresh `view/page` from `earliestCursor`/`latestBoundaryCursor`, re-cut |
| F3 | fork | lease / session missing | `failed to acquire source|target session writer lease: ` / `could not resolve session writer lease: ` / `-32021 sessionInUse` (held by another host) / `-32020 sessionNotFound` | back off on `-32021`; re-resolve on lease-missing; never steal `.session.lock` |
| F4 | fork | materialization race | `source run cancelled while branch materialization was pending` / `runtime restarted while branch materialization was pending` → `branch materialization rejected` / `rewind cut window holds no record before the selected turn` | retry same `commandId` (idempotent replay joins original); move cut earlier |
| F5 | fork | publish half-failure | `fork child seeded but its materialized history failed to publish` → `session/fork failed after publish; the child was unpublished` (safe retry) vs `…and the child could not be unpublished` (sweep DB side files per CHANGELOG:213, then retry with new `commandId`) | distinguish the two suffixes before retrying |
| F6 | fork | `cutCursor` misuse | client parses/forwards `ForkProvenance.cutCursor` as a view cursor → `notFound/missingAnchor` or `-32042 boundaryPruned/boundaryUnusable/noBoundary` | `cutCursor` is display-only; resume/page only with `viewCursor`/`summarizedThrough` from the *result* |
| F7 | fork | budget/mode surprise | `history.mode` downgraded (`inline→snapshot→anchoredSnapshot→none`), `noneReason: historyBudget\|excluded\|cursorSuffix` | honor served `mode`; page via `view/page`; do not assume inline items |
| F8 | fork+compact | cut inside uncompacted tail / fork-then-compact | pays `runtime_full_replay` (`source_records_read`) + fresh summarizer; `DroppedCounts{compaction_residue}` stays dropped in child | cut just after a compaction boundary; compact *before* fork, not after |

`spark_worktree` rule summary: one worktree per parallel session (Git-first,
`.muse/worktrees` default, `HEAD` base unless pinned); refuse
`--no-session-log` combos at argv validation; quarantine (never delete) on
lease-loss/crash; prune only runtime-created trees. `spark_fork` rule
summary: copy-through-cut log fork (no fs clone); cut must be a completed
turn id; same-`commandId` retry is safe; post-compaction cuts are cheapest;
never parse `cutCursor`; always fold the served envelope + `history.mode`.
