/**
 * fold.ts — streaming fold with memory.
 *
 * Per-field memo slots (absent = -1 sentinel, the i64 reading of the
 * binary's 0xffffffffffffffff): parse once, reuse. Fixed re-emit field
 * orders. Result envelopes lead with usage. Position classes
 * (fold_iterator @0x772a830, magic prefixes "stream"/"first"/"last"):
 * stream=0 (deltas) / first=1 (display early) / last=2 (authoritative) /
 * other=3. Keyed emit funnels through one primitive
 * (fold_keyed_emit @0x6a8f9e0, tagged-pointer low bit = alloc).
 */

export const SLOT_ABSENT = -1;

export type FoldPosition = 0 | 1 | 2 | 3;
export const POS_STREAM: FoldPosition = 0;
export const POS_FIRST: FoldPosition = 1;
export const POS_LAST: FoldPosition = 2;
export const POS_OTHER: FoldPosition = 3;

/** Classify a fold position by field-name prefix (last/first/stream). */
export function classifyPosition(field: string): FoldPosition {
  if (field.startsWith("stream")) return POS_STREAM;
  if (field.startsWith("first")) return POS_FIRST;
  if (field.startsWith("last")) return POS_LAST;
  return POS_OTHER;
}

/** Item/view event re-emit order (verbatim). */
export const ITEM_FIELD_ORDER: readonly string[] = [
  "turnId",
  "itemId",
  "toolCallId",
  "viewCursor",
  "sourceRange",
  "questions",
  "label",
  "preview",
  "format",
  "content",
  "uri",
  "mediaType",
];

/** Result envelope wire order — usage FIRST. */
export const RESULT_FIELD_ORDER: readonly string[] = [
  "usage",
  "durationMs",
  "resultRef",
  "recordedAt",
  "fallbackText",
  "displayText",
];

/** Memo slot table: field -> slot index; absent fields hold SLOT_ABSENT. */
export class MemoSlots {
  private slots = new Map<string, number>();

  memoize(field: string, index: number): void {
    this.slots.set(field, index);
  }

  lookup(field: string): number {
    return this.slots.get(field) ?? SLOT_ABSENT;
  }

  has(field: string): boolean {
    const v = this.slots.get(field);
    return v !== undefined && v !== SLOT_ABSENT;
  }
}

/** Re-emit fields in a fixed order, skipping absent ones. */
export function reemitInOrder(
  record: Record<string, unknown>,
  order: readonly string[],
): [string, unknown][] {
  const out: [string, unknown][] = [];
  for (const key of order) {
    if (key in record && record[key] !== undefined) out.push([key, record[key]]);
  }
  return out;
}

/** Tagged-pointer emit input: low bit clear = inline, else alloc-copy. */
export function emitNeedsAlloc(tagged: number): boolean {
  return (tagged & 1) !== 0;
}
