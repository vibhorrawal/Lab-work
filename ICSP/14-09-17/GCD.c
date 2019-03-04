#include<stdio.h>
int main()
{
	int n;
	printf("Enter the numbers: ");
	scanf("%d",&n);
	if(n%2)
	printf("Goodbye");
	else
    	{
	    	printf("Enter 2 numbers in ascending order: ");
		    int a,b,t;
		    scanf("%d%d",&a,&b);
	    	while(a!=0)
	        	{
			      t=b%a;
			      b=a;
			      a=t;
			
	         	}
	        printf("GCD is %d",b);
		
	   }
}
