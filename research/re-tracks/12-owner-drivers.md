# 12 — Owner-Command Drivers (who drives owner commands)

Source: 3 CALL-code callers of `owner_child_control` @0x75876a0,
decompiled via ghidra-rpc, renamed + saved in `ghidra/muse.gpr`.
Decompilations: `re-tracks/decomp/owner_driver_{A,B,C}.c`
(final names below).

## The three drivers

1. `owner_control_default` @0x67b1d30 (385 B decomp): thin wrapper —
   resolve control, optional finalize via `func_0x07abbdc0` when flag==0,
   return the triple. The DEFAULT path (wire `subagent/*` steady state).
2. `owner_control_replace_idle` @0x6966b40 (3.8 KB): guarded path — only
   resolves when control state is idle/empty (`[3]==0 && [2]==0`); frees
   the old 0x18-stride array, installs the fresh triple. The
   REPLACE-ON-IDLE path (resume/reopen/re-readResult semantics).
3. `owner_command_pipeline` @0x71d80c0 (54 KB): full pipeline — resolve,
   run stages `0x75875b0` (init) / `0x75885d0` (fill, x3 call sites) /
   `0x75882d0` (seal, x2), build 0x1f-stride (248-byte) outcome rows,
   commit via `func_0x07c7ec00` (x5). The MODEL-TOOL path (spawn,
   followupTask — wide outcome records).

## PORT (answers "wire handler vs model-tool path")

Both paths exist and converge on `owner_child_control`:
- Wire owner commands (`sendMessage/interrupt/stop/close/resume/
  reopen/readResult`) → driver 1, or driver 2 when the child is
  idle/recoverable. No new record width beyond the triple.
- Model-tool spawn/followup → driver 3, producing 248-byte outcome rows
  committed last. Spawn cost lives here, not in validation (track 08).
- Enforce the idle gate of driver 2 in `spark resume/reopen`:
  refuse when control state is non-idle/non-empty instead of
  overwriting (matches `sessionInUse`-style fail-closed behavior).
