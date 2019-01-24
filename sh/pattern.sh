#!/bin/bash
echo "Enter the number of lines: "
read n
i=0
k=$n
p=0
clear
z=0
while [ $i -lt $n ]
do
j=$(($p*2+1))	
 m=$k
  while [ $m -gt 0 ]
   do
    echo -n "  "
  m=$(($m-1))
   done

 echo -n "* "
if [ $z -gt 0 ]
then 
while [ $j -gt 0 ]
 do
 echo -n ". "
 j=$(($j-1))
 done
echo -n "* "


fi
p=$(($p+1))
k=$(($k-1))
i=$(($i+1))
echo
z=$(($z+1))
done





