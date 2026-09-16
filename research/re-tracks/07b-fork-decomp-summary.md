# 07b — FUN_0556e5d0 fork-materialization path: decomp summary

Source: `tool_0a6ac56f1001iOyqG1MsRPdp3n` (decomp, 2099 lines / 91940 chars,
`WARNING: Type propagation algorithm not settling`); disasm
`tool_0a6ac037b001XUcIMs3OhumYKn` (first 8192 B, 0x556e5d0–0x55705cf, 1000 insns, no RET in window).

## 1. Signature (as decompiled)

```c
void FUN_0556e5d0(long *******param_1, long *******param_2,
                  long *******param_3, long *******param_4)
```

Void return; 4 opaque 7-level `long*` context/borrow/blob params.
~0x1738 B stack frame (`SUB RSP,0x1000` + `SUB RSP,0x738`; ~150 `Stack_*`
7-level-pointer spills + XMM/flag temporaries). Types never settle: all
locals are `long *******` + `undefined1[16]` vector slots (Rust
`Option<Arc<T>>` / enum layouts after monomorphization, most likely).

## 2. Keyword string literals: NONE

Case-insensitive verbatim search for `fork|checkpoint|replay|materializ|
branch|approval|lease|worktree` = **0 hits in decomp, 0 hits in disasm
window**. Decomp contains **zero C string literals at all**
(`"..."` count = 0); all names/strings are out-of-line (DAT_/GOT
indirects, `UNK_00660c56/00667898/121075c0/121075e0`, param-passed blobs).

## 3. Callees called more than twice (decomp counts; disasm window agrees)

- `LOCK()` x32 / `UNLOCK()` x32 — paired `Arc` refcount inc/dec critical
  sections (NOT functions; every `*p = *p + 1/-1` is wrapped).
- `DAT_04732840` x18 indirect — 3-arg `(ptr,len,1)` dealloc/free, dominates
  the `LAB_0556fd83→fdf1` tail cleanup.
- `DAT_120846f0` x14, `DAT_120cba68` x11 indirect — alloc/combinator + 0x88-B
  struct writer (`(auStack_470,&iStack_fd8,0x88)`).
- `DAT_0f75f870` x6 / `DAT_0f75f930` x6 — paired Arc-drop/dtor on the two
  words of the 16-B result (`&uStack_758` / `&uStack_750`).
- `func_0x058497e0` x7 — per-stage dispatch/build
  `(obj,slot,&tmp,&Stack_f88)`; hottest direct helper.
- `func_0x064e4160` x5 — result-merge `(&uStack_bc8,obj,&tmp)`.
- `func_0x053530f0` x5 / `func_0x05354f00` x4 — complementary
  ok/err cleanup arms on status word (`-2`/`-1` test of `uStack_bc8`).
- `func_0x055715c0` x3 — error-box finalizer (`&iStack_fd8`).
- Disasm PLT/GOT (first 8 KiB only): `[0x124447e0]` x8, `[0x12444628]` x5,
  `[0x124445f8]` x5. Tracing-span `func_0x05462db0` appears only **x1**
  (`(Var8,&Stack_f88,&UNK_00660c56,0x1c)`), so it misses the >2 cut.
- `SUB161/SUB81/CONCAT71/17/25/41/44/SCARRY8` (120/31/30/23/23/23/19/18x)
  are decompiler intrinsics, not calls.

## 4. Loop/exit structure (one paragraph)

Decomp text shows `for=4 while=10 do=5 goto=43 if=125`; the "34 loops" of
the CFG metric counts disasm back-edges (XMM `MOVUPS/MOVDQU` block-copy
unrolls + `while(true)` state-machine dispatch at ll.334/422/1915), not
source loops. The only true counted loops are 4 textually identical
bit-scan normalizers `for(uVar14=uVar35;(uVar14&1)==0;uVar14=uVar14>>1|
0x80000000)` (ll.370/458/806/1940), each nested in a
`while(uVar37!=0)` tag/flag drain; everything else that "iterates" is
straight-line: sequential `Arc`-slot bumps over refcount tables at
`obj+0x1b06–0x1b0e` and `0x1df3–0x1df6`, 16-B XMM vector copies through
`auStack_*`, and status-word (`uStack_bc8/iStack_fd8 ∈ {-2,-1,0}`) dispatch
via gotos. There is exactly one function exit: the `void return` tail at
ll.2089–2097 reached through `joined_r0x0556f5cc → joined_r0x0556f94a →
LAB_0556fd83 → LAB_0556fdf1`; all early paths funnel through that shared
free-chain (`DAT_04732840` on `param_2[1,4,8]` + `DAT_0e2c5090` + `05b55930`)
rather than returning directly.

## 5. Length/capacity comparisons and trap paths

No `512/0x200/32768` anywhere; `0x8000` (7x) occurs only inside the
`0x80000000` rotate and the `0x8000000000000001` niche/`None` sentinel
(ll.1510/1632/1782); `0x1c` (1x) is the span-metadata length arg to
`func_0x05462db0`, not a capacity check. Real bounds are field offsets and
status codes: `param_2+0x81` null test, `param_2+0xbfe0/bfc8`, `R14+0x50`,
struct size `0x88`, sentinel compares against `-2/-1/0/
0xffffffffffffffff`. Every `Arc` increment is guarded by
`if (*p==0 || SCARRY8(old,1) != new<0) goto LAB_05570eef` (~20 sites,
ll.1138–1541); `LAB_05570eef` (l.1373) is the sole trap:
`invalidInstructionException()` marked `/* WARNING: Does not return */`.
No other abort/panic/exit call exists in the decomp.
