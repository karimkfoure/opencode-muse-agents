/**
 * recovery.ts — crashes are a normal input.
 *
 * Orphan reconcile, quarantine-never-delete for unprovable ownership,
 * and remove_if_clean cleanup policy. Fence breach aborts (see worktree),
 * quarantine retains without deleting.
 */

export type OrphanOutcome = "reconciled" | "quarantined" | "restart_required";

export interface OrphanReport {
  runId: string;
  ownershipProvable: boolean;
  retainedPrimary: boolean;
}

/**
 * Reconcile an orphaned run: provable + retained -> reconcile;
 * unprovable -> quarantine (retain, never delete); no retained
 * primary -> restart the session to continue.
 */
export function reconcileOrphan(report: OrphanReport): OrphanOutcome {
  if (!report.ownershipProvable) return "quarantined";
  if (!report.retainedPrimary) return "restart_required";
  return "reconciled";
}

export type CleanupPolicy = "remove_if_clean";

export interface CleanupState {
  clean: boolean;
  leaseActive: boolean;
}

/**
 * remove_if_clean: remove only when clean AND lease released; dirty or
 * leased worktrees are retained (caller_owned retained, never forced).
 */
export function cleanupDecision(policy: CleanupPolicy, state: CleanupState): "remove" | "retain" {
  if (policy !== "remove_if_clean") return "retain";
  if (!state.clean) return "retain";
  if (state.leaseActive) return "retain";
  return "remove";
}
