import { describe, expect, test, beforeEach, afterEach } from "bun:test";
import { mkdtempSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import { assertSafeSegment } from "../src/paths";
import { validateSubagentId } from "../src/envelope";
import { INTAKE_FAIL_STATUS, OWNER_VERBS, executeSteeringIntake } from "../src/intake";
import { admitSpawn } from "../src/admission";
import { createChildRecord } from "../src/child";
import { ROW_ABSENT, appendRow, commitRow, createTable, probeByKey } from "../src/registry";
import sendTool from "../bundle/tools/spark_send";
import registryTool from "../bundle/tools/spark_registry";
import worktreeTool from "../bundle/tools/spark_worktree";

function fakeContext(worktree: string) {
  return {
    sessionID: "ses-test",
    directory: worktree,
    worktree,
    abort: new AbortController().signal,
    ask: (async () => {}) as never,
  } as never;
}

describe("assertSafeSegment (traversal guard)", () => {
  test("rejects traversal and empty shapes", () => {
    for (const bad of ["../e", "a/b", "", ".", "a\\b", "a..b", "a\0b", "ok name", "..", "/abs", "-lead"]) {
      const r = assertSafeSegment(bad);
      expect(r.ok).toBe(false);
      if (!r.ok) {
        // Reason names the key, echoes the got value, and tells the fix.
        expect(r.reason).toContain(JSON.stringify(bad));
        expect(r.reason.toLowerCase()).toContain("segment");
        expect(r.reason.toLowerCase()).toContain("fix");
      }
    }
  });
  test("ok names pass", () => {
    for (const good of ["ok-name", "ok_name", "ok.name", "s1", "t", "A1", "my-table-1", "a"]) {
      expect(assertSafeSegment(good)).toEqual({ ok: true });
    }
  });
  test("length cap is 128", () => {
    expect(assertSafeSegment("a".repeat(128)).ok).toBe(true);
    expect(assertSafeSegment("a".repeat(129)).ok).toBe(false);
  });
});

describe("validateSubagentId (trim-first)", () => {
  test("whitespace-only ids fail with the same empty detail", () => {
    for (const bad of ["", "   ", "\t\n "]) {
      const r = validateSubagentId(bad);
      expect(r.ok).toBe(false);
      if (!r.ok) expect(r.issue.detail).toBe("subagentId must be a non-empty durable child id");
    }
    expect(validateSubagentId("c1").ok).toBe(true);
  });
});

describe("OWNER_VERBS allowlist", () => {
  test("8 verbs, no spawn", () => {
    expect([...(OWNER_VERBS as readonly string[])].sort()).toEqual(
      ["close", "followupTask", "interrupt", "readResult", "reopen", "resume", "sendMessage", "stop"].sort(),
    );
    expect((OWNER_VERBS as readonly string[])).not.toContain("spawn");
  });
  test("unknown verb intake rejection", () => {
    const r = executeSteeringIntake({ verb: "dance", subagentId: "c1", body: "x" });
    expect(r.status).toBe(INTAKE_FAIL_STATUS);
    expect(r.error).toBe("unknown verb dance");
    const ok = executeSteeringIntake({ verb: "sendMessage", subagentId: "c1", body: "hi" });
    expect(ok.status).toBe(0);
  });
});

describe("admission numerics", () => {
  const cap = { rootLimit: 8, rootUsed: 0, activeLimit: 4, activeUsed: 0, maxDepth: 2, fanoutLimit: 8, fanoutUsed: 0 };
  const base = {
    commandId: "01900000-0000-7000-8000-000000000000",
    agentPath: "spark-worker",
    objective: "answer with evidence",
    depth: 0,
    parentSessionId: "p1",
    parentRunId: "r1",
    worktreeMode: 0 as const,
  };
  test("non-integer/NaN depth is policy_denied; negative is missing_parent", () => {
    const nan = admitSpawn({ ...base, depth: NaN }, cap);
    expect(nan.admitted).toBe(false);
    if (!nan.admitted) expect(nan.key).toBe("policy_denied");
    const fl = admitSpawn({ ...base, depth: 1.5 }, cap);
    expect(fl.admitted).toBe(false);
    if (!fl.admitted) expect(fl.key).toBe("policy_denied");
    const neg = admitSpawn({ ...base, depth: -1 }, cap);
    expect(neg.admitted).toBe(false);
    if (!neg.admitted) expect(neg.key).toBe("missing_parent");
  });
  test("non-finite/negative limits are policy_denied", () => {
    for (const badCap of [
      { ...cap, rootLimit: NaN },
      { ...cap, rootUsed: Infinity },
      { ...cap, activeLimit: -1 },
      { ...cap, maxDepth: NaN },
      { ...cap, fanoutUsed: Number.POSITIVE_INFINITY },
    ]) {
      const r = admitSpawn(base, badCap);
      expect(r.admitted).toBe(false);
      if (!r.admitted) expect(r.key).toBe("policy_denied");
    }
  });
  test("oversize objective is policy_denied", () => {
    const r = admitSpawn({ ...base, objective: "x".repeat(65537) }, cap);
    expect(r.admitted).toBe(false);
    if (!r.admitted) expect(r.key).toBe("policy_denied");
    expect(admitSpawn({ ...base, objective: "x".repeat(65536) }, cap).admitted).toBe(true);
  });
  test("worktreeMode still enforced", () => {
    const bad = admitSpawn({ ...base, worktreeMode: 2.5 }, cap);
    expect(bad.admitted).toBe(false);
    if (!bad.admitted) expect(bad.key).toBe("worktree_mode_invalid");
    expect(admitSpawn({ ...base, worktreeMode: 3 }, cap).admitted).toBe(true);
  });
});

describe("child depth", () => {
  const spec = {
    subagentId: "c1",
    agentPath: "spark-worker",
    depth: 0,
    objective: "answer with evidence",
    childSessionId: "s9",
    workflowRunId: "r7",
    maxDepth: 2,
  };
  test("NaN/float/negative depth yields missing_field depth", () => {
    for (const depth of [NaN, 1.5, -1]) {
      const r = createChildRecord({ ...spec, depth });
      expect(r.ok).toBe(false);
      if (!r.ok) expect(r.issues).toContainEqual({ key: "missing_field", field: "depth" });
    }
  });
});

describe("registry keyIdx guard", () => {
  test("probe 4/-1 refused without touching the table", () => {
    const t = createTable("m");
    appendRow(t, ["k", 1, 2, 3]);
    expect(probeByKey(t, 4 as never, "k")).toBe(ROW_ABSENT);
    expect(probeByKey(t, -1 as never, "k")).toBe(ROW_ABSENT);
    expect(t.rows.length).toBe(1);
  });
  test("commit with bad keyIdx refuses without touching the table", () => {
    const t = createTable("m");
    appendRow(t, ["k", 1, 2, 3]);
    expect(commitRow(t, ["k", 9, 9, 9], { keyIdx: 4 as never, key: "k" })).toEqual({
      committed: false,
      index: ROW_ABSENT,
    });
    expect(commitRow(t, ["k", 9, 9, 9], { keyIdx: -1 as never, key: "k" })).toEqual({
      committed: false,
      index: ROW_ABSENT,
    });
    expect(t.rows[0][1]).toBe(1);
  });
});

describe("bundle path guards", () => {
  let dir = "";
  beforeEach(() => {
    dir = mkdtempSync(join(tmpdir(), "spark-harden-"));
  });
  afterEach(() => {
    rmSync(dir, { recursive: true, force: true });
  });
  test("spark_send rejects traversal session ids", async () => {
    const out = JSON.parse(
      (await sendTool.execute(
        { targetSessionId: "../e", body: "hi", deliveryPolicy: "queue_next_turn", wakePolicy: "wake_when_idle" },
        fakeContext(dir),
      )) as string,
    );
    expect(out.admitted).toBe(false);
  });
  test("spark_registry rejects bad table and bad row JSON", async () => {
    const ctx = fakeContext(dir);
    const badTable = JSON.parse(
      (await registryTool.execute({ table: "../e", op: "append", row: JSON.stringify(["k", 1, 2, 3]) }, ctx)) as string,
    );
    expect(badTable.ok).toBe(false);
    const badRow = JSON.parse(
      (await registryTool.execute({ table: "t", op: "append", row: "not-json{" }, ctx)) as string,
    );
    expect(badRow).toEqual({ ok: false, error: "row must be a JSON 4-tuple" });
  });
  test("spark_worktree rejects traversal branch", async () => {
    const out = JSON.parse(
      (await worktreeTool.execute({ mode: 0, branch: "a/b" }, fakeContext(dir))) as string,
    );
    expect(out.placed).toBe(false);
    expect(typeof out.reason).toBe("string");
  });
});
