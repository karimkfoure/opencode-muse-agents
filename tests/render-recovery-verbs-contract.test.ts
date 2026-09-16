import { describe, expect, test } from "bun:test";
import { progressiveDisplay, advanceCursor } from "../src/render";
import { cleanupDecision, reconcileOrphan } from "../src/recovery";
import { AGENT_VERBS, VERB_PORT, agentVerbs } from "../src/verbs";
import { validateAgainstContract } from "../src/contract";

describe("progressiveDisplay", () => {
  test("completed terminal wins over everything", () => {
    const out = progressiveDisplay([
      { text: "early", terminal: false, position: 1 },
      { text: "d1", terminal: false, position: 0 },
      { text: "final", terminal: true, position: 2 },
    ]);
    expect(out).toBe("final");
  });
  test("first display before deltas", () => {
    const out = progressiveDisplay([
      { text: "d1d2", terminal: false, position: 0 },
      { text: "hello", terminal: false, position: 1 },
    ]);
    expect(out).toBe("hello");
  });
  test("deltas join when nothing else", () => {
    expect(
      progressiveDisplay([
        { text: "a", terminal: false, position: 0 },
        { text: "b", terminal: false, position: 0 },
      ]),
    ).toBe("ab");
  });
  test("empty yields empty", () => {
    expect(progressiveDisplay([])).toBe("");
  });
});

describe("advanceCursor", () => {
  test("advances only on commit", () => {
    expect(advanceCursor(true, "c1", "c2")).toBe("c2");
    expect(advanceCursor(false, "c1", "c2")).toBe("c1");
  });
});

describe("reconcileOrphan", () => {
  test("unprovable quarantines; no primary restarts; else reconciles", () => {
    expect(reconcileOrphan({ runId: "r", ownershipProvable: false, retainedPrimary: true })).toBe("quarantined");
    expect(reconcileOrphan({ runId: "r", ownershipProvable: true, retainedPrimary: false })).toBe("restart_required");
    expect(reconcileOrphan({ runId: "r", ownershipProvable: true, retainedPrimary: true })).toBe("reconciled");
  });
});

describe("cleanupDecision (remove_if_clean)", () => {
  test("removes only clean + lease released", () => {
    expect(cleanupDecision("remove_if_clean", { clean: true, leaseActive: false })).toBe("remove");
    expect(cleanupDecision("remove_if_clean", { clean: false, leaseActive: false })).toBe("retain");
    expect(cleanupDecision("remove_if_clean", { clean: true, leaseActive: true })).toBe("retain");
  });
});

describe("verbs (12 verbatim)", () => {
  test("twelve verbs in binary order, all mapped", () => {
    expect(agentVerbs().length).toBe(12);
    expect(AGENT_VERBS[0]).toBe("Agent.start");
    for (const v of AGENT_VERBS) {
      expect(typeof VERB_PORT[v]).toBe("string");
      expect(VERB_PORT[v].length).toBeGreaterThan(0);
    }
  });
});

describe("validateAgainstContract", () => {
  test("default_text needs a summary", () => {
    expect(validateAgainstContract({ summary: "x" }, { kind: "default_text" }).ok).toBe(true);
    expect(validateAgainstContract({}, { kind: "default_text" }).ok).toBe(false);
  });
  test("declared_schema checks required fields", () => {
    const c = { kind: "declared_schema" as const, requiredFields: ["summary", "usage"] };
    expect(validateAgainstContract({ summary: "x", usage: 1 }, c).ok).toBe(true);
    const r = validateAgainstContract({ summary: "x" }, c);
    expect(r.ok).toBe(false);
    if (!r.ok) expect(r.issues).toEqual([{ key: "missing_contract_field", field: "usage" }]);
  });
});
