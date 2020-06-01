#!/bin/csh

echo -n "Enter the file name: "
set name = $<

set count = `grep -c "." $name`
echo "Number of lines in $name = $count"
