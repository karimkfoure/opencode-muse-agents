import { join } from "node:path";
import { mkdir, appendFile } from "node:fs/promises";
import { tool } from "@opencode-ai/plugin";
import { validateBody } from "../../src/envelope";
import { assertSafeSegment } from "../../src/paths";
import { DELIVERY_POLICIES, admitMessage, type DeliveryPolicy, type WakePolicy } from "../../src/mailbox";
import { mintCommandId } from "../../src/ids";

const MAILBOX_DIR = ".spark/mailbox";

/**
 * spark_send — append a note to a session mailbox (ledger, not a socket).
 * Validates + appends durably; routing/wake is decided by the notify
 * plugin on session.idle. Returns the appended record (admission stays
 * pending until the fold runs).
 */
export default tool({
  description:
    "Append a note to a Spark session mailbox. Body is trimmed and rejected when empty. Delivery policy must be one of the closed 9-enum; non-canonical combos fail closed.",
  args: {
    targetSessionId: tool.schema.string().describe("Target session id (uuid)"),
    body: tool.schema.string().describe("Note text; trimmed, non-empty after trim"),
    deliveryPolicy: tool.schema.string().describe(`One of: ${DELIVERY_POLICIES.join(", ")}`),
    wakePolicy: tool.schema.string().describe("One of: do_not_wake, wake_when_idle, wake_at_safe_point"),
    subagentId: tool.schema.string().optional().describe("Child id when steering a worker"),
    inReplyTo: tool.schema.string().optional().describe("Reply token being answered"),
    conversationId: tool.schema.string().optional().describe("Thread id"),
    targetRunning: tool.schema.boolean().optional().describe("Target running (for steer admission)"),
    targetIdle: tool.schema.boolean().optional().describe("Target idle (for wake admission)"),
    targetUnfinished: tool.schema.boolean().optional().describe("Target unfinished (for wake admission)"),
    queueFull: tool.schema.boolean().optional().describe("Queue full signal"),
    duplicate: tool.schema.boolean().optional().describe("Already delivered (dedupe hit)"),
  },
  async execute(args, context) {
    const seg = assertSafeSegment(args.targetSessionId);
    if (!seg.ok) {
      return JSON.stringify({ admitted: false, admission: "invalid_target", reason: seg.reason });
    }
    if (!(DELIVERY_POLICIES as readonly string[]).includes(args.deliveryPolicy)) {
      return `rejected: invalid_target (unknown delivery policy ${JSON.stringify(args.deliveryPolicy)})`;
    }
    if (!["do_not_wake", "wake_when_idle", "wake_at_safe_point"].includes(args.wakePolicy)) {
      return `rejected: invalid_target (unknown wake policy ${JSON.stringify(args.wakePolicy)})`;
    }
    const v = validateBody(args.body);
    if (!v.ok) return `rejected: empty_after_trim (${v.issue.detail})`;
    const id = mintCommandId();
    const admission = admitMessage({
      message: {
        id,
        sessionId: args.targetSessionId,
        body: v.trimmed,
        deliveryPolicy: args.deliveryPolicy as DeliveryPolicy,
        wakePolicy: args.wakePolicy as WakePolicy,
      },
      targetRunning: args.targetRunning ?? false,
      targetIdle: args.targetIdle ?? true,
      targetUnfinished: args.targetUnfinished ?? true,
      queueFull: args.queueFull ?? false,
      duplicate: args.duplicate ?? false,
      receiverBlocked: false,
      retentionAvailable: true,
    });
    if (admission !== "pending_admission" && admission !== "accepted" && admission !== "accepted_queue_full") {
      return JSON.stringify({ admitted: false, admission });
    }
    const message = {
      id,
      sessionId: args.targetSessionId,
      ...(args.subagentId ? { subagentId: args.subagentId } : {}),
      body: v.trimmed,
      deliveryPolicy: args.deliveryPolicy as DeliveryPolicy,
      wakePolicy: args.wakePolicy as WakePolicy,
      ...(args.inReplyTo ? { inReplyTo: args.inReplyTo } : {}),
      ...(args.conversationId ? { conversationId: args.conversationId } : {}),
      admitted: admission,
      at: new Date().toISOString(),
    };
    const dir = join(context.worktree, MAILBOX_DIR);
    await mkdir(dir, { recursive: true });
    await appendFile(join(dir, `${args.targetSessionId}.jsonl`), JSON.stringify(message) + "\n", "utf8");
    return JSON.stringify({ messageId: message.id, admission });
  },
});
