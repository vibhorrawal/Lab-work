//spoj 2
#include<stdio.h>
void printPrime(int x1,int x2);
int main()
{
 int n,x1[10],x2[10],i;
 scanf("%d",&n);
 for(i=0;i<n;i++)
   scanf("%d %d",&x1[i],&x2[i]);
  printf("OUTPUT:\n");
 for(i=0;i<n;i++)
 printPrime(x1[i],x2[i]);
return 0;
}  

void printPrime(int x1,int x2)
{
 int i,c;
 
for(;x1<=x2;x1++)
{ 
 for(i=2,c=0;i<=x1/2;i++)
 { 
  if(x1%i==0)
   {c=1;break;}
 }

 if(c==0 && x1!=1)
 printf("%d \n",x1);
}
printf("\n");
}
 
