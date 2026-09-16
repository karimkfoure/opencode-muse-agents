import { describe, expect, test, beforeEach, afterEach } from "bun:test";
import { mkdtempSync, mkdirSync, rmSync, readdirSync, writeFileSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import decideTool from "../bundle/tools/spark_decide";

function fakeContext(worktree: string) {
  return {
    sessionID: "s",
    directory: worktree,
    worktree,
    abort: new AbortController().signal,
    ask: (async () => {}) as never,
  } as never;
}

let dir = "";
beforeEach(() => {
  dir = mkdtempSync(join(tmpdir(), "spark-decide-rotation-"));
});
afterEach(() => {
  rmSync(dir, { recursive: true, force: true });
});

describe("spark_decide verdict rotation", () => {
  test("oversized verdicts.jsonl rotates and decision stays effective", async () => {
    mkdirSync(join(dir, ".spark"), { recursive: true });
    writeFileSync(join(dir, ".spark/verdicts.jsonl"), "\n".repeat(256 * 1024 + 1), "utf8");
    const out = JSON.parse(
      (await decideTool.execute(
        {
          actionDigest: "abc",
          policy: "default",
          riskLevel: "low",
          candidates: JSON.stringify([{ id: "auto", policies: ["default"], riskCap: "low" }]),
        },
        fakeContext(dir),
      )) as string,
    );
    expect(out.effective).toBe(true);
    const rotated = readdirSync(join(dir, ".spark")).filter(
      (f) => f.startsWith("verdicts-") && f.endsWith(".jsonl"),
    );
    expect(rotated.length).toBe(1);
  });
});
