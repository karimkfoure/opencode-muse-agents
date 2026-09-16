/* dispatcher_candidate.c — group0 anomalous header site (re-tracks/21 §3)
 *
 * STATUS: NO DECOMPILATION OBTAINED (blocked, not a negative finding).
 * Every ghidra-rpc call against muse_analysis.gpr timed out server-side:
 * the project daemon (pid 2405751, sock /tmp/ghidra-rpc-9c5210ff.sock)
 * is serialising a sustained back-to-back decompile sweep issued by
 * another worker (continuous `decompile' children observed 16:19–16:50
 * local; e.g. pids 2859081, 2863384, 2865361, 2865639, 2868748, 2869192,
 * 2869292). Each attempt (list-binaries, status, read-bytes x4) was kept
 * under the 120 s cap and abandoned past ~100 s per the work order.
 * Restarting/killing the daemon to preempt the other sweep was rejected
 * (shared resource). No writes (create-function/rename/tag/save) were
 * issued — nothing was verified, so nothing was mutated.
 *
 * STATIC FACTS (from re-tracks/21-wire-descriptors.md + goalB evidence):
 * - Group0 anomalous header record embeds code ptr 0x0a726b10 (claimed
 *   .text) and data word 0x0038ba4d.
 * - Prior xrefs-to on 0x121b02a8/0x121b0260: EMPTY. Per goalB note this
 *   is expected under EITHER computed base+index dispatch (linear scan
 *   of name slices) OR incomplete analysis (analysis_complete=false, so
 *   the reference graph is unavailable). The two causes are currently
 *   indistinguishable — do NOT over-read empty xrefs as proof of a
 *   dispatcher.
 * - Serve error cluster @0x2fccae holds format templates (turn/unqueue,
 *   pending admission, UUIDv7, dispatch-failed).
 *
 * PLANNED STEPS (re-run when the daemon is idle):
 *   ghidra-rpc read-bytes  <bin> 0xa726b10 32
 *   ghidra-rpc read-bytes  <bin> 0x38ba4d 64
 *   ghidra-rpc disassemble <bin> 0xa726b10 --count 20
 *   ghidra-rpc create-function <bin> 0xa726b10
 *   ghidra-rpc decompile  <bin> 0xa726b10
 *   ghidra-rpc xrefs-to   <bin> 0xa726b10 --limit 10
 * Then: rename descriptively if anonymous, tag `orchestration`, save.
 *
 * VERDICT: UNDETERMINED — dispatcher yes/no/other cannot be decided
 * from strings-level evidence alone. Signature: unknown. Length: unknown.
 */
