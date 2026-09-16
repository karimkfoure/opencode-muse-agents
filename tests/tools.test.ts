import { describe, expect, test, beforeEach, afterEach } from "bun:test";
import { mkdtempSync, rmSync, readdirSync, readFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import sendTool from "../bundle/tools/spark_send";
import registryTool from "../bundle/tools/spark_registry";
import decideTool from "../bundle/tools/spark_decide";
import steerTool from "../bundle/tools/spark_steer";

function fakeContext(worktree: string) {
  return {
    sessionID: "ses-test",
    directory: worktree,
    worktree,
    abort: new AbortController().signal,
    ask: (async () => {}) as never,
  } as never;
}

let dir = "";
beforeEach(() => {
  dir = mkdtempSync(join(tmpdir(), "spark-tools-"));
});
afterEach(() => {
  rmSync(dir, { recursive: true, force: true });
});

describe("spark_send (ledger append)", () => {
  test("appends a pending record and returns its id", async () => {
    const out = JSON.parse(
      (await sendTool.execute(
        { targetSessionId: "s1", body: "  hello  ", deliveryPolicy: "queue_next_turn", wakePolicy: "wake_when_idle" },
        fakeContext(dir),
      )) as string,
    );
    expect(out.admission).toBe("pending_admission");
    const files = readdirSync(join(dir, ".spark/mailbox"));
    expect(files).toEqual(["s1.jsonl"]);
    const rec = JSON.parse(readFileSync(join(dir, ".spark/mailbox/s1.jsonl"), "utf8"));
    expect(rec.id).toBe(out.messageId);
    expect(rec.body).toBe("hello");
  });
  test("forbidden combos never reach the ledger", async () => {
    const out = JSON.parse(
      (await sendTool.execute(
        {
          targetSessionId: "s1",
          body: "x",
          deliveryPolicy: "steer_active_turn",
          wakePolicy: "do_not_wake",
          targetRunning: true,
        },
        fakeContext(dir),
      )) as string,
    );
    expect(out.admitted).toBe(false);
    expect(() => readdirSync(join(dir, ".spark/mailbox"))).toThrow();
  });
});

describe("spark_registry (durable tables)", () => {
  test("append/probe/swap/commit round-trip on disk", async () => {
    const ctx = fakeContext(dir);
    const a = JSON.parse(
      (await registryTool.execute({ table: "t", op: "append", row: JSON.stringify(["k", 1, 2, 3]) }, ctx)) as string,
    );
    expect(a).toEqual({ ok: true, index: 0 });
    const p = JSON.parse(
      (await registryTool.execute({ table: "t", op: "probe", keyIdx: 0, key: "K" }, ctx)) as string,
    );
    expect(p).toEqual({ ok: true, index: 0 });
    const c = JSON.parse(
      (await registryTool.execute({ table: "t", op: "commit", row: JSON.stringify(["k", 9, 9, 9]), keyIdx: 0, key: "k" }, ctx)) as string,
    );
    expect(c).toEqual({ committed: true, index: 0 });
    const locked = JSON.parse(
      (await registryTool.execute({ table: "t", op: "commit", row: JSON.stringify(["z", 1, 1, 1]), locked: true }, ctx)) as string,
    );
    expect(locked).toEqual({ committed: false, index: -2 });
  });
});

describe("spark_decide (judge + durable verdicts)", () => {
  const candidates = JSON.stringify([{ id: "auto", policies: ["default"], riskCap: "low" }]);
  test("first match wins and persists with read-back", async () => {
    const out = JSON.parse(
      (await decideTool.execute(
        { actionDigest: "abc", policy: "default", riskLevel: "low", candidates },
        fakeContext(dir),
      )) as string,
    );
    expect(out.ok).toBe(true);
    expect(out.matched).toBe(true);
    expect(out.by).toBe("auto");
    expect(out.effective).toBe(true);
    expect(readdirSync(join(dir, ".spark"))).toContain("verdicts.jsonl");
  });
  test("no match falls back to human", async () => {
    const out = JSON.parse(
      (await decideTool.execute(
        { actionDigest: "abc", policy: "other", riskLevel: "low", candidates },
        fakeContext(dir),
      )) as string,
    );
    expect(out).toMatchObject({ ok: true, matched: false });
  });
  test("over-cap risk falls through", async () => {
    const out = JSON.parse(
      (await decideTool.execute(
        { actionDigest: "abc", policy: "default", riskLevel: "medium", candidates },
        fakeContext(dir),
      )) as string,
    );
    expect(out.matched).toBe(false);
  });
  test("malformed riskCap fails closed per candidate", async () => {
    const out = JSON.parse(
      (await decideTool.execute(
        {
          actionDigest: "abc",
          policy: "default",
          riskLevel: "low",
          candidates: JSON.stringify([{ id: "auto", policies: ["default"], riskCap: "high" }]),
        },
        fakeContext(dir),
      )) as string,
    );
    expect(out).toEqual({ ok: false, error: "candidate auto needs riskCap low|medium" });
  });
  test("malformed id/policies shape reuses the candidates error", async () => {
    const out = JSON.parse(
      (await decideTool.execute(
        {
          actionDigest: "abc",
          policy: "default",
          riskLevel: "low",
          candidates: JSON.stringify([{ id: 7, policies: "default", riskCap: "low" }]),
        },
        fakeContext(dir),
      )) as string,
    );
    expect(out).toEqual({ ok: false, error: "candidates must be a JSON array of {id, policies[], riskCap}" });
  });
});

describe("spark_steer (wired drivers)", () => {
  test("message verbs run default driver + intake record", async () => {
    const out = JSON.parse(
      (await steerTool.execute({ verb: "followupTask", subagentId: "c1", body: "  go  " }, fakeContext(dir))) as string,
    );
    expect(out.ok).toBe(true);
    expect(out.driver).toBe("default");
    expect(out.intake.body).toBe("go");
  });
  test("lifecycle verbs refuse non-idle targets", async () => {
    const no = JSON.parse(
      (await steerTool.execute({ verb: "resume", subagentId: "c1", targetIdle: false, targetEmpty: true }, fakeContext(dir))) as string,
    );
    expect(no).toEqual({ ok: false, reason: "owner_still_running" });
    const yes = JSON.parse(
      (await steerTool.execute({ verb: "resume", subagentId: "c1", targetIdle: true, targetEmpty: true }, fakeContext(dir))) as string,
    );
    expect(yes).toEqual({ ok: true, verb: "resume", driver: "replace-on-idle" });
  });
  test("signal verbs succeed with reason and no body", async () => {
    const out = JSON.parse(
      (await steerTool.execute({ verb: "interrupt", subagentId: "c1", reason: "halt" }, fakeContext(dir))) as string,
    );
    expect(out).toEqual({ ok: true, verb: "interrupt", driver: "default", reason: "halt" });
    const bare = JSON.parse(
      (await steerTool.execute({ verb: "stop", subagentId: "c1" }, fakeContext(dir))) as string,
    );
    expect(bare).toEqual({ ok: true, verb: "stop", driver: "default", reason: null });
  });
  test("record verbs still require a body", async () => {
    const out = JSON.parse(
      (await steerTool.execute({ verb: "sendMessage", subagentId: "c1" }, fakeContext(dir))) as string,
    );
    expect(out.ok).toBe(false);
  });
  test("unknown verbs fail closed", async () => {
    const out = JSON.parse((await steerTool.execute({ verb: "dance", subagentId: "c1" }, fakeContext(dir))) as string);
    expect(out.ok).toBe(false);
  });
});
