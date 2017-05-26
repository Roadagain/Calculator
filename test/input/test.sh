#!/bin/sh

status=0

for i in $@
do
    echo "Executing $i..."
    $i
    if [ $? -ne 0 ]; then
        echo "Error on $i"
        status=1
    fi
done

if [ $status -eq 0 ]; then
    echo "All test has completed successfully"
else
    exit $status
fi
