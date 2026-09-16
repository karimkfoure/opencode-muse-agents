/**
 * ids.ts — identity primitives ported from Muse Code internals.
 *
 * - commandId: client-minted UUIDv7 per command (SS3.1.1). Retry with the
 *   SAME commandId joins the original; never mint a new one on retry.
 * - Event ID canonical form: 16 bytes -> 36 lowercase hex chars,
 *   hyphenated 8-4-4-4-12 (uuid_canonical_encode @0x6c61450, nibble table).
 * - Dedupe keys + generation/lease guards for stale-write protection.
 */

const HEX = "0123456789abcdef";

function randomBytes(n: number): Uint8Array {
  const b = new Uint8Array(n);
  crypto.getRandomValues(b);
  return b;
}

/** Mint a UUIDv7: 48-bit unix_ms + ver(0111) + 12-bit rand_a + var(10) + 62-bit rand_b. */
export function mintCommandId(nowMs: number = Date.now()): string {
  const ms = Math.floor(nowMs);
  const randA = randomBytes(2);
  const randB = new Uint8Array(8);
  crypto.getRandomValues(randB);
  const b = new Uint8Array(16);
  // time_hi (48 bits big-endian)
  let t = ms;
  for (let i = 5; i >= 0; i--) {
    b[i] = t & 0xff;
    t = Math.floor(t / 256);
  }
  b[6] = 0x70 | (randA[0] & 0x0f);
  b[7] = randA[1];
  b[8] = 0x80 | (randB[0] & 0x3f);
  b.set(randB.subarray(1), 9);
  return canonicalEventId(b);
}

/** 16 bytes -> 36 lowercase hex chars, hyphenated 8-4-4-4-12. Byte-exact. */
export function canonicalEventId(bytes16: Uint8Array): string {
  if (bytes16.length !== 16) throw new RangeError("canonicalEventId needs 16 bytes");
  const h = (i: number) => HEX[(bytes16[i] >> 4) & 0xf] + HEX[bytes16[i] & 0xf];
  let out = "";
  for (let i = 0; i < 16; i++) {
    if (i === 4 || i === 6 || i === 8 || i === 10) out += "-";
    out += h(i);
  }
  return out;
}

const CANONICAL_RE = /^[0-9a-f]{8}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{4}-[0-9a-f]{12}$/;

/** True iff exactly 36 canonical bytes: lowercase hyphenated spelling. */
export function isCanonicalEventId(s: string): boolean {
  return CANONICAL_RE.test(s);
}

/** Parse canonical back to 16 bytes; throws on any deviation. */
export function parseCanonicalEventId(s: string): Uint8Array {
  if (!isCanonicalEventId(s)) throw new Error("Event ID must contain exactly 36 canonical bytes");
  const hex = s.replaceAll("-", "");
  const out = new Uint8Array(16);
  for (let i = 0; i < 16; i++) out[i] = parseInt(hex.slice(i * 2, i * 2 + 2), 16);
  return out;
}

/** Dedupe key over canonical evidence parts (join with \x1f, sha256 hex). */
export async function dedupeKey(parts: string[]): Promise<string> {
  const data = new TextEncoder().encode(parts.join(""));
  const digest = await crypto.subtle.digest("SHA-256", data);
  return [...new Uint8Array(digest)].map((x) => x.toString(16).padStart(2, "0")).join("");
}

/** Synchronous dedupe over already-hashed hex parts (no WebCrypto needed). */
export function dedupeKeyHex(parts: string[]): string {
  // FNV-1a 64-bit x2 with domain separation — NOT cryptographic; only a
  // local dedupe index. Durable fingerprints must use dedupeKey().
  let h1 = 0xcbf29ce484222325n;
  let h2 = 0x84222325cbf29ce4n;
  const M = (1n << 64n) - 1n;
  for (const p of parts) {
    for (let i = 0; i < p.length; i++) {
      const c = BigInt(p.charCodeAt(i));
      h1 = ((h1 ^ c) * 0x100000001b3n) & M;
      h2 = ((h2 ^ (c + 0x9e3779b9n)) * 0x100000001b3n) & M;
    }
    h1 = ((h1 ^ 0x1fn) * 0x100000001b3n) & M;
  }
  return h1.toString(16).padStart(16, "0") + h2.toString(16).padStart(16, "0");
}

export interface LeaseGuard {
  generation: number;
}

/**
 * True when `seen` is stale relative to `current` (generation moved).
 * Stale writes must never land: fail closed.
 */
export function isGenerationStale(current: LeaseGuard, seen: LeaseGuard): boolean {
  return seen.generation !== current.generation;
}
