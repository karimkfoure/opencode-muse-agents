import { describe, expect, test } from "bun:test";
import { CONTROL_STATUS, createChildRecord, transitionControlStatus } from "../src/child";
import { checkForkIds, planFork } from "../src/fork";

describe("createChildRecord", () => {
  const spec = {
    subagentId: "c1",
    agentPath: "spark-worker",
    depth: 0,
    objective: "answer with evidence",
    childSessionId: "s9",
    workflowRunId: "r7",
    maxDepth: 2,
  };
  test("happy path starts at accepted", () => {
    const r = createChildRecord(spec);
    expect(r.ok).toBe(true);
    if (r.ok) {
      expect(r.record.controlStatus).toBe("accepted");
      expect(r.record.objective).toBe(spec.objective);
    }
  });
  test("objective mandatory; bad ids and depth enforced", () => {
    expect(createChildRecord({ ...spec, objective: "  " }).ok).toBe(false);
    expect(createChildRecord({ ...spec, subagentId: "" }).ok).toBe(false);
    expect(createChildRecord({ ...spec, depth: 2 }).ok).toBe(false);
    expect(createChildRecord({ ...spec, depth: 1 }).ok).toBe(true);
  });
});

describe("transitionControlStatus", () => {
  test("closed is terminal; unknown rejected", () => {
    expect(transitionControlStatus("running", "resultReady")).toBe(true);
    expect(transitionControlStatus("closed", "running")).toBe(false);
    // @ts-expect-error intentional
    expect(transitionControlStatus("running", "nope")).toBe(false);
  });
  test("vocabulary is the closed 8-enum", () => {
    expect(CONTROL_STATUS).toContain("recoveryPending");
    expect(CONTROL_STATUS.length).toBe(8);
  });
});

describe("fork", () => {
  test("provenance records cut explicitness; cursor opaque", () => {
    const p = planFork({ sourceSessionId: "s", commandId: "c" }, "n", "opaque-xyz");
    expect(p.provenance.cutExplicit).toBe(false);
    expect(p.provenance.cutCursor).toBe("opaque-xyz");
    const q = planFork({ sourceSessionId: "s", commandId: "c", cutPoint: { lastTurnId: "t" } }, "n", "z");
    expect(q.provenance.cutExplicit).toBe(true);
  });
  test("fork id must differ from source", () => {
    expect(checkForkIds("n", "s")).toBe(true);
    expect(checkForkIds("s", "s")).toBe(false);
  });
});
