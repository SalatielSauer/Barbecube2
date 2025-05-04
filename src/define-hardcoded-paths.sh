#!/bin/bash

# The directory containing source files
SRC_DIR="engine"

# Output engine.cfg
CFG_OUT="../data/engine.cfg"

echo "// engine.cfg with path aliases" > "$CFG_OUT"
echo "// the files below are essential to run the engine" >> "$CFG_OUT"
echo "" >> "$CFG_OUT"

# Temp file for storing matches
TMPFILE=$(mktemp)

# Find hardcoded paths in C++ files
grep -rEo '"(data|packages)/[^"]+"' "$SRC_DIR"/*.cpp "$SRC_DIR"/*.h | \
    sed -E 's/.*"(data|packages)\/([^"]+)"/\1\/\2/' | \
    sort | uniq > "$TMPFILE"

# Build aliases
n=1
while read -r path; do
    # Sanitize variable name
    varname=$(echo "$path" | tr '/.' '_' | tr -cd '[:alnum:]_')

    # Avoid duplicates
    aliasname="_engine_path_$varname"

    echo "$aliasname = \"$path\"" >> "$CFG_OUT"

    ((n++))
done < "$TMPFILE"

# Clean up
rm "$TMPFILE"

echo ""
echo "Generated $CFG_OUT with $((n-1)) aliases."
