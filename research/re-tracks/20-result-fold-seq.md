# 20 — Attempt-Result Fold Sequence

Source: objdump call/LEA map of `attempt_result_fold` @0xc721eb0
(decompiler timed out — too large; sequence recovered statically).
Annotated + saved in `ghidra/muse.gpr`.

## Sequence (in order)
1. Anchor tables: `0x11be74b`, `0x11b9e70`, `0x26a46c` (kind), calls
   `0xc3d1d40`, `0xc2cf9b0`, `0xb71e570` (open/validate phase).
2. Tables `0x12211938/48`, call `0xdf071e0`, `0xc257450`.
3. `0xdce8e70` + `0x2950fd`, calls `0xde775f0`, `0xe3832f0`.
4. Core loop (4x unrolled): `LEA base 0x11be6b1` + `LEA field
   (0x11be7a0/78b/77c/7b2/…)` + `CALL 0xb74bb50` applier, each followed
   by a per-field `0xb84xxx` helper
   (fcb0/c990/e770/507e0/d550/f270).
5. Commit: `LEA 0x122074a8` + indirect allocator/memcpy PLT calls
   (`0x12444610`, `0x124445f8`), twice (record + mirror).

## PORT
Result fold = table-order field apply (base + field + applier,
unrolled) with per-field helpers, then allocator commit of record +
mirror. Field order is the table order — same rule as the view fold
(track 11). The applier/handler addresses are build-specific; the
ORDER and the apply-then-commit shape are what port.
