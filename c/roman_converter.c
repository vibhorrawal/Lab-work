#include<stdio.h>
void main()
{
int d;
printf("ENTER NUMBER: ");
scanf("%d",&d);

if(d>=1000)
 while(d>=1000)
 {
  printf("m");
  d=d-1000;
 }
 
if(d>=500)
 while(d>=500)
 {
  printf("d");
  d=d-500;
 }
 
if(d>=100)
 while(d>=100)
 {
  printf("c");
  d=d-100;
 }
 
if(d>=50)
 while(d>=50)
 {
  printf("l");
  d=d-50;
 }
 
if(d>=10)
 while(d>=10)
 {
  printf("x");
  d=d-10;
 } 
 
if(d==9)
 {
 printf("ix");
 d=d-9;
 }

if(d>=5)
 while(d>=5)
 {
  printf("v");
  d=d-5;
 } 
 
 if(d>=1)
 while(d>=1)
 {
  printf("i");
  d=d-1;
 }
printf("\n"); 
 }
