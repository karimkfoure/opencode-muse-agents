import { describe, expect, test } from "bun:test";
import {
  ITEM_FIELD_ORDER,
  MemoSlots,
  POS_FIRST,
  POS_LAST,
  POS_OTHER,
  POS_STREAM,
  RESULT_FIELD_ORDER,
  SLOT_ABSENT,
  classifyPosition,
  emitNeedsAlloc,
  reemitInOrder,
} from "../src/fold";

describe("classifyPosition", () => {
  test("stream/first/last/other by prefix", () => {
    expect(classifyPosition("stream_delta")).toBe(POS_STREAM);
    expect(classifyPosition("first_message")).toBe(POS_FIRST);
    expect(classifyPosition("last_turn")).toBe(POS_LAST);
    expect(classifyPosition("middle")).toBe(POS_OTHER);
  });
});

describe("field orders (verbatim)", () => {
  test("item order starts turnId/itemId/toolCallId/viewCursor", () => {
    expect(ITEM_FIELD_ORDER.slice(0, 4)).toEqual(["turnId", "itemId", "toolCallId", "viewCursor"]);
  });
  test("result order leads with usage", () => {
    expect(RESULT_FIELD_ORDER[0]).toBe("usage");
    expect(RESULT_FIELD_ORDER).toContain("displayText");
  });
});

describe("MemoSlots", () => {
  test("absent sentinel, memoize, lookup", () => {
    const m = new MemoSlots();
    expect(m.lookup("viewCursor")).toBe(SLOT_ABSENT);
    expect(m.has("viewCursor")).toBe(false);
    m.memoize("viewCursor", 7);
    expect(m.lookup("viewCursor")).toBe(7);
    expect(m.has("viewCursor")).toBe(true);
  });
});

describe("reemitInOrder", () => {
  test("fixed order, skips absent", () => {
    const out = reemitInOrder({ content: "c", turnId: "t", extra: 1 }, ITEM_FIELD_ORDER);
    expect(out).toEqual([
      ["turnId", "t"],
      ["content", "c"],
    ]);
  });
});

describe("emitNeedsAlloc", () => {
  test("low bit clear = inline", () => {
    expect(emitNeedsAlloc(4)).toBe(false);
    expect(emitNeedsAlloc(5)).toBe(true);
  });
});
