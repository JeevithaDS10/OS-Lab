#!/bin/bash
echo "Enter the size of the matrix"
read m
read n

declare -A X
declare -A Y 
declare -A z

echo "Enter the elements of the first matrix:"

for ((i=0;i<$m;i++))
do
for ((j=0;j<$n;j++))
do
read X[$i,$j]
done
done

echo "Enter the elements of the second matrix:"

for ((i=0;i<$m;i++))
do
for ((j=0;j<$n;j++))
do
read Y[$i,$j]
done
done

echo "The input matrices are:"
echo "Matrix-X:"

for ((i=0;i<$m;i++))
do
for ((j=0;j<$n;j++))
do
echo -ne "${X[$i,$j]}  "
done
echo
done


echo "Matrix-Y:"

for ((i=0;i<$m;i++))
do
for ((j=0;j<$n;j++))
do
echo -ne "${Y[$i,$j]}  "
done
echo
done


echo "The resultant matrix:"

for ((i=0;i<$m;i++))
do
for ((j=0;j<$n;j++))
do
Z[$i,$j]=$((X[$i,$j]+Y[$i,$j]))
echo -ne "${Z[$i,$j]}  "
done
echo
done
