#include<stdio.h>
void main()
{
	printf("Enter the character: ");
	char a,b;
	scanf("%c",&a);
	switch(a)
	{
		case 'a':b=1;
		break;
		case 'e':b=1;
		break;
		case 'o':b=1;
		break;
		case 'u':b=1;
		break;
		case 'A':b=1;
		break;
		case 'E':b=1;
		break;
		case 'i':b=1;
		break;
		case 'I':b=1;
		break;
		case 'O':b=1;
		break;
		case 'U':b=1;
		break;
	}
	if(b==1)
{
	printf("Enter the month number: ");
	scanf("%d",&a);
	switch(a)
	{
		case 1:b=1;
		break;
		case 3:b=1;
		break;
		case 5:b=1;
		break;
		case 7:b=1;
		break;
		case 8:b=1;
		break;
		case 10:b=1;
		break;
		case 12:b=1;
		break;
		case 4:b=0;
		break;
		case 6:b=0;
		break;
		case 9:b=0;
		break;
		case 11:b=0;
		break;
		case 2:b=2;
		break;
	}
	  
	  if(b==0)
	  printf("30 days in this month");
	   else if(b==1)
	   printf("31 days in this month");
	   else
	   printf("28 days in this month");
	   
	
		
	}
}
