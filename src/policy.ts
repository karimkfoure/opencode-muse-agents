/**
 * policy.ts — policy separated from mechanism.
 *
 * Staged approval requirements, a judge lane + human lane with
 * first-fire-wins ordering, field-wise decision equality, and durable
 * verdict records (verdicts die without them). The mechanism never asks
 * "should I"; it asks the committed policy record.
 */

export type ApprovalMode = "allow_all" | "on_request" | "deny_unmatched" | "prompt_unmatched";

export type RiskLevel = "low" | "medium";

export interface ApprovalDecision {
  actionDigest: string;
  policy: string;
  riskLevel: RiskLevel;
  userAuthorization: "unknown" | "approved" | "denied";
  rationale?: string;
}

export interface JudgeCandidate {
  id: string;
  /** Returns a decision, or null to pass to the next candidate. */
  judge: (action: { actionDigest: string; policy: string }) => ApprovalDecision | null;
}

export type JudgeOutcome =
  | { matched: true; by: string; decision: ApprovalDecision }
  | { matched: false };

/** First-fire-wins across ordered candidates; exhausted -> human fallback. */
export function runJudgeLane(
  candidates: JudgeCandidate[],
  action: { actionDigest: string; policy: string },
): JudgeOutcome {
  for (const c of candidates) {
    const d = c.judge(action);
    if (d) return { matched: true, by: c.id, decision: d };
  }
  return { matched: false };
}

/**
 * Field-wise decision equality (never pointer/reference equality):
 * actionDigest + policy + riskLevel + userAuthorization all equal.
 */
export function decisionsEqual(a: ApprovalDecision, b: ApprovalDecision): boolean {
  return (
    a.actionDigest === b.actionDigest &&
    a.policy === b.policy &&
    a.riskLevel === b.riskLevel &&
    a.userAuthorization === b.userAuthorization
  );
}

export interface VerdictRecord {
  decision: ApprovalDecision;
  decidedBy: string;
  commandId: string;
  persisted: boolean;
}

/** A verdict only counts when durably recorded. */
export function isEffectiveVerdict(v: VerdictRecord): boolean {
  return v.persisted;
}

export type ApprovalSubjectKind = "shell_command" | "tool_action" | "filesystem" | "network" | "process" | "url";

export interface ApprovalSubject {
  kind: ApprovalSubjectKind;
  target: string;
}

/** Stage matcher: shell prefix, exact tool action, filesystem scope. */
export function matchStage(
  subject: ApprovalSubject,
  rule: { shellPrefix?: string; toolAction?: string; fsScope?: string },
): boolean {
  if (rule.shellPrefix !== undefined) {
    if (subject.kind !== "shell_command") return false;
    return subject.target.startsWith(rule.shellPrefix);
  }
  if (rule.toolAction !== undefined) {
    if (subject.kind !== "tool_action") return false;
    return subject.target === rule.toolAction;
  }
  if (rule.fsScope !== undefined) {
    if (subject.kind !== "filesystem") return false;
    return subject.target === rule.fsScope || subject.target.startsWith(rule.fsScope + "/");
  }
  return false;
}
