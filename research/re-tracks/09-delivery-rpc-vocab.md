# 09 — Delivery Policies + Agent RPC Verbs (verbatim from binary)

Recovered via ghidra-rpc `read-bytes` on enum tables consumed by
`workflow_journal_site` @0xc17c0a0 (journal match predicate) and the
`agent_rpc_router` @0xc177520 region. Saved + tagged in `ghidra/muse.gpr`.

## Delivery-policy enum (9 values, order = table A @0x119b738/0x12211300)

| # | Value | Use |
|---|---|---|
| 0 | `advisory` | Informational; no wake, no queue |
| 1 | `runtime_context` | Context injection (origin wrapper `session_message_remote`) |
| 2 | `user_message` | Delivered as user turn content |
| 3 | `queue_next_turn` | Queue for next turn (canonical + wake_when_idle) |
| 4 | `steer_active_turn` | Steer the running turn (canonical steer path) |
| 5 | `notify_only` | Notify, no delivery |
| 6 | `do_not_wake` | Hold until explicitly pulled |
| 7 | `wake_when_idle` | Wake iff idle and unfinished (canonical + queue_next_turn) |
| 8 | `wake_at_safe_point` | Deferred wake (@0x1198600, len 18) |

PORT (`spark_send`): `policy` field REQUIRED, closed enum of the 9 above.
Default `queue_next_turn` + `wake_when_idle` (the canonical pair the
binary itself uses). Reject anything else fail-closed
(`invalid_display_context` family). Non-canonical combos fail closed —
do not invent `steer + do_not_wake`.

## Agent RPC verbs (12, packed @0x118f1dc, lengths in tables B/C)

`Agent.start`, `Agent.followup`, `Agent.send`,
`AgentAttempt.getStatus`, `AgentAttempt.result`, `AgentAttempt.interrupt`,
`Pipeline.start`, `Pipeline.result`,
`ParallelGroup.start`, `ParallelGroup.result`,
`Phase.create`, `Phase.log`.

PORT: this is the workflow-layer API the model drives. `ParallelGroup.start`
is the native fan-out verb (maps to coordinator `task(..., run_in_background)`
fan-out); `Phase.create/log` + `Pipeline.result` is the plan ledger;
`AgentAttempt.*` is the child lifecycle (`getStatus` → poll,
`result` → consume = `subagent/readResult`, `interrupt` → yield).
Mirror these 12 as the `spark_*` tool surface instead of inventing names.

## Method descriptor layout (wire dispatch tables)

MSP method descriptors are 32 B rows `{name_ptr, name_len, desc_ptr, desc_len}`:
e.g. `subagent/sendMessage` (len 20 = 0x14) @0x121b02a8 with
`CommandAcceptedResult` + `Queue a user note into a running child;
admission-only ack, …`. Descriptors are consumed by array base + index
(no direct xrefs — computed). PORT: nothing to clone; confirms the
`msp.schema.json` export is complete and authoritative for the wire.

##Journal match predicate (workflow_journal_site, full decomp)
Match = tombstone flag clear (`+0x8e == 0`) AND record present
(`*rec != -1`) AND generation cap (`+0x3f <= 2`) AND slot-wise memcmp
against the enum tables above (offsets 0x5d–0x83 vs event +0x20–0x188).
PORT (`spark_result` acceptance): tombstone check → generation cap →
field-wise equality. Same shape as the approval decision predicate
(track 08 §5) — one shared `record_matches()` helper serves both.
