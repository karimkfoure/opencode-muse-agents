/**
 * precall.ts — model-facing tuning: effort-gated proactive delegation.
 *
 * At high reasoning effort, proactive workflow delegation activates via
 * injected policy context (decompose early into tracks; user opt-out
 * always wins). First turn runs cheap. Roles carry model fallback chains.
 */

export type ReasoningEffort = "none" | "minimal" | "low" | "medium" | "high" | "xhigh" | "max" | "ultra";

/** Proactive delegation is active at ultra; user opt-out always wins. */
export function isProactiveDelegationActive(effort: ReasoningEffort, userOptOut: boolean): boolean {
  if (userOptOut) return false;
  return effort === "ultra";
}

export function proactiveDelegationPolicy(effort: ReasoningEffort): string {
  if (!isProactiveDelegationActive(effort, false)) {
    return "Delegate only when the user explicitly requests parallel or background work.";
  }
  return [
    "Proactive delegation is active.",
    "When a task decomposes into independent investigation, implementation,",
    "verification, or synthesis tracks, fan out early before repository discovery.",
    "When decomposition value is uncertain, briefly propose it instead of",
    "silently defaulting to one turn. Vague wording is not an opt-out.",
    "Do not use background workers for atomic quick checks or single small edits.",
    'User opt-outs ("no background workers", "single agent") always win.',
  ].join(" ");
}

export interface RoleFallback {
  role: string;
  models: string[];
}

/** First configured model wins; empty chain means unconfigured (fail closed at call time). */
export function selectModel(chain: RoleFallback): string | null {
  return chain.models.length > 0 ? chain.models[0] : null;
}

/** First turn runs at minimal effort regardless of configured effort. */
export function firstTurnEffort(): ReasoningEffort {
  return "minimal";
}
