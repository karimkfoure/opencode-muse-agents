#!/usr/bin/env bash
# Install opencode-muse-agents bundle into THIS package's .opencode (local, no npm).
# Copies agents/skills/commands/tools/plugins verbatim with NO import rewrite:
# bundle/tools/*.ts import ../../src/* which from .opencode/tools/ resolves to <root>/src.
# The ONLY generated file is .opencode/plugins/spark.ts (composed plugin re-export).
# Idempotent: re-running overwrites the spark_* files only.
set -euo pipefail
ROOT="$(cd -- "$(dirname -- "${BASH_SOURCE[0]}")/.." && pwd -P)"
PKG="$ROOT"
DEST="$ROOT/.opencode"

mkdir -p "$DEST/agents" "$DEST/tools" "$DEST/plugins" "$DEST/skills" "$DEST/commands"
cp -f "$PKG/bundle/agents/"*.md "$DEST/agents/"
cp -f "$PKG/bundle/commands/"*.md "$DEST/commands/"
cp -rf "$PKG/bundle/skills/"* "$DEST/skills/"
cp -f "$PKG"/bundle/tools/*.ts "$DEST/tools/"
cp -f "$PKG"/bundle/plugins/*.ts "$DEST/plugins/"
cat > "$DEST/plugins/spark.ts" <<EOF
// Composed Spark plugin (notify + policy + compact + precall).
export { default } from "../../src/plugin";
EOF
echo "installed spark bundle into $DEST"
ls "$DEST/agents" | grep spark; ls "$DEST/tools" | grep spark; ls "$DEST/plugins" | grep spark
