#include <stdio.h>
#include <stdlib.h>
int count = 0;
int a[10];

void push();
void pop();
void display();
void main()
{
	int i;
	while(1){
		printf("\t\t\t\n\n\n********** MAIN MENU **********\n\n1) Push\n2) Pop\n3) Display\nEnter Choice : ");
		scanf("%d",&i);
		switch(i)
		{
			case 1:
			push();
			break;

			case 2:
			pop();
			break;

			case 3:
			display();
			break;

			default :
			exit(0);
		}
	}

}

void push()
{
	if ( count == 10 )
	{
		printf("Stack is full!!!\n");
		return;
	}

		int data;
		printf("\nEnter data: ");
		scanf("%d",&data);
		a[count] = data;
		count++;
}

void pop()
{
	if (count == 0)
	{
		printf("Stack is empty!!!\n");
		return;
	}

	count--;
}

void display()
{
	if(count != 0)
	{
	int i;
	printf("\nStack is :\n");
	for (int i = 0; i < count; i++)
	{
		printf("%d\n", a[i] );
	}
	}
	else printf("Stack is empty!!!\n");

}