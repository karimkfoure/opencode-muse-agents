/**
 * errors.ts — the central keyed error catalog.
 *
 * Every spawn/steer refusal resolves through ONE lookup (key -> message),
 * never an inline string (error_message_lookup). Callers port the key;
 * user text lives here exactly once.
 */

export type SpawnRejectionKey =
  | "missing_parent"
  | "agent_name_invalid"
  | "agent_name_conflict"
  | "agent_path_too_long"
  | "caller_not_executing"
  | "parent_closed"
  | "policy_denied"
  | "reserved_role"
  | "lineage_integrity_failed"
  | "root_capacity_exhausted"
  | "active_capacity"
  | "max_depth"
  | "parent_run_terminal"
  | "fanout_limit"
  | "worktree_isolation_unavailable"
  | "worktree_mode_invalid"
  | "target_missing"
  | "command_id_reused"
  | "unsupported_real_execution"
  | "child_run_rejected"
  | "generated_agent_name_collision";

export type IntakeRejectionKey =
  | "stopped"
  | "not_admitted"
  | "not_queued"
  | "strict_retention_unavailable"
  | "not_committed"
  | "not_requested"
  | "not_performed"
  | "closed"
  | "missing_parent"
  | "parent_mismatch";

const SPANISH: Record<string, string> = {
  // Spawn admission
  missing_parent: "missing_parent: the parent session or run does not exist",
  agent_name_invalid: "agent_name_invalid: the agent name is not valid",
  agent_name_conflict: "agent_name_conflict: the agent name is already taken",
  agent_path_too_long: "agent_path_too_long: the agent path exceeds its bound",
  caller_not_executing: "caller_not_executing: the caller is not executing",
  parent_closed: "parent_closed: the parent session is closed",
  policy_denied: "policy_denied: the permission catalog denies this spawn",
  reserved_role: "reserved_role: the requested role is reserved",
  lineage_integrity_failed: "lineage_integrity_failed: lineage attestation does not verify",
  root_capacity_exhausted: "root_capacity_exhausted: no root capacity remains",
  active_capacity: "active_capacity: no active capacity remains",
  max_depth: "max_depth: lineage depth limit reached",
  parent_run_terminal: "parent_run_terminal: the parent run is terminal",
  fanout_limit: "fanout_limit: fan-out limit reached",
  worktree_isolation_unavailable:
    "worktree_isolation_unavailable: retry without worktree_isolation or fix Git/logging/capacity",
  worktree_mode_invalid: "worktree_mode_invalid: mode must be -1 off, 0 shared, or a positive integer identity length",
  target_missing: "target_missing: the target child does not exist",
  command_id_reused: "command_id_reused: commandId already used with a different payload",
  unsupported_real_execution: "unsupported_real_execution: real execution is not supported here",
  child_run_rejected: "child_run_rejected: the child run was rejected",
  generated_agent_name_collision: "generated_agent_name_collision: generated name collided; retry",
  // Intake / message admission
  stopped: "stopped: the target is stopped",
  not_admitted: "not_admitted: the message was not admitted",
  not_queued: "not_queued: the message was not queued",
  strict_retention_unavailable: "strict_retention_unavailable: durable log unavailable",
  not_committed: "not_committed: the record was not committed",
  not_requested: "not_requested: nothing was requested",
  not_performed: "not_performed: the effect was not performed",
  closed: "closed: the target is closed",
  parent_mismatch: "parent_mismatch: the record belongs to another parent",
};

/** Central lookup: key -> message. Unknown keys fail closed (never default text). */
export function lookupError(key: string): { ok: true; message: string } | { ok: false; key: string } {
  const message = SPANISH[key];
  if (message === undefined) return { ok: false, key };
  return { ok: true, message };
}

/** All catalogued keys (for tests + compat checks across versions). */
export function catalogKeys(): string[] {
  return Object.keys(SPANISH);
}
