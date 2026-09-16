# 07 — Ghidra Deep RE: Two Targeted Slices (x86_linux 1.3.0-R3057.1)

Method: separate project `muse_code_re` (NOT the m8 project), `load_program` headless
(x86:LE:64, image_base 0x200000, 304,933,251 B), `disassemble_bytes` on two
seed ranges only. No full auto-analysis (242 MB .text; hours + GBs). Evidence:
`~/.local/share/opencode/tool-output/tool_0a6ac037b001XUcIMs3OhumYKn` (8 KB disasm),
`tool_0a6ac56f1001iOyqG1MsRPdp3n` (94 KB decomp), `re-tracks/07b-fork-decomp-summary.md`.

CAUTION: this switched the shared Ghidra server off the m8 firmware program.
To restore: re-open project `m8_headless_652c` / reload
`/home/karim/dev/m8/teensy-emu/firmware/M8_V6_5_2C_HEADLESS.bin`
(ARM:LE:32:Cortex). Nothing m8-side was deleted; only the server's open
program changed. The muse work lives in project `muse_code_re`.

## Slice A — Schema descriptor builder FUN_0a81b980 (SubagentResult)

- Function: entry 0xa81b980, body 1,046 B, prologue `PUSH RBP; MOV RBP,RSP`,
  frame 0x88. Ends `RET` at 0xa81bd48, `INT3` pad, next function 0xa81bda0
  (same prologue — sibling descriptor, likely SubagentInputParams).
- Control flow: CC 29 (very high), 19 blocks, 46 edges, 236 insns, 12
  conditional branches, 0 loops, 32 calls, 1 return.
- Decompiled fully. Core pattern, repeated per field:
  `func_0x0a762a30(&buf, &UNK_0096a6dd, 0xb, &UNK_<field>, <tag>)`
  with tags 0x37, 0x25, 0x3f, 0x1e, 0x2f, 0x45 — field registrar
  (name-ptr + len 0xb + tag). Prologue writes magic tags
  `*p = 0x65707974` ("ty pe"), `*p = 0x656a626f` + `0x7463`.
- Strings at 0x96b1b1 packed back-to-back (verified via memory read):
  `Bounded result summary (<=512 chars, runtime-enforced).summary`,
  `Result text (<=32 KiB), when present.`, `Error kind, verbatim durable
  vocabulary…errorKind`, `Evidence references, verbatim.evidenceRefs`,
  `Artifact references, verbatim.artifactRefs` (+ `structuredData`).
- Failure arms call allocator-fail handlers then `swi(3)` trap.
- CONCLUSION for reimplementation: schema is baked as generated
  descriptor-builder tables; `muse schema` dumps them. Copy the exported
  JSON (`artifacts/schema/stable/msp.schema.json`), never the assembly.
  Validation caps (512 chars summary, 32 KiB text) live server-side in
  Rust, confirmed by strings + descriptor; exact enforcement site is Rust
  `SubagentResultEnvelope`, not recoverable further without symbols.

## Slice B — Fork materialization FUN_0556e5d0

- Function: entry 0x556e5d0, body 10,534 B (~8 KB past the seed xref),
  frame ~0x1738. Signature decompiled as
  `void (long******* x4)` — 4 opaque context/borrow params; types never
  settle (Rust monomorphized `Option<Arc<T>>` layouts). Type-propagation
  warning present.
- Control flow: CC 220 (extreme), 261+ blocks, 479 edges, 1,888 insns,
  162 conditional branches, 34 loop-headers (mostly XMM block-copy unrolls
  + `while(true)` state-machine dispatch, NOT source loops), 127 calls,
  exactly 1 return (all paths funnel through shared free-chain tail).
- Span confirmed at 0x5570676 (objdump + Ghidra agree):
  `LEA RDX,[RIP-…]` → 0x660c56 `session.fork.materialization`,
  `MOV ECX,0x1c` (28 = strlen), `CALL 0x5462db0` (tracing-span start).
  Memory read at 0x660c56 shows packed neighbors
  (`…approval reviewer route unavailable; using human approval…`),
  i.e. a dense message table, not isolated strings.
- Callee census (decomp): `LOCK/UNLOCK` x32/x32 (Arc inc/dec guards),
  dealloc `DAT_04732840` x18, alloc/combinator `DAT_120846f0` x14,
  Arc-drop pair `DAT_0f75f870/930` x6/x6, stage dispatch
  `func_0x058497e0` x7, result-merge `func_0x064e4160` x5. Zero C string
  literals in decomp (all out-of-line DAT_/GOT).
- Guards: ~20 Arc-increment sites `if (*p==0 || carry) goto LAB_05570eef`;
  sole trap `invalidInstructionException()` (no return). Bounds are
  structural (field offsets, status words -2/-1/0, `None` niche
  `0x8000000000000001`), NOT numeric caps — no 512/32768 anywhere.
  Only counted loops: 4 identical bit-scan normalizers.
- CONCLUSION for reimplementation: fork is an async state machine with
  checkpoint_tail vs full_replay branches (matches strings evidence
  `session.fork.materialization|compaction|model_prefix` and the cost
  model in `02-worktree-fork.md`: cut just after a compaction boundary
  is cheapest; fork-then-compact pays twice). `spark_fork` should prefer
  post-boundary cuts and treat `history.mode` downgrade as normal.

## Xref methodology (reusable without Ghidra)

`fileoff → vaddr = fileoff + 0x200000` (.rodata base 0x201000 @ 0x1000).
Strict REX.W-LEA scan finds exact refs (fork span x6, bounded_summary x1);
broad ±512 scan finds clusters (steering 220, hydrate 100, worktree 88,
fork 210, journal 104, summary 68 — mostly neighbor-string noise in the
dense table). Function starts via backward `55 48 89 e5` scan
(bounded 0xa81b980 @ -0x18a; fork 0x556e5d0 @ -0x20a6). No CET endbr64
markers in this build.

## What Ghidra did NOT need to answer

Trim semantics, envelope caps, lease/quarantine rules, mailbox ordering —
all already fixed by schema + strings (tracks 01–03). Further Ghidra on
steering/worktree/approval slices would confirm but not change the
`spark_*` validation code. Next Ghidra step only if a runtime behavior
contradicts the schema (e.g. a fork that fails on a valid cut).
