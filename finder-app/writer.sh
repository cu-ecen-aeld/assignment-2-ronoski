#!/bin/sh
# writer.sh - Create (or overwrite) a file with the supplied content.
# Author: ronoski

if [ $# -lt 2 ]; then
    echo "Error: missing arguments. Usage: $0 <writefile> <writestr>" 1>&2
    exit 1
fi

writefile=$1
writestr=$2

writedir=$(dirname "$writefile")
if ! mkdir -p "$writedir"; then
    echo "Error: could not create directory '$writedir'" 1>&2
    exit 1
fi

if ! echo "$writestr" > "$writefile"; then
    echo "Error: could not write to file '$writefile'" 1>&2
    exit 1
fi
