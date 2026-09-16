# 13 — Tool Slots + Worktree Placement

Source: `tool_apply_slot` @0x6462200 (919 B decomp), `worktree_place`
@0x6e85ac0 (3 KB decomp, full logic). Annotated + saved in
`ghidra/muse.gpr`. Decompilations: `re-tracks/decomp/tool_apply_slot.c`,
`re-tracks/decomp/worktree_place.c`.

## Tool slots: geometric growth, trap on OOM

`tool_apply_slot`: `new_cap = max(2*old, needed)`, small-class fast path
(`param_5 < 0x401 → ×3+1`), commit via `func_0x064d5b40`, failure →
`trap`. Called 8x while building the preset tool table.
PORT: tool-table vectors grow geometrically; allocation failure is fatal,
never degraded. Same append/grow discipline as records (track 10).

## Worktree placement: gate + 3 modes (full logic recovered)

```
if (req->mode(+0xd8) == -1) goto shared_tail;   // not requested
build 0x1b0 placement record; resolve source (+0x4b0/0x4b8/0x4c0);
validate via 0x076fd180;
join path under ".muse/worktrees" (len 15);
if (mode == 0) {          // shared
  copy 0x1e0 + 0x660 records; return;
}
if (mode > 0) {           // isolated: alloc mode bytes, copy identity
  alloc(mode); copy; join; copy 0x1e0 + 0x660; free temp; return;
}
// mode < 0: fail → cleanup@0x06cf9b20, plain 0x660 copy, return
```

PORT (`spark_worktree`): tri-state mode REQUIRED — `-1` off / `0`
shared / `>0` isolated with N identity bytes. Path ALWAYS under
`.muse/worktrees` (never bare `git worktree add` elsewhere). Record
shapes 0x1b0/0x1e0/0x660. Negative mode must run cleanup, not skip it.
Oversight in earlier tracks corrected: isolation is a mode VALUE, not
just a flag — the affirmative per-child request carries its identity
length.
