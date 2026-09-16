/**
 * contract.ts — per-child completion contracts.
 *
 * A child declares the schema its result MUST satisfy
 * (WorkflowChildCompletionContract: kind, schemaRef, required fields).
 * Results are validated against the contract; mismatches are
 * malformed_arguments-class rejections, not silent drops.
 */

export interface CompletionContract {
  kind: "default_text" | "declared_schema";
  schemaRef?: string;
  requiredFields?: string[];
}

export type ContractIssue =
  | { key: "missing_contract_field"; field: string }
  | { key: "malformed_result" };

/** Validate a result object against its completion contract. */
export function validateAgainstContract(
  result: Record<string, unknown>,
  contract: CompletionContract,
): { ok: true } | { ok: false; issues: ContractIssue[] } {
  if (contract.kind === "default_text") {
    if (typeof result.summary !== "string" || result.summary.length === 0) {
      return { ok: false, issues: [{ key: "malformed_result" }] };
    }
    return { ok: true };
  }
  const issues: ContractIssue[] = [];
  for (const field of contract.requiredFields ?? []) {
    if (!(field in result) || result[field] === undefined) {
      issues.push({ key: "missing_contract_field", field });
    }
  }
  return issues.length > 0 ? { ok: false, issues } : { ok: true };
}
