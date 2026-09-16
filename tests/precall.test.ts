import { describe, expect, test } from "bun:test";
import { firstTurnEffort, isProactiveDelegationActive, proactiveDelegationPolicy, selectModel } from "../src/precall";

describe("isProactiveDelegationActive", () => {
  test("ultra activates; user opt-out always wins", () => {
    expect(isProactiveDelegationActive("ultra", false)).toBe(true);
    expect(isProactiveDelegationActive("high", false)).toBe(false);
    expect(isProactiveDelegationActive("medium", false)).toBe(false);
    expect(isProactiveDelegationActive("ultra", true)).toBe(false);
  });
  test("policy text differs by gate", () => {
    expect(proactiveDelegationPolicy("ultra")).toContain("Proactive delegation is active");
    expect(proactiveDelegationPolicy("low")).toContain("explicitly requests");
  });
});

describe("selectModel", () => {
  test("first configured wins; empty is null (fail closed at call time)", () => {
    expect(selectModel({ role: "worker", models: ["a", "b"] })).toBe("a");
    expect(selectModel({ role: "worker", models: [] })).toBe(null);
  });
});

describe("firstTurnEffort", () => {
  test("first turn is minimal", () => {
    expect(firstTurnEffort()).toBe("minimal");
  });
});
