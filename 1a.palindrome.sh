#!/bin/bash
echo "Enter the string you have to check:"
read str
length=${#str}

for ((i=length-1;i>=0;i--))
do
reverse=$reverse${str:$i:1}
done

if [[ $reverse == "$str" ]]
then
echo "The string $str is palindrome"
else
echo "The string $str is not palindrome"
fi