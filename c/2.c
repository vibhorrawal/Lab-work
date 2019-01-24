#include<stdio.h>
void main()
{
int n,i=0;
int rem[100];
scanf("%d",&n);
while(n!=0)
{
rem[i]=n%8;
n=n/8;
i++;
}
i--;
while(i>=0)
{
printf("%d",rem[i]);
i--;
}
}
