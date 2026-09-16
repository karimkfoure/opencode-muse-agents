# bundle/ — the shippable unit

Install one of three ways:

1. **npm plugin** (recommended):

   ```sh
   npm i opencode-muse-agents
   ```

   ```json
   { "plugin": ["opencode-muse-agents"] }
   ```

   Add the snippet to `opencode.json`. Loads `dist/index.js`
   (`SparkNotify`, `SparkPolicy`, `SparkCompact`, `SparkPrecall`
   composed).
2. **Copy**: copy `bundle/{agents,tools,plugins,skills,commands}` into
   `.opencode/` and merge `bundle/opencode.fragment.json` into
   `opencode.json` (agents, permissions, `subagent_depth: 2`).
3. **Fragment merge** (automates path 2's merge step): run
   `scripts/merge-fragment.sh [TARGET]` from the repo root
   (default `TARGET` is `./opencode.json`). It deep-merges the
   fragment's `agent` entries (fragment wins per-agent), sets
   `subagent_depth` to `max(existing, 2)`, and merges
   `permission.skill.* = "allow"`, leaving everything else untouched.
   Backs up to `<target>.bak-<unixms>` first; re-runs are no-ops.

Contents:

- `agents/`: `spark-coordinator` (primary, delegates only),
  `spark-worker` (hidden subagent, no redelegation),
  `spark-reviewer` (read-only + git).
- `tools/`: `spark_send`, `spark_result`, `spark_submit`,
  `spark_decide`, `spark_fork`, `spark_intake`, `spark_registry`,
  `spark_steer`, `spark_worktree` (default exports; tool name = file
  name) plus named exports `spark_errors_errors_lookup`,
  `spark_errors_errors_catalog`, `spark_intake_intake_kind_index`,
  `spark_uuid_uuid_mint`, `spark_uuid_uuid_canonicalize`,
  `spark_uuid_uuid_check`, `spark_worktree_worktree_bind_verdict`
  (tool name = file_export).
- `plugins/`: notify (idle delivery), policy (fail-closed gates),
  compact (control state survives), precall (effort-gated delegation).
- `skills/`: `spark-plan-protocol`, `spark-code-review` (lazy-loaded).
- `commands/`: `spark-plan`, `spark-start`, `spark-review`.
- `opencode.fragment.json`: agent defs, task gating, depth 2.
