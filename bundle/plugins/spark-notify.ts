import { readdir, readFile, rename, writeFile } from "node:fs/promises";
import { join } from "node:path";
import type { Plugin } from "@opencode-ai/plugin";
import { shouldWake, type WakePolicy } from "../../src/mailbox";

const MAILBOX_DIR = ".spark/mailbox";

export interface MailboxRecord {
  id: string;
  sessionId: string;
  body: string;
  deliveryPolicy: string;
  wakePolicy: string;
  admitted?: string;
}

/** Admitted states that are still eligible for idle delivery. Anything else
 *  (notably "delivered") is skipped so a record is never re-delivered. */
const DELIVERABLE_ADMITTED: readonly string[] = ["pending_admission", "accepted", "accepted_queue_full"];

/**
 * Pure selection: which parsed ledger records are deliverable to the idle
 * session. Applies the session match, the wake gate (idle + unfinished),
 * and the admitted allowlist — records already marked "delivered" are
 * skipped, as are do_not_wake records (via shouldWake).
 */
export function selectDeliverable(records: MailboxRecord[], sessionId: string): MailboxRecord[] {
  const out: MailboxRecord[] = [];
  for (const r of records) {
    if (r.sessionId !== sessionId) continue;
    if (!shouldWake(r.wakePolicy as WakePolicy, true, true)) continue;
    if (r.admitted === "delivered") continue;
    if (!DELIVERABLE_ADMITTED.includes(r.admitted ?? "")) continue;
    out.push(r);
  }
  return out;
}

/**
 * Pure rewrite: mark exactly the delivered ids as admitted:"delivered".
 * Every input line survives — malformed lines and non-delivered records are
 * preserved byte-for-byte; only delivered records are re-serialized with the
 * admitted field replaced. Trailing-newline shape is preserved because the
 * split/join round-trips the separators.
 */
export function rewriteMailboxLines(linesText: string, deliveredIds: Set<string> | readonly string[]): string {
  const ids = deliveredIds instanceof Set ? deliveredIds : new Set(deliveredIds);
  if (ids.size === 0) return linesText;
  const lines = linesText.split("\n");
  return lines
    .map((line) => {
      if (!line.trim()) return line;
      let parsed: MailboxRecord;
      try {
        parsed = JSON.parse(line) as MailboxRecord;
      } catch {
        return line;
      }
      if (typeof parsed.id !== "string" || !ids.has(parsed.id)) return line;
      return JSON.stringify({ ...parsed, admitted: "delivered" });
    })
    .join("\n");
}
/**
 * spark-notify — completion delivery without polling.
 * On session.idle, scans mailbox files for pending_admission records
 * addressed to the idle session and delivers them as one synthetic
 * prompt. Retained files stay authoritative; delivery is a ping.
 */
export const SparkNotify: Plugin = async ({ client, directory }) => {
  async function pendingFor(sessionID: string): Promise<MailboxRecord[]> {
    try {
      const files = await readdir(join(directory, MAILBOX_DIR));
      const records: MailboxRecord[] = [];
      for (const f of files) {
        if (!f.endsWith(".jsonl")) continue;
        const lines = (await readFile(join(directory, MAILBOX_DIR, f), "utf8")).split("\n");
        for (const line of lines) {
          if (!line.trim()) continue;
          try {
            records.push(JSON.parse(line) as MailboxRecord);
          } catch {
            // Malformed ledger lines fail closed: skipped, never guessed.
          }
        }
      }
      return selectDeliverable(records, sessionID);
    } catch {
      return [];
    }
  }

  /** Mark exactly the delivered ids as admitted:"delivered" in the session's
   *  mailbox file, atomically via tmp file + rename. Malformed lines are
   *  preserved byte-for-byte, never dropped. Best-effort: any I/O failure
   *  leaves the file for retry on the next idle. */
  async function markDelivered(sessionID: string, deliveredIds: Set<string>): Promise<void> {
    if (deliveredIds.size === 0) return;
    const file = join(directory, MAILBOX_DIR, `${sessionID}.jsonl`);
    const text = await readFile(file, "utf8");
    const rewritten = rewriteMailboxLines(text, deliveredIds);
    if (rewritten === text) return;
    const tmp = `${file}.tmp.${process.pid}`;
    await writeFile(tmp, rewritten, "utf8");
    await rename(tmp, file);
  }

  return {
    async event({ event }) {
      const item = event as { type?: string; properties?: { sessionID?: string } };
      if (item.type !== "session.idle") return;
      const sessionID = item.properties?.sessionID;
      if (!sessionID) return;
      const pending = await pendingFor(sessionID);
      if (pending.length === 0) return;
      const text =
        "Spark mailbox delivery. Read retained records; inbox files stay authoritative.\n" +
        JSON.stringify(pending.map((p) => ({ id: p.id, body: p.body, deliveryPolicy: p.deliveryPolicy })));
      try {
        await client.session.promptAsync({
          path: { id: sessionID },
          query: { directory },
          body: { parts: [{ type: "text", synthetic: true, text }] },
        });
      } catch {
        // Delivery threw: leave the mailbox file untouched so the records
        // are retried on the next idle.
        return;
      }
      try {
        await markDelivered(
          sessionID,
          new Set(pending.map((p) => p.id)),
        );
      } catch {
        // Marking is best-effort; a failure retries on the next idle.
      }
    },
  };
};

export default { id: "spark-notify", server: SparkNotify };
