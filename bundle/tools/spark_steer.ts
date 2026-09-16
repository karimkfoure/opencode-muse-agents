import { tool } from "@opencode-ai/plugin";
import { driveDefault, driveReplaceOnIdle, type OwnerCommandKind, type OwnerControl } from "../../src/control";
import { executeSteeringIntake } from "../../src/intake";

const RECORD_VERBS: OwnerCommandKind[] = ["sendMessage", "followupTask"];
const SIGNAL_VERBS: OwnerCommandKind[] = ["interrupt", "stop", "close"];
const LIFECYCLE: OwnerCommandKind[] = ["resume", "reopen", "readResult"];

/**
 * spark_steer — owner commands through the wired drivers.
 * Record verbs run driveDefault + build the intake record (body required);
 * signal verbs (interrupt/stop/close) run driveDefault and return directly
 * with the optional reason (no body; see SubagentOwnerReasonParams);
 * lifecycle verbs run driveReplaceOnIdle (refuses non-idle targets).
 */
export default tool({
  description:
    "Steer a worker via owner drivers: message verbs use the default driver + intake record; resume/reopen/readResult require an idle target.",
  args: {
    verb: tool.schema.string().describe("sendMessage|followupTask|interrupt|stop|close|resume|reopen|readResult"),
    subagentId: tool.schema.string().describe("Durable child id"),
    body: tool.schema.string().optional().describe("Note/task text (message verbs)"),
    reason: tool.schema.string().optional().describe("Human-readable reason"),
    targetIdle: tool.schema.boolean().optional().describe("Child idle state (lifecycle verbs)"),
    targetEmpty: tool.schema.boolean().optional().describe("Child empty state (lifecycle verbs)"),
  },
  async execute(args) {
    const verb = args.verb as OwnerCommandKind;
    if (![...RECORD_VERBS, ...SIGNAL_VERBS, ...LIFECYCLE].includes(verb)) {
      return JSON.stringify({
        ok: false,
        error: `unknown verb: got ${JSON.stringify(args.verb)}, want one of ${[...RECORD_VERBS, ...SIGNAL_VERBS, ...LIFECYCLE].join("|")}, do use a supported verb`,
      });
    }
    // Resolve step is the coordinator's control record; the tool operates on
    // the caller's Triple. Idle/empty flags model the resolved state.
    const control: OwnerControl = { base: args.subagentId, entries: [], params: {} };
    if ((LIFECYCLE as string[]).includes(verb)) {
      const driven = driveReplaceOnIdle(control, { idle: args.targetIdle ?? false, empty: args.targetEmpty ?? false });
      if (!driven.ok) return JSON.stringify({ ok: false, reason: driven.reason });
      return JSON.stringify({ ok: true, verb, driver: "replace-on-idle" });
    }
    const driven = driveDefault(control);
    if (!driven.ok) return JSON.stringify({ ok: false, reason: driven.reason });
    if ((SIGNAL_VERBS as string[]).includes(verb)) {
      return JSON.stringify({ ok: true, verb, driver: "default", reason: args.reason ?? null });
    }
    const intake = executeSteeringIntake({
      verb,
      subagentId: args.subagentId,
      body: args.body ?? "",
      reason: args.reason,
    });
    if (intake.status !== 0 || !intake.record) {
      return JSON.stringify({ ok: false, reason: intake.error ?? "intake_failed" });
    }
    return JSON.stringify({ ok: true, verb, driver: "default", intake: intake.record });
  },
});
