# Research (Muse Code teardown)

Source evidence for this package's design. Read-only; never imported by code.

- `TEARDOWN.md` — binary teardown entry point.
- `SPARK-ORCHESTRATION-DESIGN.md` — orchestration design notes.
- `NEW-REPO-PLAN.md` — extraction plan that created this repo.
- `re-tracks/` — 21 evidence tracks (`01-21`), plus `decomp/`, `xplat/`, logs.
- `artifacts/` — install/launcher scripts, manifests, `schema/`, `sdk-tarball/`,
  `muse-sdk-multiagent-report.md`. Big binaries (`.bin`/`.exe`/`.pkg`) excluded.
- `ghidra/` — `.gpr` project pointers only; `.rep/` state ignored, see `ghidra/README.md`.

## Regen ignored artifacts

Big binaries and Ghidra `.rep/` are git-ignored and regenerable:

- `research/artifacts/bin/all-platforms/*` via `tools/muse-fetch` + `tools/muse-schema`.
- `research/ghidra/*.rep/` via re-import + analyze in the per-project daemon.

## Daemon setup

See `.opencode/skills/ghidra-rpc/SKILL.md` (project `research/ghidra/muse.gpr`).

## Shipping and tests

`research/` never ships in npm (`files: dist, bundle`) and never affects tests.
