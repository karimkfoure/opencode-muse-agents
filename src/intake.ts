/**
 * intake.ts — steering/message intake records.
 *
 * A steering record is a 4-pair envelope
 * {SessionCommandIntakeCommand, SubagentSteering, kind, subagent_steering},
 * dispatched by numeric kind through one 16-arm jumptable
 * (intake_dispatcher @0x5a1fb80, table @0x66be1c). The 11 kinds below are
 * the evidenced vocabulary (@0x673758); remaining arms are unmapped and
 * fail closed. Execution is ordered keyed takes:
 *   verb -> subagentId -> body -> reason -> append.
 * Any take returning -2 fails the whole intake as {0xff, err};
 * -3 also fails. -1 = absent. Unset fold fields default-accept.
 */

export const INTAKE_TYPE = "SessionCommandIntakeCommand";
export const STEERING_KIND = "SubagentSteering";
export const STEERING_NAME = "subagent_steering";

/** Intake command vocabulary, jumptable order (kind = index).
 * 11 evidenced names (@0x673758 cluster; `side_chat_start` parses as
 * kind + `requested_side_session_id` field); remaining dispatcher arms
 * are unmapped and fail closed via kindIndex -1. */
export const INTAKE_KINDS = [
  "settled",
  "subagent_steering",
  "conversation_rewind",
  "session_name",
  "session_start",
  "turn_submit",
  "direct_user_carrier",
  "turn_queue_submit",
  "run_retract",
  "side_chat_start",
  "session_fork",
] as const;

export type IntakeKind = (typeof INTAKE_KINDS)[number];

/** Jumptable index for a kind; -1 when unknown (fail closed). */
export function kindIndex(kind: string): number {
  const i = (INTAKE_KINDS as readonly string[]).indexOf(kind);
  return i;
}

export interface SteeringRecord {
  recordType: typeof INTAKE_TYPE;
  kind: typeof STEERING_KIND;
  lane: "kind";
  name: typeof STEERING_NAME;
  verb: string;
  subagentId: string;
  body: string;
  reason?: string;
}

/** Build the 4-pair steering record shape (verbatim field tags). */
export function buildSteeringRecord(input: {
  verb: string;
  subagentId: string;
  body: string;
  reason?: string;
}): SteeringRecord {
  return {
    recordType: INTAKE_TYPE,
    kind: STEERING_KIND,
    lane: "kind",
    name: STEERING_NAME,
    verb: input.verb,
    subagentId: input.subagentId,
    body: input.body,
    ...(input.reason !== undefined ? { reason: input.reason } : {}),
  };
}

export const TAKE_ABSENT = -1;
export const TAKE_FOLLOWUP = -2;
/** Executor-level deferred marker; surfaces as {0xff, err} like -2. */
export const TAKE_DEFERRED = -3;
export const INTAKE_FAIL_STATUS = 0xff;

/** Owner steering verbs (closed 8-enum; no spawn). */
export const OWNER_VERBS = [
  "sendMessage",
  "followupTask",
  "interrupt",
  "stop",
  "close",
  "resume",
  "reopen",
  "readResult",
] as const;

export type TakeResult<T> = { status: "value"; value: T } | { status: "absent" } | { status: "followup" };

/** One keyed take: missing -> absent(-1); explicitly deferred -> followup(-2). */
export function takeField(record: Record<string, unknown>, key: string): TakeResult<unknown> {
  if (!(key in record) || record[key] === undefined) return { status: "absent" };
  if (record[key] === null) return { status: "followup" };
  return { status: "value", value: record[key] };
}

export interface IntakeOutcome {
  status: number;
  record?: SteeringRecord;
  error?: string;
}

/**
 * Execute intake in the binary's order: verb -> subagentId -> body ->
 * reason -> append. Any -2 (or empty-after-trim body) fails closed as
 * {0xff, err}. Returns the appended record on success (append itself is
 * the caller's durable write; this function only validates + shapes).
 */
export function executeSteeringIntake(input: {
  verb: string;
  subagentId: string;
  body: string;
  reason?: string;
}): IntakeOutcome {
  const verb = takeField({ verb: input.verb }, "verb");
  if (verb.status !== "value" || typeof verb.value !== "string" || verb.value.length === 0) {
    return { status: INTAKE_FAIL_STATUS, error: "verb is required" };
  }
  if (!(OWNER_VERBS as readonly string[]).includes(verb.value)) {
    return { status: INTAKE_FAIL_STATUS, error: `unknown verb ${verb.value}` };
  }
  const id = takeField({ subagentId: input.subagentId }, "subagentId");
  if (id.status !== "value" || typeof id.value !== "string" || id.value.length === 0) {
    return { status: INTAKE_FAIL_STATUS, error: "subagentId must be a non-empty durable child id" };
  }
  const body = takeField({ body: input.body }, "body");
  if (body.status !== "value" || typeof body.value !== "string" || body.value.trim().length === 0) {
    return { status: INTAKE_FAIL_STATUS, error: "body must be non-empty after trimming" };
  }
  const trimmed = (body.value as string).trim();
  const reason = takeField(input.reason === undefined ? {} : { reason: input.reason }, "reason");
  if (reason.status === "followup") {
    return { status: INTAKE_FAIL_STATUS, error: "reason deferred" };
  }
  return {
    status: 0,
    record: buildSteeringRecord({
      verb: verb.value as string,
      subagentId: id.value as string,
      body: trimmed,
      ...(reason.status === "value" ? { reason: reason.value as string } : {}),
    }),
  };
}
