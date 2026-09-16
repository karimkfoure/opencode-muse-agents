import { describe, expect, test } from "bun:test";
import { buildForkCall } from "../src/fork";

describe("buildForkCall", () => {
  test("with lastTurnId: path.id + body.messageID + query.directory", () => {
    expect(
      buildForkCall({ sourceSessionId: "ses_src", lastTurnId: "msg_123", directory: "/repo" }),
    ).toEqual({
      path: { id: "ses_src" },
      body: { messageID: "msg_123" },
      query: { directory: "/repo" },
    });
  });

  test("without lastTurnId: body key absent (fork copies the whole log)", () => {
    const got = buildForkCall({ sourceSessionId: "ses_src", directory: "/repo" });
    expect(got).toEqual({ path: { id: "ses_src" }, query: { directory: "/repo" } });
    expect("body" in got).toBe(false);
  });

  test("without directory: query key absent", () => {
    const got = buildForkCall({ sourceSessionId: "ses_src", lastTurnId: "msg_9" });
    expect(got).toEqual({ path: { id: "ses_src" }, body: { messageID: "msg_9" } });
    expect("query" in got).toBe(false);
  });

  test("bare minimum: only path.id", () => {
    expect(buildForkCall({ sourceSessionId: "ses_src" })).toEqual({ path: { id: "ses_src" } });
  });

  test("never leaks the opaque cut cursor into SDK args", () => {
    const got = JSON.stringify(buildForkCall({ sourceSessionId: "s", lastTurnId: "m", directory: "d" }));
    expect(got).not.toContain("cutCursor");
    expect(got).not.toContain("cursor");
  });
});
