#include<stdio.h>
void main()
{
	printf("Enter gender: M/F ");
	char gender;
	scanf("%c",&gender);
	if(gender=='M')
	{
		printf("Enter 2 numbers:");
		int a,b,c;
		scanf("%d %d",&a,&b);
		c=a;
		a=b;
		b=c;
		printf("%d %d",a,b);
		
	}
else if(gender=='F')
{
	printf("Enter 2 numbers:");
		int a,b,c;
		scanf("%d %d",&a,&b);
		c=a+b;
		printf("%d",c);
}
}
