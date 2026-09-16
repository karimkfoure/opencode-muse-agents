/**
 * admission.ts — spawn admission: resolve -> status dispatch -> capacity ->
 * keyed errors -> context attach -> staged commit.
 *
 * Order is verbatim from subagent_spawn_validate. Rejections are built
 * records carrying catalog keys, never thrown exceptions.
 */
import { lookupError, type SpawnRejectionKey } from "./errors";

export type SpawnStatus = "accepted" | "deferred" | "rejected";

export interface CapacityState {
  rootLimit: number;
  rootUsed: number;
  activeLimit: number;
  activeUsed: number;
  maxDepth: number;
  fanoutLimit: number;
  fanoutUsed: number;
}

export interface SpawnRequest {
  commandId: string;
  agentPath: string;
  objective: string;
  depth: number;
  parentSessionId: string;
  parentRunId: string;
  /** -1 off, 0 shared, >0 isolated identity length */
  worktreeMode: number;
  status?: SpawnStatus;
}

export interface AdmissionAccept {
  admitted: true;
  status: Exclude<SpawnStatus, "rejected">;
  commitFields: {
    schema_version: number;
    spawn_decision: string;
    parent_binding: string;
    agent_lineage_admission: string;
    accepted: string;
    description: string;
  };
}

export interface AdmissionReject {
  admitted: false;
  key: SpawnRejectionKey;
  message: string;
}

export interface AdmissionReplay {
  admitted: true;
  replay: true;
  status: Exclude<SpawnStatus, "rejected">;
  commitFields: AdmissionAccept["commitFields"];
}

/** Ledger: commandId -> canonical payload fingerprint of the admitted intent. */
export type CommandLedger = Map<string, string>;

/** Canonical payload fingerprint for idempotency comparison. */
export function fingerprintSpawnIntent(req: Pick<SpawnRequest, "agentPath" | "objective" | "depth" | "parentSessionId" | "parentRunId">): string {
  return JSON.stringify([req.agentPath, req.objective, req.depth, req.parentSessionId, req.parentRunId]);
}

export type AdmissionOutcome = AdmissionAccept | AdmissionReject | AdmissionReplay;

function reject(key: SpawnRejectionKey): AdmissionReject {
  const found = lookupError(key);
  return { admitted: false, key, message: found.ok ? found.message : key };
}

/**
 * Admit a spawn. Checks run in binary order:
 * 1. required fields (objective mandatory, ids non-empty),
 * 2. idempotency ledger (identical replay joins; different payload
 *    under the same commandId is command_id_reused),
 * 3. explicit rejected status,
 * 4. worktreeMode shape (-1/0/positive-int),
 * 5. numerics/caps (finite numbers, integer depth, harness objective cap),
 * 6. capacity roots (root, active, fan-out, depth),
 * 7. accept (accepted|deferred) with the 6-field commit record.
 * The admitted fingerprint is recorded in the ledger by the caller
 * (or passed pre-recorded); this function never mutates it.
 */
export function admitSpawn(
  req: SpawnRequest,
  cap: CapacityState,
  ledger?: CommandLedger,
): AdmissionOutcome {
  if (!req.objective || req.objective.trim().length === 0) {
    return reject("policy_denied");
  }
  if (!req.agentPath || !req.parentSessionId || !req.parentRunId || !req.commandId) {
    return reject("missing_parent");
  }
  if (ledger) {
    const seen = ledger.get(req.commandId);
    const mine = fingerprintSpawnIntent(req);
    if (seen !== undefined) {
      if (seen !== mine) return reject("command_id_reused");
      return {
        admitted: true,
        replay: true,
        status: "accepted",
        commitFields: commitFieldsFor(req, "accepted"),
      };
    }
  }
  if (req.status === "rejected") return reject("child_run_rejected");
  if (!Number.isInteger(req.worktreeMode) || (req.worktreeMode !== -1 && req.worktreeMode < 0)) return reject("worktree_mode_invalid");
  // Harness-level cap: objectives above 64 Ki chars never admit (fail closed).
  if (req.objective.length > 65536) return reject("policy_denied");
  if (!Number.isInteger(req.depth)) return reject("policy_denied");
  if (req.depth < 0) return reject("missing_parent");
  for (const v of [cap.rootLimit, cap.rootUsed, cap.activeLimit, cap.activeUsed, cap.fanoutLimit, cap.fanoutUsed, cap.maxDepth]) {
    if (typeof v !== "number" || !Number.isFinite(v) || v < 0) return reject("policy_denied");
  }
  if (cap.rootUsed >= cap.rootLimit) return reject("root_capacity_exhausted");
  if (cap.activeUsed >= cap.activeLimit) return reject("active_capacity");
  if (cap.fanoutUsed >= cap.fanoutLimit) return reject("fanout_limit");
  if (req.depth + 1 > cap.maxDepth) return reject("max_depth");
  const status = req.status ?? "accepted";
  return { admitted: true, status, commitFields: commitFieldsFor(req, status) };
}

function commitFieldsFor(req: SpawnRequest, status: Exclude<SpawnStatus, "rejected">): AdmissionAccept["commitFields"] {
  return {
    schema_version: 1,
    spawn_decision: status,
    parent_binding: `${req.parentSessionId}/${req.parentRunId}`,
    agent_lineage_admission: req.agentPath,
    accepted: status,
    description: req.objective,
  };
}
