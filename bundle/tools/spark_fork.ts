import { tool } from "@opencode-ai/plugin";
import { checkForkIds, planFork } from "../../src/fork";

/**
 * spark_fork — record a history-branch fork with opaque provenance.
 * The cut cursor is display-only: never parsed, never passed to methods.
 * Execution itself uses the host session.fork; this tool owns the record.
 */
export default tool({
  description:
    "Record a session fork (history branch, not worker spawn) with opaque provenance. Execution happens via the host session.fork; this tool owns the provenance record. Cut cursor is display-only and never parsed.",
  args: {
    sourceSessionId: tool.schema.string().describe("Source session"),
    newSessionId: tool.schema.string().describe("New session id (must differ from source)"),
    servedCutCursor: tool.schema.string().describe("Opaque cursor served by the host (display-only)"),
    lastTurnId: tool.schema.string().optional().describe("Last completed turn to copy, inclusive"),
    commandId: tool.schema.string().describe("Idempotency key"),
  },
  async execute(args) {
    if (args.lastTurnId !== undefined && (typeof args.lastTurnId !== "string" || args.lastTurnId.length === 0)) {
      return JSON.stringify({ ok: false, error: "lastTurnId must name a completed turn" });
    }
    if (!checkForkIds(args.newSessionId, args.sourceSessionId)) {
      return JSON.stringify({
        ok: false,
        error: `ForkIdEqualsSourceId: got newSessionId=${JSON.stringify(args.newSessionId)} == sourceSessionId=${JSON.stringify(args.sourceSessionId)}, want distinct ids, do mint a fresh newSessionId`,
      });
    }
    const p = planFork(
      {
        sourceSessionId: args.sourceSessionId,
        commandId: args.commandId,
        ...(args.lastTurnId ? { cutPoint: { lastTurnId: args.lastTurnId } } : {}),
      },
      args.newSessionId,
      args.servedCutCursor,
    );
    return JSON.stringify({ ok: true, ...p });
  },
});
