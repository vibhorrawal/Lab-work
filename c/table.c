#include<stdio.h>
int n;
int table(n)
{
int i=0;
while(i++<10)
printf("%d X %d = %d\n",n,i,n*i);
return 0;
}
int main()
{
printf("Enter the number whose table you want to know: ");
scanf("%d",&n);
table(n);
return 0;
}
