/**
 * Plugin entry: composes the four Spark hooks into one PluginModule.
 * opencode.json: { "plugin": ["opencode-muse-agents"] }.
 */
import type { Hooks, Plugin } from "@opencode-ai/plugin";
import { SparkNotify } from "../bundle/plugins/spark-notify";
import { SparkForkExec } from "../bundle/plugins/spark-fork-exec";
import { SparkPolicy } from "../bundle/plugins/spark-policy";
import { SparkCompact } from "../bundle/plugins/spark-compact";
import { SparkPrecall } from "../bundle/plugins/spark-precall";

type Ctx = Parameters<Plugin>[0];

async function merge(base: Hooks, add: Hooks): Promise<Hooks> {
  const out: Hooks = { ...base };
  if (add.event) {
    const prev = out.event;
    const next = add.event;
    out.event = prev ? async (i) => { await prev(i); await next(i); } : next;
  }
  const keys = ["tool.execute.before", "tool.execute.after", "experimental.session.compacting", "experimental.chat.system.transform", "permission.ask", "chat.message"] as const;
  for (const k of keys) {
    const fn = (add as Record<string, unknown>)[k] as ((...a: never[]) => Promise<void>) | undefined;
    if (!fn) continue;
    const prev = (out as Record<string, unknown>)[k] as ((...a: never[]) => Promise<void>) | undefined;
    (out as Record<string, unknown>)[k] = prev
      ? async (...a: never[]) => { await prev(...a); await fn(...a); }
      : fn;
  }
  if (add.dispose) {
    const prev = out.dispose;
    const next = add.dispose;
    out.dispose = prev ? async () => { await prev(); await next(); } : next;
  }
  return out;
}

export const SparkPlugin: Plugin = async (ctx: Ctx) => {
  let hooks: Hooks = {};
  for (const make of [SparkNotify, SparkForkExec, SparkPolicy, SparkCompact, SparkPrecall]) {
    hooks = await merge(hooks, await make(ctx));
  }
  return hooks;
};

export { SparkNotify, SparkForkExec, SparkPolicy, SparkCompact, SparkPrecall };
export default { id: "opencode-muse-agents", server: SparkPlugin };
