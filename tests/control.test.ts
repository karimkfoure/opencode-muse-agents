import { describe, expect, test } from "bun:test";
import { driveDefault, drivePipeline, driveReplaceOnIdle, stripWorkflowEntry } from "../src/control";

describe("stripWorkflowEntry", () => {
  test("removes workflow entries, keeps the rest in order", () => {
    const out = stripWorkflowEntry([
      { tag: "spawn", attempt: 1, payload: "a" },
      { tag: "workflow", attempt: 1, payload: "w" },
      { tag: "close", attempt: 2, payload: "c" },
    ]);
    expect(out.map((e) => e.tag)).toEqual(["spawn", "close"]);
  });
});

describe("driveDefault", () => {
  test("resolves + strips; null fails target_missing", () => {
    const ctl = { base: "b", entries: [{ tag: "workflow", attempt: 0, payload: null }], params: {} };
    const r = driveDefault(ctl);
    expect(r.ok).toBe(true);
    if (r.ok) expect(r.control.entries).toEqual([]);
    expect(driveDefault(null).ok).toBe(false);
  });
});

describe("driveReplaceOnIdle", () => {
  const ctl = { base: "b", entries: [], params: {} };
  test("idle+empty proceeds", () => {
    expect(driveReplaceOnIdle(ctl, { idle: true, empty: true }).ok).toBe(true);
  });
  test("non-idle or non-empty refuses owner_still_running (never overwrites)", () => {
    expect(driveReplaceOnIdle(ctl, { idle: false, empty: true })).toEqual({
      ok: false,
      reason: "owner_still_running",
    });
    expect(driveReplaceOnIdle(ctl, { idle: true, empty: false })).toEqual({
      ok: false,
      reason: "owner_still_running",
    });
  });
});

describe("drivePipeline", () => {
  test("builds committed outcome rows in order", () => {
    const ctl = { base: "b", entries: [], params: {} };
    const r = drivePipeline(ctl, [
      { kind: "spawn", attempt: 1 },
      { kind: "close", attempt: 1, fields: { reason: "done" } },
    ]);
    expect(r.ok).toBe(true);
    if (r.ok) {
      expect(r.rows.length).toBe(2);
      expect(r.rows.every((x) => x.committed)).toBe(true);
      expect(r.rows[1].fields).toEqual({ reason: "done" });
    }
  });
  test("empty pipeline with empty control is not_requested", () => {
    const r = drivePipeline({ base: "b", entries: [], params: {} }, []);
    expect(r).toEqual({ ok: false, reason: "not_requested" });
  });
});
