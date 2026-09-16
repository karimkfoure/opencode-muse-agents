import { describe, expect, test } from "bun:test";
import {
  admitMessage,
  isCanonicalPair,
  shouldWake,
} from "../src/mailbox";

describe("admitMessage (binary order)", () => {
  const base = {
    message: {
      id: "m1",
      sessionId: "s1",
      body: "hello",
      deliveryPolicy: "queue_next_turn" as const,
      wakePolicy: "wake_when_idle" as const,
    },
    targetRunning: false,
    targetIdle: true,
    targetUnfinished: true,
    queueFull: false,
    duplicate: false,
    receiverBlocked: false,
    retentionAvailable: true,
  };
  test("retention loss fails first", () => {
    expect(admitMessage({ ...base, retentionAvailable: false })).toBe("strict_retention_failed");
  });
  test("duplicate suppressed before receiver check", () => {
    expect(admitMessage({ ...base, duplicate: true, receiverBlocked: true })).toBe("duplicate_suppressed");
  });
  test("blocked receiver", () => {
    expect(admitMessage({ ...base, receiverBlocked: true })).toBe("blocked_by_receiver");
  });
  test("stale reply context expires", () => {
    const m = { ...base, message: { ...base.message, inReplyTo: "old" }, replyContextValid: false };
    expect(admitMessage(m)).toBe("reply_context_expired");
    expect(admitMessage({ ...m, replyContextValid: true })).toBe("pending_admission");
  });
  test("steer requires a running target", () => {
    const m = { ...base, message: { ...base.message, deliveryPolicy: "steer_active_turn" as const } };
    expect(admitMessage(m)).toBe("invalid_target");
    expect(admitMessage({ ...m, targetRunning: true })).toBe("pending_admission");
  });
  test("full queue admits as accepted_queue_full", () => {
    expect(admitMessage({ ...base, queueFull: true })).toBe("accepted_queue_full");
  });
  test("notify_only / advisory accept without queueing", () => {
    expect(
      admitMessage({ ...base, message: { ...base.message, deliveryPolicy: "notify_only" } }),
    ).toBe("accepted");
  });
  test("steer + do_not_wake is forbidden", () => {
    const m = {
      ...base,
      message: { ...base.message, deliveryPolicy: "steer_active_turn" as const, wakePolicy: "do_not_wake" as const },
      targetRunning: true,
    };
    expect(admitMessage(m)).toBe("invalid_target");
  });
  test("rate limited and reply gone splits", () => {
    expect(admitMessage({ ...base, rateLimited: true })).toBe("rate_limited");
    const m = { ...base, message: { ...base.message, inReplyTo: "t" }, replyContextGone: true };
    expect(admitMessage(m)).toBe("reply_context_unavailable");
  });
  test("unknown policy fails closed", () => {
    const m = { ...base, message: { ...base.message, deliveryPolicy: "teleport" as never } };
    expect(admitMessage(m)).toBe("invalid_target");
  });
});

describe("isCanonicalPair / shouldWake", () => {
  test("queue_next_turn + wake_when_idle is canonical", () => {
    expect(isCanonicalPair("queue_next_turn", "wake_when_idle")).toBe(true);
    expect(isCanonicalPair("queue_next_turn", "do_not_wake")).toBe(false);
  });
  test("wake iff idle and unfinished; do_not_wake never", () => {
    expect(shouldWake("wake_when_idle", true, true)).toBe(true);
    expect(shouldWake("wake_when_idle", false, true)).toBe(false);
    expect(shouldWake("wake_when_idle", true, false)).toBe(false);
    expect(shouldWake("do_not_wake", true, true)).toBe(false);
    expect(shouldWake("wake_at_safe_point", true, true)).toBe(true);
  });
});
