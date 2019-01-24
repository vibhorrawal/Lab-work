#!/bin/bash/
echo "Enter number of rows to be printed: "
read n
i=$n
clear
k=0
while [ $i -gt 0 ]
 do
 j=$i
 
 m=$k
 while [ $m -ge 0 ]
 do
 echo -n " "
 m=$(($m-1))
 done
 k=$(($k+1))
 
  while [ $j -gt 0 ]
   do
   echo -n "* "
   j=$(($j-1))
   done
  echo
  i=$(($i-1))
 done
