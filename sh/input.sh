#!/bin/bash/
clear
echo "enter three numbers"
read a
read b
read c
echo  "GREATest among them is "
if [ $a -gt $b ]
 then
     if [ $a -gt $c ]
      then
        echo $a
     else
       echo $c
     fi
     
else
    if [ $c -gt $b ]
     then
      echo $c
     else
      echo $b
      fi
fi
