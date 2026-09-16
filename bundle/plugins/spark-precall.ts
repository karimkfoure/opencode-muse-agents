import type { Plugin } from "@opencode-ai/plugin";
import { isProactiveDelegationActive, proactiveDelegationPolicy, type ReasoningEffort } from "../../src/precall";

/**
 * spark-precall — effort-gated proactive delegation (PreLLMCall emulation).
 * OpenCode has no pre-LLM-call hook, so policy rides the system prompt:
 * when SPARK_EFFORT is high/ultra (and no opt-out marker), the delegation
 * policy is appended to the system array. User opt-out always wins.
 */
export const SparkPrecall: Plugin = async () => {
  function effort(): ReasoningEffort {
    const v = (process.env.SPARK_EFFORT ?? "medium").toLowerCase();
    const known: ReasoningEffort[] = ["none", "minimal", "low", "medium", "high", "xhigh", "max", "ultra"];
    return (known as string[]).includes(v) ? (v as ReasoningEffort) : "medium";
  }

  return {
    async "experimental.chat.system.transform"(input, output) {
      void input;
      if (process.env.SPARK_NO_DELEGATE === "1") return;
      const e = effort();
      if (!isProactiveDelegationActive(e, false)) return;
      output.system.push(proactiveDelegationPolicy(e));
    },
  };
};

export default { id: "spark-precall", server: SparkPrecall };
