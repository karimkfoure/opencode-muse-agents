/**
 * mailbox.ts — ledger admission, not messaging.
 *
 * A message is appended, then ADMITTED with ~20 distinct outcomes.
 * Delivery policy is a closed 9-enum; non-canonical combos fail closed.
 * Canonical pairs: queue_next_turn+wake_when_idle, steer_active_turn
 * (running target). Wake iff idle and unfinished.
 */

export type DeliveryPolicy =
  | "advisory"
  | "runtime_context"
  | "user_message"
  | "queue_next_turn"
  | "steer_active_turn"
  | "notify_only"
  | "do_not_wake"
  | "wake_when_idle"
  | "wake_at_safe_point";

export const DELIVERY_POLICIES: readonly DeliveryPolicy[] = [
  "advisory",
  "runtime_context",
  "user_message",
  "queue_next_turn",
  "steer_active_turn",
  "notify_only",
  "do_not_wake",
  "wake_when_idle",
  "wake_at_safe_point",
];

export type WakePolicy = "do_not_wake" | "wake_when_idle" | "wake_at_safe_point";

// Harness-level DoS guard, not a ported constant: the binary has
// inputTooLarge/body_too_large but the exact intake threshold is unevidenced.
export const MAILBOX_BODY_MAX_BYTES = 262144;

export type AdmissionOutcomeKind =
  | "pending_admission"
  | "accepted"
  | "accepted_queue_full"
  | "duplicate_suppressed"
  | "blocked_by_receiver"
  | "reply_context_expired"
  | "reply_context_unavailable"
  | "strict_retention_failed"
  | "message_too_large"
  | "invalid_target"
  | "rate_limited";

export interface MailboxMessage {
  id: string;
  sessionId: string;
  subagentId?: string;
  body: string;
  deliveryPolicy: DeliveryPolicy;
  wakePolicy: WakePolicy;
  inReplyTo?: string;
  conversationId?: string;
}

export interface AdmitInput {
  message: MailboxMessage;
  targetRunning: boolean;
  targetIdle: boolean;
  targetUnfinished: boolean;
  queueFull: boolean;
  duplicate: boolean;
  receiverBlocked: boolean;
  retentionAvailable: boolean;
  replyContextValid?: boolean;
  replyContextGone?: boolean;
  rateLimited?: boolean;
}

/**
 * Admit in binary order: retention -> target -> duplicate -> receiver ->
 * reply context -> queue capacity -> policy/target coherence.
 * Non-canonical policy combos fail closed.
 */
export function admitMessage(input: AdmitInput): AdmissionOutcomeKind {
  const { message } = input;
  if (!retentionAvailable(input)) return "strict_retention_failed";
  if (new TextEncoder().encode(message.body).length > MAILBOX_BODY_MAX_BYTES) return "message_too_large";
  if (!DELIVERY_POLICIES.includes(message.deliveryPolicy)) return "invalid_target";
  if (message.deliveryPolicy === "steer_active_turn" && message.wakePolicy === "do_not_wake") {
    return "invalid_target";
  }
  if (input.rateLimited) return "rate_limited";
  if (input.duplicate) return "duplicate_suppressed";
  if (input.receiverBlocked) return "blocked_by_receiver";
  if (message.inReplyTo !== undefined && input.replyContextGone === true) {
    return "reply_context_unavailable";
  }
  if (message.inReplyTo !== undefined && input.replyContextValid !== true) {
    return "reply_context_expired";
  }
  if (message.deliveryPolicy === "steer_active_turn" && !input.targetRunning) {
    return "invalid_target";
  }
  if (message.deliveryPolicy === "queue_next_turn" && input.queueFull) {
    return "accepted_queue_full";
  }
  if (message.deliveryPolicy === "notify_only" || message.deliveryPolicy === "advisory") {
    return "accepted";
  }
  return "pending_admission";
}

function retentionAvailable(input: AdmitInput): boolean {
  return input.retentionAvailable;
}

/** Canonical pair check: queue_next_turn+wake_when_idle. */
export function isCanonicalPair(delivery: DeliveryPolicy, wake: WakePolicy): boolean {
  return delivery === "queue_next_turn" && wake === "wake_when_idle";
}

/** Wake iff idle and unfinished (wake_when_idle / wake_at_safe_point). */
export function shouldWake(wake: WakePolicy, idle: boolean, unfinished: boolean): boolean {
  if (wake === "do_not_wake") return false;
  return idle && unfinished;
}
