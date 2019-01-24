#include<stdio.h>
int n;
int factorial(n)
{
if(n==0)
return 1;
else 
return n*factorial(n-1);
}
int main()
{
printf("Enter the number whose factorial you want to know: ");
scanf("%d",&n);
printf("\nFactorial of %d is %d.\n",n,factorial(n));
}
