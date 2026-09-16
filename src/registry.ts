/**
 * registry.ts — THE table-driven registry engine.
 *
 * Prover, validator and schema-register are one engine with different
 * tables: fixed rows, -1 sentinel for absent, swap/commit against a row
 * index, keyed lookup as normalize-then-probe. Ported from
 * schema_field_register, bind_validator and table_keyed_lookup.
 */

export const ROW_ABSENT = -1;
export const ROW_FENCED = -2;

export type Row = [unknown, unknown, unknown, unknown];

export interface RegistryTable {
  name: string;
  rows: Row[];
}

/** Normalize a lookup key: Unicode trim + lowercase (canonical spelling). */
export function normalizeKey(key: string): string {
  return key.trim().toLowerCase();
}

export function createTable(name: string): RegistryTable {
  return { name, rows: [] };
}

/** Append a row; returns its index. */
export function appendRow(table: RegistryTable, row: Row): number {
  table.rows.push(row);
  return table.rows.length - 1;
}

/** Keyed probe: first row whose cell `keyIdx` normalizes equal. -1 when none. */
export function probeByKey(table: RegistryTable, keyIdx: 0 | 1 | 2 | 3, key: string): number {
  if (!Number.isInteger(keyIdx) || (keyIdx as number) < 0 || (keyIdx as number) > 3) return ROW_ABSENT;
  const want = normalizeKey(key);
  for (let i = 0; i < table.rows.length; i++) {
    const cell = table.rows[i][keyIdx];
    if (typeof cell === "string" && normalizeKey(cell) === want) return i;
  }
  return ROW_ABSENT;
}

/** Swap row at index; out-of-range is a no-op returning false (fail closed upstream). */
export function swapRow(table: RegistryTable, index: number, row: Row): boolean {
  if (!Number.isInteger(index) || index < 0 || index >= table.rows.length) return false;
  table.rows[index] = row;
  return true;
}

export interface CommitResult {
  committed: boolean;
  index: number;
}

/**
 * Commit a row: prove (key must resolve when required) then store.
 * Fenced tables (locked) refuse with committed:false.
 */
export function commitRow(
  table: RegistryTable,
  row: Row,
  opts: { keyIdx?: 0 | 1 | 2 | 3; key?: string; locked?: boolean } = {},
): CommitResult {
  if (opts.locked) return { committed: false, index: ROW_FENCED };
  if (opts.key !== undefined) {
    const keyIdx = opts.keyIdx ?? 0;
    if (!Number.isInteger(keyIdx) || (keyIdx as number) < 0 || (keyIdx as number) > 3) {
      return { committed: false, index: ROW_ABSENT };
    }
    const at = probeByKey(table, keyIdx, opts.key);
    if (at === ROW_ABSENT) return { committed: false, index: ROW_ABSENT };
    swapRow(table, at, row);
    return { committed: true, index: at };
  }
  return { committed: true, index: appendRow(table, row) };
}
