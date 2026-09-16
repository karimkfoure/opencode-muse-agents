---
description: Execute the accepted Spark plan with background workers.
---

Execute the accepted plan: admit each worker through spark_submit
(capacity, lineage, keyed errors), fan out with one worktree per worker,
steer only through mailbox notes with closed delivery policies, collect
bounded result envelopes, gate every result through spark-reviewer, and
integrate only verified work in this session.

Retry rule: same commandId to reconcile, never a new one. Fail closed on
unknown terminals, stale generations, and non-idle resume targets.
