import { tool } from "@opencode-ai/plugin";
import { executeSteeringIntake, kindIndex } from "../../src/intake";

/**
 * spark_intake — run a steering intake through the ordered takes
 * (verb -> subagentId -> body -> reason). Returns the shaped record or
 * the fail pair {0xff, err}. Shared by owner and model steering paths.
 */
export default tool({
  description:
    "Run a steering intake: ordered takes verb/subagentId/body/reason, body trimmed and non-empty. Returns the intake record or {status:255, error}.",
  args: {
    verb: tool.schema.string().describe("sendMessage | followupTask | interrupt | stop | close | resume | reopen"),
    subagentId: tool.schema.string().describe("Durable child id"),
    body: tool.schema.string().describe("Note/task text; trimmed, non-empty after trim"),
    reason: tool.schema.string().optional().describe("Human-readable reason, preserved on the record"),
  },
  async execute(args) {
    return JSON.stringify(executeSteeringIntake({ verb: args.verb, subagentId: args.subagentId, body: args.body, reason: args.reason }));
  },
});

export const intake_kind_index = tool({
  description: "Resolve an intake kind to its jumptable index; unknown kinds fail closed (-1).",
  args: { kind: tool.schema.string().describe("Intake kind, e.g. subagent_steering") },
  async execute(args) {
    return JSON.stringify({ kind: args.kind, index: kindIndex(args.kind) });
  },
});
