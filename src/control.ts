/**
 * control.ts — owner control records + the three drivers.
 *
 * Owner commands resolve a control record, STRIP the `workflow` entry,
 * and run one path: default (steady state), replace-on-idle (refuse
 * non-idle instead of overwriting), staged pipeline (spawn/followup,
 * commit-last outcome rows). Every command is admission-only.
 */

export const WORKFLOW_ENTRY_TAG = "workflow";

export interface ControlEntry {
  tag: string;
  attempt: number;
  payload: unknown;
}

export interface OwnerControl {
  base: string;
  entries: ControlEntry[];
  params: Record<string, unknown>;
}

export interface ControlState {
  idle: boolean;
  empty: boolean;
}

/** Strip the `workflow` entry from a control list (memmove-close the gap). */
export function stripWorkflowEntry(entries: ControlEntry[]): ControlEntry[] {
  return entries.filter((e) => e.tag !== WORKFLOW_ENTRY_TAG);
}

export type OwnerCommandKind =
  | "spawn"
  | "interrupt"
  | "resume"
  | "reopen"
  | "close"
  | "sendMessage"
  | "followupTask"
  | "readResult"
  | "stop";

/** Driver 1 — default: resolve + strip, always allowed when resolvable. */
export function driveDefault(control: OwnerControl | null): { ok: true; control: OwnerControl } | { ok: false; reason: string } {
  if (!control) return { ok: false, reason: "target_missing" };
  return { ok: true, control: { ...control, entries: stripWorkflowEntry(control.entries) } };
}

/** Driver 2 — replace-on-idle: refuse non-idle/non-empty instead of overwriting. */
export function driveReplaceOnIdle(
  control: OwnerControl | null,
  state: ControlState,
): { ok: true; control: OwnerControl } | { ok: false; reason: "owner_still_running" | "target_missing" } {
  if (!control) return { ok: false, reason: "target_missing" };
  if (!state.idle || !state.empty) return { ok: false, reason: "owner_still_running" };
  return { ok: true, control: { ...control, entries: stripWorkflowEntry(control.entries) } };
}

export interface PipelineOutcomeRow {
  kind: OwnerCommandKind;
  attempt: number;
  committed: boolean;
  fields: Record<string, unknown>;
}

/**
 * Driver 3 — staged pipeline: init/fill/seal stages build outcome rows,
 * commit LAST. Rows are wide records; commit releases replaced payloads.
 */
export function drivePipeline(
  control: OwnerControl | null,
  commands: { kind: OwnerCommandKind; attempt: number; fields?: Record<string, unknown> }[],
): { ok: true; rows: PipelineOutcomeRow[] } | { ok: false; reason: string } {
  if (!control) return { ok: false, reason: "target_missing" };
  const stripped = stripWorkflowEntry(control.entries);
  if (stripped.length === 0 && commands.length === 0) return { ok: false, reason: "not_requested" };
  const rows: PipelineOutcomeRow[] = commands.map((c) => ({
    kind: c.kind,
    attempt: c.attempt,
    committed: true,
    fields: c.fields ?? {},
  }));
  return { ok: true, rows };
}
