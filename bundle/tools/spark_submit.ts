import { tool } from "@opencode-ai/plugin";
import { admitSpawn, fingerprintSpawnIntent, type CommandLedger } from "../../src/admission";
import { createChildRecord } from "../../src/child";
import { mintCommandId } from "../../src/ids";

/** Process-local idempotency ledger: commandId -> admitted intent fingerprint. */
const ledger: CommandLedger = new Map();

/**
 * spark_submit — admit a worker spawn through the full gate
 * (required fields -> status -> capacity roots -> depth) and build the
 * child record. Returns the 6-field commit record or a keyed rejection.
 * Retries must reuse the returned/provided commandId, never mint anew.
 */
export default tool({
  description:
    "Admit a Spark worker spawn: validates objective/ids, checks capacity roots and depth, builds the child record. Returns commit fields or a keyed rejection (e.g. max_depth, fanout_limit).",
  args: {
    agentPath: tool.schema.string().describe("Worker agent name, e.g. spark-worker"),
    objective: tool.schema.string().describe("The one assigned unit (mandatory)"),
    childSessionId: tool.schema.string().describe("The worker session id"),
    workflowRunId: tool.schema.string().describe("Parent run linkage id"),
    depth: tool.schema.number().describe("Worker depth (child depth = depth+1 <= maxDepth)"),
    maxDepth: tool.schema.number().describe("Lineage depth limit"),
    rootLimit: tool.schema.number().describe("Root capacity limit"),
    rootUsed: tool.schema.number().describe("Root capacity used"),
    activeLimit: tool.schema.number().describe("Active capacity limit"),
    activeUsed: tool.schema.number().describe("Active capacity used"),
    fanoutLimit: tool.schema.number().optional().describe("Fan-out limit (default: no bound)"),
    fanoutUsed: tool.schema.number().optional().describe("Fan-out used"),
    commandId: tool.schema.string().optional().describe("Idempotency key (minted if omitted; reuse on retry)"),
    worktreeMode: tool.schema.number().optional().describe("Worktree mode: -1 off, 0 shared, >0 isolated"),
    parentSessionId: tool.schema.string().optional().describe("Defaults to the current session"),
  },
  async execute(args, context) {
    const commandId = args.commandId ?? mintCommandId();
    const req = {
      commandId,
      agentPath: args.agentPath,
      objective: args.objective,
      depth: args.depth,
      parentSessionId: args.parentSessionId ?? context.sessionID,
      parentRunId: args.workflowRunId,
      worktreeMode: args.worktreeMode ?? 0,
    };
    const admitted = admitSpawn(
      req,
      {
        rootLimit: args.rootLimit,
        rootUsed: args.rootUsed,
        activeLimit: args.activeLimit,
        activeUsed: args.activeUsed,
        maxDepth: args.maxDepth,
        fanoutLimit: args.fanoutLimit ?? Number.MAX_SAFE_INTEGER,
        fanoutUsed: args.fanoutUsed ?? 0,
      },
      ledger,
    );
    if (!admitted.admitted) return JSON.stringify({ admitted: false, key: admitted.key, message: admitted.message, commandId });
    if (!("replay" in admitted) || !admitted.replay) {
      ledger.set(commandId, fingerprintSpawnIntent(req));
    }
    const child = createChildRecord({
      subagentId: commandId,
      agentPath: args.agentPath,
      depth: args.depth,
      objective: args.objective,
      childSessionId: args.childSessionId,
      workflowRunId: args.workflowRunId,
      maxDepth: args.maxDepth,
    });
    if (!child.ok) return JSON.stringify({ admitted: false, key: "policy_denied", issues: child.issues, commandId });
    return JSON.stringify({ admitted: true, status: admitted.status, commandId, commit: admitted.commitFields, child: child.record });
  },
});
