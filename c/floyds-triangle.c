#include<stdio.h>
int main()
{
 int i,j,k,n,l=1;
 printf("Enter value upto which you want to print: ");
 scanf("%d",&n);

for(i=0;i<=n;i++,n--)
{
 k=n;
 while(k-->=0)
 printf(" ");

 for(j=0;j<i;j++)
 printf(" %d",l++);
 printf("\n");
}
}
