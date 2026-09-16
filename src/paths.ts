/**
 * paths.ts — safe path segment validation.
 *
 * Single-segment names for tables, branches, and session files. Rejects
 * traversal and separator tricks; callers keep path joins under their
 * own roots (.spark/tables, .muse/worktrees, .spark/mailbox).
 */

const SEGMENT_RE = /^[A-Za-z0-9][A-Za-z0-9._-]{0,127}$/;

/**
 * Validate one path segment. Accepts only SEGMENT_RE and rejects any
 * string containing "..", "/", "\\", or a null byte.
 */
export function assertSafeSegment(name: string): { ok: true } | { ok: false; reason: string } {
  const got = JSON.stringify(name);
  const fix = 'fix by using a plain name like "my-table-1" (letters, digits, ".", "_", "-" only, max 128 chars)';
  if (typeof name !== "string") {
    return { ok: false, reason: `invalid segment got ${got}: segment must be a string; ${fix}` };
  }
  if (name.includes("\0")) {
    return { ok: false, reason: `invalid segment got ${got}: segment must not contain a null byte; ${fix}` };
  }
  if (name.includes("/") || name.includes("\\")) {
    return { ok: false, reason: `invalid segment got ${got}: segment must not contain "/" or "\\"; ${fix}` };
  }
  if (name.includes("..")) {
    return { ok: false, reason: `invalid segment got ${got}: segment must not contain ".."; ${fix}` };
  }
  if (!SEGMENT_RE.test(name)) {
    return { ok: false, reason: `invalid segment got ${got}: segment must match /^[A-Za-z0-9][A-Za-z0-9._-]{0,127}$/; ${fix}` };
  }
  return { ok: true };
}
