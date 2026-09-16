/**
 * child.ts — the durable child record schema.
 *
 * subagentId, agentPath, depth, [objective], childSessionId,
 * controlStatus, workflowRunId, result — in this order.
 * `objective` is MANDATORY at spawn. `depth` is enforced numerically.
 */
import { validateSubagentId } from "./envelope";

export type ControlStatus =
  | "accepted"
  | "starting"
  | "running"
  | "resultReady"
  | "closing"
  | "closed"
  | "recoveryPending"
  | "manualReconciliation";

export const CONTROL_STATUS: readonly ControlStatus[] = [
  "accepted",
  "starting",
  "running",
  "resultReady",
  "closing",
  "closed",
  "recoveryPending",
  "manualReconciliation",
];

export interface ChildRecord {
  subagentId: string;
  agentPath: string;
  depth: number;
  objective: string;
  childSessionId: string;
  controlStatus: ControlStatus;
  workflowRunId: string;
  result?: unknown;
}

export interface ChildSpec {
  subagentId: string;
  agentPath: string;
  depth: number;
  objective: string;
  childSessionId: string;
  workflowRunId: string;
  maxDepth: number;
}

export type ChildIssue =
  | { key: "empty_subagent_id" }
  | { key: "missing_objective" }
  | { key: "missing_field"; field: string }
  | { key: "max_depth"; depth: number; maxDepth: number };

/** Create a child record: objective mandatory, depth enforced, ids verified. */
export function createChildRecord(spec: ChildSpec): { ok: true; record: ChildRecord } | { ok: false; issues: ChildIssue[] } {
  const issues: ChildIssue[] = [];
  if (validateSubagentId(spec.subagentId).ok === false) issues.push({ key: "empty_subagent_id" });
  for (const [field, value] of [
    ["agentPath", spec.agentPath],
    ["childSessionId", spec.childSessionId],
    ["workflowRunId", spec.workflowRunId],
  ] as const) {
    if (!value || typeof value !== "string") issues.push({ key: "missing_field", field });
  }
  if (!spec.objective || spec.objective.trim().length === 0) issues.push({ key: "missing_objective" });
  if (!Number.isInteger(spec.depth) || spec.depth < 0) issues.push({ key: "missing_field", field: "depth" });
  if (spec.depth + 1 > spec.maxDepth) issues.push({ key: "max_depth", depth: spec.depth, maxDepth: spec.maxDepth });
  if (issues.length > 0) return { ok: false, issues };
  return {
    ok: true,
    record: {
      subagentId: spec.subagentId,
      agentPath: spec.agentPath,
      depth: spec.depth,
      objective: spec.objective,
      childSessionId: spec.childSessionId,
      controlStatus: "accepted",
      workflowRunId: spec.workflowRunId,
    },
  };
}

/** Transition guard: only known statuses; closed is terminal (no exit). */
export function transitionControlStatus(from: ControlStatus, to: ControlStatus): boolean {
  if (!CONTROL_STATUS.includes(from) || !CONTROL_STATUS.includes(to)) return false;
  if (from === "closed") return false;
  return true;
}
