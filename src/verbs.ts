/**
 * verbs.ts — the 12 Agent RPC verbs and their spark counterparts.
 * The verbs are verbatim from the binary (@0x118f1dc cluster);
 * the mapping is the port contract: same capability, spark names.
 */

export const AGENT_VERBS = [
  "Agent.start",
  "Agent.followup",
  "Agent.send",
  "AgentAttempt.getStatus",
  "AgentAttempt.result",
  "AgentAttempt.interrupt",
  "Pipeline.start",
  "Pipeline.result",
  "ParallelGroup.start",
  "ParallelGroup.result",
  "Phase.create",
  "Phase.log",
] as const;

export type AgentVerb = (typeof AGENTS)[number];

/** Canonical verb list (12, order as packed in the binary). */
export function agentVerbs(): readonly string[] {
  return AGENT_VERBS;
}

const AGENTS = AGENT_VERBS;

/** Spark counterpart per verb (tool or pattern that carries it). */
export const VERB_PORT: Record<AgentVerb, string> = {
  "Agent.start": "spark_submit (admission + child record)",
  "Agent.followup": "spark_steer verb=followupTask",
  "Agent.send": "spark_send (mailbox append)",
  "AgentAttempt.getStatus": "spark_steer verb=status (control read)",
  "AgentAttempt.result": "spark_result (bounded envelope)",
  "AgentAttempt.interrupt": "spark_steer verb=interrupt",
  "Pipeline.start": "coordinator task() fan-out (plan first)",
  "Pipeline.result": "spark_result (folded, reviewer-gated)",
  "ParallelGroup.start": "coordinator task(..., run_in_background) fan-out",
  "ParallelGroup.result": "background_output/task join + spark_result each",
  "Phase.create": "spark-plan-protocol skill (unit record)",
  "Phase.log": "evidence files + ledger appends",
};
