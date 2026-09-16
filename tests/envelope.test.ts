import { describe, expect, test } from "bun:test";
import {
  RESULT_TEXT_MAX_BYTES,
  SUMMARY_MAX_CHARS,
  byteLength,
  scalarLength,
  validateBody,
  validateSubagentId,
  validateSubagentResult,
} from "../src/envelope";

describe("scalarLength vs byteLength", () => {
  test("ASCII: equal", () => {
    expect(scalarLength("hello")).toBe(5);
    expect(byteLength("hello")).toBe(5);
  });
  test("multibyte: scalars != bytes (summary counts scalars, text counts bytes)", () => {
    const s = "é🤖";
    expect(scalarLength(s)).toBe(2);
    expect(byteLength(s)).toBe(6);
    expect(s.length).toBe(3); // UTF-16 units are neither
  });
});

describe("validateBody", () => {
  test("trims ends, keeps interior", () => {
    const r = validateBody("  hello   world  ");
    expect(r.ok).toBe(true);
    if (r.ok) expect(r.trimmed).toBe("hello   world");
  });
  test("rejects empty after trim (spaces, tabs, newlines, unicode)", () => {
    for (const bad of ["", "   ", "\t\n ", " 　"]) {
      const r = validateBody(bad);
      expect(r.ok).toBe(false);
      if (!r.ok) expect(r.issue.key).toBe("empty_after_trim");
    }
  });
  test("multibyte content passes through byte-intact", () => {
    const body = "  héllo 🤖 wörld  ";
    const r = validateBody(body);
    expect(r.ok).toBe(true);
    if (r.ok) {
      expect(r.trimmed).toBe("héllo 🤖 wörld");
      expect(byteLength(r.trimmed)).toBe(byteLength("héllo 🤖 wörld"));
    }
  });
  test("rejects non-strings", () => {
    // @ts-expect-error intentional
    expect(validateBody(undefined).ok).toBe(false);
  });
});

describe("validateSubagentId", () => {
  test("accepts opaque ids", () => {
    expect(validateSubagentId("child-01").ok).toBe(true);
  });
  test("rejects empty", () => {
    expect(validateSubagentId("").ok).toBe(false);
  });
});

describe("validateSubagentResult", () => {
  const base = {
    summary: "did the thing",
    artifactRefs: ["a.txt"],
    evidenceRefs: ["runs/1/result.json"],
  };
  test("accepts a valid envelope with all optionals", () => {
    const r = validateSubagentResult({ ...base, text: "details", structuredData: { n: 1 }, errorKind: "none" });
    expect(r.ok).toBe(true);
  });
  test("summary cap is 512 CHARS not bytes", () => {
    const wide = "é".repeat(SUMMARY_MAX_CHARS); // 1024 bytes, 512 scalars
    expect(validateSubagentResult({ ...base, summary: wide }).ok).toBe(true);
    const over = "é".repeat(SUMMARY_MAX_CHARS + 1);
    const r = validateSubagentResult({ ...base, summary: over });
    expect(r.ok).toBe(false);
    if (!r.ok) expect(r.issues[0].key).toBe("summary_too_long");
  });
  test("text cap is 32 KiB BYTES", () => {
    const okText = "x".repeat(RESULT_TEXT_MAX_BYTES);
    expect(validateSubagentResult({ ...base, text: okText }).ok).toBe(true);
    const big = "x".repeat(RESULT_TEXT_MAX_BYTES + 1);
    const r = validateSubagentResult({ ...base, text: big });
    expect(r.ok).toBe(false);
    if (!r.ok) expect(r.issues[0].key).toBe("text_too_large");
  });
  test("multibyte text near the byte cap", () => {
    const s = "🤖".repeat(RESULT_TEXT_MAX_BYTES / 4); // exactly 32 KiB
    expect(byteLength(s)).toBe(RESULT_TEXT_MAX_BYTES);
    expect(validateSubagentResult({ ...base, text: s }).ok).toBe(true);
  });
  test("missing refs fail, and issues accumulate", () => {
    // @ts-expect-error intentional
    const r = validateSubagentResult({ summary: "x".repeat(600) });
    expect(r.ok).toBe(false);
    if (!r.ok) {
      const keys = r.issues.map((i) => i.key).sort();
      expect(keys).toEqual(["missing_refs", "summary_too_long"]);
    }
  });
  test("never truncates: over-cap input is rejected, not cut", () => {
    const r = validateSubagentResult({ ...base, summary: "y".repeat(513) });
    expect(r.ok).toBe(false);
  });
});
