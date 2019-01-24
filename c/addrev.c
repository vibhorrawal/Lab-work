//spoj 42
#include<stdio.h>
int rev(int );
void main()
{
 int x,n1[100],n2[100],i;
 scanf("%d",&x);
 i=x;
 while(x-->0)
  {
   scanf("%d %d",&n1[x],&n2[x]);
   n1[x]=rev(n1[x]);
   n2[x]=rev(n2[x]);
  }

 while(i-->0)
  printf("%d\n",rev(n1[i]+n2[i]));
}
int rev(int n)
{
 int i,rev=0;
 while(n>0)
 {
 i=n%10;
 rev = rev * 10 + i;
 n=n/10;
 }
 return rev;
}
