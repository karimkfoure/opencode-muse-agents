# Ghidra projects (pointers only)
Use per-project daemon via `.opencode/skills/ghidra-rpc/SKILL.md`.
Projects: `research/ghidra/muse.gpr`, `research/ghidra/muse_analysis.gpr`.
`.rep/` state is git-ignored and regenerable (re-import + analyze).
Binaries: `research/artifacts/bin/all-platforms/` (manifest only in git).
Start: `ghidra-rpc start --project <repo>/research/ghidra/muse.gpr --headless --detach`.
Stop saves everything: `ghidra-rpc stop --project <same>`.
Never load these binaries into the shared lab Ghidra server.
See skill for decompile/xrefs/strings/rename loop.
Regen: re-import binary with `--no-analyze`, then analyze.
