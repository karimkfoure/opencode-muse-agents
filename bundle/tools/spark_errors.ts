import { tool } from "@opencode-ai/plugin";
import { catalogKeys, lookupError } from "../../src/errors";

export const errors_lookup = tool({
  description: "Resolve a keyed error from the central catalog. Unknown keys fail closed (never default text).",
  args: { key: tool.schema.string().describe("Catalog key, e.g. fanout_limit, max_depth, command_id_reused") },
  async execute(args) {
    return JSON.stringify(lookupError(args.key));
  },
});

export const errors_catalog = tool({
  description: "List all catalogued error keys (for compat checks across versions).",
  args: {},
  async execute() {
    return JSON.stringify(catalogKeys());
  },
});
