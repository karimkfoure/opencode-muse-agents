/* dispatcher_site.c — group0 header site 0x0a726b10 (re-tracks/21 §3)
 *
 * SOURCE: ghidra-rpc on MAIN project ghidra/muse.gpr
 * (binary x86_linux-1.3.0-R3057.1.bin-39ae89, --no-analyze import,
 * analysis_complete=false). Daemon responded fast; NOT saturated.
 * dispatcher_candidate.c left untouched.
 *
 * READ-BACK EVIDENCE:
 * - read-bytes 0xa726b10 32 =
 *   ff25ea2fd207 cccccccccccc... 554889e55350488b1f4889dfff156e1a
 *   (indirect-jump thunk + INT3 padding + next function prologue at
 *   0x0a726b20: 55 48 89 e5 53 50 ...).
 * - read-bytes 0x38ba4d 64 = ASCII "<redacted>.>tbh: worktree cleanup
 *   after permission resume failur..." — .rodata log/format strings,
 *   NOT a pointer table. The "data 0x38ba4d" is an offset into strings.
 * - disassemble 0xa726b10/0x0a726b20: refused server-side
 *   ("in a data section (type: undefined), not executable code") because
 *   the --no-analyze import defines no code units there; worked around
 *   via create-function.
 * - create-function 0xa726b10 -> FUN_0a726b10, body size 1
 *   (0a726b10-0a726b10): single indirect-jump instruction.
 * - xrefs-to 0xa726b10 limit 10 -> EMPTY (count 0), expected with
 *   analysis_complete=false; proves nothing either way.
 *
 * DECOMPILATION (ghidra-rpc decompile FUN_0a726b10):
 *
 *   void FUN_0a726b10(void)
 *   {
 *     (*(code *)&DAT_120000b0)();
 *     return;
 *   }
 *
 * VERDICT: NO dispatcher — 0x0a726b10 is a PLT/GOT-style import thunk
 * (single indirect jump through DAT_120000b0), not a dispatch table or
 * handler. The adjacent prologue bytes belong to the NEXT function at
 * ~0x0a726b20, not to this site.
 */
