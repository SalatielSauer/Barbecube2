#!/bin/bash

SCAN_DIR="${1:-.}"
OUTPUT="game_calls_report.html"

echo "Scanning directory: $SCAN_DIR"

# Find all uses of game::
GAME_CALLS=$(grep -rho 'game::[a-zA-Z_][a-zA-Z0-9_]*' "$SCAN_DIR" | sort | uniq)

# Find all uses of entities::
ENTITIES_CALLS=$(grep -rho 'entities::[a-zA-Z_][a-zA-Z0-9_]*' "$SCAN_DIR" | sort | uniq)

# Start HTML report
cat <<EOF > "$OUTPUT"
<!DOCTYPE html>
<html>
<head>
    <meta charset="UTF-8">
    <title>Game and Entities Namespace Usage Report</title>
    <style>
        body { font-family: Arial, sans-serif; margin: 20px; }
        h1 { color: #2a5d9f; }
        ul { line-height: 1.6; }
        li code { color: #333; }
    </style>
</head>
<body>
<h1>Functions and Variables the Engine Calls in game::</h1>
<ul>
EOF

for CALL in $GAME_CALLS; do
    echo "<li><code>$CALL</code></li>" >> "$OUTPUT"
done

cat <<EOF >> "$OUTPUT"
</ul>

<h1>Functions and Variables the Engine Calls in entities::</h1>
<ul>
EOF

for CALL in $ENTITIES_CALLS; do
    echo "<li><code>$CALL</code></li>" >> "$OUTPUT"
done

cat <<EOF >> "$OUTPUT"
</ul>
</body>
</html>
EOF

echo "Report generated: $OUTPUT"
