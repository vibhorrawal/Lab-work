#include<stdio.h>
int main()
{
	printf("Enter the number: ");
	int n,new1=0,rem=0;
	scanf("%d",&n);
	while(n!=0)
	{
		rem=n%10;
		new1=new1*10+rem;
		n=n/10;
		
	}
	printf("Its reverse is %d",new1);
}
