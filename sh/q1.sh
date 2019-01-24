#!/bin/bash/
clear
echo Enter your number:
read n
m=0
temp=$n
while [ $n -ne 0 ]
do
r=$(($n%10))
p=$(($r*$r*$r))
m=$(($m+$p))
n=$(($n/10))
done

if [ $temp -eq $m ]
then echo It is an armstrong number
else echo It is not an armstrong number
fi
