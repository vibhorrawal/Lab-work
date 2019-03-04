#include<stdio.h>
void main()
{
	int n,old,new=0,rem=0;
	printf("Enter the number: ");
	scanf("%d",&n);
	old=n;
	while(n!=0)
	{
		rem=n%10;
		new=new*10+rem;
		n=n/10;
	}
	if(old==new)
	printf("Its a palindrome");
	else
	printf("Its not a palindrome");
	
}
