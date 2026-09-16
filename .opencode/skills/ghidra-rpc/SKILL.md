---
name: ghidra-rpc
description: >
  Reverse engineering via per-project Ghidra daemon. Use for this project's
  binaries (Muse Code teardown targets): decompile, disassemble, xrefs,
  strings, rename, type recovery, patch diff. Prefers this over the shared
  ghidra-mcp server.
---

# ghidra-rpc (muse-teardown project)

CLI installed globally via `uv tool install /home/karim/tools/ghidra-rpc`
(`ghidra-rpc 0.2.0`). Run commands directly — no `uv run` prefix needed.
Full agent manual: `/home/karim/tools/ghidra-rpc/SKILL.md`.
Flow guides: `/home/karim/tools/ghidra-rpc/docs/flows/`.

## This project's space

```bash
export GHIDRA_INSTALL_DIR=/opt/ghidra_12.1.3_PUBLIC
export GHIDRA_RPC_PROJECT=<repo>/research/ghidra/muse.gpr
```

- One daemon per project. Ours is `research/ghidra/muse.gpr`
  (socket hash-derived, no ports to manage). Never load these binaries
  into the shared lab Ghidra server.
- Binaries live in `research/artifacts/bin/all-platforms/` (7 platform builds of
  `muse-bin-1.3.0-R3057.1`, checksums in `research/artifacts/bin/`).
- For binaries over 50 MB prefix `_JAVA_OPTIONS="-Xmx8g"`.

## Session

```bash
ghidra-rpc start --project "$GHIDRA_RPC_PROJECT" --headless --detach
ghidra-rpc load research/artifacts/bin/all-platforms/x86_linux-1.3.0-R3057.1.bin --no-analyze
ghidra-rpc metadata muse-bin-1.3.0-R3057.1
ghidra-rpc list-instances   # health check; our daemon listed by project path
ghidra-rpc stop --project "$GHIDRA_RPC_PROJECT"   # saves everything first
```

`load` returns a `short_name` alias for later commands. `--no-analyze`
skips auto-analysis (fast import); `--analysis-timeout SECS` caps it.
Response always includes `"analysis_complete": bool`.

## Core loop

`functions` (paginated, `--limit`) → `decompile <bin> <fn|addr>` →
`xrefs-to`/`xrefs-from` → `strings`/`symbols` → `rename-function`/
`set-comment`. One-shot alternatives: `search-decompiled <regex>`
(bounded by `--max-scan`), `version-track` + `function-diff` for the
7 platform builds, `pcode [--high]`, `basic-blocks`.

## Rules

- All output is JSON (`{"ok": true|false, ...}`); parse stdout directly.
- Writes auto-save to the project DB with a `verified` read-back flag.
  They are visible in the Ghidra GUI on reopen.
- `create-label` (not `rename-symbol`) for addresses without symbols.
- Prior findings: `research/TEARDOWN.md`, `research/re-tracks/07-ghidra-deep.md`
  (descriptor builder `FUN_0a81b980`, fork state machine `FUN_0556e5d0`).
