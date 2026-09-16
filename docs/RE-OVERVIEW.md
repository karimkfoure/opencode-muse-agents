# RE-OVERVIEW — how the port was derived and how sure each part is

Target: Muse Code 1.3.0-R3057.1 (`x86_linux` primary; all 7 builds
verified same-logic). No account, no live runs. Evidence: installer +
launcher scripts, embedded MSP schema export, SDK source (contract
only), strings harvests, ~35 decompiled functions via isolated
ghidra-rpc (`ghidra/muse.gpr`, `orchestration` tag).

## Confidence map

- High (code-verified): spawn validate chain + commit (writer, fenced,
  alloc) + 6 commit fields; owner control + workflow strip + 3 drivers;
  keyed error catalog; judge callsite + decision equality; journal match
  predicate; steering intake (dispatcher, arm, executor, take order);
  folds (view, subagent, attempt-result sequence); keyed emit primitive;
  fold position classes; worktree place/bind/open/resolve/cleanup/fenced
  paths + tri-state + verdicts; 32B registry engine; UUID canonical
  encoder; intake jumptable; delivery policies (9) + RPC verbs (12);
  child record order; envelope caps; UUIDv7 ids.
- Medium (vocabulary-verbatim, behavior inferred): mailbox admission
  outcome ordering, fork cost ordering, attach field completeness,
  router arm internals, handler deep phases.
- Structural limits (documented, non-blocking): computed dispatch
  defeats static xref hunting; monomorphized Rust has no symbols;
  tombstoned socket means the mailbox is ledger-only by elimination;
  serve loop and `resultReady` as isolated functions unseen (bounded
  both sides by verified neighbors).

## Deliberately not cloned

The transport loop (OpenCode owns a server), Rust memory internals
(replaced by record shapes), per-instance micro-details that repeat a
proven family shape.

## Staying current

Each Muse Code release re-runs `tools/muse-*` in order; seeds are
STRINGS, never addresses. Fingerprint or vocabulary delta opens a
bundle patch before the `VERSIONS.md` row is added.
