/**
 * fork.ts — history branching, not worker spawn.
 *
 * Fork copies the log through a cut point with durable provenance.
 * The cut cursor is OPAQUE and display-only: never parse it, never hand
 * it to a method. Cut just after a compaction boundary (cheapest);
 * fork-then-compact pays twice.
 */

import type { SessionForkData } from "@opencode-ai/sdk";

export interface ForkCutPoint {
  /** Last completed turn to copy, inclusive. Turn ids stay stable. */
  lastTurnId: string;
}

export interface ForkRequest {
  sourceSessionId: string;
  cutPoint?: ForkCutPoint;
  commandId: string;
}

export interface ForkProvenance {
  sourceSessionId: string;
  commandId: string;
  /** Opaque. Display-only. MUST NOT be parsed or passed to any method. */
  cutCursor: string;
  cutExplicit: boolean;
}

export function planFork(req: ForkRequest, newSessionId: string, servedCutCursor: string): { provenance: ForkProvenance; newSessionId: string } {
  return {
    newSessionId,
    provenance: {
      sourceSessionId: req.sourceSessionId,
      commandId: req.commandId,
      cutCursor: servedCutCursor,
      cutExplicit: req.cutPoint !== undefined,
    },
  };
}

/** Guard: a fork id must differ from its source (ForkIdEqualsSourceId). */
export function checkForkIds(forkId: string, sourceId: string): boolean {
  return forkId !== sourceId;
}

/**
 * Provenance-ish input for building a host session.fork call.
 * sourceSessionId identifies the log to branch; lastTurnId (when the
 * caller cut at an explicit turn) becomes the SDK body.messageID;
 * directory scopes the forked session.
 */
export interface ForkCallInput {
  sourceSessionId: string;
  /** Last completed turn to copy, inclusive. Omit to fork the whole log. */
  lastTurnId?: string;
  /** Working directory for the forked session. */
  directory?: string;
}

/**
 * Pure helper: build the exact args for `client.session.fork`.
 * Field names match SessionForkData (path.id, body.messageID,
 * query.directory). body is present only when lastTurnId is given
 * (the SDK forks the whole log otherwise); query is present only
 * when directory is given. The opaque cut cursor is never included.
 */
export function buildForkCall(input: ForkCallInput): Omit<SessionForkData, "url"> {
  const args: Omit<SessionForkData, "url"> = { path: { id: input.sourceSessionId } };
  if (input.lastTurnId !== undefined) {
    args.body = { messageID: input.lastTurnId };
  }
  if (input.directory !== undefined) {
    args.query = { directory: input.directory };
  }
  return args;
}

/**
 * Pure helper: check whether a receipt file's existing text already
 * contains a line with the given commandId. Each line is parsed as
 * JSON; malformed lines are ignored. Empty text never matches.
 */
export function isDuplicateReceipt(existingLinesText: string, commandId: string): boolean {
  if (!existingLinesText || !commandId) return false;
  for (const line of existingLinesText.split("\n")) {
    const trimmed = line.trim();
    if (!trimmed) continue;
    try {
      const parsed = JSON.parse(trimmed) as { commandId?: unknown };
      if (parsed?.commandId === commandId) return true;
    } catch {
      continue;
    }
  }
  return false;
}
