#include<stdio.h>
int sum(int n)
{
int rem;
if(n==0)
{
return 0;
}
else
 {
 rem=n%10;
 n=n/10;
rem=rem+sum(n);
return rem;
 }
}
int main()
{
int n;
printf("Enter the number: ");
scanf("%d",&n);
printf("\nSum of digits is %d.\n",sum(n));
}
