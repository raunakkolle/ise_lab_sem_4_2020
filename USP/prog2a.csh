#!/bin/csh

echo "Enter a String"

set var1 = $<


echo "Enter a start position"

set var2 = $<

echo "Enter an end position"

set var3 = $<


set var4 = `echo $var1 | cut -c$var2-$var3`

echo $var4
printf "\n"      
