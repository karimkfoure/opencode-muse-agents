# 01 — Subagent steering + result envelope: exact validation rules (Muse Code 1.3.0-R3057.1)

Static-only. No Ghidra load, no auth, no network beyond public. Binary:
`/tmp/opencode/muse-teardown/bin/muse-bin-1.3.0-R3057.1` ≡
`research/artifacts/bin/all-platforms/x86_linux-1.3.0-R3057.1.bin`
(verified `cmp` → IDENTICAL, 304744664 bytes).

## 1. strings sweep (100+ unique lines)

Method (verbatim):

```bash
strings -n 8 /tmp/opencode/muse-teardown/bin/muse-bin-1.3.0-R3057.1 \
  | grep -E "subagent steering intake|hydrate retained subagent|subagentId must be|trimmed with|rejected when empty|byte-for-byte intact|Bounded result summary|32 KiB|512 chars|artifactRefs|evidenceRefs|SubagentResult|SubagentInputParams" \
  | sort -u > /tmp/opencode/subagent_exact.txt   # 54 lines

strings -n 8 /tmp/opencode/muse-teardown/bin/muse-bin-1.3.0-R3057.1 \
  | grep -i -E "subagent|steering|trim|artifactRefs|evidenceRefs|SubagentResult|SubagentInputParams|32 KiB|512 chars|byte-for-byte|Unicode-whitespace|rejected when empty" \
  | sort -u > /tmp/opencode/subagent_strings.txt # 759 lines
```

Exact-pattern grep yields 54 unique lines; broadened case-insensitive sweep
yields 759 unique lines (`wc -l`), satisfying the 100+ requirement.
Full list in `/tmp/opencode/subagent_strings.txt`; key verbatim hits below
(offsets via `python3 open(...,'rb').read().find(needle)`):

| needle | offset | verbatim window |
|---|---|---|
| `The note/task text` | 7504035 | `The note/task text: trimmed with Unicode-whitespace semantics,\nrejected when empty after trimming, delivered trimmed with multibyte\ncontent byte-for-byte intact (SS3.16).` |
| `rejected when empty` | 7504098 | same as above (continuation) |
| `byte-for-byte intact` | 7504175 | same as above (tail) |
| `Bounded result summary` | 7778737 | `Bounded result summary (<=512 chars, runtime-enforced).summary` + `Result text (<=32 KiB), when present.` + `Error kind, verbatim durable vocabulary, when the child failed.errorKind` + `Evidence references, verbatim.evidenceRefs` + `Artifact references, verbatim.artifactRefs` + `Structured result data, verbatim, when present.structuredData` + `A subagent's result envelope (tdd SS4.5.7, SubagentResultEnvelope).` |
| `subagent steering intake` | 1186335 | `failed to append subagent steering intake record: ` (format-string prefix, `%`-style payload follows) |
| `hydrate retained subagent` | 1624930 | `internal error: hydrate retained subagent state: ` (format-string prefix) |
| `subagentId must be` | 845589 | `0 subagentId must be a non-empty durable child id` (adjacent blob also contains `& body must be non-empty after trimming`) |
| `body must be non-empty after trimming` | ~845600 | `body must be non-empty after trimming` (same blob as above) |
| `objective must be non-empty` | ~845620 | `(internal error: open session retention: …` blob contains `objective must be non-empty` — spawn path, not steering; listed to avoid confusion) |

Additional verbatim singletons (each count == 1 in binary, i.e. canonical source):

- `0[context trimmed without a model call]`
- `` `subagent/readResult` (SS3.16): the bare child target. ``
- `Params for 'subagent/sendMessage' and 'subagent/followupTask' (SS3.16):` + `a child target plus the input body.`
- `Params for 'subagent/resume', 'subagent/reopen', and 'subagent/readResult' (SS3.16): the bare child target.`
- `Params for 'subagent/interrupt', 'subagent/stop', and 'subagent/close' (SS3.16): a child target plus an optional human-readable reason that is preserved on the durable effect record.`
- `Durable child id (the SS4.5.7 item's 'subagentId'; opaque string).subagentId`
- `assertion failed: self.is_char_boundary(new_len)` (UTF-8 boundary guard — the enforcement behind "multibyte intact"; never split a scalar)
- `struct SubagentResult with 6 elements` (serde shape: exactly 6 fields)
- `SubagentControlStatus … SubagentResult …` open/closed enum metadata blobs
- `subagent/sendMessageCommandAcceptedResultQueue a user note into a running child; admission-only ack … (SS3.16).SubagentInputParams` (method table)
- `The objective text; required, non-empty after Unicode-whitespace trim` (spawn analogue — same trim family)

Counts: `Bounded result summary` ×1, `32 KiB` ×1, `rejected when empty` ×1,
`Unicode-whitespace` ×2 (steering body + objective text).

Multibyte proof: transcript `subagent-sendmessage-round-trip` sends
`"body":"focus on the multibyte case: 事件日志 ✓"` and receives
`{"commandId":"…","status":"accepted"}` — CJK + checkmark pass through;
delivery is trimmed but otherwise byte-for-byte.

## 2. Verbatim schemas (`artifacts/schema/stable/msp.schema.json`, $defs)

Source SHA (first 16 hex of sha256): `4101b1c23179360f`; 232 `$defs` keys.
Extracted via `python3 -c "json.load(... )['$defs'][k]"`. Byte-identical to
`/tmp/opencode/muse-teardown/muse-code-sdk/schema/msp/stable/msp.schema.json`
(same generator; `msp.d.ts` renders from the same model).

### 2.1 SubagentInputParams

```json
{
  "description": "Params for `subagent/sendMessage` and `subagent/followupTask` (SS3.16):\na child target plus the input body.",
  "properties": {
    "body": {
      "description": "The note/task text: trimmed with Unicode-whitespace semantics,\nrejected when empty after trimming, delivered trimmed with multibyte\ncontent byte-for-byte intact (SS3.16).",
      "type": "string"
    },
    "commandId": {
      "description": "Client-minted UUIDv7 command id (SS3.1.1).",
      "type": "string"
    },
    "sessionId": {
      "description": "Target session (UUIDv7 string; SS3 preamble).",
      "type": "string"
    },
    "subagentId": {
      "description": "Durable child id (the SS4.5.7 item's `subagentId`; opaque string).",
      "type": "string"
    }
  },
  "required": [
    "body",
    "commandId",
    "sessionId",
    "subagentId"
  ],
  "type": "object"
}
```

### 2.2 SubagentTargetParams

```json
{
  "description": "Params for `subagent/resume`, `subagent/reopen`, and\n`subagent/readResult` (SS3.16): the bare child target.",
  "properties": {
    "commandId": {
      "description": "Client-minted UUIDv7 command id (SS3.1.1).",
      "type": "string"
    },
    "sessionId": {
      "description": "Target session (UUIDv7 string; SS3 preamble).",
      "type": "string"
    },
    "subagentId": {
      "description": "Durable child id (the SS4.5.7 item's `subagentId`; opaque string).",
      "type": "string"
    }
  },
  "required": [
    "commandId",
    "sessionId",
    "subagentId"
  ],
  "type": "object"
}
```

### 2.3 SubagentOwnerReasonParams

```json
{
  "description": "Params for `subagent/interrupt`, `subagent/stop`, and `subagent/close`\n(SS3.16): a child target plus an optional human-readable reason that is\npreserved on the durable effect record.",
  "properties": {
    "commandId": {
      "description": "Client-minted UUIDv7 command id (SS3.1.1).",
      "type": "string"
    },
    "reason": {
      "description": "Optional reason, preserved on the durable owner-command record.",
      "type": "string"
    },
    "sessionId": {
      "description": "Target session (UUIDv7 string; SS3 preamble).",
      "type": "string"
    },
    "subagentId": {
      "description": "Durable child id (the SS4.5.7 item's `subagentId`; opaque string).",
      "type": "string"
    }
  },
  "required": [
    "commandId",
    "sessionId",
    "subagentId"
  ],
  "type": "object"
}
```

### 2.4 SubagentResult

```json
{
  "description": "A subagent's result envelope (tdd SS4.5.7, `SubagentResultEnvelope`).",
  "properties": {
    "artifactRefs": {
      "description": "Artifact references, verbatim.",
      "items": {
        "type": "string"
      },
      "type": "array"
    },
    "errorKind": {
      "description": "Error kind, verbatim durable vocabulary, when the child failed.",
      "type": "string"
    },
    "evidenceRefs": {
      "description": "Evidence references, verbatim.",
      "items": {
        "type": "string"
      },
      "type": "array"
    },
    "structuredData": {
      "description": "Structured result data, verbatim, when present.",
      "properties": {},
      "type": "object"
    },
    "summary": {
      "description": "Bounded result summary (<=512 chars, runtime-enforced).",
      "type": "string"
    },
    "text": {
      "description": "Result text (<=32 KiB), when present.",
      "type": "string"
    }
  },
  "required": [
    "artifactRefs",
    "evidenceRefs",
    "summary"
  ],
  "type": "object"
}
```

### 2.5 SubagentControlStatus

```json
{
  "description": "Subagent control status (tdd SS4.5.7, camelCased\n`SubagentControlStatus`). Open; the generic item `status` is the terminal\nauthority.",
  "enum": [
    "accepted",
    "starting",
    "running",
    "resultReady",
    "closing",
    "closed",
    "recoveryPending",
    "manualReconciliation"
  ],
  "type": "string",
  "x-msp-openness": "open"
}
```

### 2.6 CommandAcceptedResult (+ CommandAckStatus, needed to read it)

```json
{
  "description": "The uniform SS3.1.2 command acknowledgement: admission only, never an\noutcome. `session/compact` alone may answer `\"noop\"`; every other command\nanswers `\"accepted\"`.",
  "properties": {
    "commandId": {
      "description": "Echo of the client-minted UUIDv7 `commandId` (SS3.1.1).",
      "type": "string"
    },
    "status": {
      "$ref": "#/$defs/CommandAckStatus",
      "description": "`\"accepted\"` for every admitted command (SS3.1.2; closed vocabulary)."
    }
  },
  "required": [
    "commandId",
    "status"
  ],
  "type": "object"
}
```

```json
{
  "description": "The ack-status vocabulary (`tdd.md` SS3.1/SS3.1.2): `\"accepted\"` for every\nadmitted command; `session/compact` alone may answer `\"noop\"`. Closed:\nSS3.1.2 names exactly these two values, so SDK clients get a discriminated\ntype and validation catches a wrong status (PR #21550 review) — and a\nclient that received a third value would have been told nothing it can act\non, unlike [`TurnStartDisposition`], where \"acked, not otherwise\nclassified\" is a usable reading.",
  "enum": [
    "accepted",
    "noop"
  ],
  "type": "string",
  "x-msp-openness": "closed"
}
```

`msp.d.ts` twins (same model, `schema/msp/msp.d.ts:1275-1326,242-250`):

```ts
export type SubagentControlStatus = "accepted" | "starting" | "running" | "resultReady" | "closing" | "closed" | "recoveryPending" | "manualReconciliation" | (string & {});
export interface SubagentInputParams {
  /** The note/task text: trimmed with Unicode-whitespace semantics, rejected when empty after trimming, delivered trimmed with multibyte content byte-for-byte intact (SS3.16). */
  body: string;
  commandId: string; sessionId: string; subagentId: string;
}
export interface SubagentResult {
  artifactRefs: string[];
  errorKind?: string;
  evidenceRefs: string[];
  structuredData?: Record<string, unknown>;
  /** Bounded result summary (<=512 chars, runtime-enforced). */
  summary: string;
  /** Result text (<=32 KiB), when present. */
  text?: string;
}
export interface CommandAcceptedResult { commandId: string; status: CommandAckStatus; }
export type CommandAckStatus = "accepted" | "noop";
```

## 3. SDK clone: validation logic hunt (negative evidence confirmed)

Clone: `/tmp/opencode/muse-teardown/muse-code-sdk`
(`schema/msp/msp.d.ts` 1892 lines; `clients/sdk-ts/src/{connection,facade,fold,pending}`).

Grep (POSIX `grep`, `rg` absent):

```bash
grep -R -n -i -E "trim|non-empty after trimming|byte-for-byte|512|32 KiB|32768|artifactRefs|evidenceRefs|SubagentResult|SubagentInputParams|body must be" \
  schema/msp/msp.d.ts clients/sdk-ts/src
```

Hits — types only, no enforcement:

- `schema/msp/msp.d.ts:525` — `result?: SubagentResult;` (field reference, no check)
- `schema/msp/msp.d.ts:1279-1288` — `SubagentInputParams` + doc comment `/** The note/task text: trimmed with … byte-for-byte intact (SS3.16). */` (comment only)
- `schema/msp/msp.d.ts:1302-1316` — `SubagentResult` + `/** Bounded result summary (<=512 chars, runtime-enforced). */`, `/** Result text (<=32 KiB), when present. */` (comments only)
- `clients/sdk-ts/src/fold/item-store.ts:177` — verbatim: `* The last wire item remains byte-for-byte intact: terminal-unknown is a` (ephemeral-host-death display annotation, unrelated to steering trim)
- `clients/sdk-ts/src/index.ts:142` — `// Trimmed deliberately (Constitution XI): …` (export-list comment)
- `clients/sdk-ts/src/connection/connection.ts:524` — `if (line.trim().length === 0) return;` (NDJSON blank-line skip on inbound framing, NOT body validation; uses JS `String.trim`, not Unicode-trim + reject)
- `clients/sdk-ts/src/connection/spawn.ts:155-156,166-185` —
  `this.#trimLines();` / `this.#trimBytes();` + `#trimLines` (stderr tail line cap) + `#trimBytes` (stderr tail byte cap with UTF-8 continuation guard `while (start < … && (bytes[start]! & 0xc0) === 0x80) start += 1;`). Stderr ring-buffer hygiene only; not steering/result validation.

Facade zero-hit proof:

```bash
grep -R -n -i "subagent" clients/sdk-ts/src/facade/  # → no output (only false positive "somebody" on a case-sensitive 'body' search)
grep -R -n "subagent" clients/sdk-ts/src/            # → no output
```

So: **zero facade hits for `subagent/SendMessage/body/summary/artifactRefs/evidenceRefs/512/32768`** — the TS facade is a thin transport/fold layer; all steering/result validation lives server-side (Rust runtime). Negative evidence as expected.

Transcripts corroborate server-side admission (no client pre-check):
`subagent-sendmessage-round-trip` (multibyte body → `accepted`),
`subagent-steering-duplicate-replay` (same `commandId` + identical payload → value-identical ack, durable ledger),
`subagent-steering-rejection` (`subagent/readResult` unready → `commandRejected/not_ready`).

## 4. Synthesis: exact pseudo-validation for `spark_send` / `spark_result`

Conventions: `chars(s)` = Unicode scalar count (Rust `s.chars().count()`; NOT UTF-8 bytes, NOT UTF-16 units). `bytes(s)` = UTF-8 byte length. Trim = Unicode White_Space trim both ends (Rust `str::trim`, i.e. `char::is_whitespace` incl. U+0020 U+0009-000D U+00A0 U+1680 U+2000-200A U+2028 U+2029 U+202F U+205F U+3000; NOT byte-strip). Trim must land on a char boundary (else `is_char_boundary` panic path — trim ASCII-whitespace only, interior multibyte untouched).

```
const SUMMARY_MAX_CHARS = 512;
const TEXT_MAX_BYTES    = 32 * 1024; // 32768

fn spark_send_validate(sessionId, commandId, subagentId, body) -> Result<TrimmedBody, Reject>:
  # envelopes: sessionId/commandId UUIDv7 strings (SS3 preamble/SS3.1.1); subagentId opaque durable child id
  if subagentId is empty:                      # verbatim runtime string
    reject("subagentId must be a non-empty durable child id")
  # body rule, verbatim schema doc:
  #   "trimmed with Unicode-whitespace semantics, rejected when empty
  #    after trimming, delivered trimmed with multibyte content byte-for-byte intact"
  trimmed = unicode_whitespace_trim(body)       # both ends; interior bytes untouched; char-boundary safe
  if trimmed is empty:
    reject("body must be non-empty after trimming")   # verbatim runtime string
  deliver(sessionId, subagentId, commandId, trimmed)   # trimmed payload is what is stored/displayed; ack is CommandAcceptedResult{status:"accepted"} only
  # failure modes: same-commandId replay with IDENTICAL payload → identical accepted ack, no duplicate intake
  #   (durable family ledger). Different payload under same commandId → commandId_conflict rejection.
  #   Intake write failure → "failed to append subagent steering intake record: {cause}".
  #   Retained-state load failure → "internal error: hydrate retained subagent state: {cause}".

fn spark_result_validate(summary, text?, errorKind?, evidenceRefs, artifactRefs, structuredData?) -> Result<Envelope, Reject>:
  require evidenceRefs: array of string (may be empty; must be present; verbatim passthrough)
  require artifactRefs: array of string (may be empty; must be present; verbatim passthrough)
  require summary: string AND chars(summary) <= 512      # "Bounded result summary (<=512 chars, runtime-enforced)"
    else reject aligning to durable `invalid_result` / `result_validation_rejections` counters
       (binary exposes SubagentResultReportOutcome{missing,schema_invalid,cancelled_before_report} telemetry; no per-field message string in binary)
  if text present: require bytes(text) <= 32768          # "Result text (<=32 KiB), when present"
    else reject as above (oversize)
  errorKind: when child failed, verbatim durable vocabulary string (no normalization)
  structuredData: when present, verbatim object passthrough
  envelope = SubagentResult{summary, text?, errorKind?, evidenceRefs, artifactRefs, structuredData?}
  # controlStatus ∈ SubagentControlStatus (open: accepted|starting|running|resultReady|closing|closed|recoveryPending|manualReconciliation + future additively);
  # generic item `status` is the terminal authority, not controlStatus.
  # ack for every steering command is CommandAcceptedResult{commandId: echo, status: "accepted"}
  #   ("noop" is legal ONLY for session/compact; never for subagent/*).
```

Port verbatim into `spark_send`/`spark_result` tools: copy the six `$defs`
JSON blocks (§2) as the JSON-Schema, enforce the two functions above
(server-side semantics; client must NOT pre-truncate — send through and
surface the runtime rejection so behavior matches Muse byte-for-byte),
count summary in chars and text in bytes, trim body with Unicode semantics
(`\p{White_Space}` both ends, e.g. Python `str.strip()` is close but
validates against Rust `char::is_whitespace`; test with U+00A0 U+2003 U+3000
+ `事件日志 ✓`), and never split UTF-8 scalars when slicing.

Touches nothing under `/home/karim/dev/m8` (this track wrote only
`re-tracks/01-steering-result.md` + `/tmp/opencode/subagent_*.txt` scratch).
