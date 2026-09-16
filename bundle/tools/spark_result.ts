import { tool } from "@opencode-ai/plugin";
import { validateAgainstContract } from "../../src/contract";
import { validateSubagentResult } from "../../src/envelope";

/**
 * spark_result — validate a worker result envelope. Bounded summary
 * (<=512 chars), text (<=32 KiB bytes), required refs. Optional completion
 * contract: required fields must be present in the result object.
 * Never truncates: over-cap input is rejected with its issue keys.
 */
export default tool({
  description:
    "Validate a Spark worker result envelope (summary<=512 chars, text<=32KiB, artifactRefs+evidenceRefs required, optional completion contract). Returns ok or the issue list; never truncates.",
  args: {
    summary: tool.schema.string().describe("Bounded result summary (<=512 chars)"),
    text: tool.schema.string().optional().describe("Result text (<=32 KiB)"),
    artifactRefs: tool.schema.array(tool.schema.string()).describe("Artifact references, verbatim"),
    evidenceRefs: tool.schema.array(tool.schema.string()).describe("Evidence references, verbatim"),
    errorKind: tool.schema.string().optional().describe("Error kind when the child failed"),
    contract: tool.schema
      .string()
      .optional()
      .describe('Completion contract JSON: {"kind":"default_text"|"declared_schema","requiredFields":[]}'),
  },
  async execute(args) {
    const r = validateSubagentResult({
      summary: args.summary,
      ...(args.text !== undefined ? { text: args.text } : {}),
      artifactRefs: args.artifactRefs,
      evidenceRefs: args.evidenceRefs,
      ...(args.errorKind !== undefined ? { errorKind: args.errorKind } : {}),
    });
    if (!r.ok) return JSON.stringify(r);
    if (args.contract !== undefined) {
      let contract: { kind: "default_text" | "declared_schema"; requiredFields?: string[] };
      try {
        contract = JSON.parse(args.contract);
      } catch {
        return JSON.stringify({ ok: false, issues: [{ key: "malformed_result", detail: "contract is not JSON" }] });
      }
      const c = validateAgainstContract({ summary: r.result.summary, ...(r.result.text !== undefined ? { text: r.result.text } : {}) }, contract);
      if (!c.ok) return JSON.stringify(c);
    }
    return JSON.stringify(r);
  },
});
