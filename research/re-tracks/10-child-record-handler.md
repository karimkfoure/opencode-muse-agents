# 10 — Child Record Schema + Handler Architecture

Source: `subagent_managed_handler` @0x6d81730 (145 KB decomp, 3 returns —
one giant state machine), `phase_step_emit` @0x6a90090 (44 call sites),
field vocabularies read verbatim from .rodata. Annotated + saved in
`ghidra/muse.gpr` (`orchestration` tag).

## Child record (verbatim field order, packed @0x6d4819 / @0x6cc7a1)

`subagentId agentPath depth [objective] childSessionId controlStatus
workflowRunId result …`

- `agentPath`: which agent definition spawned this child (maps to
  opencode `agent:` name + `permission.task` routing).
- `depth`: nesting depth, runtime-tracked. The binary enforces it;
  opencode's `subagent_depth` config is the same knob — set 2 for
  coordinator→worker→helper, 1 for flat fan-out only.
- `objective`: present in the fuller variant — the assigned unit of work.
  REQUIRED at spawn (mirrors m8's one-question-per-agent rule).
- `childSessionId`: the child's own session (own log, own lease).
- `controlStatus`: open enum incl. `resultReady closing closed
  recoveryPending manualReconciliation` (packed @0x6cc554).
- `workflowRunId`: parent run linkage.

PORT (`spark_result` / worker record): this exact field set, this order.
`objective` mandatory; `depth` enforced numerically.

## Handler facts

- Model-spawned ("managed") handler carries NO managed identity and runs
  stream-first (@0x6d5c89 note). Trust comes from the control record +
  approval gate, never from handler identity. PORT: never trust a worker
  by session/agent name; check its control record + policy.
- 145 KB single-flow machine, 3 exits: spawn→run→steer→result phases
  share one function with computed dispatch — i.e. no per-phase
  functions to clone. Clone the PHASE CONTRACT (record shapes +
  transition guards), not the code.
- All 44 phase steps go through `phase_step_emit`: alloc(n) → memcpy →
  commit; alloc-fail → trap. PORT: phase transitions APPEND durable
  records (lab `result.json` appends / mailbox ledger); never mutate a
  record in place. This is the same discipline as the journal (track 08)
  and the fork provenance log.

## What this closes

Steering/result path end-to-end at record level: validate (08 §2) →
control resolve + workflow-strip (08 §4) → child record above →
phase-append commits → `resultReady` → parent fold reads
`SubagentResult` (07) → wire `item/completed` (schema). The remaining
turn-machine work is transport (OpenCode-owned) and stays deferred.
