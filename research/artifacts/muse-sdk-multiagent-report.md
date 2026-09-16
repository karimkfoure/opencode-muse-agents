# Muse Code SDK — Multi-Agent Teardown Report

Source: `https://github.com/meta-models/muse-code-sdk.git`
Local clone: `/tmp/opencode/muse-teardown/muse-code-sdk`
Git HEAD at clone time: `fbce769 Re-mirror SDK source closure at the docs cohort head (tbh #26230/#26772/#26724)`
Tarball: `/tmp/opencode/muse-teardown/muse-code-sdk-0.1.1.tgz` (copied to `research/artifacts/sdk-tarball/muse-code-sdk-0.1.1.tgz`)
Report output dir: `research/artifacts` (this file)

npm pack results:
- `@muse-code/sdk@0.1.1` — EXISTS. `dist.tarball = https://registry.npmjs.org/@muse-code/sdk/-/sdk-0.1.1.tgz`. Packed OK: `muse-code-sdk-0.1.1.tgz`, 134.6 kB packed / 442.2 kB unpacked, 38 files, `shasum 6f0f714a7aed85962655682460d46bedcaf4956b`. Tarball contains `dist/src/*.{js,d.ts}` + `dist/src/msp.d.ts` (103.6 kB, bundled wire types) + `package.json` + `README.md` + `LICENSE`. Full listing verified via `tar tzf` (see §0).
- `@muse-code/msp` — DOES NOT EXIST on npm. `npm view @muse-code/msp` → `E404 Not Found`. Also checked `@muse-code/msp-ts` → E404, `muse-code-sdk` → E404. Only `@muse-code/sdk` versions `['0.1.0','0.1.1']` are published. This is by design: `clients/msp-ts/package.json` is `"name": "@muse-code/msp", "version": "0.0.0", "private": true` with comment "Repo-build-only during 0.x (#211 O-5)". Root `package.json` confirms: "Only @muse-code/sdk is published to npm, at 0.x with no stability promise (tdd D-013 as amended by D-053); every other package here is repo-build-only and private."

Constraint honored: nothing under `/home/karim/dev/m8` was read or edited. All work in `/tmp/opencode/muse-teardown` + this artifacts dir.

---

## 0. Provenance / layout ground truth

### 0.1 Top level (`/tmp/opencode/muse-teardown/muse-code-sdk/`)

```
CHANGELOG.md            393 lines (product changelog; SDK publish noted in 1.0.1)
clients/                sdk-ts, msp-ts, sdk-quickstart, sdk-cookbook (+ referenced clients/acp in workspaces, not present)
LICENSE                 MIT
package.json            "@muse-code/workspace", private:true, workspaces=[msp-ts, sdk-ts, cookbook, quickstart, acp]
package-lock.json
publish-anchor.json     upstream mirror pointer; hand_authored=[README.md, .nojekyll, LICENSE, .github/, publish-anchor.json]
README.md               102 lines (mirror notice + docs-site pointer)
schema/msp/             msp.d.ts (1892 lines) + stable/ + transcripts/ (~48 scenarios)
scripts/                check-msp-ts-typecheck.sh etc.
```

Root `package.json` verbatim (`/tmp/opencode/muse-teardown/muse-code-sdk/package.json:1-22`):

```json
{
  "name": "@muse-code/workspace",
  "private": true,
  "description": "TypeScript workspace for the MSP client tier (spec 14990-muse-sdk). Only @muse-code/sdk is published to npm, at 0.x with no stability promise (tdd D-013 as amended by D-053); every other package here is repo-build-only and private.",
  "workspaces": [
    "clients/msp-ts",
    "clients/sdk-ts",
    "clients/sdk-cookbook",
    "clients/sdk-quickstart",
    "clients/acp"
  ],
  "engines": { "node": ">=20" }
}
```

### 0.2 `clients/sdk-ts/` — `@muse-code/sdk@0.1.1` (the only published package)

`clients/sdk-ts/package.json:1-35` (verbatim excerpts):

```json
{
  "name": "@muse-code/sdk",
  "version": "0.1.1",
  "description": "TypeScript SDK for the Muse Session Protocol (MSP): connect to a Muse Code session, drive turns, and fold the event stream. Zero runtime dependencies.",
  "type": "module",
  "main": "dist/src/index.js",
  "types": "dist/src/index.d.ts",
  "files": ["dist/src"],
  "dependencies": {},
  "devDependencies": { "@muse-code/msp": "*", "@types/node": "26.2.0" }
}
```

Build/pack: `"prepack": "npm run build && node scripts/bundle-msp-types.mjs"` — this is why the tarball carries `dist/src/msp.d.ts` (103.6 kB notice line). Zero runtime deps (INV-009).

Source tree (`clients/sdk-ts/src/`, line counts via `wc -l`):

```
src/index.ts                    183  barrel (MuseClient, Session, Connection, spawnMspConnection, folds, errors)
src/errors.ts                    71  MuseForeignSessionError, MuseGapFillError, MuseSessionDiscardedError
src/fingerprint.ts               71  EXPECTED_SCHEMA_FINGERPRINT + checkServedFingerprint
src/connection/connection.ts    669  DuplexTransport, Connection (NDJSON, command/request/notify, UUIDv7 mint)
src/connection/spawn.ts         645  SpawnMspConnectionOptions, MuseServeChild, MspHandshake, SpawnedMspConnection, spawnMspConnection()
src/facade/client.ts            393  MuseClient, StartSessionOptions, ResumeSessionOptions, MuseClientSpawnOptions
src/facade/session.ts           903  Session (fold+pending+turn routing, sendUserTurn, onApproval, gap-fill, host-death)
src/facade/turn-submit.ts       223  TurnSubmitter, SendUserTurnOptions, submit()/replay()
src/facade/turn-handle.ts       381  TurnHandle/Turn, TurnOutcome, isLaunchFailure, items()/deltas()/completed
src/facade/approval.ts          228  ApprovalRouter (approval/decide)
src/facade/gap-fill.ts          428  GapFiller (SS4.8 splice-fill)
src/facade/host-death.ts        193  readSessionDurability, isAbnormalHostDeath, survivesHostDeath
src/facade/discarded.ts          37  DiscardedSessions
src/fold/item-store.ts          215  generic item fold
src/fold/session-fold.ts        822  SessionFold bound to generated view types
src/fold/state-store.ts         110  session-state fold
src/pending/pending-command-set.ts 681  SS4.13 PendingCommandSet
scripts/bundle-msp-types.mjs         tarball bundler for msp.d.ts
qa/  (attribution.ts, binary.ts, bin.ts, index.ts, oracle.ts, recorder.ts, replay-host.ts, report.ts, run.ts, scenario-kit.ts, scenarios.ts, tap-shim.ts, tap.ts, scenarios/conformance.ts, scenarios/defect-classes.ts, scenarios/turn-blocked.ts)
  — NOT shipped; black-box QA driver spawning real `tbh serve` (see clients/sdk-ts/README.md "qa/ — the --area sdk black-box QA driver").
test/ (27 files; binary-free except muse-serve-child.test.ts + spawn-handshake.test.ts which need a real `muse` host)
```

### 0.3 `clients/msp-ts/` — `@muse-code/msp@0.0.0` (private, never published)

```
clients/msp-ts/index.d.ts     14 lines (whole package)
clients/msp-ts/package.json   name @muse-code/msp, version 0.0.0, private:true, types:index.d.ts, files:[index.d.ts]
clients/msp-ts/README.md      INV-001 discipline + fingerprint pin rationale
```

Verbatim `clients/msp-ts/index.d.ts:1-14`:

```ts
// @muse-code/msp — the generated MSP wire types, consumed IN PLACE.
//
// This file is the whole package. It re-exports the committed declarations
// that `crates/protocol` renders (spec 206, byte-pinned by the required Rust
// test `generate_ts_reproduces_the_committed_declarations`). The artifact is
// NOT copied or vendored here: a second copy would drift from the one #206
// owns, which is exactly what the fingerprint-pinning discipline exists to
// prevent (spec 14990 INV-008).
//
// Hand-writing a protocol type anywhere in this workspace is forbidden
// (INV-001). A type the generated layer lacks is a #206 request, not a local
// interface.

export type * from "../../schema/msp/msp.js";
```

Verbatim `clients/msp-ts/package.json:1-17`:

```json
{
  "name": "@muse-code/msp",
  "version": "0.0.0",
  "private": true,
  "description": "Generated MSP wire types. Re-exports the committed declarations at schema/msp/msp.d.ts in place; no runtime code, no copy (spec 14990 INV-008).",
  "types": "index.d.ts"
}
```

README key line (`clients/msp-ts/README.md:14`): "would fork from the one #206 owns — the failure mode the fingerprint pin … exists to prevent". Here "fork" = copy-drift, NOT session/fork or process fork.

### 0.4 `schema/msp/` — the protocol source of truth

```
schema/msp/msp.d.ts                  1892 lines, generated by tbh-protocol (spec 206), DO NOT EDIT
schema/msp/stable/msp.schema.json    190795 bytes, $defs=185, methods + notifications + errors + capabilities
schema/msp/stable/manifest.json      {"experimental":false,"fingerprint":"sha256:cfd31ee77d78fdada9febc4edccd29b0434ff8f6bf157c7c03fd0ecfcbc29f5a","schemaVersion":1}
schema/msp/transcripts/              ~48 scenarios × (manifest.json + transcript.ndjson); 5× subagent*, 3× workflow*
```

Subagent transcripts present: `subagent-close-round-trip/`, `subagent-nested-lifecycle/`, `subagent-sendmessage-round-trip/`, `subagent-steering-duplicate-replay/`, `subagent-steering-rejection/`. Workflow transcripts: `workflow-cancel-round-trip/`, `workflow-child-control-skip/`, `workflow-child-lifecycle/`. Full list in §5.

### 0.5 `clients/sdk-quickstart/` — executable first-session journey (private)

```
package.json   name @muse-code/sdk-quickstart, 0.0.0, private:true, deps @muse-code/msp + @muse-code/sdk + @muse-code/sdk-cookbook (dev)
src/host.ts          20 lines (re-export shim → cookbook kit)
src/journey.ts      672 lines (12-segment acceptance journey vs release-built `muse serve`; QUICKSTART_CLIENT_INFO={name:"muse_sdk_quickstart"})
src/main.ts          57 lines
src/provider.ts     283 lines (loopback fake first-party endpoint seeding HOME)
src/segments.ts      23 lines (shim → kit)
test/journey.test.ts, test/segments.test.ts
README.md            renders the same program the package executes
```

No subagent coverage: `grep -rn subagent clients/sdk-quickstart/src` → zero hits. Single-session journey only (`sessionId?: string` in Context, one `session-new` + resumes + turns + one approval).

### 0.6 `clients/sdk-cookbook/` — executable cookbook recipes (private)

```
package.json   name @muse-code/sdk-cookbook, 0.0.0, private:true, exports {"./kit": ...}, deps @muse-code/msp + @muse-code/sdk (dev)
src/args.ts             39
src/main.ts             48  (recipe runner entry)
src/manifest.ts         32  (recipe→docs-page binding, tested both directions)
src/runner.ts          150  (serial runner, verdict aggregation)
src/kit/host.ts        307  (Host.spawn/Host.start over spawnMspConnection + notification recorder; isolatedHostEnv)
src/kit/index.ts        40
src/kit/segments.ts    207  (Segment/runSegment/summarize expect-block contract)
src/recipes/ (10 files):
  answer-user-input.ts (376), approve-or-deny.ts (378), cancel-mid-turn.ts (177),
  classify-serve-exits.ts (343), fingerprint-mismatch.ts (120),
  list-models-and-switch-mid-session.ts (336), queue-steer-reclaim.ts (332),
  retry-without-double-submitting.ts (532), stream-a-turn.ts (253),
  survive-the-host-dying.ts (542)
test/runner.test.ts
```

No subagent recipe: `grep -rn subagent clients/sdk-cookbook/src` → zero hits in `src/` (only incidental "durability fork" prose in survive-the-host-dying.ts:5,23 — see §2). All recipes are single-session `Host.spawn` + `session/start|resume` + `turn/*` + `approval/*`.

---

## 1. How multi-agent is exposed in the SDK (`clients/*/src` search)

Method: `grep -rn -i "subagent\|fork\|WorkflowChild\|worktree\|parallel" clients --include='*.ts' --include='*.md'` + per-term `grep -rn <term> clients/*/src`. All paths below are repo-relative to `/tmp/opencode/muse-teardown/muse-code-sdk`.

### 1.1 Result summary (the headline finding)

**There is NO multi-agent facade in `clients/*/src`.** Zero hits for `subagent`, `WorkflowChild`, `worktree` in any `clients/*/src` file. The only `fork`/`parallel` hits are English prose / unrelated identifiers. Multi-agent lives ONE layer down: generated wire types in `schema/msp/msp.d.ts` + `schema/msp/stable/msp.schema.json`, exercised by hand-authored conformance transcripts in `schema/msp/transcripts/subagent-*/` + `workflow-*/`, folded generically by `SessionFold`/`ItemStore` as `kind:"subagent"|"workflow"` items. The SDK never mints a subagent (no `subagent/spawn` method exists on the wire); children are created by the MODEL inside a turn, and the SDK only observes their `Item` records and drives the 8 owner-control commands via raw `Connection.command()`.

### 1.2 Per-term exact hits in `clients/*/src`

#### `subagent` — ZERO hits in `clients/*/src`

```
$ grep -rn "subagent" clients/*/src
(no output, exit 0)
```

Wider `clients/` (incl. tests/docs) hits, for completeness — none is a facade API:

| File | Line | Text | Why not multi-agent API |
|---|---|---|---|
| `clients/sdk-cookbook/test/runner.test.ts` | 63 | `// Yield so an accidentally-parallel runner would interleave.` | comment about test runner serialization |
| `clients/sdk-ts/test/session-fold.test.ts` | 206,208 | `fold.apply(turnCompleted("turn-1", "supersededByFork", "v:s:2"));` / `assert.equal(fold.turn("turn-1")?.terminal, "supersededByFork");` | a `TurnTerminal`-adjacent test string, not `session/fork` |
| `clients/sdk-ts/test/workspace-pins.test.ts` | 107 | `"a vendored copy of msp.d.ts would fork from the artifact #206 owns",` | copy-drift prose (same as msp-ts README) |
| `clients/msp-ts/README.md` | 14 | `would fork from the one #206 owns — the failure mode the fingerprint pin` | same copy-drift prose |

#### `fork` — 3 hits in `clients/*/src`, all prose, none is `session/fork`

```
clients/sdk-cookbook/src/recipes/survive-the-host-dying.ts:5: * of them ask your app first. What this recipe teaches is the durability fork
clients/sdk-cookbook/src/recipes/survive-the-host-dying.ts:23: * Two arms, mirroring that fork:
clients/sdk-ts/src/facade/host-death.ts:110: * joins the same predicate rather than getting a parallel one that could drift.
```

Wait — the third line is the `parallel` hit, not `fork`; the `fork` set in `src/` is exactly the first two. Verbatim context (`survive-the-host-dying.ts:1-30`):

```ts
/**
 * … What this recipe teaches is the durability fork
 * …
 * Two arms, mirroring that fork:
 */
```

= durable-vs-ephemeral host-death fork. No `session/fork` call, no `ForkCutPoint`, no `ForkProvenance` anywhere in `clients/*/src`.

Test-only `fork` strings (NOT `src/`, listed so a text search doesn't mislead):

```
clients/sdk-ts/test/session-fold.test.ts:206:  fold.apply(turnCompleted("turn-1", "supersededByFork", "v:s:2"));
clients/sdk-ts/test/session-fold.test.ts:208:  assert.equal(fold.turn("turn-1")?.terminal, "supersededByFork");
clients/sdk-ts/test/workspace-pins.test.ts:107:    "a vendored copy of msp.d.ts would fork from the artifact #206 owns",
```

#### `WorkflowChild` — ZERO hits in `clients/*/src` (and in all of `clients/`)

```
$ grep -rn "WorkflowChild" clients/*/src
(no output, exit 0)
$ grep -rn "WorkflowChild" clients
(no output, exit 0)
```

`WorkflowChild` exists ONLY in `schema/msp/msp.d.ts:1865-1885` (folded per-child state inside a `kind:"workflow"` Item) + JSON Schema `$defs.WorkflowChild`. The SDK folds it opaquely; no helper, no launcher, no per-child handle.

#### `parallel` — 1 hit in `clients/*/src`, unrelated

```
clients/sdk-ts/src/facade/host-death.ts:110: * joins the same predicate rather than getting a parallel one that could drift.
```

Verbatim context (`host-death.ts:100-115`): two death-notification paths (process exit vs transport EOF) sharing one discharge predicate. Nothing to do with parallel agents.

#### `worktree` — ZERO hits in `clients/*/src` (and in all of `clients/`)

```
$ grep -rn -i "worktree" clients/*/src
(no output, exit 0)
$ grep -rn -i "worktree" clients
(no output, exit 0)
```

`worktree` appears ONLY in `CHANGELOG.md` (product notes: `--worktree` flag, session/subagent worktrees — see §5). No worktree type, param, or helper exists in the SDK or the MSP schema (`grep -rln worktree schema` → no hits either; worktrees are a host-runtime concern, invisible on the wire).

#### `session/message` — literal string ZERO hits; the two halves separately are ubiquitous transport vocabulary

```
$ grep -rn "session/message" clients/*/src
(no output, exit 0)
```

- `session/*` method strings in `clients/sdk-ts/src` are the LIFECYCLE verbs the facade actually wraps or folds — `session/start`, `session/resume` (client.ts), `session/fork`/`session/read`/`session/list` (fold/history only, never called by the facade), `session/compact`, `session/setModel`, `session/userShell`, `session/setApprovalMode` (params types only), plus `session/*` view notifications folded in `fold/session-fold.ts:94-101,577-582` (`session/modelChanged|goalChanged|todoListChanged|branchChanged|tokenUsage|contextUsage|approvalModeChanged`). Representative signature sites:
  - `clients/sdk-ts/src/facade/client.ts:278: async startSession(options: StartSessionOptions = {}): Promise<Session>`
  - `clients/sdk-ts/src/facade/client.ts:305: async resumeSession(options: ResumeSessionOptions): Promise<Session>`
  - `clients/sdk-ts/src/fold/session-fold.ts:84-101` — `ViewEvent` union (`turn/started|completed|retracted|retryScheduled|unqueued`, `session/modelChanged|…`, `item/started|updated|delta|completed`, etc.)
- `message` in `clients/sdk-ts/src` = ~15 hits, all `Error.message` / `MspError.message` / user-message item prose (e.g. `connection.ts:109 super(error.message)`, `errors.ts:7 "the only alternative is matching message text"`). There is NO `session/message` or `message/send` wire method; the peer-messaging feature noted in CHANGELOG 1.0.1 ("Two sessions on the same machine can message each other") has NO corresponding method in `MspMethod` (see §3) — it is a product feature outside this SDK snapshot's wire surface.

### 1.3 What the SDK *does* expose that a coordinator reuses (signatures)

These are the exact seams a multi-agent coordinator builds on (full semantics in §4):

```
clients/sdk-ts/src/connection/spawn.ts:643: export function spawnMspConnection(options: SpawnMspConnectionOptions): MspHandshake
clients/sdk-ts/src/connection/spawn.ts:30:  export interface SpawnMspConnectionOptions { readonly command: string; readonly args?: readonly string[]; readonly cwd?: string; readonly env?: NodeJS.ProcessEnv; readonly connection?: ConnectionOptions; readonly onStderr?: (chunk: string) => void; readonly shutdownTimeoutMs?: number; }
clients/sdk-ts/src/connection/spawn.ts:588: async initialize(params: InitializeParams): Promise<SpawnedMspConnection>   (on MspHandshake; may be sent only once)
clients/sdk-ts/src/facade/client.ts:219: static async spawn(options: MuseClientSpawnOptions): Promise<MuseClient>
clients/sdk-ts/src/facade/client.ts:278: async startSession(options: StartSessionOptions = {}): Promise<Session>
clients/sdk-ts/src/facade/client.ts:305: async resumeSession(options: ResumeSessionOptions): Promise<Session>
clients/sdk-ts/src/facade/client.ts:98:  export type StartSessionOptions = Readonly<Omit<SessionStartParams, "commandId" | "config">>
clients/sdk-ts/src/facade/session.ts:721: async sendUserTurn(options: SendUserTurnOptions<I>): Promise<Turn>
clients/sdk-ts/src/facade/session.ts:580: turn(turnId: string): Turn
clients/sdk-ts/src/facade/session.ts:729: onApproval(handler: ApprovalHandler): void
clients/sdk-ts/src/connection/connection.ts:341: async command(method: string, params: Record<string, unknown>, options?: CommandOptions): Promise<Record<string, unknown>>
clients/sdk-ts/src/connection/connection.ts:311: mintCommandId(): string
clients/sdk-ts/src/connection/connection.ts:274: request(method: string, params?: Record<string, unknown>): Promise<Record<string, unknown>>
clients/sdk-ts/src/facade/turn-handle.ts:252: get completed(): Promise<TurnOutcome>
clients/sdk-ts/src/facade/turn-handle.ts:280: items(): AsyncIterableIterator<FoldedItem>
clients/sdk-ts/src/facade/turn-handle.ts:300: deltas(): AsyncIterableIterator<ItemDeltaParams>
clients/sdk-ts/src/facade/turn-submit.ts:39: export type SendUserTurnOptions<I> = Readonly<Omit<TurnStartParams, "commandId" | "sessionId">> & { readonly composerInput?: I }
```

Note what is MISSING (deliberately, INV-001): no `startSubagent()`, no `sendToSubagent()`, no `forkSession()`, no `SubagentHandle`, no `WorkflowHandle`. A coordinator drives subagents either (a) as MODEL-spawned children observed as `Item{kind:"subagent"}` + controlled via raw `connection.command("subagent/*", …)`, or (b) as N independent SESSIONS (N× `startSession` + `sendUserTurn`, `Promise.all` over `turn.completed`) — pattern in §4.4.

---

## 2. MSP wire types for `subagent/*` — all 8 methods, full TS definitions

Canonical source: `/tmp/opencode/muse-teardown/muse-code-sdk/schema/msp/msp.d.ts` (generated, spec 206, INV-017). JSON binding: `schema/msp/stable/msp.schema.json` → `methods["subagent/*"]`. The SDK consumes these via `@muse-code/msp` (in-place re-export, §0.3) and bundles a copy at `dist/src/msp.d.ts` in the published tarball.

### 2.1 Method index entry

`schema/msp/msp.d.ts:1887-1888`:

```ts
/** Every wire method in this schema (SS1.9 index). */
export type MspMethod = "initialize" | "subagent/sendMessage" | "subagent/followupTask" | "subagent/interrupt" | "subagent/stop" | "subagent/resume" | "subagent/reopen" | "subagent/close" | "subagent/readResult" | "session/start" | "session/resume" | "session/fork" | "session/list" | "session/read" | "turn/start" | "turn/steer" | "turn/interrupt" | "turn/cancel" | "turn/unqueue" | "session/compact" | "session/setModel" | "session/userShell" | "model/list" | "view/unsubscribe" | "view/page" | "approval/decide" | "approval/listPending" | "session/setApprovalMode" | "userInput/answer" | "userInput/cancel" | "userInput/clarify";
```

The 8 `subagent/*` members: `sendMessage`, `followupTask`, `interrupt`, `stop`, `resume`, `reopen`, `close`, `readResult`. There is NO `subagent/spawn`/`subagent/start` — children are model-spawned inside a turn; the owner commands below only STEER already-existing children. (Spec refs: SS3.16 for commands, SS4.5.7 for the folded item lifecycle.)

### 2.2 JSON Schema method table (`schema/msp/stable/msp.schema.json: methods`, verbatim)

```json
"subagent/close": {
  "description": "Owner-close a child; the terminal mapping folds per SS4.5.7 (SS3.16).",
  "params": { "$ref": "#/$defs/SubagentOwnerReasonParams" },
  "result": { "$ref": "#/$defs/CommandAcceptedResult" }
},
"subagent/followupTask": {
  "description": "Queue a follow-up task for a child; admission-only ack, the task settles on the child session's view stream (SS3.16).",
  "params": { "$ref": "#/$defs/SubagentInputParams" },
  "result": { "$ref": "#/$defs/CommandAcceptedResult" }
},
"subagent/interrupt": {
  "description": "Ask a child to yield at its next boundary; outcome folds to the parent's subagent item (SS3.16, SS4.5.7).",
  "params": { "$ref": "#/$defs/SubagentOwnerReasonParams" },
  "result": { "$ref": "#/$defs/CommandAcceptedResult" }
},
"subagent/readResult": {
  "description": "Consume a ready child result (state-changing; the content is already the subagent item's result field) (SS3.16).",
  "params": { "$ref": "#/$defs/SubagentTargetParams" },
  "result": { "$ref": "#/$defs/CommandAcceptedResult" }
},
"subagent/reopen": {
  "description": "Reopen a stopped/closed child as a durable later attempt (SS3.16).",
  "params": { "$ref": "#/$defs/SubagentTargetParams" },
  "result": { "$ref": "#/$defs/CommandAcceptedResult" }
},
"subagent/resume": {
  "description": "Resume a paused/recoverable child as a durable later attempt (SS3.16).",
  "params": { "$ref": "#/$defs/SubagentTargetParams" },
  "result": { "$ref": "#/$defs/CommandAcceptedResult" }
},
"subagent/sendMessage": {
  "description": "Queue a user note into a running child; admission-only ack, the note settles on the child session's view stream (SS3.16).",
  "params": { "$ref": "#/$defs/SubagentInputParams" },
  "result": { "$ref": "#/$defs/CommandAcceptedResult" }
},
"subagent/stop": {
  "description": "Stop a running child; outcome folds to the parent's subagent item (SS3.16, SS4.5.7).",
  "params": { "$ref": "#/$defs/SubagentOwnerReasonParams" },
  "result": { "$ref": "#/$defs/CommandAcceptedResult" }
}
```

All 8 return the uniform SS3.1.2 admission ack (`CommandAcceptedResult`), never an outcome — the outcome folds later as `item/updated|completed` on the PARENT view stream (and task settlement on the CHILD stream for sendMessage/followupTask).

### 2.3 Full TS definitions (verbatim from `schema/msp/msp.d.ts`)

`msp.d.ts:1275-1276` — control status:

```ts
/** Subagent control status (tdd SS4.5.7, camelCased `SubagentControlStatus`). Open; the generic item `status` is the terminal authority. */
export type SubagentControlStatus = "accepted" | "starting" | "running" | "resultReady" | "closing" | "closed" | "recoveryPending" | "manualReconciliation" | (string & {});
```

`msp.d.ts:1278-1288` — input params (sendMessage + followupTask):

```ts
/** Params for `subagent/sendMessage` and `subagent/followupTask` (SS3.16): a child target plus the input body. */
export interface SubagentInputParams {
  /** The note/task text: trimmed with Unicode-whitespace semantics, rejected when empty after trimming, delivered trimmed with multibyte content byte-for-byte intact (SS3.16). */
  body: string;
  /** Client-minted UUIDv7 command id (SS3.1.1). */
  commandId: string;
  /** Target session (UUIDv7 string; SS3 preamble). */
  sessionId: string;
  /** Durable child id (the SS4.5.7 item's `subagentId`; opaque string). */
  subagentId: string;
}
```

`msp.d.ts:1290-1300` — owner+reason params (interrupt + stop + close):

```ts
/** Params for `subagent/interrupt`, `subagent/stop`, and `subagent/close` (SS3.16): a child target plus an optional human-readable reason that is preserved on the durable effect record. */
export interface SubagentOwnerReasonParams {
  /** Client-minted UUIDv7 command id (SS3.1.1). */
  commandId: string;
  /** Optional reason, preserved on the durable owner-command record. */
  reason?: string;
  /** Target session (UUIDv7 string; SS3 preamble). */
  sessionId: string;
  /** Durable child id (the SS4.5.7 item's `subagentId`; opaque string). */
  subagentId: string;
}
```

`msp.d.ts:1302-1316` — result envelope:

```ts
/** A subagent's result envelope (tdd SS4.5.7, `SubagentResultEnvelope`). */
export interface SubagentResult {
  /** Artifact references, verbatim. */
  artifactRefs: string[];
  /** Error kind, verbatim durable vocabulary, when the child failed. */
  errorKind?: string;
  /** Evidence references, verbatim. */
  evidenceRefs: string[];
  /** Structured result data, verbatim, when present. */
  structuredData?: Record<string, unknown>;
  /** Bounded result summary (<=512 chars, runtime-enforced). */
  summary: string;
  /** Result text (<=32 KiB), when present. */
  text?: string;
}
```

`msp.d.ts:1318-1326` — bare-target params (resume + reopen + readResult):

```ts
/** Params for `subagent/resume`, `subagent/reopen`, and `subagent/readResult` (SS3.16): the bare child target. */
export interface SubagentTargetParams {
  /** Client-minted UUIDv7 command id (SS3.1.1). */
  commandId: string;
  /** Target session (UUIDv7 string; SS3 preamble). */
  sessionId: string;
  /** Durable child id (the SS4.5.7 item's `subagentId`; opaque string). */
  subagentId: string;
}
```

Uniform ack (`msp.d.ts:241-253`):

```ts
/** The uniform SS3.1.2 command acknowledgement: admission only, never an outcome. `session/compact` alone may answer `"noop"`; every other command answers `"accepted"`. */
export interface CommandAcceptedResult {
  /** Echo of the client-minted UUIDv7 `commandId` (SS3.1.1). */
  commandId: string;
  /** `"accepted"` for every admitted command (SS3.1.2; closed vocabulary). */
  status: CommandAckStatus;
}
export type CommandAckStatus = "accepted" | "noop";
/** The SS3.1.2 ack `status`: `accepted` for every admitted command. … */
export type CommandStatus = "accepted" | (string & {});
```

### 2.4 The folded `subagent` Item (what the owner commands act on)

`msp.d.ts:454-572` (`export interface Item`), `subagent`-owned members only:

```ts
/** `subagent`: agent definition path. */
agentPath?: string;                                            // msp.d.ts:456-457
/** `subagent`/`reminderChild`: the child's own session id, readable via `session/read`/`view/page` — child transcript drill-down without a second protocol (tdd SS4.5.7). */
childSessionId?: string;                                       // msp.d.ts:470-471
/** `subagent`: camelCased `SubagentControlStatus` (open enum); `status` stays the generic item vocabulary. */
controlStatus?: SubagentControlStatus;                          // msp.d.ts:480-481
/** `subagent`: nesting depth. */
depth?: number;                                                // msp.d.ts:482-483
/** `userShell`/`subagent`: observed wall-clock duration. */
durationMs?: number;                                           // msp.d.ts:486-487
/** `toolCall`/`subagent`: `Failed`/`Rejected`/`Cancelled` reason text, verbatim. */
failureReason?: string;                                        // msp.d.ts:496-497
/** `subagent`: objective as spawned. */
objective?: string;                                            // msp.d.ts:510-511
/** `subagent`: the result envelope from `ResultReady` (tdd SS4.5.7). */
result?: SubagentResult;                                       // msp.d.ts:524-525
/** `subagent`: role as spawned. */
role?: string;                                                 // msp.d.ts:532-533
/** `subagent`: durable child identity (`subagent_id`). */
subagentId?: string;                                           // msp.d.ts:542-543
/** `subagent`: **transitive** observed usage — the child and its own descendants; updated in place, absent until first observation; never folded into `session/tokenUsage.cumulative` (tdd SS4.6.5). */
usage?: TokenUsage;                                            // msp.d.ts:566-567
/** `subagent`/`workflow`: the owning durable workflow run id (opaque string — not a UUID family). */
workflowRunId?: string;                                        // msp.d.ts:570-571
```

Kind + identity rule:

```ts
// msp.d.ts:600-601
export type ItemKind = "userMessage" | "agentMessage" | "reasoning" | "toolCall" | "userShell" | "subagent" | "workflow" | "reminderChild" | "compaction" | (string & {});
// msp.d.ts:502-503 — identity: "the task id for task-backed kinds (`toolCall`, `subagent`)"
```

Lifecycle (from `subagent-nested-lifecycle` transcript, `schema/msp/transcripts/subagent-nested-lifecycle/transcript.ndjson:6-16`): one stable `itemId` per child, `item/started` (controlStatus `accepted`) → `item/updated` (`starting` → `running` + `childSessionId`) → `item/updated` (`resultReady` + `result`) → `item/completed` (`closed`; `status completed` normally, `failed` when `result.errorKind` set). Two children (`subagent-a`, `subagent-b`) interleave on the same parent turn — the wire-level proof that parallel subagents are MODEL-fanned children of one turn, not SDK-spawned sessions. `depth` marks nesting; `childSessionId` enables drill-down via `session/read`/`view/page` with no second protocol.

### 2.5 The sibling `workflow` item + `WorkflowChild` (for disambiguation)

`msp.d.ts:1865-1885`:

```ts
/** One workflow child's folded state (tdd SS4.5.8, `WorkflowChildLifecycleFact`), keyed by `(childId, attempt)`. */
export interface WorkflowChild {
  /** The attempt number. */
  attempt: number;
  /** The child's id within the run. */
  childId: string;
  /** The child's observed duration, when recorded. */
  durationMs?: number;
  /** The child's display label, when recorded. */
  label?: string;
  /** The child's phase, when recorded. */
  phase?: string;
  /** The child's recorded result reference, verbatim, when present — an opaque string, matching the durable owner. */
  resultRef?: string;
  /** camelCased `WorkflowChildLifecycleStatus`, verbatim (durable runtime vocabulary). */
  status: string;
  /** The child's terminal, turn vocabulary (tdd SS4.5.8). */
  terminal?: TurnTerminal;
  /** The child's observed usage, when recorded. */
  usage?: TokenUsage;
}
```

Carried as `Item.children?: WorkflowChild[]` (`msp.d.ts:474-475`), re-emitted whole on every change with `Item.revision` as ordering guard. Workflows = deterministic fan-out scripts (CHANGELOG 1.0.1: "the agent can write and run a deterministic script that fans a large job out across focused agents working in parallel"); subagents = model-delegated children. Different kinds, different control planes (workflow has NO `workflow/*` command methods in `MspMethod`).

---

## 3. Connection → client → session → turn, and the N-parallel-subagent coordinator

### 3.1 `spawnMspConnection` (`clients/sdk-ts/src/connection/spawn.ts`)

Signature (`spawn.ts:642-644`):

```ts
/** Spawn one owned host and begin its SS1.4 handshake state machine. */
export function spawnMspConnection(options: SpawnMspConnectionOptions): MspHandshake {
  return new MspHandshake(options);
}
```

Options (`spawn.ts:30-40`):

```ts
export interface SpawnMspConnectionOptions {
  readonly command: string;
  readonly args?: readonly string[];
  readonly cwd?: string;
  readonly env?: NodeJS.ProcessEnv;
  readonly connection?: ConnectionOptions;
  /** Raw stderr chunks, drained from process birth and never parsed. */
  readonly onStderr?: (chunk: string) => void;
  /** See {@link MuseServeChildOptions.shutdownTimeoutMs}. */
  readonly shutdownTimeoutMs?: number;
}
```

State machine: `spawnMspConnection()` → `MspHandshake` (NO send method pre-handshake) → `handshake.initialize({clientInfo, capabilities?})` (exactly once, `spawn.ts:588-609`: sends `initialize`, checks `result.schema.fingerprint`, `notify("initialized")`, `flush()`) → `SpawnedMspConnection{connection, child, initializeResult, fingerprintWarning, exited}`. Ownership: POSIX spawns the host as a process-group leader (FR-017b) so TERM/KILL ends grandchildren holding stdout; `close()` = stdin-EOF drain (default 30 s) → SIGTERM → SIGKILL, resolving on the OBSERVED exit (SS2.1.2/SS2.11 table → `ExitClassification`). Cookbook usage (`clients/sdk-cookbook/src/kit/host.ts:144-152`):

```ts
static async spawn(spec: HostSpawnSpec, budgetMs: number): Promise<Host> {
  const handshake = spawnMspConnection({
    command: spec.command,
    args: [...spec.args],
    ...(spec.cwd === undefined ? {} : { cwd: spec.cwd }),
    env: spec.env,
    onStderr: (chunk) => stderr.push(chunk),
  });
```

### 3.2 `Connection` (`clients/sdk-ts/src/connection/connection.ts`)

Transport-agnostic NDJSON duplex (`connection.ts:36-49` `DuplexTransport{incoming, write, close?}`). Key methods:

```ts
// connection.ts:311-312 — INV-013 single minter; every commandId comes from here
mintCommandId(): string { return this.#mintCommandId(); }
// connection.ts:274 — plain request (initialize, view/page reads)
request(method: string, params?: Record<string, unknown>): Promise<Record<string, unknown>>
// connection.ts:315 — fire-and-forget (initialized)
notify(method: string, params?: Record<string, unknown>): void
// connection.ts:341 — SS3.1.1 idempotent command (EVERY session/turn/subagent/approval verb)
async command(method: string, params: Record<string, unknown>, options?: CommandOptions): Promise<Record<string, unknown>>
// connection.ts:75-82 — CommandOptions{commandId? (replay same logical command), maxAttempts?, retryDelay?}
```

`command()` stamps `commandId` (or reuses the pinned one for replays), enforces value-identical-ack on `commandId` reuse, surfaces server errors as typed `MspError{code, kind: ErrorKind, data, retryable}` (INV-012). This is the ONLY path subagent owner commands can take today — e.g. `connection.command("subagent/sendMessage", {sessionId, subagentId, body} as …)` — because the facade exposes no typed wrapper.

### 3.3 `MuseClient` (`clients/sdk-ts/src/facade/client.ts`)

```ts
// client.ts:219 — owns host + handshake + durability profile + inbound pump
static async spawn(options: MuseClientSpawnOptions): Promise<MuseClient>
// client.ts:127-141
export interface MuseClientSpawnOptions {
  readonly museBin: string;
  readonly args?: readonly string[];
  readonly cwd?: string;
  readonly env?: NodeJS.ProcessEnv;   // REPLACES env (spread process.env to extend)
  readonly clientInfo: InitializeParams["clientInfo"];  // {name, version, title?}
  readonly capabilities?: InitializeParams["capabilities"];
  readonly onStderr?: (chunk: string) => void;
  readonly shutdownTimeoutMs?: number;
}
// client.ts:278 — tdd SS2.5.1
async startSession(options: StartSessionOptions = {}): Promise<Session>
// client.ts:98
export type StartSessionOptions = Readonly<Omit<SessionStartParams, "commandId" | "config">>;
//  = { approvalMode?: ApprovalMode|null; providerId?: string|null; sessionId?: string; workspaceRoot?: string; modelId?: string; }
// client.ts:305 — tdd SS2.5.2 (withheld after ephemeral host death, SS2.13.3b)
async resumeSession(options: ResumeSessionOptions): Promise<Session>
// client.ts:334 — orderly SS2.1.2 shutdown, NOT a death
async close(): Promise<void>
```

Internals that matter to coordinators: ONE inbound pump (`connection.onNotification → #route` by `params.sessionId`, `client.ts:187-208` — the client OWNS the connection's single notification handler); `#sessions: Set<Session>` so one host death reaches all sessions; `#discarded: DiscardedSessions` (client-scoped SS2.13.3b memory); `#closing` flag discriminating own-EOF (orderly) from peer-EOF (death). `startSession` builds the wire params by OMIT-means-OMITTED guards (`client.ts:280-284`) and keys the `Session` by the SERVER-named id, never the requested one (`client.ts:287-293`).

README example (`clients/sdk-ts/README.md`, "Open sessions and submit through the facade"):

```ts
import { MuseClient } from "@muse-code/sdk";
const client = await MuseClient.spawn({
  museBin: "muse",
  args: ["serve"],
  clientInfo: { name: "dm", version: "1.0.0" },
});
const session = await client.startSession({ workspaceRoot });
```

### 3.4 `session/start` wire shape (`schema/msp/msp.d.ts:1130-1154`)

```ts
/** `session/start` params (tdd SS2.5.1). */
export interface SessionStartParams {
  /** The session's starting approval mode; server default when omitted or explicit `null` — both spellings select the default (#23468). Select, never create — the value names a mode the host's configuration already defines (tdd SS2.5.1, SS5.12). This is the only surface that declares a non-interactive run's policy (tdd SS5.11, D-008). */
  approvalMode?: ApprovalMode | null;
  /** The SS2.5 idempotency handle (UUIDv7). Required; the server never mints one. */
  commandId: string;
  /** Reserved for per-session overrides owned by a future Configuration section, which is why [`SessionConfig`] declares no members. */
  config?: SessionConfig;
  /** Initial model; server default when omitted. */
  modelId?: string;
  /** Initial provider routing; server default when omitted or explicit `null` — both spellings select the default (#23468). */
  providerId?: string | null;
  /** Exact identity for this new root session. When omitted the server mints a UUIDv7. This field never selects an existing session: a retained or reserved id is rejected `commandRejected` with reason `session_id_conflict` (tdd SS2.5.1). */
  sessionId?: string;
  /** Absolute path, folded into the first metadata record. */
  workspaceRoot?: string;
}
/** `session/start` result (tdd SS2.5.1). */
export interface SessionStartResult {
  /** The new session. */
  session: Session;
  /** The session view head after the start fold; the connection is subscribed and receives every view event after this cursor. A deduplicated retry returns this same result (tdd SS2.5.1). */
  viewCursor: string;
}
```

`ApprovalMode` is CLOSED (`msp.d.ts:79`: `"allowAll" | "promptUnmatched" | "onRequest" | "denyUnmatched"` — select-never-create, D-006). This is the approval-inheritance root for coordinators: every parallel session's policy is fixed HERE (or server default); `session/setApprovalMode` can only SELECT another preconfigured mode later.

### 3.5 `turn/start` + `Session.sendUserTurn` + `TurnHandle`

Wire (`msp.d.ts:1530-1558`):

```ts
/** `turn/start` params (tdd SS3.2). */
export interface TurnStartParams {
  /** The SS3.1.1 idempotency handle (UUIDv7). The fresh turn's `turnId` derives from it (tdd SS3.1.4). */
  commandId: string;
  /** Presentation form of the prompt for transcripts. Durable; carried on the resulting user-message view item. Never model-visible (tdd SS3.2). */
  displayText?: string;
  /** Disposition when a turn is already running; default `queue`. */
  ifBusy?: IfBusy;
  /** Ordered content parts; required and non-empty. */
  input: TurnInputPart[];
  /** Reasoning tier sampled at submission for this turn. */
  reasoningEffort?: ReasoningEffort;
  /** The target session. */
  sessionId: string;
}
/** `turn/start` result (tdd SS3.2). */
export interface TurnStartResult {
  /** Echoes the client's id. */
  commandId: string;
  /** What happened to the input. */
  disposition: TurnStartDisposition;   // "started" | "queued" | "steered"
  /** `true` iff `disposition` is `started`; retained as the boolean shorthand — `disposition` is authoritative (tdd SS3.2). */
  startedNewTurn: boolean;
  /** Admission status. */
  status: CommandStatus;
  /** The turn that will carry (or absorbed) this input. Authoritative: always take it from the ack rather than deriving it (tdd SS3.2). */
  turnId: string;
}
```

Facade (`clients/sdk-ts/src/facade/session.ts:721-724`, `turn-submit.ts:39-48,120-153`):

```ts
// session.ts:721
async sendUserTurn(options: SendUserTurnOptions<I>): Promise<Turn> {
  const ack = await this.#submit.submit(options, this.#lastFoldedItemId());
  return this.#handle(ack.turnId);
}
// turn-submit.ts:39
export type SendUserTurnOptions<I> = Readonly<Omit<TurnStartParams, "commandId" | "sessionId">> & { readonly composerInput?: I };
// TURN_START_FORWARDED (turn-submit.ts:55) = ["input","displayText","ifBusy","reasoningEffort"] — exhaustive AssertNever pin vs generated params
```

`Turn` consumption (`turn-handle.ts:67-93,252-300`):

```ts
export type TurnOutcome =
  | { readonly kind: "completed"; readonly params: TurnCompletedParams; readonly observedStart: boolean; }
  | { readonly kind: "unqueued"; readonly params: TurnUnqueuedParams }
  | { readonly kind: "terminalUnknown" };
export function isLaunchFailure(outcome: TurnOutcome): boolean  // terminal failed + error.kind launchError (turn-handle.ts:103)
get completed(): Promise<TurnOutcome>        // turn-handle.ts:252 — settles on EVERY no-run exit (INV-014), never local timeout
items(): AsyncIterableIterator<FoldedItem>   // turn-handle.ts:280 — replays fold + live tail; ends at settlement
deltas(): AsyncIterableIterator<ItemDeltaParams> // turn-handle.ts:300 — live-only, never replayed
```

`Session.turn(turnId)` (`session.ts:580`) returns the routed handle for any turn (pre- or post-events); `sendUserTurn` returns THE handle `apply` routes to (not a copy).

### 3.6 Coordinator pattern: N parallel subagents TODAY (two sanctioned shapes)

**Shape A — N independent sessions (true parallelism, full SDK support).** Each "subagent" is a root session on one shared host (or one host per session for full isolation). This is what `MuseClient`'s `#sessions` set + per-`sessionId` routing + per-session `Session`/`TurnHandle` are built for:

```ts
import { MuseClient } from "@muse-code/sdk";

const client = await MuseClient.spawn({ museBin: "muse", args: ["serve"], clientInfo: { name: "coordinator", version: "1.0.0" } });

// Fan out N sessions (same approval policy inherited from session/start; override per session as needed)
const objectives = ["survey the failing tests", "read the two candidate crates", /* …N */];
const sessions = await Promise.all(
  objectives.map((objective, i) =>
    client.startSession({ workspaceRoot: "/home/me/src/proj", approvalMode: "promptUnmatched", modelId: "muse-large-2" })
  ),
);

// One turn per session, all in flight concurrently
const turns = await Promise.all(
  sessions.map((s, i) => s.sendUserTurn({ input: [{ type: "text", text: objectives[i] }] }))
);

// Stream each turn independently; each turn.completed settles via its own turn/completed|unqueued|terminalUnknown
const results = await Promise.all(
  turns.map(async (turn) => {
    for await (const item of turn.items()) render(item);  // subagent/workflow items appear here as kind:"subagent"|"workflow" if the MODEL fans out further
    return turn.completed;
  }),
);
await client.close();
```

Why this works: `session/start` mints independent sessions (server UUIDv7 unless `sessionId` pinned); `turn/start` per session runs concurrently (no cross-session `ifBusy` coupling — `ifBusy` is per-session); `MuseClient.#route` demuxes by `sessionId`; `turn.completed` never times out locally (INV-006/INV-014). Approval posture: set `approvalMode` per `startSession` (or omit for server default = default-deny when no `onApproval` handler is registered — README: "Registering no handler at all is the supported posture, not a degraded one (D-008)"); per-session `session.onApproval(handler)` answers that session's `approval/requested` with server-minted `choiceId`s only. Isolation: same-host sessions share the host process but have disjoint logs/leases; separate `MuseClient.spawn` per task gives process-level isolation at the cost of N hosts.

**Shape B — MODEL-spawned children inside ONE turn (observed, not minted).** Prompt the model to delegate; children appear as `Item{kind:"subagent"}` on the parent's `turn.items()` (see nested-lifecycle transcript: two children, one turn). The coordinator READS them from the fold (`session.fold.items` / `turn.items()`, filtering `item.kind === "subagent"`, keying by `item.subagentId`), drills into a child transcript via `connection.command("session/read", {sessionId: item.childSessionId})` or `connection.command("view/page", {sessionId: childSessionId, limit})`, and steers via raw owner commands:

```ts
// After obtaining subagentId from a folded kind:"subagent" item:
await (session as any).connection /* or your own Connection handle */;
await connection.command("subagent/sendMessage", { sessionId: parentId, subagentId, body: "focus on the multibyte case" });
await connection.command("subagent/followupTask", { sessionId: parentId, subagentId, body: "also check crate B" });
await connection.command("subagent/interrupt", { sessionId: parentId, subagentId, reason: "reprioritizing" });
await connection.command("subagent/stop", { sessionId: parentId, subagentId, reason: "stale objective" });
await connection.command("subagent/close", { sessionId: parentId, subagentId, reason: "done" });
await connection.command("subagent/resume" /* | "reopen" | "readResult" */, { sessionId: parentId, subagentId });
```

Caveat (must state): `Connection` inside `Session`/`MuseClient` is PRIVATE (`#connection`); the facade offers no accessor. Shape B therefore requires either (i) composing a bare `Connection` + `Session` yourself (`new Session({sessionId, durability, connection})` — the supported fold-only/wired-composition seam, `session.ts:94-118`), keeping the `Connection` handle for raw `subagent/*` calls, or (ii) a small upstream addition (`Session.subagentSend(...)` etc. — currently absent by INV-001 minimalism, would need a #206-enrolled facade slice). All 8 ack `CommandAcceptedResult`; outcomes arrive as parent-stream `item/updated|completed` (folded `controlStatus`/`result`) — never poll; fold `turn.items()` to terminal. `subagent/readResult` is state-changing (consumes); the content is already on the item's `result` field.

What NOT to do: `session/fork` is NOT a subagent spawn — it copies history into a new sibling session (`SessionForkParams{commandId, sessionId, cutPoint?: ForkCutPoint, excludeItems?}` → `SessionForkResult{session (with forkedFrom), history, pendingRequests, viewCursor}`, `msp.d.ts:960-982`; `ForkCutPoint{lastCompletedTurnId}`, `ForkProvenance{commandId, explicitCutPoint, sourceSessionId}`, `msp.d.ts:380-394`). It has NO facade wrapper either (no `client.forkSession`), so the same raw-`command()` path applies. Forks inherit model/permission/history (CHANGELOG:212) — useful for "branch this agent's context", not for "spawn a worker".

---

## 4. README / CHANGELOG notes: multi-agent, worktree isolation, approval inheritance

### 4.1 SDK READMEs: multi-agent is ABSENT (evidence of the gap)

- `clients/sdk-ts/README.md` (285 lines): documents `MuseClient.spawn`, `startSession`/`resumeSession`, `sendUserTurn`, `turn.items()/completed`, `onApproval`, gap-fill, host-death discharge. ZERO mentions of `subagent`, `fork` (session), `WorkflowChild`, `worktree`, `parallel agents`, `subagent/*`. The "What is not here yet" table lists only snapshot ingestion, corpus replay, D-030 re-anchor — no subagent facade row.
- `clients/msp-ts/README.md`: only the INV-001/INV-008 discipline + coverage list (SS1 envelope + session-view planes). No subagent section; the single "fork" is copy-drift prose (§0.3).
- Root `README.md` (102 lines): install + layout + mirror notice. No multi-agent content.
- `clients/sdk-quickstart/README.md` + `clients/sdk-cookbook/README.md`: single-session journeys/recipes only; no subagent recipe (recipe list in §0.6 confirms: 10 recipes covering turns/approvals/cancel/steer/retry/exits/fingerprint/host-death — none for subagents).

### 4.2 CHANGELOG.md — product-side multi-agent notes (the SDK has no changelog section of its own)

All line numbers below are in `/tmp/opencode/muse-teardown/muse-code-sdk/CHANGELOG.md`. Grouped by the report's requested themes. Note: this changelog is the PRODUCT (muse CLI) changelog; the SDK publish is one bullet among product features (line ~14: "The TypeScript SDK is published: `npm install @muse-code/sdk`").

**A. Parallel / multi-agent capability (product runtime, wire-visible as subagent/workflow items):**

```
CHANGELOG.md:22: - Workflows, on Linux: the agent can write and run a deterministic script that fans a large job out across focused agents working in parallel, then folds their results into one answer. `/workflows` browses runs, `/tasks` shows each run's progress and its agents, and a setting controls whether a workflow may start on its own, only when you ask, or never
CHANGELOG.md:283: - Sessions at Ultra reasoning effort default to maximum parallel-agent capacity unless you set a limit
CHANGELOG.md:284: - Session export stitches in subagent transcripts that finish independently
CHANGELOG.md:129: - The terminal no longer jitters while several tools run in parallel
```

**B. Subagent lifecycle / steering (SS3.16 + SS4.5.7 surface):**

```
CHANGELOG.md:41: - Subagents that share a role are numbered, so duplicates are easy to tell apart
CHANGELOG.md:43: - Raised the context budget for subagent delegation rules so larger guidance files are not truncated
CHANGELOG.md:49: - Clearer message when a stop or steering command sent to a subagent is rejected
CHANGELOG.md:54: - Subagent rows in `/tasks` show a stable number and description instead of a raw identifier
CHANGELOG.md:56: - A finished subagent's timer freezes at its own runtime instead of ticking on
CHANGELOG.md:83: - A duplicate in-flight subagent steering command is reported as retryable rather than fatal
CHANGELOG.md:84: - A queued follow-up task for a subagent carries its caller, so later attempts are accepted against the right parent
CHANGELOG.md:151: - A finished subagent no longer stops delivering queued messages and appears stuck
CHANGELOG.md:152: - Follow-up messages to a subagent are no longer rejected after a resume, or dropped when sent just before it finishes
CHANGELOG.md:154: - A subagent's final result no longer renders twice, and is no longer duplicated or dropped during a retry
CHANGELOG.md:155: - Subagent results are no longer lost after a crash, and recovered results load fully before being selected
CHANGELOG.md:156: - Resuming with more in-flight subagents than available capacity no longer crashes
CHANGELOG.md:157: - Subagent identity is bound correctly when a spawn is replayed after a resume
CHANGELOG.md:158: - `/exit` no longer abandons a subagent that had just been spawned, and exiting is no longer blocked by one that already finished
CHANGELOG.md:159: - Commands that only work in the main conversation are properly rejected inside a subagent's view
CHANGELOG.md:160: - Completed subagents are cleaned up in long sessions instead of accumulating
CHANGELOG.md:161: - Resume no longer replays subagent tasks that had already completed
CHANGELOG.md:162: - Follow-up messages are no longer lost when resuming a session that used subagents
CHANGELOG.md:165: - Task-tray rows no longer linger after you navigate into a rewound subagent conversation
CHANGELOG.md:237: - The interface no longer slows down or pegs the CPU once many subagents or completed background tasks have accumulated
CHANGELOG.md:238: - Faster sessions with many subagents, by removing repeated full scans of the subagent list
CHANGELOG.md:330: - Resume replays subagent activity recorded in the parent session log, with the original identity
CHANGELOG.md:331: - Resumed sessions keep subagent lifecycle events in their original order
CHANGELOG.md:332: - Output from background subagents started before a resume is replayed instead of disappearing
CHANGELOG.md:333: - Subagent results that finished before you pressed Esc are preserved instead of disappearing with the cancelled turn
CHANGELOG.md:334: - Long-running background subagents reliably deliver their final answer
CHANGELOG.md:360: - A failed subagent launch no longer permanently consumes a capacity slot
CHANGELOG.md:361: - Subagents that finish without a result show a proper final state
CHANGELOG.md:362: - Notes typed in a subagent's view reach the running subagent
```

Wire mapping for the above: `subagent/sendMessage|followupTask` (152,162,362), `subagent/interrupt|stop|close` (49,83), `subagent/resume|reopen|readResult` + `childSessionId` drill-down (153,155,157), `SubagentResult`/`controlStatus` rendering (154,156,160,161,330-334,360,361), capacity (156,360), `/tasks` rows = `Item{kind:subagent}` + `usage`/`durationMs` (41,54,56,237,238).

**C. Subagent WORKTREE isolation (all product-side; NO SDK/MSP surface):**

```
CHANGELOG.md:64:  - `--worktree` with an empty value explains the fallback instead of refusing the command
CHANGELOG.md:107: - Session worktrees keep track of a nested working directory when you start from a subdirectory
CHANGELOG.md:231: - A session worktree removal cut short by its time budget completes instead of being recorded as failed
CHANGELOG.md:363: - Subagent worktrees whose ownership can't be proven after a crash are quarantined instead of wrongly cleaned up
CHANGELOG.md:389: - Git operations for isolated subagent worktrees no longer block the agent runtime
```

Explicit finding: `worktree` occurs NOWHERE in `schema/msp/msp.d.ts`, `msp.schema.json`, or `clients/*/src|test` (verified §1.2). Worktree isolation (per-subagent git worktrees, ownership quarantine after crash, non-blocking git ops) is a host-runtime property with no wire representation in this snapshot — a coordinator CANNOT observe or control worktrees through the SDK; isolation must be achieved via `workspaceRoot` per `session/start` (Shape A) or trusted to the host (Shape B).

**D. Approval inheritance (session/start policy + fork carry-over):**

```
CHANGELOG.md:191: - Session permission settings carry over correctly when you fork a conversation
CHANGELOG.md:212: - A forked session inherits the source's model, permission profile, committed message order and tool-call history
```

Wire grounding:

```ts
// msp.d.ts:1131-1133 — the ONLY policy-declaring surface (SS5.11, D-008)
approvalMode?: ApprovalMode | null;   // SessionStartParams; omitted|null = server default
// msp.d.ts:79 — closed select-never-create vocabulary (D-006)
export type ApprovalMode = "allowAll" | "promptUnmatched" | "onRequest" | "denyUnmatched";
// msp.d.ts:1090-1110 — mid-session SELECT only (never create inline rules)
export interface SessionSetApprovalModeParams { commandId: string; mode: ApprovalMode; sessionId: string; }
```

So: a coordinator's N sessions each inherit policy from (1) their own `session/start.approvalMode` or the server default, and (2) for forks, the source's effective permission profile (191,212). There is NO per-subagent approval override on the wire — `SubagentInputParams`/`SubagentOwnerReasonParams`/`SubagentTargetParams` carry no approval field; a model-spawned child runs under the SESSION's effective mode (`EffectiveApprovalModeState{mode, source, lastCommandId}`, `msp.d.ts:287-294`, carried on `Session.approvalMode` + `session/approvalModeChanged`). SDK posture: default-deny with no `onApproval` handler registered is SUPPORTED (sdk-ts README), and `onApproval` answers with server-minted `choiceId` only (`ApprovalRouter` refuses invented ids pre-wire).

**E. Peer-session messaging (NOT in this wire snapshot — do not confuse with subagents):**

```
CHANGELOG.md: (1.0.1 New, ~line 20): - Two sessions on the same machine can message each other. The agent can list your other sessions and send one a message, and you approve the first message from each unverified sender before it lands. Name a session with `/name` so others can address it
```

No `message/*`, `session/message`, or `session/send` method exists in `MspMethod` (full list in §2.1 — 31 methods, none matching). A coordinator needing session-to-session fan-in/fan-out TODAY must do it client-side (Shape A + local join), not via a wire peer-message verb.

---

## 5. Appendix — exact paths, transcripts, and negative-evidence log

### A. File inventory (absolute paths for copy-paste)

```
# Clone + tarball
/tmp/opencode/muse-teardown/muse-code-sdk/                                   (git clone of meta-models/muse-code-sdk, HEAD fbce769)
/tmp/opencode/muse-teardown/muse-code-sdk-0.1.1.tgz                         (npm pack @muse-code/sdk@0.1.1)
research/artifacts/sdk-tarball/muse-code-sdk-0.1.1.tgz  (copy)
research/artifacts/muse-sdk-multiagent-report.md  (this file)

# Wire source of truth
/tmp/opencode/muse-teardown/muse-code-sdk/schema/msp/msp.d.ts               1892 lines
/tmp/opencode/muse-teardown/muse-code-sdk/schema/msp/stable/msp.schema.json 190795 bytes, 185 $defs
/tmp/opencode/muse-teardown/muse-code-sdk/schema/msp/stable/manifest.json   fingerprint sha256:cfd31ee77d78fdada9febc4edccd29b0434ff8f6bf157c7c03fd0ecfcbc29f5a

# SDK facade
/tmp/opencode/muse-teardown/muse-code-sdk/clients/sdk-ts/src/index.ts
/tmp/opencode/muse-teardown/muse-code-sdk/clients/sdk-ts/src/connection/connection.ts
/tmp/opencode/muse-teardown/muse-code-sdk/clients/sdk-ts/src/connection/spawn.ts
/tmp/opencode/muse-teardown/muse-code-sdk/clients/sdk-ts/src/facade/client.ts
/tmp/opencode/muse-teardown/muse-code-sdk/clients/sdk-ts/src/facade/session.ts
/tmp/opencode/muse-teardown/muse-code-sdk/clients/sdk-ts/src/facade/turn-submit.ts
/tmp/opencode/muse-teardown/muse-code-sdk/clients/sdk-ts/src/facade/turn-handle.ts
/tmp/opencode/muse-teardown/muse-code-sdk/clients/sdk-ts/src/facade/approval.ts
/tmp/opencode/muse-teardown/muse-code-sdk/clients/sdk-ts/src/facade/gap-fill.ts
/tmp/opencode/muse-teardown/muse-code-sdk/clients/sdk-ts/src/facade/host-death.ts
```

### B. Subagent/workflow transcripts (all hand-authored fixtures, `provenance:"hand-authored"`)

```
schema/msp/transcripts/subagent-close-round-trip/            SS3.16 close admission + SS4.5.7 terminal mapping (manifest cites D-025 #14409)
schema/msp/transcripts/subagent-sendmessage-round-trip/      SS3.16 sendMessage multibyte body byte-for-byte + admission-only ack
schema/msp/transcripts/subagent-steering-duplicate-replay/   SS3.1.1 value-identical ack on replayed commandId
schema/msp/transcripts/subagent-steering-rejection/          SS3.16 readResult on unready → commandRejected not_ready
schema/msp/transcripts/subagent-nested-lifecycle/            SS4.5.7 full item lifecycle, 2 interleaved children, both Closed terminals (completed + failed via result.errorKind), transitive usage
schema/msp/transcripts/workflow-child-lifecycle/             SS4.5.8 WorkflowChild facts
schema/msp/transcripts/workflow-child-control-skip/
schema/msp/transcripts/workflow-cancel-round-trip/
```

Exemplar wire frames (verbatim, `subagent-sendmessage-round-trip/transcript.ndjson:6-7`):

```json
{"dir":"client","raw":"{\"jsonrpc\":\"2.0\",\"id\":10,\"method\":\"subagent/sendMessage\",\"params\":{\"sessionId\":\"0198f0aa-1111-7000-8000-0000000000aa\",\"commandId\":\"018f6a2f-1111-7000-8000-0000000000aa\",\"subagentId\":\"0198f0ae-0006-7000-8000-00000000001f\",\"body\":\"focus on the multibyte case: 事件日志 ✓\"}}"}
{"dir":"server","raw":"{\"jsonrpc\":\"2.0\",\"id\":10,\"result\":{\"commandId\":\"018f6a2f-1111-7000-8000-0000000000aa\",\"status\":\"accepted\"}}"}
```

Exemplar item open (verbatim truncated, `subagent-nested-lifecycle/transcript.ndjson:6` — `item/started` for `subagent-a`):

```json
{"method":"item/started","params":{"item":{"agentPath":".agents/researcher.md","controlStatus":"accepted","depth":1,"itemId":"018f7294-0000-7000-8000-7fed06700102","kind":"subagent","objective":"survey the failing tests","revision":1,"role":"worker","status":"inProgress","subagentId":"subagent-a","turnId":"018f7294-0000-7000-8000-7fed06700100"},"sessionId":"018f7294-0000-7000-8000-7fed06700000","viewCursor":"v:018f7294-0000-7000-8000-7fed06700000:3"}}
```

### C. Negative-evidence log (commands run, so "no facade" is a measurement, not an assumption)

```
$ grep -rn "subagent" clients/*/src                    → (no output)
$ grep -rn "WorkflowChild" clients/*/src               → (no output)
$ grep -rn -i "worktree" clients/*/src                 → (no output)
$ grep -rn "session/message" clients/*/src             → (no output)
$ grep -rn "fork" clients/*/src                        → 2 hits, both English prose (survive-the-host-dying.ts:5,23)
$ grep -rn "parallel" clients/*/src                    → 1 hit, unrelated (host-death.ts:110 predicate prose)
$ grep -rln "subagent|WorkflowChild|worktree" schema   → msp.d.ts, stable/msp.schema.json, 5× transcripts/subagent-*/{manifest,transcript}
$ npm view @muse-code/msp                              → E404 (no such package; @muse-code/msp is private 0.0.0 workspace-only)
$ npm view @muse-code/sdk versions                      → ['0.1.0','0.1.1']
```

### D. Key cross-references (spec IDs as cited in source)

SS1.2 envelope/optional-omitted · SS1.4 handshake (`initialize/initialized`, `clientInfo`, `sessionDurability`) · SS1.6 error taxonomy · SS2.5.1 `session/start` · SS2.5.2 `resume` · SS2.5.3 `fork` · SS2.13 host-death (3b = exit OR transport EOF) · SS3.1.1 `commandId` idempotency · SS3.1.2 admission-only ack · SS3.2 `turn/start` · SS3.3 steer · SS3.4/3.5/3.6 interrupt/cancel/unqueue · SS3.16 subagent owner commands · SS4.4.1 item identity/revision · SS4.5.7 subagent lifecycle · SS4.5.8 workflow children · SS4.6.5 usage (subagent usage NEVER folded into session cumulative) · SS4.8 gap splice-fill · SS4.13 pending commands · SS5 approval (5.4 decide, 5.11 non-interactive policy, 5.12 modes) · SS7.1 facade (`MuseClient`/`Session`/`TurnHandle`) · INV-001 (never restate protocol types) · INV-006 (never synthesize terminals) · INV-008 (no copied declarations) · INV-013 (single commandId minter) · INV-014 (every turn-wait settles).

---

*End of report. All line numbers refer to the clone at `/tmp/opencode/muse-teardown/muse-code-sdk` as cloned 2026-09-15 (≈ HEAD fbce769). Verbatim snippets preserve source casing/whitespace except where explicitly noted as truncated.*
