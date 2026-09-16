import { describe, expect, test } from "bun:test";
import { catalogKeys, lookupError } from "../src/errors";
import { admitSpawn, fingerprintSpawnIntent, type CommandLedger } from "../src/admission";

describe("lookupError (central catalog)", () => {
  test("known keys resolve, unknown fail closed", () => {
    const ok = lookupError("fanout_limit");
    expect(ok.ok).toBe(true);
    const bad = lookupError("nope_not_a_key");
    expect(bad.ok).toBe(false);
  });
  test("catalog is stable and non-empty", () => {
    const keys = catalogKeys();
    expect(keys.length).toBeGreaterThan(20);
    expect(keys).toContain("max_depth");
    expect(keys).toContain("command_id_reused");
    expect(new Set(keys).size).toBe(keys.length);
  });
});

describe("admitSpawn (binary order)", () => {
  const cap = { rootLimit: 8, rootUsed: 0, activeLimit: 4, activeUsed: 0, maxDepth: 2, fanoutLimit: 8, fanoutUsed: 0 };
  const base = {
    commandId: "01900000-0000-7000-8000-000000000000",
    agentPath: "spark-worker",
    objective: "answer the question with evidence",
    depth: 0,
    parentSessionId: "p1",
    parentRunId: "r1",
    worktreeMode: 0 as const,
  };
  test("happy path builds the 6-field commit record", () => {
    const r = admitSpawn(base, cap);
    expect(r.admitted).toBe(true);
    if (r.admitted) {
      expect(r.status).toBe("accepted");
      expect(Object.keys(r.commitFields).sort()).toEqual(
        ["accepted", "agent_lineage_admission", "description", "parent_binding", "schema_version", "spawn_decision"].sort(),
      );
      expect(r.commitFields.parent_binding).toBe("p1/r1");
    }
  });
  test("missing objective is policy_denied", () => {
    const r = admitSpawn({ ...base, objective: "   " }, cap);
    expect(r.admitted).toBe(false);
    if (!r.admitted) expect(r.key).toBe("policy_denied");
  });
  test("missing ids are missing_parent", () => {
    const r = admitSpawn({ ...base, parentRunId: "" }, cap);
    expect(r.admitted).toBe(false);
    if (!r.admitted) expect(r.key).toBe("missing_parent");
  });
  test("explicit rejected status carries child_run_rejected", () => {
    const r = admitSpawn({ ...base, status: "rejected" }, cap);
    expect(r.admitted).toBe(false);
    if (!r.admitted) expect(r.key).toBe("child_run_rejected");
  });
  test("capacity gates in order: root, active, depth", () => {
    expect(admitSpawn(base, { ...cap, rootUsed: 8 }).admitted).toBe(false);
    const r1 = admitSpawn(base, { ...cap, rootUsed: 8 });
    if (!r1.admitted) expect(r1.key).toBe("root_capacity_exhausted");
    const r2 = admitSpawn(base, { ...cap, activeUsed: 4 });
    if (!r2.admitted) expect(r2.key).toBe("active_capacity");
    const r3 = admitSpawn({ ...base, depth: 2 }, cap);
    if (!r3.admitted) expect(r3.key).toBe("max_depth");
    // depth 1 + maxDepth 2 is allowed (child depth = depth+1 <= max)
    expect(admitSpawn({ ...base, depth: 1 }, cap).admitted).toBe(true);
  });
  test("deferred is admitted with deferred status", () => {
    const r = admitSpawn({ ...base, status: "deferred" }, cap);
    expect(r.admitted).toBe(true);
    if (r.admitted) expect(r.status).toBe("deferred");
  });
  test("fan-out gate emits fanout_limit", () => {
    const r = admitSpawn(base, { ...cap, fanoutUsed: 8 });
    expect(r.admitted).toBe(false);
    if (!r.admitted) expect(r.key).toBe("fanout_limit");
  });
  test("identical replay joins; different payload conflicts", () => {
    const ledger: CommandLedger = new Map();
    const first = admitSpawn(base, cap, ledger);
    expect(first.admitted).toBe(true);
    ledger.set(base.commandId, fingerprintSpawnIntent(base));
    const replay = admitSpawn(base, cap, ledger);
    expect(replay.admitted).toBe(true);
    if (replay.admitted && "replay" in replay) expect(replay.replay).toBe(true);
    const conflict = admitSpawn({ ...base, objective: "something else entirely" }, cap, ledger);
    expect(conflict.admitted).toBe(false);
    if (!conflict.admitted) expect(conflict.key).toBe("command_id_reused");
  });
  test("worktreeMode must be -1/0/positive-int", () => { const bad = admitSpawn({ ...base, worktreeMode: 2.5 }, cap); expect(bad.admitted).toBe(false); if (!bad.admitted) expect(bad.key).toBe("worktree_mode_invalid"); expect(admitSpawn({ ...base, worktreeMode: 3 }, cap).admitted).toBe(true); });
});
