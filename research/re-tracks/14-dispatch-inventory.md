# 14 — Wire Dispatch Table Layout + Inventory Proof

Source: `.data.rel.ro` scan 0x121b0000–0x121b7000 for 32 B rows
`{name_ptr,name_len,desc_ptr,desc_len}` + 94 `read-bytes` name reads via
ghidra-rpc. Saved in `ghidra/muse.gpr`.

## Layout

- Two runs: 0x121b0260–0x121b1c00 (stable, 0x922xxx strings) and
  0x121b4100–0x121b4d60+ (experimental, 0x966xxx strings). Both bundles
  baked separately — matches the two `muse schema` exports byte-wise.
- Rows also include cross-links (name→name) and result-type names
  (`CommandAcceptedResult` x6 refs as the universal ack).
- Access is base+index computed: ZERO direct code xrefs to any row in
  the whole .text (verified for 10 row addresses). The dispatcher cannot
  be found by xref hunting — it indexes the table arithmetically.

## Inventory proof

Every wire name resolves exactly 2x (one per bundle): all 8
`subagent/*`, `session/fork|compact|resume|userShell|rename`,
`turn/start|steer|unqueue`, `task/background`, `workflow/cancel`,
`goal/edit`, `view/page|subscribe`, `RequestReceipt`, `rawLog`,
`account/*`. NO hidden third bundle, NO extra methods beyond the
exported schema. The `msp.schema.json` files are the complete,
authoritative wire surface — proven from the binary, not trusted
from docs.

## Consequence for remaining code hunts

`resultReady`-fold transition, steering-intake append, and serve-loop
sites are unreachable by static xref (computed dispatch + indirect
calls throughout). Paths forward, in order:
1. Bounded auto-analysis on the isolated daemon (function boundaries +
   refs for free; cost: long wall time on 243 MB .text even capped).
2. Dynamic tracing (needs credentials — unavailable).
3. Behavior-first port: implement from schema + record rules
   (tracks 01–13) and verify against a live host when available.
Track 01–13 rules do not depend on these sites.
