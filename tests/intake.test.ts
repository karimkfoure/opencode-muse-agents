import { describe, expect, test } from "bun:test";
import {
  INTAKE_FAIL_STATUS,
  INTAKE_KINDS,
  STEERING_KIND,
  STEERING_NAME,
  buildSteeringRecord,
  executeSteeringIntake,
  kindIndex,
  takeField,
} from "../src/intake";

describe("kindIndex (jumptable order)", () => {
  test("known kinds resolve, unknown fails closed", () => {
    expect(kindIndex("subagent_steering")).toBeGreaterThanOrEqual(0);
    expect(kindIndex("turn_submit")).toBeGreaterThanOrEqual(0);
    expect(kindIndex("nope")).toBe(-1);
  });
  test("vocabulary is stable and ordered", () => {
    expect(INTAKE_KINDS[1]).toBe("subagent_steering");
    expect(new Set(INTAKE_KINDS).size).toBe(INTAKE_KINDS.length);
  });
});

describe("buildSteeringRecord", () => {
  test("4-pair shape with verbatim tags", () => {
    const r = buildSteeringRecord({ verb: "note", subagentId: "c1", body: "hi" });
    expect(r.recordType).toBe("SessionCommandIntakeCommand");
    expect(r.kind).toBe(STEERING_KIND);
    expect(r.lane).toBe("kind");
    expect(r.name).toBe(STEERING_NAME);
    expect(r.verb).toBe("note");
  });
});

describe("takeField", () => {
  test("value / absent(-1) / followup(-2 on null)", () => {
    expect(takeField({ a: 1 }, "a")).toEqual({ status: "value", value: 1 });
    expect(takeField({}, "a")).toEqual({ status: "absent" });
    expect(takeField({ a: undefined }, "a")).toEqual({ status: "absent" });
    expect(takeField({ a: null }, "a")).toEqual({ status: "followup" });
  });
});

describe("executeSteeringIntake (verb→subagentId→body→reason)", () => {
  test("happy path trims body", () => {
    const r = executeSteeringIntake({ verb: "followupTask", subagentId: "c1", body: "  do X  ", reason: "why" });
    expect(r.status).toBe(0);
    expect(r.record?.body).toBe("do X");
    expect(r.record?.reason).toBe("why");
  });
  test("reason is optional", () => {
    const r = executeSteeringIntake({ verb: "sendMessage", subagentId: "c1", body: "hi" });
    expect(r.status).toBe(0);
    expect(r.record && "reason" in r.record).toBe(false);
  });
  test("empty-after-trim body fails {0xff,err}", () => {
    const r = executeSteeringIntake({ verb: "sendMessage", subagentId: "c1", body: "   " });
    expect(r.status).toBe(INTAKE_FAIL_STATUS);
    expect(typeof r.error).toBe("string");
    expect(r.record).toBeUndefined();
  });
  test("missing verb / subagentId fail closed", () => {
    expect(executeSteeringIntake({ verb: "", subagentId: "c1", body: "x" }).status).toBe(INTAKE_FAIL_STATUS);
    expect(executeSteeringIntake({ verb: "v", subagentId: "", body: "x" }).status).toBe(INTAKE_FAIL_STATUS);
  });
});
