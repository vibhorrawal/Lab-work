#!/bin/bash/
echo "Enter the number of rows to print :"
read n
clear
i=$n
while [ $i -gt 0 ] 
do
 j=$i
  while [ $j -gt 0 ]
   do 
      echo -n "* "
      j=$(($j-1))
   done
 echo
 i=$(($i-1))
done
