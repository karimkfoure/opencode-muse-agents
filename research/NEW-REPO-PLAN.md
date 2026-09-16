# New Repo Plan — Spark Orchestration for OpenCode (publishable, m8-free)

Status: PLAN ONLY. No final code. Target: a shareable OpenCode "algo"
(bundle) that runs Muse Spark agents + subagents with Muse Code-grade
coordination / orchestration / communication, plus the RE toolkit that
keeps the port current with Muse Code releases.

## 1. Repo identity (DECIDED)

- Name: `opencode-muse-agents`.
- No license file.
- Rule: ZERO m8 content. m8 later consumes this as a dependency and
  builds its own flows on top. No lab runner, no teensy, no `.lab`.
- Location: `opencode-muse-agents/` inside the teardown repo for now;
  split to its own public repo at publish time.
- Hosting: public GitHub + optional ocx registry entry + npm plugin
  package for one-line install.

## 2. Proposed layout

```
<repo>/
  README.md                # what it is, 5-min install, demo, compat matrix
  OVERVIEW.md              # how it works (coordinator/workers/mailbox/policy)
  RE-OVERVIEW.md           # what was reverse engineered, method, confidence map
  VERSIONS.md              # muse version <-> bundle version <-> schema fingerprint
  CHANGELOG.md
  bundle/                  # the shippable OpenCode unit (ocx-compatible)
    agents/                # spark-coordinator.md (primary, read-only)
                           # spark-worker.md (subagent, hidden, no redelegate)
                           # spark-reviewer.md (subagent, read-only+git)
    tools/                 # spark_send.ts (mailbox, 9-policy enum, trim rules)
                           # spark_result.ts (bounded envelope 512/32KiB + refs,
                           #   fold position classes stream/first/last/other)
                           # spark_submit.ts (admission gate: capacity + keyed errors,
                           #   commit sizing adaptive, attach attestation fields)
                           # spark_errors.ts (central keyed error catalog)
                           # spark_intake.ts (4-pair intake records + take order
                           #   verb→subagent_id→body→reason, fail pair {0xff,err})
                           # spark_uuid.ts (canonical 36B Event IDs, nibble table)
                           # spark_registry.ts (the one table-driven registry engine:
                           #   32B rows, -1 sentinel, swap/commit, {-2} follow-up)
                           # spark_fork.ts (variant branches + provenance)
                           # spark_worktree.ts (tri-state -1/0/>0 isolation +
                           #   path-semantics flag v3/legacy + bind-verify verdicts)
    plugins/               # spark-notify.ts (completion -> coordinator ping)
                           # spark-policy.ts (permission matrices, fail-closed,
                           #   judge lane + human lane, verdict protocol {0,1,3,4,0xff})
                           # spark-compact.ts (goal + pending IDs survive compact)
                           # spark-precall.ts (PreLLMCall emulation: effort-gated
                           #   proactive-delegation policy text + first-turn-cheap
                           #   + model fallback chains per role)
    skills/                # plan-protocol, code-review (lazy-loaded)
    commands/              # /spark-plan, /spark-start, /spark-review
    opencode.fragment.json # agent/tool/permission blocks to merge
  schema/                  # pinned MSP exports per muse version
    stable-1.3.0-R3057.1/  # msp.schema.json + manifest + fingerprint
    experimental-.../
  re/                      # RE evidence (curated, not raw dumps)
    tracks/                # our 01-16, cleaned of machine paths
    vocabularies/          # delivery policies, RPC verbs, error catalogs
    functions/             # annotated decompilations that matter
  tools/                   # RE continuity toolkit (the version treadmill)
    muse-fetch/            # channel manifest -> all 7 artifacts + checksums
    muse-schema/           # schema export stable+experimental + fingerprint
    muse-harvest/          # strings sweep -> vocab diff vs previous version
    muse-ghidra/           # ghidra-rpc project bootstrap + seed addresses
    muse-diff/             # version-track/function-diff old vs new build
    muse-report/           # fingerprint+vocab+function diff -> port-changelog
  tests/                   # check-mode assertions per port rule (no live host)
  examples/                # minimal coordinator run + expected envelopes
```

## 3. Integration story (simple)

1. Install: `ocx add <bundle>` OR copy `bundle/` into `.opencode/` OR
   `npm i <plugin-pkg>` + fragment merge. One command, no manual edits.
2. Configure: model per role in `opencode.json` (reasoning coordinator,
   cheap workers); `subagent_depth: 2`; server mode for attach/tmux.
3. Run: `/spark-plan <goal>` → review plan → `/spark-start` → workers fan
   out → reviewer gates → single-owner integrate.
Nothing to learn beyond 3 commands; every default is the safe one
(queue, shared-nothing worktrees, human approval).

## 4. OVERVIEW.md contents (actual, in `opencode-muse-agents/docs/`)

1. One sentence: durable log records first, processes second.
2. Nine mechanisms: spawn-as-commit, lineage identity, ledger admission,
   capacity gates, 3-driver ownership, fingerprints/idempotency,
   policy-vs-mechanism, memo fold, crashes-as-input.
3. Model-facing tuning: effort-gated proactive delegation, first-turn
   cheap, routing with downshift fallback, boundary hooks (PreLLMCall
   gap noted), presets as loop shapers, delegation posture.
4. OpenCode gap list (9 items).
5. Port shape per mechanism + what is NOT ported (transport loop,
   Rust internals).

## 5. RE-OVERVIEW.md outline (what we learned + how sure)

- Method: install chain → schema export → strings harvest → SDK source
  (contract only) → ghidra-rpc targeted slices (mechanism).
- Confidence map per subsystem (high/medium/low + what would raise it).
- Structural limits found: computed dispatch (no xref hunting),
  monomorphized Rust (no symbols), brokerless mailbox (no send handler).
- Full function catalog with addresses + port rule each (tracks 07–16).
- What was deliberately NOT cloned (transport loop — OpenCode owns it).

## 6. RE continuity toolkit (staying current)

On each Muse Code release, run in order; each step emits a diff artifact:
1. `muse-fetch`: poll channel manifest → download 7 artifacts → verify
   sha256 → record. Detects new version.
2. `muse-schema`: export stable+experimental → compare fingerprints. If
   unchanged AND `muse-harvest` clean → port stays green, done in minutes.
3. `muse-harvest`: strings sweep with the fixed keyword set → diff vs
   previous vocabularies → new/removed records, enums, errors.
4. `muse-ghidra`: fresh ghidra-rpc project for the version, load
   x86_linux `--no-analyze`, re-apply seed addresses (fileoff→vaddr math
   re-derives them; addresses WILL move — seeds are string-anchored, not
   hardcoded).
5. `muse-diff`: `version-track` + `function-diff` on the ~20 annotated
   functions (matched by BSim/correlators, not address).
6. `muse-report`: fingerprint + vocab + function diffs → port-changelog
   entry → bundle patch (new policy value? new error key? new record
   field?) → VERSIONS.md row + tests update.
Design rule: seeds are STRINGS, never addresses. The toolkit survives
ASLR of the binary layout across releases.

## 7. Build plan (what, using what, in order)

- Phase 0 — Scaffold + docs skeleton (README/OVERVIEW/RE-OVERVIEW/
  VERSIONS from tracks + TEARDOWN). Uses: TEARDOWN.md,
  tracks 01–06. DONE (docs exist; bundle empty).
- Phase 1 — Mailbox + result slice (`spark_send`, `spark_result`,
  notify plugin, envelope tests). Uses: tracks 03, 09, 10, 11, 19, 20.
- Phase 2 — Spawn + control slice (validate chain, owner control +
  drivers, error catalog, worktree tri-state + bind-verify, commit
  sizing, registry engine). Uses: tracks 02, 08, 12, 13, 16, 17, 18.
- Phase 3 — Coordinator slice (3 agents, permission matrices, background
  fan-out, compact plugin, 3 commands). Uses: SPARK-ORCHESTRATION-DESIGN,
  tracks 04–06.
- Phase 4 — RE toolkit (fetch→report) + VERSIONS pinning for 1.3.0.
  Uses: artifacts layout, track 14, xplat findings.
- Phase 5 — Tests + examples + publish (ocx + npm + GUI notes).
  Acceptance: every port rule in tracks 01–20 (as assimilated into
  OVERVIEW.md) has a check-mode test; green suite = shippable.
- Explicitly later: live-host validation (needs credentials), serve-loop
  parity (OpenCode-owned), auto-analysis-scale RE (only on schema
  contradiction).

## 8. Naming the "algo"

Ship as an ocx bundle + npm plugin, both named `opencode-muse-agents`,
from one repo. Same source, two install paths. Versioned with the compat
matrix: bundle x.y <-> muse A.B <-> schema fingerprint `sha256:…`.
