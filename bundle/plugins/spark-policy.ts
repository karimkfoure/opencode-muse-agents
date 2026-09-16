import type { Plugin } from "@opencode-ai/plugin";
import { validateBody, validateSubagentResult } from "../../src/envelope";

/**
 * spark-policy — fail-closed gates on spark tools.
 * tool.execute.before validates args with the same pure functions the
 * tests pin; violations throw, which blocks the call. Nothing here
 * guesses: unknown tools pass through untouched.
 */
export const SparkPolicy: Plugin = async ({ client }) => {
  async function log(message: string, extra: Record<string, unknown>) {
    await client.app.log({ body: { service: "spark-policy", level: "info", message, extra } }).catch(() => undefined);
  }

  return {
    async "tool.execute.before"(input, output) {
      const args = output.args as Record<string, unknown>;
      if (input.tool === "spark_send") {
        const v = validateBody(typeof args.body === "string" ? args.body : "");
        if (!v.ok) throw new Error(`spark policy: ${v.issue.key} (${v.issue.detail})`);
        await log("spark_send admitted", { sessionID: input.sessionID });
        return;
      }
      if (input.tool === "spark_result") {
        const r = validateSubagentResult({
          summary: typeof args.summary === "string" ? args.summary : "",
          ...(typeof args.text === "string" ? { text: args.text } : {}),
          artifactRefs: Array.isArray(args.artifactRefs) ? (args.artifactRefs as string[]) : [],
          evidenceRefs: Array.isArray(args.evidenceRefs) ? (args.evidenceRefs as string[]) : [],
        });
        if (!r.ok) {
          const keys = r.issues.map((i) => i.key).join(",");
          await log("spark_result rejected", { sessionID: input.sessionID, keys });
          throw new Error(`spark policy: result envelope invalid (${keys})`);
        }
        return;
      }
      if (input.tool === "spark_submit") {
        if (!args.objective || typeof args.objective !== "string" || args.objective.trim().length === 0) {
          throw new Error("spark policy: objective is mandatory at spawn");
        }
        return;
      }
    },
    async "permission.ask"(input, output) {
      await log("permission asked", { status: output.status });
    },
  };
};

export default { id: "spark-policy", server: SparkPolicy };
