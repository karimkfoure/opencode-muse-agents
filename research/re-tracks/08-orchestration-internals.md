# 08 — Orchestration Internals Spec (from binary, via ghidra-rpc only)

Source: `x86_linux-1.3.0-R3057.1.bin` in isolated project
`ghidra/muse.gpr` (socket daemon, `--no-analyze` import, targeted
create-function + decompile only). No shared-server use, no MCP tools.
Prior slices: `07-ghidra-deep.md` (`msp_SubagentResult_desc` @0xa81b980,
fork machine `FUN_0556e5d0` @0x556e5d0). Decompilations retained in
`re-tracks/decomp/`. Annotations + `orchestration`/`error-catalog` tags
saved in the project DB (visible on GUI reopen).

## Recovered chain (addresses are vaddrs in x86_linux build)

### 1. Tool table: Rust `&str` fat-pointer array @0x1211cee0
Rows are 16 B `{ptr,len}`: `write_file`(10), … — the preset tool list
(`native-basic`: read_file/search/write_file/edit_file/…).
Consumer `tool_table_consumer` @0x65227e0 (67 KB decomp): iterates the
table with policy strings (workspace trust, approval bypass, capability
policy). Hot helper `func_0x06462200` (x8). PORT: preset = ordered
`&str` table + policy fold at apply time; tool identity is (ptr,len),
never bare pointer.

### 2. Spawn validation `subagent_spawn_validate` @0x7599130 (22 KB decomp)
Order (port verbatim):
1. Resolve handle via string-registry lookup (`DAT_06c60840`-class fn).
   Miss → fail-closed record, never proceed.
2. Status-word dispatch on record tag: `accepted` (0x6465747065636361)
   / `deferred` (0x6465727265666564) take the success arm;
   `rejected` (0x64657463656a6572) takes the rejection arm.
3. Inline capacity check: compares for `capacity` (0x7974696361706163)
   + `…_queue` (0x65756575715f7974) — the fan-out gate input.
4. Known error keys → `error_message_lookup` @0x759a200, then build the
   rejection record (`func_0x0759ab80` + `func_0x0757ca40` record writers).
5. Attach 0x80-byte context blob (`func_0x0759a580`) — carries
   worktree/isolation context on the spawn record.
PORT: validate → status dispatch → capacity → keyed errors → context
attach. Rejection records are built, not thrown.

### 3. Error catalog `error_message_lookup` @0x759a200
Pure `match (len-0xc, bytes) → message` switch: `fanout_limit…` →
`…fan-out limit…` @0x6fce82; `capacity…` → next message @0x6fce97; plus
~20 further arms incl. memcmp fallback arms (0x16/0x1b compare 0x22/0x27
bytes) and a jumptable tail. Callers: the validate function above
(0x75995d5/0x75995fe) + dispatch tail (0x759a6c3/0x759a6df).
PORT: centralize every spawn/steer refusal string behind one keyed
lookup; user text never constructed inline at call sites.

### 4. Owner control `owner_child_control` @0x75876a0 (full logic)
- `*ctl == 2` → empty control `{8,0,0}` (no-control fast path).
- Else resolve handle; miss → log (`UNK_006cd078` len 0x31 via table
  `UNK_121357f0`), invoke with owner table `UNK_1214ab00`
  (0x10-stride descriptor array @0x1214ab18–68), then trap `swi(3)`.
  Miss is fatal, never default-allow.
- Hit → load `{base+0x90, count+0x98 (0x10 stride), params+0xa0..0xac}`,
  then scan the 0x18-stride list and REMOVE the entry whose
  `[+0x10]==8 && *[+8]==0x776f6c666b726f77` ("workflow"). Memmove-close
  the gap. Return `{base,ptr,count}`.
- Callers found: 0x67b1d45, 0x6966ba6, 0x71d811f.
PORT: resolve → strip `workflow` entry → return triple. Replicate the
strip: owner commands must never carry the workflow control entry.

### 5. Approval judge
- `approval_judge_callsite` @0x6aff010: TLS-flag gated; walks candidate
  table `UNK_006c35d0` until one fires; returns 3 (early match) / 4
  (exhausted → human fallback). First-fire-wins ordering.
- `approval_decision_apply` @0xd2a6ebb: pure equality predicate —
  decisions equal iff `+8` bytes AND `+0x28` longs AND `+0x20` bytes
  equal. Dedupe/compare rule (never pointer equality).
- Verdicts do not survive restart without a durable `DecisionApplied`
  (strings track); judge is Prompt-bound only, cannot widen mode.
PORT: ordered candidates + equality predicate + durable record.

### 6. Mailbox (negative finding, high value)
`TBH_SESSION_MESSAGE_SOCKET` retired marker has NO direct code xrefs
(4 string sites, 0 callers) — consistent with the brokerless registry:
delivery is admission-folded, not socket-called. So the mailbox has no
single send-handler to clone; replicate as ledger behavior
(append → admission fold → wake-iff-idle), which matches the
`spark_send` mailbox-file design, not a socket.

### 7. Workflow journal sites
Table entry @0x12211330–48 referenced from 0xc15073c, 0xc17c4de
(`workflow_journal_site` @0xc17c0a0, created+renamed, decomp pending),
0xc17fd25. Three call sites = record/append/read paths. Next slice.

## Method (reusable without analysis)
`fileoff → vaddr = fileoff + 0x200000`. Exact LEA scan (REX.W + modrm
`…05`) for string vaddrs → caller addrs; `E8`-scan for function callers;
pointer-table scan in `.data.rel.ro` for `{ptr,len}` `&str` arrays, then
refs-to-table. Backward `55 48 89 e5` scan for function starts.
`create-function` + `decompile` + `rename`/`set-comment`/`tag-function`
+ `save`. Nothing here required auto-analysis.

## Remaining slices (ordered)
1. `workflow_journal_site` decomp (created, not yet read).
2. `owner_child_control` callers (0x67b1d45/0x6966ba6/0x71d811f) — who
   drives owner commands (wire handler vs model-tool path).
3. `func_0x06462200` (tool-table hot helper x8) — likely per-tool apply.
4. Steering-intake cluster (0x4c71e8d+) and hydrate cluster
   (0x7751df3+) — same treatment once 1–3 settle.
5. Turn machine + serve loop — last; needs the most context.
