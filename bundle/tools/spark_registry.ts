import { existsSync, mkdirSync, readFileSync, writeFileSync } from "node:fs";
import { join } from "node:path";
import { tool } from "@opencode-ai/plugin";
import { appendRow, commitRow, createTable, probeByKey, swapRow, type Row } from "../../src/registry";
import { assertSafeSegment } from "../../src/paths";

const TABLES_DIR = ".spark/tables";

function tablePath(worktree: string, name: string): string {
  return join(worktree, TABLES_DIR, `${name}.json`);
}

function loadTable(worktree: string, name: string): { name: string; rows: Row[] } {
  const p = tablePath(worktree, name);
  if (!existsSync(p)) return createTable(name);
  try {
    const raw = JSON.parse(readFileSync(p, "utf8"));
    if (Array.isArray(raw?.rows)) return { name, rows: raw.rows };
  } catch {
    // Corrupt ledger fails closed: start empty rather than guessing.
  }
  return createTable(name);
}

function saveTable(worktree: string, table: { name: string; rows: Row[] }): void {
  mkdirSync(join(worktree, TABLES_DIR), { recursive: true });
  writeFileSync(tablePath(worktree, table.name), JSON.stringify({ rows: table.rows }), "utf8");
}

/**
 * spark_registry — durable table operations over JSONL-backed tables:
 * append | probe (normalize-then-probe) | swap | commit | list. Locked tables
 * refuse with FENCED. Corrupt ledgers fail closed to empty.
 */
export default tool({
  description:
    "Durable registry ops (append/probe/swap/commit/list) over JSONL-backed tables. Locked tables refuse FENCED; corrupt ledgers start empty.",
  args: {
    table: tool.schema.string().describe("Table name"),
    op: tool.schema.string().describe("append | probe | swap | commit | list"),
    row: tool.schema.string().optional().describe("JSON 4-tuple for append/swap/commit"),
    keyIdx: tool.schema.number().optional().describe("Key cell 0-3 for probe/commit"),
    key: tool.schema.string().optional().describe("Lookup key for probe/commit"),
    index: tool.schema.number().optional().describe("Row index for swap"),
    locked: tool.schema.boolean().optional().describe("Refuse commits when true"),
  },
  async execute(args, context) {
    const seg = assertSafeSegment(args.table);
    if (!seg.ok) {
      return JSON.stringify({ ok: false, error: `invalid table name ${JSON.stringify(args.table)}: ${seg.reason}` });
    }
    const t = loadTable(context.worktree, args.table);
    switch (args.op) {
      case "append": {
        if (!args.row) return JSON.stringify({ ok: false, error: "row required" });
        let parsed: Row;
        try {
          parsed = JSON.parse(args.row);
        } catch {
          return JSON.stringify({ ok: false, error: "row must be a JSON 4-tuple" });
        }
        const idx = appendRow(t, parsed);
        saveTable(context.worktree, t);
        return JSON.stringify({ ok: true, index: idx });
      }
      case "probe": {
        if (args.keyIdx === undefined || args.key === undefined) {
          return JSON.stringify({ ok: false, error: "keyIdx+key required" });
        }
        const at = probeByKey(t, args.keyIdx as 0 | 1 | 2 | 3, args.key);
        return JSON.stringify({ ok: true, index: at });
      }
      case "swap": {
        if (!args.row || args.index === undefined) return JSON.stringify({ ok: false, error: "row+index required" });
        let parsed: Row;
        try {
          parsed = JSON.parse(args.row);
        } catch {
          return JSON.stringify({ ok: false, error: "row must be a JSON 4-tuple" });
        }
        const ok = swapRow(t, args.index, parsed);
        if (ok) saveTable(context.worktree, t);
        return JSON.stringify({ ok });
      }
      case "commit": {
        let parsed: Row;
        try {
          parsed = args.row ? JSON.parse(args.row) : (["", "", "", ""] as Row);
        } catch {
          return JSON.stringify({ ok: false, error: "row must be a JSON 4-tuple" });
        }
        const r = commitRow(
          t,
          parsed,
          {
            ...(args.keyIdx !== undefined ? { keyIdx: args.keyIdx as 0 | 1 | 2 | 3 } : {}),
            ...(args.key !== undefined ? { key: args.key } : {}),
            ...(args.locked !== undefined ? { locked: args.locked } : {}),
          },
        );
        if (r.committed) saveTable(context.worktree, t);
        return JSON.stringify(r);
      }
      case "list": {
        return JSON.stringify({ ok: true, rows: t.rows });
      }
      default:
        return JSON.stringify({ ok: false, error: `unknown op ${JSON.stringify(args.op)}` });
    }
  },
});
