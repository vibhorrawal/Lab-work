#!/bin/bash
clear
echo "Enter a number "
read n
m=0
while [ $n -ne 0 ]
do
p=$(($n%10))
m=$(($m+$p))
n=$(($n/10))
done
echo "sum is $m"
