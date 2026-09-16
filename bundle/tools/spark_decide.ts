import { existsSync, mkdirSync, readFileSync, readdirSync, renameSync, statSync, unlinkSync, writeFileSync } from "node:fs";
import { join } from "node:path";
import { tool } from "@opencode-ai/plugin";
import { decisionsEqual, isEffectiveVerdict, runJudgeLane, type ApprovalDecision, type RiskLevel } from "../../src/policy";
import { mintCommandId } from "../../src/ids";

const VERDICTS_FILE = ".spark/verdicts.jsonl";
const MAX_VERDICTS_BYTES = 256 * 1024;
const MAX_ROTATED_VERDICTS = 5;

interface StoredVerdict {
  decision: ApprovalDecision;
  decidedBy: string;
  commandId: string;
  persisted: true;
}

function readVerdicts(worktree: string): StoredVerdict[] {
  const p = join(worktree, VERDICTS_FILE);
  if (!existsSync(p)) return [];
  const out: StoredVerdict[] = [];
  for (const line of readFileSync(p, "utf8").split("\n")) {
    if (!line.trim()) continue;
    try {
      out.push(JSON.parse(line) as StoredVerdict);
    } catch {
      // Corrupt verdict lines fail closed: skipped, never guessed.
    }
  }
  return out;
}

function rotateVerdictsIfNeeded(worktree: string): void {
  try {
    const p = join(worktree, VERDICTS_FILE);
    if (!existsSync(p)) return;
    if (statSync(p).size <= MAX_VERDICTS_BYTES) return;
    const dir = join(worktree, ".spark");
    renameSync(p, join(dir, `verdicts-${Date.now()}.jsonl`));
    const rotated = readdirSync(dir)
      .filter((f) => /^verdicts-\d+\.jsonl$/.test(f))
      .sort();
    while (rotated.length > MAX_ROTATED_VERDICTS) {
      const oldest = rotated.shift()!;
      unlinkSync(join(dir, oldest));
    }
  } catch {
    // Rotation failures must not fail the decision — continue to append.
  }
}

/**
 * spark_decide — two-lane approval decisions with durable verdicts.
 * Candidates are data ({id, policies[], riskCap}); first match wins,
 * else human fallback. persist:true appends the verdict; a verdict only
 * counts when a matching durable record exists (read-back check).
 */
export default tool({
  description:
    "Decide an approval through ordered judge candidates (first match wins, else human). Persisted verdicts are read back; only durable verdicts count.",
  args: {
    actionDigest: tool.schema.string().describe("Canonical action digest"),
    policy: tool.schema.string().describe("Policy name"),
    riskLevel: tool.schema.string().describe("low | medium"),
    candidates: tool.schema
      .string()
      .describe('JSON array of {id, policies:[], riskCap:"low"|"medium"}'),
    persist: tool.schema.boolean().optional().describe("Append the verdict durably (default true)"),
    commandId: tool.schema.string().optional().describe("Idempotency key (minted if omitted)"),
  },
  async execute(args, context) {
    const riskLevel = args.riskLevel as RiskLevel;
    if (riskLevel !== "low" && riskLevel !== "medium") {
      return JSON.stringify({ ok: false, error: "riskLevel must be low|medium" });
    }
    const commandId = args.commandId ?? mintCommandId();
    let candidates: { id: string; policies: string[]; riskCap: RiskLevel }[];
    try {
      candidates = JSON.parse(args.candidates);
      if (!Array.isArray(candidates)) throw new Error("not an array");
    } catch {
      return JSON.stringify({ ok: false, error: "candidates must be a JSON array" });
    }
    {
      const malformed = { ok: false, error: "candidates must be a JSON array of {id, policies[], riskCap}" };
      for (const c of candidates as unknown[]) {
        const id = (c as { id?: unknown } | null)?.id;
        const policies = (c as { policies?: unknown } | null)?.policies;
        if (typeof c !== "object" || c === null || typeof id !== "string" || !Array.isArray(policies) || !policies.every((p) => typeof p === "string")) {
          return JSON.stringify(malformed);
        }
        const riskCap = (c as { riskCap?: unknown }).riskCap;
        if (riskCap !== "low" && riskCap !== "medium") {
          return JSON.stringify({ ok: false, error: `candidate ${id} needs riskCap low|medium` });
        }
      }
    }
    const outcome = runJudgeLane(
      candidates.map((c) => ({
        id: c.id,
        judge: (action) => {
          if (!c.policies.includes(action.policy)) return null;
          const order: RiskLevel[] = ["low", "medium"];
          if (order.indexOf(riskLevel) > order.indexOf(c.riskCap)) return null;
          return { actionDigest: action.actionDigest, policy: action.policy, riskLevel, userAuthorization: "unknown" as const };
        },
      })),
      { actionDigest: args.actionDigest, policy: args.policy },
    );
    if (!outcome.matched) return JSON.stringify({ ok: true, matched: false, note: "human fallback", commandId });
    const record: StoredVerdict = {
      decision: outcome.decision,
      decidedBy: outcome.by,
      commandId,
      persisted: true,
    };
    if (args.persist !== false) {
      mkdirSync(join(context.worktree, ".spark"), { recursive: true });
      rotateVerdictsIfNeeded(context.worktree);
      writeFileSync(join(context.worktree, VERDICTS_FILE), JSON.stringify(record) + "\n", { flag: "a" });
      const back = readVerdicts(context.worktree).find(
        (v) => v.commandId === commandId && decisionsEqual(v.decision, record.decision),
      );
      if (!back || !isEffectiveVerdict({ ...back, persisted: true })) {
        return JSON.stringify({
          ok: false,
          error: `verdict read-back failed: got no durable verdict for commandId=${JSON.stringify(commandId)}, want a persisted verdict, do retry the same request with the same commandId`,
        });
      }
    }
    return JSON.stringify({ ok: true, matched: true, by: outcome.by, decision: outcome.decision, commandId, effective: true });
  },
});
