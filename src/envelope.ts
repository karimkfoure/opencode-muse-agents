/**
 * envelope.ts — bounded result + body validation.
 *
 * - SubagentResult: summary <= 512 CHARS (Unicode scalars, NOT bytes),
 *   text <= 32 KiB BYTES when present, artifactRefs/evidenceRefs required.
 *   Never split a UTF-8 scalar; the client must NOT pre-truncate.
 * - Steering bodies: Unicode-whitespace trim, reject when empty after
 *   trimming, delivered trimmed with multibyte content byte-for-byte intact.
 */

export const SUMMARY_MAX_CHARS = 512;
export const RESULT_TEXT_MAX_BYTES = 32 * 1024;

export type EnvelopeErrorKey =
  | "empty_after_trim"
  | "summary_too_long"
  | "text_too_large"
  | "missing_refs";

export interface EnvelopeIssue {
  key: EnvelopeErrorKey;
  detail: string;
}

const te = new TextEncoder();

/** Unicode scalar count (matches Rust chars().count(), not UTF-16 length). */
export function scalarLength(s: string): number {
  return [...s].length;
}

/** Byte length (matches Rust s.len()). */
export function byteLength(s: string): number {
  return te.encode(s).length;
}

/**
 * Trim Unicode whitespace (both ends, interior untouched, char-boundary
 * safe) and reject empties. Mirrors Rust str::trim + empty rejection.
 */
export function validateBody(body: string): { ok: true; trimmed: string } | { ok: false; issue: EnvelopeIssue } {
  if (typeof body !== "string") {
    return { ok: false, issue: { key: "empty_after_trim", detail: "body must be a string" } };
  }
  const trimmed = body.trim();
  if (trimmed.length === 0) {
    return {
      ok: false,
      issue: { key: "empty_after_trim", detail: "subagentId/body must be non-empty after trimming" },
    };
  }
  return { ok: true, trimmed };
}

/** Durable child id validation: non-empty opaque string. */
export function validateSubagentId(id: string): { ok: true } | { ok: false; issue: EnvelopeIssue } {
  if (typeof id !== "string" || id.trim().length === 0) {
    return {
      ok: false,
      issue: { key: "empty_after_trim", detail: "subagentId must be a non-empty durable child id" },
    };
  }
  return { ok: true };
}

export interface SubagentResultInput {
  summary: string;
  text?: string;
  artifactRefs: string[];
  evidenceRefs: string[];
  structuredData?: Record<string, unknown>;
  errorKind?: string;
}

export interface ValidSubagentResult {
  summary: string;
  text?: string;
  artifactRefs: string[];
  evidenceRefs: string[];
  structuredData?: Record<string, unknown>;
  errorKind?: string;
}

/**
 * Validate a subagent result envelope. Returns ALL issues (no fail-fast)
 * so callers can report precisely. Never truncates.
 */
export function validateSubagentResult(input: SubagentResultInput): { ok: true; result: ValidSubagentResult } | { ok: false; issues: EnvelopeIssue[] } {
  const issues: EnvelopeIssue[] = [];
  if (typeof input.summary !== "string" || scalarLength(input.summary) > SUMMARY_MAX_CHARS) {
    issues.push({
      key: "summary_too_long",
      detail: `Bounded result summary (<=${SUMMARY_MAX_CHARS} chars, runtime-enforced)`,
    });
  }
  if (input.text !== undefined && byteLength(input.text) > RESULT_TEXT_MAX_BYTES) {
    issues.push({ key: "text_too_large", detail: "Result text (<=32 KiB), when present" });
  }
  if (!Array.isArray(input.artifactRefs) || !Array.isArray(input.evidenceRefs)) {
    issues.push({ key: "missing_refs", detail: "artifactRefs and evidenceRefs are required (verbatim)" });
  }
  if (issues.length > 0) return { ok: false, issues };
  const result: ValidSubagentResult = {
    summary: input.summary,
    artifactRefs: input.artifactRefs,
    evidenceRefs: input.evidenceRefs,
  };
  if (input.text !== undefined) result.text = input.text;
  if (input.structuredData !== undefined) result.structuredData = input.structuredData;
  if (input.errorKind !== undefined) result.errorKind = input.errorKind;
  return { ok: true, result };
}
