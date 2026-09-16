# 21 — Subagent Wire Descriptors

Sources: `re-tracks/decomp/goalA_subagent_wire.evidence.txt` (record
decode) and `goalB_serve_dispatch.evidence.txt` (dispatch table).

## 1. Descriptor record layout

Record = {u64 zero, u64 zero, Slice name, Slice result, Slice doc,
Slice params}, Slice = (ptr, len) into .rodata. Record groups are
0xfffffffffffffffe-terminated; name→(result, doc, params) resolves by
linear scan of slices (table @0x121b0200..).

- sendMessage (group2 @0x121b02a0): name=`subagent/sendMessage`,
  result=`CommandAcceptedResult`, params=`SubagentInputParams`.
- readResult (group9 @~0x121b0358): name=`subagent/readResult`,
  result=`CommandAcceptedResult`, params=`SubagentTargetParams`.

## 2. Params-sharing table

Every verb acks `CommandAcceptedResult` (admission-only, SS3.16).

| Method | Params | Doc one-liner |
|---|---|---|
| sendMessage | SubagentInputParams | Queue a user note into a running child; settles on its view stream. |
| followupTask | SubagentInputParams | Queue a follow-up task for a child; same admission ack. |
| interrupt | SubagentOwnerReasonParams | Ask a child to yield at its next boundary; folds to parent item. |
| stop | SubagentOwnerReasonParams | Doc not in evidence; shares owner+reason shape. |
| close | SubagentOwnerReasonParams | Owner-close a child; terminal mapping folds per SS4.5.7. |
| resume | SubagentTargetParams | Doc not in evidence; target-only shape. |
| reopen | SubagentTargetParams | Doc not in evidence; target-only shape. |
| readResult | SubagentTargetParams | Consume a ready child result (state-changing). |

## 3. Goal B verdict

xrefs-to on 0x121b02a8/0x121b0260: EMPTY — no direct callers, consistent with computed base+index dispatch, NOT proven — analysis_complete=false so empty xrefs are indistinguishable from an unavailable reference graph. Computed dispatch (linear scan) remains a hypothesis, not a confirmed finding.
Salvaged via `strings -n 6` (blob Read cannot parse): 0xa726b10 is a PLT/GOT-style import thunk
(single indirect jump, FUN_0a726b10, body size 1), NOT a dispatcher; 0x38ba4d is .rodata strings, not a pointer table.
Serve error cluster @0x2fccae holds format templates (turn/unqueue, pending admission, UUIDv7, dispatch-failed). Nothing beyond the dump.

## 4. Portable rules (version-diff toolkit)

1. Detect methods by record layout ({0,0,slices…} + feff terminator).
2. Match methods by `name` slice bytes (`subagent/<verb>`), not position.
3. Group methods by shared `params` slice (Input/OwnerReason/Target).
4. Expect `CommandAcceptedResult` on every verb; a new result is change.
5. Hypothesize computed dispatch (base+index scan); empty xrefs are EXPECTED while analysis_complete=false and prove nothing — re-test after full analysis.
