import { tool } from "@opencode-ai/plugin";
import { canonicalEventId, isCanonicalEventId, mintCommandId } from "../../src/ids";

export const uuid_mint = tool({
  description: "Mint a UUIDv7 command id (idempotency key). Reuse the SAME id on retry; never mint anew.",
  args: {},
  async execute() {
    return JSON.stringify({ commandId: mintCommandId() });
  },
});

export const uuid_canonicalize = tool({
  description: "Render 32 lowercase hex chars as canonical 36-char hyphenated Event ID (8-4-4-4-12).",
  args: { hex32: tool.schema.string().describe("32 lowercase hex chars (16 bytes)") },
  async execute(args) {
    if (!/^[0-9a-f]{32}$/.test(args.hex32)) return JSON.stringify({ ok: false, error: "need 32 lowercase hex chars" });
    const b = new Uint8Array(16);
    for (let i = 0; i < 16; i++) b[i] = parseInt(args.hex32.slice(i * 2, i * 2 + 2), 16);
    return JSON.stringify({ ok: true, eventId: canonicalEventId(b) });
  },
});

export const uuid_check = tool({
  description: "Check canonical Event ID spelling (36 bytes, lowercase hyphenated).",
  args: { eventId: tool.schema.string() },
  async execute(args) {
    return JSON.stringify({ eventId: args.eventId, canonical: isCanonicalEventId(args.eventId) });
  },
});
