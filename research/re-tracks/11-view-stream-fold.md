# 11 — View Stream Fold (streaming parser)

Source: `view_stream_fold` @0x6d98ea0 (27 KB decomp), 5–8 direct
`viewCursor` refs in 0x6d99xxx–0x6d9bxxx, field vocabularies read
verbatim. Annotated + saved in `ghidra/muse.gpr`.

## Fold architecture

Tag-switched streaming parser over the event log. Per-field memo slots
(`uStack_50/90/a0/98…`) with sentinel `0xffffffffffffffff` = absent:
first occurrence parses via `func_0x07731a70` / `func_0x077311e0`
(zero-copy address capture) and caches; repeats reuse the cached
address. Output re-emits field tags from the fixed vocabularies
(assembled byte/short/int codes at `code_r0x06d99c21`).

## Fixed field orders (verbatim)

Item/view event:
`turnId itemId toolCallId viewCursor sourceRange questions label
preview format content uri mediaType …`
(@0x6d4646 len ~50, @0x6d4666 continuation.)

Result envelope (wire order — usage FIRST):
`usage durationMs resultRef recordedAt fallbackText displayText …`
(@0x6d4720/0x6d4725.)

Rewind/blocked record:
`reason count blocked` + `internally tagged enum RewindCapabilit[y]`
(@0x6d379c).

## PORT (streaming/feel parity)

1. Memo slots with -1 sentinel per folded field; parse once, reuse.
2. Re-emit in the exact orders above — client rendering (deltas →
   completed) depends on order, not just presence.
3. `usage` leads every result envelope (budget UI reads it first).
4. Cursor advance points are the fold commits, not the ack receipts
   (consistent with track 07: ack ≠ outcome).
5. `fallbackText`/`displayText` trail the result — progressive rendering
   contract: show displayText early, treat completed text authoritative.
