#!/bin/bash
echo "Enter a number to check if it is a palindrome: "
read n
m= 0
while [ $n -ne 0 ]
do
p= $(( $n % 10 ))

 m= $(( $p + ( $m * 10 ) ))
 n= $(( $n / 10 ))
done
echo $m
