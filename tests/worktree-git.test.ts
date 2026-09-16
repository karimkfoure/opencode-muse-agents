import { describe, expect, test } from "bun:test";
import { execFileSync } from "node:child_process";
import { existsSync, mkdirSync, mkdtempSync, rmSync } from "node:fs";
import { tmpdir } from "node:os";
import { dirname, join } from "node:path";
import { joinWorktreePath, placeWorktree } from "../src/worktree";

let hasGit = true;
try {
  execFileSync("git", ["--version"], { stdio: "ignore", timeout: 5000 });
} catch {
  hasGit = false;
}

const maybeTest = hasGit ? test : test.skip;

describe("worktree git round-trip", () => {
  maybeTest("placeWorktree + git worktree add/remove", () => {
    const repoDir = mkdtempSync(join(tmpdir(), "wt-git-"));
    try {
      execFileSync("git", ["init", "-b", "main"], { cwd: repoDir, stdio: "pipe", timeout: 8000 });
      execFileSync(
        "git",
        [
          "-c",
          "user.email=test@example.com",
          "-c",
          "user.name=test",
          "commit",
          "--allow-empty",
          "-m",
          "init",
        ],
        { cwd: repoDir, stdio: "pipe", timeout: 8000 },
      );

      const branch = "wt-roundtrip";
      const expected = joinWorktreePath(repoDir, branch);
      const outcome = placeWorktree({ mode: 0, branch }, { storageRoot: repoDir });
      expect(outcome.placed).toBe(true);
      if (!outcome.placed) return;
      expect(outcome.placement.path).toBe(expected);

      mkdirSync(dirname(outcome.placement.path), { recursive: true });
      execFileSync("git", ["worktree", "add", "-b", branch, outcome.placement.path, "HEAD"], {
        cwd: repoDir,
        stdio: "pipe",
        timeout: 8000,
      });
      expect(existsSync(outcome.placement.path)).toBe(true);

      execFileSync("git", ["worktree", "remove", "--force", outcome.placement.path], {
        cwd: repoDir,
        stdio: "pipe",
        timeout: 8000,
      });
      execFileSync("git", ["worktree", "prune"], { cwd: repoDir, stdio: "pipe", timeout: 8000 });
      expect(existsSync(outcome.placement.path)).toBe(false);
    } finally {
      rmSync(repoDir, { recursive: true, force: true });
    }
  }, 15000);
});
