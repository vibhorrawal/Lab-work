//spoj 24
#include<stdio.h>
int trailingZeroes(int);
void main()
{
 int n,x[10],i;
 scanf("%d",&n);
 for(i=0;i<n;i++)
  scanf("%d",&x[i]);
  
 printf("\nOUTPUT:\n");
 for(i=0;i<n;i++)
  printf("%d\n",trailingZeroes(x[i]));
}

int trailingZeroes(int n)
{
 int x,i=0;
 while(n!=0)
{
i+=n/5;
n=n/5;
}
return i;
}
