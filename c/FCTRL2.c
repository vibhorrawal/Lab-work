//spoj 24
#include<stdio.h>
int factorial(int);
void main()
{
 int n,x[10],i;
 scanf("%d",&n);
 for(i=0;i<n;i++)
  scanf("%d",&x[i]);
  
 printf("\nOUTPUT:\n");
 for(i=0;i<n;i++)
  printf("%d\n",factorial(x[i]));
}

int factorial(int n)
{
if (n==1)
 return 1;
else
 return n * factorial(n-1);
}
