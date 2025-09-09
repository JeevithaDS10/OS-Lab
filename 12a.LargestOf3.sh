#!/bin/bash
echo "Enter three numbers:"
read n1 
read n2 
read n3
if [[ $n1 -gt $n2 ]]
then 
max=$n1
else
max=$n2
fi
if [[ $n3 -gt $max ]]
then
max=$n3
fi
echo "The largest of 3 numbers is $max"