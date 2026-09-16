# 19 — Steering Intake Path (dispatcher → arm → executor)

Source: `intake_dispatcher` @0x5a1fb80, `steering_intake_arm` @0x5a200e6
(kind[8] arm of jumptable @0x66be1c), `intake_executor` @0x79ba800.
Annotated + saved in `ghidra/muse.gpr`. Decompilations in
`re-tracks/decomp/intake_{dispatcher,executor}.c`,
`steering_intake_arm.c`.

## Dispatcher: kind-indexed jump, 16 arms
`jump(table[kind-2])`, no if-chains. Intake vocabulary
(@0x673758): settled, subagent_steering, conversation_rewind,
session_name, session_start, turn_submit, direct_user_carrier,
turn_queue_submit, run_retract, side_chat, … — steering ≈ kind[8].
PORT: dispatch intakes by numeric kind through one table.

## Steering arm: 4-pair record
`{SessionCommandIntakeCommand(27), SubagentSteering(16),
kind(4), subagent_steering(17)}` built on stack, then executor.
PORT: steering record shape verbatim (type+kind tags included —
never a bare body string).

## Executor: ordered keyed takes + append
resolve-ctx (`0x6e1c8a0`) → take(`verb`,4) → take(`subagent_id`,11) →
take(`body`,4) → take(`reason`,6) → append (`DAT_0ff4b870`).
Any stage `-2` → fail pair `{0xff, err}`; `lStack_98 == -3` also fails.
PORT: take order verb → subagent_id → body → reason; fail pair
`{0xff, err}`; `-3` sentinel also fails. This is the sendMessage /
followupTask intake both owner and model paths share.
