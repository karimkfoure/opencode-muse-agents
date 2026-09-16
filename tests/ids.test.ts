import { describe, expect, test } from "bun:test";
import {
  canonicalEventId,
  dedupeKey,
  dedupeKeyHex,
  isCanonicalEventId,
  isGenerationStale,
  mintCommandId,
  parseCanonicalEventId,
} from "../src/ids";

describe("mintCommandId (UUIDv7)", () => {
  test("mints canonical 36-char ids", () => {
    const id = mintCommandId(1_700_000_000_000);
    expect(isCanonicalEventId(id)).toBe(true);
    expect(id.length).toBe(36);
  });
  test("embeds unix_ms in the first 48 bits", () => {
    const ms = 1_700_000_000_123;
    const b = parseCanonicalEventId(mintCommandId(ms));
    let t = 0;
    for (let i = 0; i < 6; i++) t = t * 256 + b[i];
    expect(t).toBe(ms);
  });
  test("version nibble is 7 and variant is 10xxxxxx", () => {
    const b = parseCanonicalEventId(mintCommandId());
    expect(b[6] >> 4).toBe(7);
    expect(b[8] >> 6).toBe(2);
  });
  test("two mints differ", () => {
    expect(mintCommandId()).not.toBe(mintCommandId());
  });
});

describe("canonicalEventId", () => {
  test("16 zero bytes -> 00000000-0000-0000-0000-000000000000", () => {
    expect(canonicalEventId(new Uint8Array(16))).toBe("00000000-0000-0000-0000-000000000000");
  });
  test("hyphen positions 8-4-4-4-12 with lowercase hex", () => {
    const b = Uint8Array.from({ length: 16 }, (_, i) => (i * 17 + 171) & 0xff);
    const s = canonicalEventId(b);
    expect(s[8]).toBe("-");
    expect(s[13]).toBe("-");
    expect(s[18]).toBe("-");
    expect(s[23]).toBe("-");
    expect(s).toBe(s.toLowerCase());
    expect(s.length).toBe(36);
  });
  test("round-trips through parse", () => {
    const b = Uint8Array.from({ length: 16 }, (_, i) => (i * 31 + 7) & 0xff);
    expect(parseCanonicalEventId(canonicalEventId(b))).toEqual(b);
  });
  test("rejects wrong length", () => {
    expect(() => canonicalEventId(new Uint8Array(15))).toThrow();
  });
  test("rejects uppercase / bad spelling / wrong length", () => {
    expect(isCanonicalEventId("00000000-0000-0000-0000-000000000000")).toBe(true);
    expect(isCanonicalEventId("00000000-0000-0000-0000-00000000000Z")).toBe(false);
    expect(isCanonicalEventId("00000000_0000_0000_0000_000000000000")).toBe(false);
    expect(isCanonicalEventId("00000000-0000-0000-0000-00000000000")).toBe(false);
    expect(isCanonicalEventId("")).toBe(false);
  });
  test("parse throws on non-canonical", () => {
    expect(() => parseCanonicalEventId("nope")).toThrow();
  });
});

describe("dedupeKeyHex", () => {
  test("stable and order-sensitive", () => {
    expect(dedupeKeyHex(["a", "b"])).toBe(dedupeKeyHex(["a", "b"]));
    expect(dedupeKeyHex(["a", "b"])).not.toBe(dedupeKeyHex(["b", "a"]));
  });
  test("separator prevents ambiguity", () => {
    expect(dedupeKeyHex(["ab", "c"])).not.toBe(dedupeKeyHex(["a", "bc"]));
  });
});

describe("dedupeKey (sha256, async)", () => {
  test("stable, order-sensitive, 64 hex chars", async () => {
    const a = await dedupeKey(["x", "y"]);
    expect(a).toBe(await dedupeKey(["x", "y"]));
    expect(a).not.toBe(await dedupeKey(["y", "x"]));
    expect(a).toMatch(/^[0-9a-f]{64}$/);
  });
});

describe("isGenerationStale", () => {
  test("same generation is fresh", () => {
    expect(isGenerationStale({ generation: 3 }, { generation: 3 })).toBe(false);
  });
  test("moved generation is stale", () => {
    expect(isGenerationStale({ generation: 4 }, { generation: 3 })).toBe(true);
  });
});
