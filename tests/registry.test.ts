import { describe, expect, test } from "bun:test";
import {
  ROW_ABSENT,
  ROW_FENCED,
  appendRow,
  commitRow,
  createTable,
  normalizeKey,
  probeByKey,
  swapRow,
} from "../src/registry";

describe("normalizeKey", () => {
  test("trim + lowercase canonical spelling", () => {
    expect(normalizeKey("  Queue_Next_Turn ")).toBe("queue_next_turn");
  });
});

describe("table engine", () => {
  test("append returns indexes, probe finds normalized", () => {
    const t = createTable("m");
    expect(appendRow(t, ["Subagent_SendMessage", 20, "d", 21])).toBe(0);
    expect(appendRow(t, ["turn/start", 10, "d", 5])).toBe(1);
    expect(probeByKey(t, 0, "subagent_sendmessage")).toBe(0);
    expect(probeByKey(t, 0, "TURN/START")).toBe(1);
    expect(probeByKey(t, 0, "missing")).toBe(ROW_ABSENT);
  });
  test("swap out-of-range fails closed", () => {
    const t = createTable("m");
    expect(swapRow(t, 5, ["a", "b", "c", "d"])).toBe(false);
    appendRow(t, ["a", "b", "c", "d"]);
    expect(swapRow(t, 0, ["w", "x", "y", "z"])).toBe(true);
    expect(t.rows[0][0]).toBe("w");
  });
  test("commit appends when no key required", () => {
    const t = createTable("m");
    const r = commitRow(t, ["a", 1, 2, 3]);
    expect(r).toEqual({ committed: true, index: 0 });
  });
  test("commit with key swaps in place or refuses", () => {
    const t = createTable("m");
    appendRow(t, ["k", 1, 2, 3]);
    const ok = commitRow(t, ["k", 9, 9, 9], { keyIdx: 0, key: "K" });
    expect(ok).toEqual({ committed: true, index: 0 });
    expect(t.rows[0][1]).toBe(9);
    expect(commitRow(t, ["z", 1, 1, 1], { keyIdx: 0, key: "zzz" })).toEqual({
      committed: false,
      index: ROW_ABSENT,
    });
  });
  test("locked table refuses with FENCED", () => {
    const t = createTable("m");
    expect(commitRow(t, ["a", 1, 2, 3], { locked: true })).toEqual({ committed: false, index: ROW_FENCED });
  });
});
