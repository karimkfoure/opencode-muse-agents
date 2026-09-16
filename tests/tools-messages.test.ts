import { describe, expect, test, beforeEach, afterEach } from "bun:test";
import { mkdtempSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import forkTool from "../bundle/tools/spark_fork";
import decideTool from "../bundle/tools/spark_decide";
import steerTool from "../bundle/tools/spark_steer";
import registryTool from "../bundle/tools/spark_registry";
import { worktree_bind_verdict } from "../bundle/tools/spark_worktree";

function fakeContext(worktree: string) {
  return {
    sessionID: "s",
    directory: "/tmp",
    worktree,
    abort: new AbortController().signal,
    ask: (async () => {}) as never,
  } as never;
}

let dir = "";
beforeEach(() => {
  dir = mkdtempSync(join(tmpdir(), "spark-msgs-"));
});
afterEach(() => {
  rmSync(dir, { recursive: true, force: true });
});

describe("tools error messages carry received values", () => {
  test("fork with equal ids names both ids", async () => {
    const out = JSON.parse(
      (await forkTool.execute(
        { sourceSessionId: "abc", newSessionId: "abc", servedCutCursor: "c", commandId: "cmd1" },
        fakeContext(dir),
      )) as string,
    );
    expect(out.ok).toBe(false);
    expect(out.error).toContain("abc");
    expect(out.error).toContain("ForkIdEqualsSourceId");
  });
  test("steer unknown verb names the verb and the valid list", async () => {
    const out = JSON.parse(
      (await steerTool.execute({ verb: "dance", subagentId: "c1" }, fakeContext(dir))) as string,
    );
    expect(out.ok).toBe(false);
    expect(out.error).toContain("dance");
    expect(out.error).toContain("sendMessage");
  });
  test("decide malformed candidates shape fails closed", async () => {
    const out = JSON.parse(
      (await decideTool.execute(
        { actionDigest: "a", policy: "p", riskLevel: "low", candidates: "[1,2]" },
        fakeContext(dir),
      )) as string,
    );
    expect(out).toEqual({ ok: false, error: "candidates must be a JSON array of {id, policies[], riskCap}" });
  });
  // Owned by another worker (excluded files): assert the stable core that
  // both the current and the improved messages keep, so this stays green
  // before and after their upgrade.
  test("registry missing row fails closed naming row", async () => {
    const out = JSON.parse(
      (await registryTool.execute({ table: "t", op: "append" }, fakeContext(dir))) as string,
    );
    expect(out.ok).toBe(false);
    expect(out.error).toContain("row");
  });
  test("unknown verdict fails closed", async () => {
    const out = JSON.parse(
      (await worktree_bind_verdict.execute({ verdict: 7 }, fakeContext(dir))) as string,
    );
    expect(out.ok).toBe(false);
    expect(out.error).toContain("unknown verdict");
  });
});
