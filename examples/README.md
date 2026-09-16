# Example: one coordinator turn

1. Coordinator admits the worker: `spark_submit` with objective, session
   ids, depth 0/2, capacity counters. Golden output:
   `spawn-commit.json` (commit fields + child record at `accepted`).
2. Coordinator steers: `spark_send` to the worker session with
   `queue_next_turn` + `wake_when_idle`. Golden record:
   `mailbox-note.json` (appended to `.spark/mailbox/<session>.jsonl`,
   admission stays `pending_admission` until the fold).
3. Worker finishes: `spark_result` validates the envelope. Golden:
   `result-envelope.json` (summary + refs; over-cap input is rejected,
   never cut).
4. Reviewer gates with the `spark-code-review` skill; coordinator
   integrates only on accept.

Retry rule everywhere: same commandId, never a new one.
