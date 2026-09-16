import { describe, expect, test } from "bun:test";
import { readFileSync } from "node:fs";
import { join } from "node:path";
import { validateBody, validateSubagentResult } from "../src/envelope";
import { isCanonicalPair, shouldWake } from "../src/mailbox";
import { createChildRecord } from "../src/child";

const examplesDir = join(import.meta.dir, "..", "examples");

function readFixture(name: string): unknown {
  return JSON.parse(readFileSync(join(examplesDir, name), "utf8"));
}

describe("golden: mailbox-note.json", () => {
  test("body validates and policy pair is canonical", () => {
    const fixture = readFixture("mailbox-note.json") as {
      body: string;
      deliveryPolicy: "queue_next_turn";
      wakePolicy: "wake_when_idle";
    };
    const body = validateBody(fixture.body);
    expect(body.ok).toBe(true);
    expect(isCanonicalPair(fixture.deliveryPolicy, fixture.wakePolicy)).toBe(true);
    expect(shouldWake(fixture.wakePolicy, true, true)).toBe(true);
  });
});

describe("golden: result-envelope.json", () => {
  test("envelope validates ok:true", () => {
    const fixture = readFixture("result-envelope.json") as {
      summary: string;
      text?: string;
      artifactRefs: string[];
      evidenceRefs: string[];
    };
    const result = validateSubagentResult(fixture);
    expect(result.ok).toBe(true);
  });
});

describe("golden: spawn-commit.json", () => {
  test("commit has exactly 6 keys and child admits with maxDepth 2", () => {
    const fixture = readFixture("spawn-commit.json") as {
      commit: Record<string, unknown>;
      child: {
        subagentId: string;
        agentPath: string;
        depth: number;
        objective: string;
        childSessionId: string;
        workflowRunId: string;
      };
    };
    expect(Object.keys(fixture.commit).sort()).toEqual(
      [
        "accepted",
        "agent_lineage_admission",
        "description",
        "parent_binding",
        "schema_version",
        "spawn_decision",
      ].sort(),
    );
    const child = createChildRecord({
      subagentId: fixture.child.subagentId,
      agentPath: fixture.child.agentPath,
      depth: fixture.child.depth,
      objective: fixture.child.objective,
      childSessionId: fixture.child.childSessionId,
      workflowRunId: fixture.child.workflowRunId,
      maxDepth: 2,
    });
    expect(child.ok).toBe(true);
  });
});
