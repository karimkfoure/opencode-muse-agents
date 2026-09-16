# 17 — Spawn Commit (writer + fenced path)

Source: `spawn_commit_writer` @0x6d3d050 (700 B, full),
`spawn_commit_fenced` @0x6de2a10 (20 KB, head + callees mapped).
Annotated + saved in `ghidra/muse.gpr`. Decompilations in
`re-tracks/decomp/spawn_commit_{writer,fenced}.c`
(site2 file = fenced).

## Writer (fast path)
Table-driven prover (`func_0x052e7150`, 6-field table @0x12137f80,
tag len 0x16) → on success copy the 0x420 (1056 B) record → transform
(`DAT_0ecb3f40`) → output. On failure: `phase_step_emit` fallback,
return `{-1, emit}`. Commit never returns partial state.

## Fenced path (generation-guarded)
Gate: `*param_1 == -2` (fenced marker) + 0x1e-key match → construct
with size COMPUTED from present optional fields:
`has(0x218) - zero(0x3c8) + 4 + has(0x3b0)`, tagged AgentSpawnCommitV1.
Then the 0x6e1–0x6e2 worktree helpers bind the worktree and 0x6d0/0x6dcc
subagent helpers attach the child; every gate returns 0 on miss
(fail-closed ladder, ~8 early exits before any write).

## PORT corrections vs earlier tracks
- Commit record size is ADAPTIVE (presence-weighted), not fixed. The
  0x1b0/0x1e0/0x660/0x420 shapes are per-stage buffers; final commit =
  computed. Size the spark commit record from present fields.
- Fenced (`-2`) commits are a separate entry path with key match, not a
  flag on the normal path. Route fenced resumes through it.
- Spawn binds worktree INSIDE the commit (0x6e helpers called before
  return), not as a separate step after. Order: validate → commit
  (incl. worktree bind) → attach → return. Never bind-then-commit.
