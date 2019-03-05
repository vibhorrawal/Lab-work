#include<stdio.h>
void main()
{
	printf("Enter number of terms(>=2) you want to print of Fibonacci series: ");
	int n,t,a=1,b=1;
	scanf("%d",&n);
	n=n-2;
	printf("1,1");
	while(n!=0)
	{
		t=b;
		b=a+b;
		a=t;
		n--;
		printf(",%d",b);
	}
	
}

