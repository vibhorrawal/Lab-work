#include<stdio.h>

main( )
{int a,b=0,c,d=1,e,n,i;
scanf("%d",&n);
for(a=n;a>=1;a--)
{   b=b+1;
	for(i=1;i<=a-1;i++)
	{printf(" ");
	}
	for(c=b;c>=1;c--)
    {
	printf("%d",d);
	d++;
    printf(" ");
    }
    printf("\n");
}}
