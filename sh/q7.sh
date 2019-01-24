#!/bin/bash/
echo "Enter number of rows to print:"
read n
clear
i=$n
k=0
while [ $i -ge 0 ]
do
m=$k
 while [ $m -ge 0 ]
 do
 echo -n " "
 m=$(($m-1))
 done
 j=$i
 while [ $j -gt 0 ]
   do
   echo -n "* "
   j=$(($j-1))
   done
   echo 
   i=$(($i-1))
   k=$(($k+2))
   done
