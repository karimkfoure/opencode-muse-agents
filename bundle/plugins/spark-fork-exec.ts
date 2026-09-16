import { appendFile, mkdir, readFile } from "node:fs/promises";
import { join } from "node:path";
import type { Plugin } from "@opencode-ai/plugin";
import { buildForkCall, isDuplicateReceipt } from "../../src/fork";

const RECEIPT_FILE = ".spark/fork-exec.jsonl";

/** Parsed shape of the spark_fork tool's JSON output (see bundle/tools/spark_fork.ts). */
interface ForkToolOutput {
  ok?: unknown;
  newSessionId?: unknown;
  provenance?: {
    sourceSessionId?: unknown;
    commandId?: unknown;
  };
}

function asString(v: unknown): string | undefined {
  return typeof v === "string" && v.length > 0 ? v : undefined;
}

/**
 * spark-fork-exec — make spark_fork EXECUTE for real.
 * Tools get no SDK client; plugins do. On tool.execute.after for
 * spark_fork with ok:true output, this hook calls client.session.fork
 * with the args from buildForkCall (directory = the plugin's
 * directory; messageID = the tool's lastTurnId arg, which the tool
 * output itself omits) and appends an execution receipt line to
 * .spark/fork-exec.jsonl. Never throws out of the hook.
 */
export const SparkForkExec: Plugin = async ({ client, directory }) => {
  async function log(message: string, extra: Record<string, unknown>): Promise<void> {
    await client.app
      .log({ body: { service: "spark-fork-exec", level: "info", message, extra } })
      .catch(() => undefined);
  }

  async function appendReceipt(record: Record<string, unknown>): Promise<void> {
    await mkdir(join(directory, ".spark"), { recursive: true });
    const receiptPath = join(directory, RECEIPT_FILE);
    const commandId = asString(record.commandId);
    if (commandId !== undefined) {
      try {
        const existing = await readFile(receiptPath, "utf8");
        if (isDuplicateReceipt(existing, commandId)) return;
      } catch {
        // Missing/unreadable file means no duplicate; proceed to append.
      }
    }
    const line = `${JSON.stringify(record)}\n`;
    await appendFile(receiptPath, line, "utf8");
  }

  return {
    async "tool.execute.after"(input, output) {
      if (input.tool !== "spark_fork") return;
      let parsed: ForkToolOutput;
      try {
        parsed = JSON.parse(output.output) as ForkToolOutput;
      } catch {
        await log("fork output unparseable, skipping execution", { sessionID: input.sessionID });
        return;
      }
      if (parsed.ok !== true) return;
      const args = (input.args ?? {}) as Record<string, unknown>;
      const sourceSessionId = asString(parsed.provenance?.sourceSessionId) ?? asString(args.sourceSessionId);
      const newSessionId = asString(parsed.newSessionId) ?? asString(args.newSessionId);
      const commandId = asString(parsed.provenance?.commandId) ?? asString(args.commandId);
      const lastTurnId = asString(args.lastTurnId);
      if (!sourceSessionId || !newSessionId || !commandId) {
        await log("fork record incomplete, skipping execution", { sessionID: input.sessionID });
        return;
      }
      const base = { sourceSessionId, commandId, directory };
      try {
        const res = (await client.session.fork(
          buildForkCall(lastTurnId ? { ...base, lastTurnId } : base),
        )) as unknown as { data?: { id?: unknown }; id?: unknown };
        const forkedSessionId =
          asString(res?.data?.id) ?? asString(res?.id) ?? newSessionId;
        await appendReceipt({ ok: true, sourceSessionId, newSessionId, commandId, forkedSessionId });
        await log("fork executed", { sourceSessionId, newSessionId, forkedSessionId });
      } catch (err) {
        try {
          await appendReceipt({
            ok: false,
            sourceSessionId,
            newSessionId,
            commandId,
            error: err instanceof Error ? err.message : String(err),
          });
        } catch {
          // Receipt write is best-effort; the hook must never throw.
        }
        await log("fork execution failed", { sourceSessionId, newSessionId });
      }
    },
  };
};

export default { id: "spark-fork-exec", server: SparkForkExec };
