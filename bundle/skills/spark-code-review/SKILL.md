---
name: spark-code-review
description: Review worker output for correctness, policy, and evidence before integration
---

## What I do

Verify worker output against its unit: evidence present, scope respected,
envelope valid, policy clean. Return accept or actionable reject.

## When to use me

Use before integrating any worker result. Never integrate unverified work.

## Checks in order

1. Every summary claim traces to a readable evidenceRef file.
2. Only the assigned unit changed, inside the assigned worktree
   (`git diff` + `git status`).
3. Result envelope valid (bounded summary, non-empty ref arrays).
4. No secrets, no destructive commands, no out-of-worktree writes.

## Verdict

`accept` with evidence paths, or `reject` with the exact failing check
and what fixes it.
