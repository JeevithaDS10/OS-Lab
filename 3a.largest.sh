#!/bin/bash
declare -A arr

echo "Enter the size of the array:"
read n
echo "Enter the array elements:"
for ((i=0;i<n;i++))
do
read arr["$i"]
done
max=${arr[$i]}

for ((i=1;i<n;i++))
do
if [[ max -lt ${arr[$i]} ]]
then
max=${arr[$i]}
fi
done

echo "The largest is $max"