# 16 — Owning Helpers Batch (record writers, cleanup, commit, parse)

Source: 5 small functions via ghidra-rpc, all annotated + saved in
`ghidra/muse.gpr` (`orchestration` tag). Decompilations:
`re-tracks/decomp/{spawn_rec_writer,record_alloc_write,worktree_cleanup,pipeline_commit,fold_field_parse}.c`.

## spawn_rec_writer @0x759aa20
Resolve (`0x07b3e040`) → alloc-retry loop (trap on persistent OOM) →
anchor write (`UNK_006f6ad3`) → commit (`0x0759ae00`) → free temp
(16 B rows) → temp freed post-commit. `-1` = failure.
PORT order: resolve → retry-alloc → anchor → commit → free-temp.

## record_alloc_write @0x757c880
Gated writer returning triple-or-`-1`: kind `0xf` requires
reminder/snooze magic match; kind `0xb` requires tool_search/create
magic match (`0x07577290` prover, `-1` = unproven). Mismatch → `-1`,
never a partial write.
PORT: gate every record write on (kind, magic); unproven → `-1`.

## worktree_cleanup @0x6cf9a90
Frees owned slots `[0..1]`, `[3..4]`, and `[6..7]`/`[9..10]` unless
sentinel: `-2` = fenced (skip whole tail), `-1`/`0` = empty (skip slot).
PORT: cleanup honors the `-2` fence — never free fenced slots; free
exactly owned slots, nothing else.

## pipeline_commit @0x7c7eba0
Walks count @+0x10 over 24 B rows from +8, freeing non-null superseded
payloads (`ptr[-1] != 0` → free). Commit = release of replaced rows.
PORT: publish-then-release; commit walks and frees replaced payloads.

## fold_field_parse @0x7731a10
Flag @+0x48: `-1` (unset) → emit default record via `phase_step_emit`
+ return accept(1). Set → copy bitfield window (+0x49..+0x64),
delegate to `0x073ec410`, return `result & 1`.
PORT: unset field = default-accept, not error. Delegate verdict is a
single bit.
