#include<stdio.h>
void main()
{
int a[6],n,i,k=0;
printf("Enter 6 numbers to insert them in an array:\n");
for(i=0;i!=6;i++)
scanf("%d",&a[i]);
printf("\nNow enter a number: ");
scanf("%d",&n);
for(i=0;i!=6;i++)
if(n==a[i])
 {
 printf("\nYou have already entered this number in array.\n");
 k=1;
 }
if(k==0)
printf("\nYou have not entered this number in array.\n");
}
