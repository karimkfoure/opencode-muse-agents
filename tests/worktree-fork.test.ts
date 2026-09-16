import { describe, expect, test } from "bun:test";
import forkTool from "../bundle/tools/spark_fork";
import { joinWorktreePath, placeWorktree } from "../src/worktree";
import { MAILBOX_BODY_MAX_BYTES, admitMessage, type AdmitInput } from "../src/mailbox";

describe("fork description honesty", () => {
  test('mentions host session.fork', () => {
    const desc = (forkTool as unknown as { description: string }).description;
    expect(desc).toContain("session.fork");
  });
});

describe("placeWorktree still fine", () => {
  test("joins under .muse/worktrees and -1 skips", () => {
    expect(joinWorktreePath("/repo", "feat")).toBe("/repo/.muse/worktrees/feat");
    expect(placeWorktree({ mode: -1 }, { storageRoot: "/r" })).toEqual({
      placed: false,
      reason: "not_requested",
    });
  });
});

describe("mailbox body cap", () => {
  test("body over cap admits message_too_large", () => {
    const input: AdmitInput = {
      message: {
        id: "m-big",
        sessionId: "s1",
        body: "x".repeat(MAILBOX_BODY_MAX_BYTES + 1),
        deliveryPolicy: "queue_next_turn",
        wakePolicy: "wake_when_idle",
      },
      targetRunning: false,
      targetIdle: true,
      targetUnfinished: true,
      queueFull: false,
      duplicate: false,
      receiverBlocked: false,
      retentionAvailable: true,
    };
    expect(MAILBOX_BODY_MAX_BYTES).toBe(262144);
    expect(input.message.body.length).toBe(262145);
    expect(admitMessage(input)).toBe("message_too_large");
  });
});
