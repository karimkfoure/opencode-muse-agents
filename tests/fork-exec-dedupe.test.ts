import { describe, expect, test } from "bun:test";
import { isDuplicateReceipt } from "../src/fork";

describe("isDuplicateReceipt", () => {
  test("dup found: returns true when a line carries the same commandId", () => {
    const text =
      `${JSON.stringify({ ok: true, commandId: "cmd-1" })}\n` +
      `${JSON.stringify({ ok: true, commandId: "cmd-2" })}\n`;
    expect(isDuplicateReceipt(text, "cmd-2")).toBe(true);
  });

  test("absent: returns false when no line carries the commandId", () => {
    const text =
      `${JSON.stringify({ ok: true, commandId: "cmd-1" })}\n` +
      `${JSON.stringify({ ok: true, commandId: "cmd-2" })}\n`;
    expect(isDuplicateReceipt(text, "cmd-9")).toBe(false);
  });

  test("malformed skipped: bad lines never match and never throw", () => {
    const text = `not json at all\n{truncated\n${JSON.stringify({ ok: true, commandId: "cmd-1" })}\n`;
    expect(isDuplicateReceipt(text, "cmd-1")).toBe(true);
    expect(isDuplicateReceipt(text, "cmd-missing")).toBe(false);
    expect(isDuplicateReceipt("garbage{{\n[[[\n", "cmd-1")).toBe(false);
  });

  test("empty text never matches", () => {
    expect(isDuplicateReceipt("", "cmd-1")).toBe(false);
    expect(isDuplicateReceipt("\n   \n", "cmd-1")).toBe(false);
  });
});
