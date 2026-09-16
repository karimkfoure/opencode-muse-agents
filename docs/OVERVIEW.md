# OVERVIEW — the subagent magic in Muse Code, and how it ports to OpenCode

## The one sentence

Muse Code treats subagents as DURABLE LOG RECORDS first and running
processes second. Every coordination act — spawn, steer, message, result,
approval, recovery — is an appended, fingerprinted, validated record.
Processes come and go; the log decides truth. OpenCode treats subagents
as live sessions; when the process ends or context compacts, the truth
goes with it. That gap is the whole difference.

## The 9 pieces of magic

### 1. Spawn = commit a validated record, not launch a process
`AgentSpawnCommitV1 {spawn_decision, parent_binding, agent_lineage_admission}`.
Before anything runs: resolve the agent definition (by digest, never by
name), check capacity (`root_capacity / active_capacity / max_depth /
fanout_limit`), bind the worktree (TRI-STATE mode: `-1` off / `0` shared /
`>0` isolated carrying N identity bytes — the request carries its identity
length), attach the completion contract (schema the child MUST return),
fingerprint everything (canonical evidence + body digests + tool-surface
version).SIZE the commit record from present fields (adaptive, never
fixed), and bind the worktree INSIDE the commit — never bind-then-commit.
Only then does execution start. Failure produces a KEYED error
(`policy_denied`, `parent_closed`, `lineage_integrity_failed`,
`command_id_reused`…) from one central catalog — never an inline string.

### 2. Identity = lineage attestation, never names
`AgentPathSemanticsV1`, `immediate_parent_session_id /
immediate_parent_run_id`, `journal_chain_digest`, definition/context/
toolset digests. Worktree paths select semantics by flag (v3-canonical
vs legacy-ordinal) before bind-verify. The commit carries exactly six
fields (`schema_version`, `spawn_decision`, `parent_binding`,
`agent_lineage_admission`, `accepted`, `description`); the attach step
adds `parent_session_id`, `parent_run_id`, `agent_path`,
`path_semantics`, `legacy_projection`, `attempt_ref`. The model-spawned
("managed") handler explicitly carries NO identity — trust comes from
attestation + policy checks at every step. A worker is believed because
its lineage verifies, not because of which session it claims to be.

### 3. Communication = ledger admission, not messaging
There is no send path — the socket transport was RETIRED
(`TBH_SESSION_MESSAGE_SOCKET retired → brokerless session registry`).
A message is appended, then ADMITTED through a fold with 11 coded
outcomes (the binary names more: `pending_admission`,
`accepted_queue_full`,
`duplicate_suppressed`, `blocked_by_receiver`, `reply_context_expired`,
`strict_retention_failed`…). Steering a child = a 4-pair intake record
`{SessionCommandIntakeCommand, SubagentSteering, kind, subagent_steering}`
dispatched by numeric kind through one jumptable, then executed as ordered
takes (verb → subagent_id → body → reason) with fail pair `{0xff, err}`.
Results = a `SubagentResult` envelope (summary ≤512 chars, text ≤32 KiB +
refs) folded into the parent's item by table-order field apply + commit.
Delivery policy is a closed 9-enum (`queue_next_turn`,
`steer_active_turn`, `wake_when_idle`, `do_not_wake`, …); non-canonical
combos fail closed.

### 4. Capacity is a gate, not a hope
`root_capacity_exhausted`, `active_capacity`, `max_depth`,
`fanout_limit`, per-generation guards. Checked at admission, before any
work. OpenCode's background fan-out has concurrency settings; Muse Code
additionally binds capacity to lineage depth and roots, so a runaway
tree is structurally impossible.

### 5. Ownership is a record with three drivers
Owner commands (interrupt/stop/close/resume/reopen/readResult) resolve
an owner control record, STRIP the `workflow` entry from it, and run one
of three paths: default (steady state), replace-on-idle (refuse
non-idle instead of overwriting), staged pipeline (spawn/followup,
commit-last 248-byte outcome rows). Every command is admission-only;
truth arrives on the stream.

### 6. Determinism machinery: fingerprints + idempotency everywhere
Canonical evidence digests, command-id digests, 36-byte canonical Event
IDs (16 B → lowercase hex 8-4-4-4-12 via nibble table — byte-exact),
dedupe keys, generation/lease guards (`lease_generation_changed`,
`projection_changed`, `prepared_receipt_mismatch`). `-2` is polymorphic:
fenced marker AND follow-up-required; `-1` = absent/failed. Fence breach
TRAPS (aborts, never recovers); unprovable ownership quarantines (never
deletes) — two distinct rules. The retry rule is written into user-facing
text: "Retry the same request with the same command_id to reconcile; do
not use a new command_id." Retry storms and double effects are impossible
BY CONSTRUCTION, not by discipline.

### 7. Policy separated from mechanism
Permission catalog snapshots, staged approval requirements (shell prefix
/ tool action / filesystem matchers), a judge lane + human lane with
first-fire-wins ordering, field-wise decision equality, and durable
`DecisionApplied` records — verdicts die without them. The mechanism
never asks "should I"; it asks the policy record, which was committed
earlier.

### 8. Stream folding with memory
Per-field memo slots (absent = -1 sentinel), fixed re-emit field order,
usage-first result envelopes, fold position classes coded as
stream=0 / first=1 / last=2 / other=3, progressive `displayText` with
authoritative `completed` text. One keyed-emit primitive, one
table-driven registry engine, and one fence+key+tag+walk micro-protocol
family serve all folds/phases/validators/commits — port each shape ONCE,
not per call site. This is the "it feels live and never glitches" part:
order and cursor discipline, not speed.

### 9. Crashes are a normal input
Orphan reconcile, retained/resume shape checks, hydration target
validation, boundary/cut validation, quarantine-never-delete for
unprovable ownership. Every recovery path was found as a first-class
code path with its own records — not exception handlers.

## Model-facing tuning (effort-gated autonomy)

The harness is model-agnostic (provider/model are config strings; no
Spark-specific paths exist in the binary — "Sparkplug" hits are a JS
engine). What shapes model behavior is configuration, verified in strings:

- Reasoning effort scale (none → ultra). At `ultra`, PROACTIVE WORKFLOW
  DELEGATION activates via injected policy context (decompose early into
  tracks, call Workflow before discovery, user opt-out always wins).
  Mid-session effort changes flip it with explicit messages.
  Port: effort/config-gated delegation policy text, not a code path.
- `first_turn_minimal_effort`: first turn runs cheap by default.
- Model routing with `model_downshift_resume` + fallback chains on
  failure. Port: per-role fallback chains (oh-my-opencode pattern).
- Hooks at model boundaries: `PreLLMCall` / `PostLLMCall` /
  `SubagentStart` / `SubagentStop` (+ tool/session/compact hooks).
  Gap: OpenCode plugin events lack a pre-LLM-call hook — emulate via
  `tool.execute.before` on the first tool call or prompt-prefix rules.
- Presets shape the agent loop (`native-basic` tool agent vs `miniswe`
  JS-cell agent). Port: preset = permission matrix + loop prompt.
- `subagent_delegation_modes`, `workflow_trigger_mode`,
  `delegation_posture` in run settings. Port as coordinator config.

## What OpenCode lacks (gap list)

1. No durable child record with lineage — children are live sessions.
2. No admission control with capacity/depth roots.
3. No keyed error catalog — failures are prose.
4. No ledger mailbox — only live delivery; nothing survives restart.
5. No canonical fingerprints / idempotency keys — retries can double-apply.
6. No generation/lease guards — stale writes can land silently.
7. Approvals without stages, judge lane, or durable verdicts.
8. Compaction drops pending IDs and control state (the bundled spark-compact plugin re-injects them).
9. No completion contract per child — result shape is convention.

## How it ports (shape of the something)

- Child record + lineage → worker session frontmatter + `spark_result`
  envelope validation (tracks 10, 07).
- Admission + capacity + keyed errors → `spark_submit` gate + error
  catalog (tracks 08, 15).
- Ledger mailbox + 9 policies → append-only mailbox files + wake rules
  (tracks 03, 09).
- Fingerprints + same-commandId retry → UUIDv7 ids + dedupe keys +
  documented retry rule (tracks 08, 15).
- Owner control + 3 drivers → coordinator/steer/resume tools with the
  idle gate + workflow strip (tracks 08, 12).
- Judge + equality + durable verdicts → policy plugin with two lanes
  (track 08).
- Memo fold + fixed orders → streaming render rules (track 11).
- Reconcile paths → startup recovery + quarantine (tracks 02, 13).
- Coordinator/worker/reviewer agents + permission matrices → the role
  split OpenCode already supports (design doc + tracks 04–06).

NOT ported: the transport loop itself (OpenCode owns a server already),
the Rust internals (replaced by the same record shapes in TS/Python).
