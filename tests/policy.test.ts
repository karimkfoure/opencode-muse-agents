import { describe, expect, test } from "bun:test";
import { decisionsEqual, isEffectiveVerdict, matchStage, runJudgeLane } from "../src/policy";

describe("runJudgeLane (first-fire-wins)", () => {
  const action = { actionDigest: "abc", policy: "default" };
  test("first matching candidate wins", () => {
    const r = runJudgeLane(
      [
        { id: "j1", judge: () => null },
        { id: "j2", judge: () => ({ actionDigest: "abc", policy: "default", riskLevel: "low" as const, userAuthorization: "unknown" as const }) },
        {
          id: "j3",
          judge: () => {
            throw new Error("must not be reached");
          },
        },
      ],
      action,
    );
    expect(r.matched).toBe(true);
    if (r.matched) expect(r.by).toBe("j2");
  });
  test("exhausted falls back to human", () => {
    expect(runJudgeLane([{ id: "j1", judge: () => null }], action)).toEqual({ matched: false });
  });
});

describe("decisionsEqual (field-wise, never reference)", () => {
  const d = { actionDigest: "a", policy: "p", riskLevel: "low" as const, userAuthorization: "unknown" as const };
  test("equal fields match; rationale ignored", () => {
    expect(decisionsEqual(d, { ...d, rationale: "x" })).toBe(true);
    expect(decisionsEqual(d, { ...d, riskLevel: "medium" })).toBe(false);
    expect(decisionsEqual(d, { ...d, userAuthorization: "approved" })).toBe(false);
  });
});

describe("isEffectiveVerdict", () => {
  test("only persisted verdicts count", () => {
    const v = {
      decision: { actionDigest: "a", policy: "p", riskLevel: "low" as const, userAuthorization: "unknown" as const },
      decidedBy: "judge",
      commandId: "c",
      persisted: false,
    };
    expect(isEffectiveVerdict(v)).toBe(false);
    expect(isEffectiveVerdict({ ...v, persisted: true })).toBe(true);
  });
});

describe("matchStage", () => {
  test("shell prefix / tool action / fs scope", () => {
    expect(matchStage({ kind: "shell_command", target: "git status" }, { shellPrefix: "git " })).toBe(true);
    expect(matchStage({ kind: "shell_command", target: "rm -rf /" }, { shellPrefix: "git " })).toBe(false);
    expect(matchStage({ kind: "tool_action", target: "write" }, { toolAction: "write" })).toBe(true);
    expect(matchStage({ kind: "filesystem", target: "/repo/src/a.ts" }, { fsScope: "/repo/src" })).toBe(true);
    expect(matchStage({ kind: "filesystem", target: "/etc/passwd" }, { fsScope: "/repo/src" })).toBe(false);
    expect(matchStage({ kind: "network", target: "x" }, { fsScope: "/repo" })).toBe(false);
  });
});
