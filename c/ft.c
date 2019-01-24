#include<stdio.h>
int main()
{
 int i,j,k,n,o,m,l=1;
 printf("Enter number of lines you want to print: ");
 scanf("%d",&n);
 k=n;
 o=k;
for(i=0;i<=k;i++)
{ 
 for(j=o--;j>=0;j--)
 printf("\t");
 for(m=0;m<i;m++)
 printf("\t%d\t",l++);
 printf("\n");	
}
}

