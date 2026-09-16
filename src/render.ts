/**
 * render.ts — progressive streaming render rules.
 *
 * Position classes (fold_iterator @0x772a830, magic prefixes
 * "stream"/"first"/"last"): first shows displayText early, stream
 * carries deltas, last is authoritative. Completed text always wins
 * over deltas. Cursor advances only at fold commits, never on acks.
 */

import { classifyPosition, type FoldPosition } from "./fold";

export interface StreamPart {
  text: string;
  terminal: boolean;
  position: FoldPosition;
}

/** Display text for progressive rendering from a part sequence. */
export function progressiveDisplay(parts: StreamPart[]): string {
  const completed = parts.filter((p) => p.terminal);
  if (completed.length > 0) return completed[completed.length - 1].text;
  const firsts = parts.filter((p) => p.position === 1);
  if (firsts.length > 0) return firsts[0].text;
  return parts
    .filter((p) => p.position === 0)
    .map((p) => p.text)
    .join("");
}

/** Cursor advances only when the fold committed. */
export function advanceCursor(committed: boolean, cursor: string, next: string): string {
  return committed ? next : cursor;
}

export { classifyPosition };
