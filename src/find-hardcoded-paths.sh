#!/bin/bash

SOURCE_FILES=$(find . -name "*.cpp" -o -name "*.h")

OUTPUT="hardcoded-paths-report.html"

echo "<html><head><title>Hardcoded Paths Report</title></head><body>" > $OUTPUT
echo "<h1>Hardcoded Paths in Source Files</h1>" >> $OUTPUT
echo "<ul>" >> $OUTPUT

grep -H -n -E '"(data|packages|init\.cfg|.*\.cfg|.*\.png|.*\.jpg|.*\.ogg|.*\.wav|.*\.ttf|.*\.obj|.*\.md5)"' $SOURCE_FILES | while read -r line ; do
    FILE=$(echo "$line" | cut -d: -f1)
    LINENUM=$(echo "$line" | cut -d: -f2)
    CONTENT=$(echo "$line" | cut -d: -f3- | sed 's/</\&lt;/g' | sed 's/>/\&gt;/g')
    echo "<li><b>$FILE</b>:<b>$LINENUM</b> — <code>$CONTENT</code></li>" >> $OUTPUT
done

echo "</ul>" >> $OUTPUT
echo "</body></html>" >> $OUTPUT

echo "Report generated: $OUTPUT"
