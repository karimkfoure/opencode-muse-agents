# 18 — Router Verdicts + Worktree Bind Protocol

Source: `agent_rpc_router` @0xc177520 (51 KB, skeleton mapped),
`rpc_exec_arm` @0xc179120 (25 KB, fan-out mapped),
`worktree_bind_commit` @0x6e2c6a0 (3 KB, full). Annotated + saved in
`ghidra/muse.gpr`. Decompilations in `re-tracks/decomp/`.

## Router: verdict-gated arms
Entry branches on signed verdict: `0` → copy 0x4b8 record, call exec
arm (`func_0x0c179120`); `1` → unpack 6-wide struct, flag-gated exec.
Exec arm fans to backend executors (`0xbf9xxx` trio, `0xb469860`,
`0xd6xxx`, `0xe3xxxx`). Method-name match lives in callees (SSE vector
compares at 0xc177684+), not in the router body.
PORT: verdict → copy → fan-out. Copy the record BEFORE exec so the
executor never mutates the inbound.

## Worktree bind: record + verify
36 B / 9-slot binding record, then validator verdicts `{0,1,3,4,0xff}`:
3/4 require follow-up calls (`0x07c89080`, shifts, frees), else the
verdict stands. Returns 0/1.
PORT: bind-then-verify. Verdicts 3/4 are "needs follow-up", not success.
Replicate the follow-up table, not just pass/fail.
