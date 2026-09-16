import { readdir, readFile } from "node:fs/promises";
import { join } from "node:path";
import type { Plugin } from "@opencode-ai/plugin";

/**
 * spark-compact — control state survives compaction.
 * Injects the goal, pending mailbox ids, and the next-step reminder so a
 * compacted session resumes as coordinator/worker/reviewer instead of a
 * blank slate. Never replaces the prompt, only appends context.
 */
export const SparkCompact: Plugin = async ({ directory }) => {
  return {
    async "experimental.session.compacting"(input, output) {
      let pending = 0;
      try {
        const files = await readdir(join(directory, ".spark/mailbox"));
        for (const f of files) {
          if (!f.endsWith(".jsonl")) continue;
          const lines = (await readFile(join(directory, ".spark/mailbox", f), "utf8")).split("\n");
          for (const line of lines) {
            if (line.includes("pending_admission")) pending++;
          }
        }
      } catch {
        pending = 0;
      }
      output.context.push(
        `Spark continuation state for ${input.sessionID}: ${pending} pending mailbox record(s). ` +
          "Preserve the current decision, evidence paths, assigned work, pending run IDs, and next unfinished step. " +
          "A summary must not reactivate a paused goal. Results live in evidence files, never only in chat.",
      );
    },
  };
};

export default { id: "spark-compact", server: SparkCompact };
