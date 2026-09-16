# Analysis retry status — 2026-09-16 ~16:20Z

## Attempted
Restarted stopped daemon on muse_analysis.gpr, ran `load` + 1800s
analysis budget in background (log: re-tracks/analysis-retry.log),
polled DB bytes + process CPU every ~5 min.

## Measurements (UTC)
- 15:44:47 baseline: DB 3349103684 B, daemon ~9% CPU
- 15:44:55 load launched (re-opened stored program, no duplicate import)
- 15:49:59 DB 6698206276 B (+3.35 GB in 5 min), CPU 104%
- 15:56→16:11 DB flat 6698206276 B, CPU 143→92% (in-memory work)
- 16:14:55 1800s budget expired: "timed out, partial results saved"
- 16:16:20 result: analysis_complete=false; DB 6737593412 B (+39 MB save)
- 16:18:28 DB stable 6737593412 B, CPU ~79% (post-timeout wind-down)

## Verdict: PROGRESSING (not stalled, not dead)
Opposite of prior stall signature (81 min at 0 CPU, flat DB): this run
held 90–140% CPU throughout and grew the DB 3.35→6.74 GB. Analysis is
incremental — each run banks more completed analyzers into the stored
program /x86_linux-1.3.0-R3057.1.bin-39ae89.

## Recommended next step
Do NOT fresh-import (load correctly re-opens the stored copy). Repeat
bounded `load --analysis-timeout` windows (30–60 min) on the analysis
daemon only; track DB-bytes growth per window. Declare done when a
window returns analysis_complete=true. Never touch muse.gpr daemon.
Main-project work should stay on the targeted --no-analyze loop.
