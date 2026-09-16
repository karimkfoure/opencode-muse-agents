import { tool } from "@opencode-ai/plugin";
import { joinWorktreePath, needsBindFollowup, placeWorktree, resolvePathSemantics, type WorktreeVerdict } from "../../src/worktree";
import { assertSafeSegment } from "../../src/paths";

/**
 * spark_worktree — tri-state worktree placement.
 * mode -1 off / 0 shared / >0 isolated (identity length must match).
 * Paths always join under .muse/worktrees. Fenced aborts, never recovers.
 * Actual git worktree add/remove runs through Bun.$ so placement is real.
 */
export default tool({
  description:
    "Place an isolated worktree (mode -1 off / 0 shared / >0 isolated with identity length). Paths always under .muse/worktrees. Fenced aborts. Action create (default) places; delete removes via git worktree remove --force + prune.",
  args: {
    action: tool.schema.string().optional().describe('Action: "create" (default) or "delete"'),
    mode: tool.schema.number().describe("Worktree mode: -1 off, 0 shared, >0 isolated identity length"),
    branch: tool.schema.string().describe("Branch/worktree name"),
    baseCommit: tool.schema.string().optional().describe("Base commit (default HEAD)"),
    pathSemantics: tool.schema.string().optional().describe("v3_canonical (default) | legacy_ordinal"),
    identityBytes: tool.schema.number().optional().describe("Identity byte length (must equal mode when >0)"),
    storageRoot: tool.schema.string().optional().describe("Storage root (defaults to session worktree)"),
    fenced: tool.schema.boolean().optional().describe("Fence breach simulation: aborts when true"),
  },
  async execute(args, context) {
    const seg = assertSafeSegment(args.branch);
    if (!seg.ok) {
      return JSON.stringify({ placed: false, reason: `invalid branch name ${JSON.stringify(args.branch)}: ${seg.reason}` });
    }
    const semantics = args.pathSemantics === "legacy_ordinal" ? "legacy_ordinal" : "v3_canonical";
    resolvePathSemantics(args.pathSemantics as "v3_canonical" | "legacy_ordinal" | undefined);
    const root = args.storageRoot ?? context.worktree;
    const action = args.action ?? "create";
    if (action !== "create" && action !== "delete") {
      return JSON.stringify({ placed: false, reason: `unknown action ${JSON.stringify(args.action)}` });
    }
    if (action === "delete") {
      const path = joinWorktreePath(root, args.branch);
      const rm = Bun.spawnSync(["git", "worktree", "remove", "--force", path], {
        cwd: root,
        stdout: "pipe",
        stderr: "pipe",
      });
      if (rm.exitCode !== 0) {
        return JSON.stringify({ removed: false, reason: "worktree_remove_failed", stderr: rm.stderr.toString().slice(0, 500) });
      }
      const prune = Bun.spawnSync(["git", "worktree", "prune"], {
        cwd: root,
        stdout: "pipe",
        stderr: "pipe",
      });
      if (prune.exitCode !== 0) {
        return JSON.stringify({ removed: false, reason: "worktree_prune_failed", stderr: prune.stderr.toString().slice(0, 500) });
      }
      return JSON.stringify({ removed: true });
    }
    const placed = placeWorktree(
      {
        mode: args.mode as -1 | 0 | number,
        branch: args.branch,
        ...(args.baseCommit ? { baseCommit: args.baseCommit } : {}),
        pathSemantics: semantics,
      },
      { storageRoot: root, ...(args.identityBytes !== undefined ? { identityBytes: args.identityBytes } : {}), ...(args.fenced ? { fenced: true } : {}) },
    );
    if (!placed.placed) return JSON.stringify(placed);
    if (args.mode > 0) {
      const base = args.baseCommit ?? "HEAD";
      const proc = Bun.spawnSync(["git", "worktree", "add", "-b", args.branch, placed.placement.path, base], {
        cwd: root,
        stdout: "pipe",
        stderr: "pipe",
      });
      if (proc.exitCode !== 0) {
        return JSON.stringify({ placed: false, reason: "worktree_setup_failed", stderr: proc.stderr.toString().slice(0, 500) });
      }
    }
    return JSON.stringify({ ...placed, pathSemantics: semantics, path: joinWorktreePath(root, args.branch) });
  },
});

export const worktree_bind_verdict = tool({
  description: "Bind-verify verdict check: 3/4 need follow-up calls, else the verdict stands.",
  args: { verdict: tool.schema.number().describe("One of 0, 1, 3, 4, 255") },
  async execute(args) {
    const v = args.verdict as WorktreeVerdict;
    if (![0, 1, 3, 4, 0xff].includes(v)) return JSON.stringify({ ok: false, error: "unknown verdict" });
    return JSON.stringify({ verdict: v, needsFollowup: needsBindFollowup(v) });
  },
});
