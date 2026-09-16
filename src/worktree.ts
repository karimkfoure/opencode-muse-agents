/**
 * worktree.ts — tri-state worktree isolation + bind-verify.
 *
 * Mode is a VALUE, not a flag: -1 off / 0 shared / >0 isolated carrying
 * N identity bytes. Path ALWAYS joins under `.muse/worktrees`.
 * Path semantics flag: v3-canonical vs legacy-ordinal.
 * Bind-then-verify with verdicts {0,1,3,4,0xff}: 3/4 need follow-up.
 * Fence (-2) breach aborts the task; never error-recovers.
 */

export const WORKTREE_ROOT_SEGMENT = ".muse/worktrees";

export type WorktreeMode = -1 | 0 | number;

export type PathSemantics = "v3_canonical" | "legacy_ordinal";

export interface WorktreeRequest {
  mode: WorktreeMode;
  identityLength?: number;
  pathSemantics?: PathSemantics;
  baseCommit?: string;
  branch?: string;
}

export type WorktreeVerdict = 0 | 1 | 3 | 4 | 0xff;

export interface WorktreePlacement {
  path: string;
  mode: Exclude<WorktreeMode, -1>;
  ownership: "runtime_owned" | "caller_owned";
  baseCommit: string | null;
}

export function joinWorktreePath(root: string, branch: string): string {
  const cleanRoot = root.replace(/\/+$/, "");
  const cleanBranch = branch.replace(/^\/+/, "");
  return `${cleanRoot}/${WORKTREE_ROOT_SEGMENT}/${cleanBranch}`;
}

export type PlaceOutcome =
  | { placed: true; placement: WorktreePlacement; needsFollowup: false }
  | { placed: true; placement: WorktreePlacement; needsFollowup: true }
  | { placed: false; reason: "not_requested" | "fence_breach" | "invalid_identity" };

/**
 * Placement gate: -1 skips; 0 shared; >0 isolated (identity length must
 * match the provided identity bytes length when given).
 */
export function placeWorktree(
  req: WorktreeRequest,
  opts: { storageRoot: string; identityBytes?: number; fenced?: boolean },
): PlaceOutcome {
  if (opts.fenced) return { placed: false, reason: "fence_breach" };
  if (req.mode === -1) return { placed: false, reason: "not_requested" };
  if (req.mode === 0) {
    return {
      placed: true,
      needsFollowup: false,
      placement: {
        path: joinWorktreePath(opts.storageRoot, req.branch ?? "shared"),
        mode: 0,
        ownership: "caller_owned",
        baseCommit: req.baseCommit ?? null,
      },
    };
  }
  if (!Number.isInteger(req.mode) || req.mode <= 0) return { placed: false, reason: "invalid_identity" };
  if (opts.identityBytes !== undefined && opts.identityBytes !== req.mode) {
    return { placed: false, reason: "invalid_identity" };
  }
  return {
    placed: true,
    needsFollowup: true,
    placement: {
      path: joinWorktreePath(opts.storageRoot, req.branch ?? `child-${req.mode}`),
      mode: req.mode,
      ownership: "runtime_owned",
      baseCommit: req.baseCommit ?? null,
    },
  };
}

/** Bind-verify verdicts: 3/4 need follow-up calls; else the verdict stands. */
export function needsBindFollowup(verdict: WorktreeVerdict): boolean {
  return verdict === 3 || verdict === 4;
}

/** Default path semantics; explicit flag overrides. */
export function resolvePathSemantics(flag?: PathSemantics): PathSemantics {
  return flag ?? "v3_canonical";
}
