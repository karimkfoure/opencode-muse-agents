import { describe, expect, test } from "bun:test";
import { joinWorktreePath, needsBindFollowup, placeWorktree, resolvePathSemantics } from "../src/worktree";

describe("joinWorktreePath", () => {
  test("always joins under .muse/worktrees", () => {
    expect(joinWorktreePath("/repo", "feat")).toBe("/repo/.muse/worktrees/feat");
    expect(joinWorktreePath("/repo/", "/feat")).toBe("/repo/.muse/worktrees/feat");
  });
});

describe("placeWorktree (tri-state mode)", () => {
  test("-1 skips (not_requested)", () => {
    expect(placeWorktree({ mode: -1 }, { storageRoot: "/r" })).toEqual({ placed: false, reason: "not_requested" });
  });
  test("0 shares with caller ownership, no followup", () => {
    const r = placeWorktree({ mode: 0, branch: "main" }, { storageRoot: "/r" });
    expect(r.placed).toBe(true);
    if (r.placed) {
      expect(r.placement.ownership).toBe("caller_owned");
      expect(r.needsFollowup).toBe(false);
    }
  });
  test(">0 isolates with runtime ownership and followup", () => {
    const r = placeWorktree({ mode: 12, branch: "w" }, { storageRoot: "/r", identityBytes: 12 });
    expect(r.placed).toBe(true);
    if (r.placed) {
      expect(r.placement.ownership).toBe("runtime_owned");
      expect(r.needsFollowup).toBe(true);
      expect(r.placement.mode).toBe(12);
    }
  });
  test("identity length mismatch fails invalid_identity", () => {
    expect(placeWorktree({ mode: 12 }, { storageRoot: "/r", identityBytes: 8 })).toEqual({
      placed: false,
      reason: "invalid_identity",
    });
  });
  test("fenced aborts (fence breach, never recover)", () => {
    expect(placeWorktree({ mode: 0 }, { storageRoot: "/r", fenced: true })).toEqual({
      placed: false,
      reason: "fence_breach",
    });
  });
});

describe("needsBindFollowup", () => {
  test("3/4 need follow-up; 0/1/0xff stand", () => {
    expect(needsBindFollowup(3)).toBe(true);
    expect(needsBindFollowup(4)).toBe(true);
    expect(needsBindFollowup(0)).toBe(false);
    expect(needsBindFollowup(1)).toBe(false);
    expect(needsBindFollowup(0xff)).toBe(false);
  });
});

describe("resolvePathSemantics", () => {
  test("default v3, explicit legacy honored", () => {
    expect(resolvePathSemantics()).toBe("v3_canonical");
    expect(resolvePathSemantics("legacy_ordinal")).toBe("legacy_ordinal");
  });
});
