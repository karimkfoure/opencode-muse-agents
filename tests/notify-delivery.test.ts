import { describe, expect, test } from "bun:test";
import {
  rewriteMailboxLines,
  selectDeliverable,
  type MailboxRecord,
} from "../bundle/plugins/spark-notify";

const rec = (over: Partial<MailboxRecord> & { id: string }): MailboxRecord => ({
  sessionId: "s1",
  body: "hello",
  deliveryPolicy: "queue_next_turn",
  wakePolicy: "wake_when_idle",
  admitted: "pending_admission",
  ...over,
});

describe("selectDeliverable", () => {
  test("delivers pending/accepted/accepted_queue_full, skips the rest", () => {
    const records = [
      rec({ id: "pending", admitted: "pending_admission" }),
      rec({ id: "acc", admitted: "accepted" }),
      rec({ id: "acc-full", admitted: "accepted_queue_full" }),
      rec({ id: "done", admitted: "delivered" }),
      rec({ id: "quiet", wakePolicy: "do_not_wake" }),
      rec({ id: "other-session", sessionId: "s2" }),
      rec({ id: "blocked", admitted: "blocked_by_receiver" }),
      rec({ id: "no-admitted", admitted: undefined }),
    ];
    const got = selectDeliverable(records, "s1").map((r) => r.id);
    expect(got).toEqual(["pending", "acc", "acc-full"]);
  });

  test("already-delivered records are never re-selected", () => {
    const records = [rec({ id: "done", admitted: "delivered" })];
    expect(selectDeliverable(records, "s1")).toEqual([]);
  });

  test("wake gate stays: do_not_wake never delivers", () => {
    const records = [rec({ id: "q", wakePolicy: "do_not_wake", admitted: "pending_admission" })];
    expect(selectDeliverable(records, "s1")).toEqual([]);
  });
});

describe("rewriteMailboxLines", () => {
  const pendingLine = JSON.stringify(rec({ id: "m1", admitted: "pending_admission" }));
  const otherPendingLine = JSON.stringify(rec({ id: "m2", admitted: "accepted" }));
  const deliveredLine = JSON.stringify(rec({ id: "m3", admitted: "delivered" }));
  const quietLine = JSON.stringify(rec({ id: "m4", wakePolicy: "do_not_wake" }));
  const malformed = "{not-json,,,";

  const ledger = [pendingLine, malformed, otherPendingLine, deliveredLine, quietLine, ""].join("\n");

  test("marks exactly the delivered ids, preserves everything else byte-for-byte", () => {
    const out = rewriteMailboxLines(ledger, new Set(["m1"]));
    const outLines = out.split("\n");
    expect(outLines.length).toBe(ledger.split("\n").length);
    // Delivered record flipped to delivered.
    expect(JSON.parse(outLines[0]!).admitted).toBe("delivered");
    expect(JSON.parse(outLines[0]!).id).toBe("m1");
    // Malformed line untouched.
    expect(outLines[1]).toBe(malformed);
    // Non-delivered records byte-identical.
    expect(outLines[2]).toBe(otherPendingLine);
    expect(outLines[3]).toBe(deliveredLine);
    expect(outLines[4]).toBe(quietLine);
    // Trailing newline shape preserved.
    expect(out.endsWith("\n")).toBe(ledger.endsWith("\n"));
  });

  test("marks multiple ids at once", () => {
    const out = rewriteMailboxLines(ledger, new Set(["m1", "m2"]));
    const outLines = out.split("\n");
    expect(JSON.parse(outLines[0]!).admitted).toBe("delivered");
    expect(JSON.parse(outLines[2]!).admitted).toBe("delivered");
    expect(outLines[1]).toBe(malformed);
    expect(outLines[4]).toBe(quietLine);
  });

  test("accepts a string array of ids", () => {
    const out = rewriteMailboxLines(ledger, ["m2"]);
    const outLines = out.split("\n");
    expect(outLines[0]).toBe(pendingLine);
    expect(JSON.parse(outLines[2]!).admitted).toBe("delivered");
  });

  test("empty id set leaves text untouched (same value)", () => {
    expect(rewriteMailboxLines(ledger, new Set())).toBe(ledger);
  });

  test("unknown ids change nothing", () => {
    expect(rewriteMailboxLines(ledger, new Set(["nope"]))).toBe(ledger);
  });

  test("selection after rewrite yields no re-delivery", () => {
    const out = rewriteMailboxLines(ledger, new Set(["m1", "m2"]));
    const records = out
      .split("\n")
      .filter((l) => l.trim())
      .flatMap((l) => {
        try {
          return [JSON.parse(l) as MailboxRecord];
        } catch {
          return [];
        }
      });
    expect(selectDeliverable(records, "s1")).toEqual([]);
  });
});
