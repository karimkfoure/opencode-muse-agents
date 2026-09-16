#!/usr/bin/env bash
# Merge bundle/opencode.fragment.json into a target opencode.json.
#
# Usage:
#   scripts/merge-fragment.sh [TARGET] [FRAGMENT]
#
#   TARGET   path to the user's opencode.json (default: ./opencode.json).
#            Created as {} first if it does not exist.
#   FRAGMENT path to the fragment (default: <repo>/bundle/opencode.fragment.json
#            resolved relative to this script).
#
# Merge rules (python3 stdlib json only):
#   - agent: deep-merge by agent name, fragment wins leaf-wise.
#   - subagent_depth: max(existing, fragment).
#   - permission.skill: merge keys, force skill["*"]="allow".
# Anything else in the target is left untouched.
#
# Safety:
#   - Creates backup <target>.bak-<unixms> before writing.
#   - Idempotent: re-running produces no content change (only a new backup).
set -euo pipefail

TARGET="${1:-./opencode.json}"
SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
FRAGMENT="${2:-${SCRIPT_DIR}/../bundle/opencode.fragment.json}"

if ! command -v python3 >/dev/null 2>&1; then
  echo "error: python3 is required" >&2
  exit 1
fi

if [[ ! -f "${FRAGMENT}" ]]; then
  echo "error: fragment not found: ${FRAGMENT}" >&2
  exit 1
fi

if [[ -d "${TARGET}" ]]; then
  echo "error: target is a directory: ${TARGET}" >&2
  exit 1
fi

if [[ ! -f "${TARGET}" ]]; then
  mkdir -p "$(dirname "${TARGET}")"
  printf '{}\n' >"${TARGET}"
  echo "created missing target: ${TARGET}"
fi

TS="$(date +%s%3N 2>/dev/null || python3 -c 'import time; print(int(time.time() * 1000))')"
BACKUP="${TARGET}.bak-${TS}"
cp -- "${TARGET}" "${BACKUP}"
echo "backup: ${BACKUP}"

python3 - "${TARGET}" "${FRAGMENT}" <<'PY'
import copy
import json
import sys

target_path, fragment_path = sys.argv[1], sys.argv[2]

with open(target_path, encoding="utf-8") as f:
    try:
        target = json.load(f)
    except json.JSONDecodeError as e:
        print(f"error: target is not valid JSON: {target_path}: {e}", file=sys.stderr)
        sys.exit(1)

with open(fragment_path, encoding="utf-8") as f:
    try:
        fragment = json.load(f)
    except json.JSONDecodeError as e:
        print(f"error: fragment is not valid JSON: {fragment_path}: {e}", file=sys.stderr)
        sys.exit(1)

if not isinstance(target, dict):
    print(f"error: target root must be a JSON object: {target_path}", file=sys.stderr)
    sys.exit(1)
if not isinstance(fragment, dict):
    print(f"error: fragment root must be a JSON object: {fragment_path}", file=sys.stderr)
    sys.exit(1)


def deep_merge(base, overlay):
    """Recursive dict merge; overlay wins. Returns list of changed leaf paths."""
    changed = []
    for k, v in overlay.items():
        if k in base and isinstance(base[k], dict) and isinstance(v, dict):
            changed.extend(deep_merge(base[k], v))
        elif k not in base:
            base[k] = copy.deepcopy(v)
            changed.append(str(k))
        elif base[k] != v:
            base[k] = copy.deepcopy(v)
            changed.append(str(k))
    return changed


changes = []

# 1. agent block: deep-merge by agent name, fragment wins per-agent (leaf-wise).
frag_agents = fragment.get("agent", {})
if not isinstance(frag_agents, dict):
    print("error: fragment 'agent' must be an object", file=sys.stderr)
    sys.exit(1)
agents = target.get("agent")
if agents is None:
    target["agent"] = copy.deepcopy(frag_agents)
    for name in sorted(frag_agents):
        changes.append(f"agent[{name}]: added")
elif not isinstance(agents, dict):
    print("error: target 'agent' must be an object", file=sys.stderr)
    sys.exit(1)
else:
    for name in sorted(frag_agents):
        if name not in agents:
            agents[name] = copy.deepcopy(frag_agents[name])
            changes.append(f"agent[{name}]: added")
        else:
            before = copy.deepcopy(agents[name])
            leaf_changes = deep_merge(agents[name], frag_agents[name])
            if agents[name] != before:
                detail = f" ({', '.join(sorted(leaf_changes))})" if leaf_changes else ""
                changes.append(f"agent[{name}]: updated{detail}")
            else:
                changes.append(f"agent[{name}]: unchanged")

# 2. subagent_depth: max(existing, fragment).
if "subagent_depth" in fragment:
    frag_depth = fragment["subagent_depth"]
    cur_depth = target.get("subagent_depth")
    if cur_depth is None:
        target["subagent_depth"] = frag_depth
        changes.append(f"subagent_depth: unset -> {frag_depth}")
    elif isinstance(cur_depth, int) and isinstance(frag_depth, int):
        new_depth = max(cur_depth, frag_depth)
        target["subagent_depth"] = new_depth
        if new_depth != cur_depth:
            changes.append(f"subagent_depth: {cur_depth} -> {new_depth}")
        else:
            changes.append(f"subagent_depth: unchanged ({cur_depth})")
    else:
        if target.get("subagent_depth") != frag_depth:
            changes.append(f"subagent_depth: {cur_depth!r} -> {frag_depth!r}")
        else:
            changes.append(f"subagent_depth: unchanged ({cur_depth!r})")
        target["subagent_depth"] = frag_depth

# 3. permission.skill.*: merge keys, force "*" = "allow".
frag_skill = (fragment.get("permission") or {}).get("skill", {})
if frag_skill:
    if not isinstance(frag_skill, dict):
        print("error: fragment 'permission.skill' must be an object", file=sys.stderr)
        sys.exit(1)
    perm = target.get("permission")
    if perm is None:
        target["permission"] = {}
        perm = target["permission"]
    if not isinstance(perm, dict):
        print("error: target 'permission' must be an object", file=sys.stderr)
        sys.exit(1)
    skill = perm.get("skill")
    if skill is None:
        perm["skill"] = {}
        skill = perm["skill"]
    if not isinstance(skill, dict):
        print("error: target 'permission.skill' must be an object", file=sys.stderr)
        sys.exit(1)
    for k in sorted(frag_skill):
        if skill.get(k) != frag_skill[k]:
            changes.append(f"permission.skill[{k}]: {skill.get(k)!r} -> {frag_skill[k]!r}")
            skill[k] = frag_skill[k]
        else:
            changes.append(f"permission.skill[{k}]: unchanged ({skill.get(k)!r})")

with open(target_path, "w", encoding="utf-8") as f:
    json.dump(target, f, indent=2, sort_keys=True)
    f.write("\n")

print(f"merged {fragment_path} -> {target_path}")
if changes:
    for c in changes:
        print(f"  {c}")
else:
    print("  no changes")
PY
