# opencode-muse-agents

Muse Code-grade subagent coordination for OpenCode: durable children, ledger mailbox, admission control, bounded results.

Guarantees:

- Durable by default: spawns commit through admission gates with idempotent command ids; verdicts only count when read back from the ledger.
- Fail-closed communication: mailbox, intake, and registry reject bad input with keyed errors instead of guessing.
- Bounded results: worker envelopes enforce summary and text caps plus required refs; over-cap input is rejected, never truncated.

## Install

npm plugin (recommended):

```sh
npm i opencode-muse-agents
```

```json
{
  "plugin": ["opencode-muse-agents"]
}
```

Copy-install (no npm): copy `bundle/{agents,tools,plugins,skills,commands}` into `.opencode/` and merge `bundle/opencode.fragment.json` into `opencode.json` (see `bundle/README.md`; `scripts/merge-fragment.sh` automates the merge).

## Quickstart

```sh
bun install
bun test
bun run build
```

Coordinator loop: `spark_submit` one worker with one objective, steer it with `spark_send` / `spark_steer`, collect it with `spark_result`. The `spark-coordinator` agent runs this loop; workers never redelegate.

## Tools

| Tool | Purpose |
|---|---|
| `spark_send` | Append a note to a session mailbox ledger; unknown policies fail closed. |
| `spark_submit` | Admit a worker spawn; returns commit fields or a keyed rejection. |
| `spark_result` | Validate a bounded result envelope; never truncates. |
| `spark_decide` | Run ordered judge candidates; only durable verdicts count. |
| `spark_fork` | Record a history-branch fork; cut cursor is display-only. |
| `spark_intake` | Run an ordered steering intake; bad input returns status 255. |
| `spark_registry` | Durable JSONL table ops; locked tables refuse with FENCED. |
| `spark_steer` | Steer a worker via owner drivers; lifecycle verbs need an idle target. |
| `spark_worktree` | Place or delete an isolated worktree under `.muse/worktrees`. |
| `spark_errors_errors_lookup` | Resolve a keyed error; unknown keys fail closed. |
| `spark_errors_errors_catalog` | List all catalogued error keys. |
| `spark_intake_intake_kind_index` | Resolve an intake kind to its jumptable index (-1 when unknown). |
| `spark_uuid_uuid_mint` | Mint a UUIDv7 command id; reuse the same id on retry. |
| `spark_uuid_uuid_canonicalize` | Render 32 hex chars as canonical hyphenated Event ID. |
| `spark_uuid_uuid_check` | Check canonical Event ID spelling. |
| `spark_worktree_worktree_bind_verdict` | Bind-verify verdict check; 3/4 need follow-up calls. |

## Tests

```sh
bun install && bun test && bun run build
```

## Versions

Bundle, Muse Code, and schema-fingerprint pins live in `docs/VERSIONS.md`. A new Muse Code release re-runs the harvest; any fingerprint or vocabulary delta opens a bundle patch before a new row is added.

## Provenance

Design is ported from reverse-engineering evidence: method and confidence map in `docs/RE-OVERVIEW.md`, full teardown at <https://github.com/karimkfoure/muse-code-teardown>.

## License

No LICENSE file is shipped, by explicit decision. No `m8` artifact is included either.
