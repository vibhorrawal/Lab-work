//spoj 1112
#include<stdio.h>
void main()
{
int x[10],y[10],n,k[10],i=0;
scanf("%d",&n);
while(n-->0)
{
 scanf("%d %d",&x[i],&y[i]);
 if( x[i]%2==0 && y[i]%2==0 && x[i]==y[i] )
  k[i]=2*x[i];

 else if ( x[i]%2==0 && y[i]%2==0 && (x[i]-y[i])==2 )
  k[i] = 2 * y[i] + 2;

 else if ( x[i]%2==1 && y[i]%2==1 && x[i]==y[i] )
  k[i] = (x[i] - 1) * 2 + 1;

 else if ( x[i]%2==1 && y[i]%2==1 && (x[i]-y[i])==2) )
 k[i] = ( y[i] - 1) * 2 + 3;
 else
 k[i] = -1
i++;
}

for(i=0; i<n; i--)
{
 if ( k[i] == -1 )
 	printf("no number\n");
 else printf("%d\n",k[i]);
}

} 
