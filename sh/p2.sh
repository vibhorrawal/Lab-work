#!/bin/bash
clear
echo "Input the number of units"
read n
echo -n "Fare is : "
if [ $n -le 50 ]
 then 
 f=100
elif [ $n -le 100 ] && [ $n -ge 51 ]
 then
echo f= $(($n*1.5)) 
elif [ $n -lt 201 ]
 then f= $((2*($n)))
elif [ $n -lt 401 ]
 then f=$(( 3*($n)))
elif [ $n -gt 400 ]
 then f= $((5*($n)))
fi


