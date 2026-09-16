import { describe, expect, test, beforeEach, afterEach } from "bun:test";
import { mkdtempSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { join } from "node:path";
import registryTool from "../bundle/tools/spark_registry";

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
  dir = mkdtempSync(join(tmpdir(), "spark-registry-ops-"));
});
afterEach(() => {
  rmSync(dir, { recursive: true, force: true });
});

describe("spark_registry list op", () => {
  test("list on empty table returns no rows", async () => {
    const out = JSON.parse(
      (await registryTool.execute({ table: "t", op: "list" }, fakeContext(dir))) as string,
    );
    expect(out).toEqual({ ok: true, rows: [] });
  });
  test("list after 2 appends returns both rows verbatim", async () => {
    const ctx = fakeContext(dir);
    await registryTool.execute({ table: "t", op: "append", row: JSON.stringify(["k1", 1, 2, 3]) }, ctx);
    await registryTool.execute({ table: "t", op: "append", row: JSON.stringify(["k2", 4, 5, 6]) }, ctx);
    const out = JSON.parse((await registryTool.execute({ table: "t", op: "list" }, ctx)) as string);
    expect(out).toEqual({
      ok: true,
      rows: [
        ["k1", 1, 2, 3],
        ["k2", 4, 5, 6],
      ],
    });
  });
});
