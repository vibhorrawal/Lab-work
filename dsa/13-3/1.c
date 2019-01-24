#include<stdio.h>
#include<stdlib.h>
int front = -1, rear = -1;
void pop();
void push(int );
void display();
int a[10];

void main()
{
	int n,data;
	pop();
	while(1)
	{
		printf("\n\t\tMain Menu\n1)push\n2)pop\n3)display\n4)exit\n");
		scanf("%d",&n);
		switch(n)
		{
			case 1:
			printf("\nEnter data: ");
			scanf("%d",&data);
			push(data);
			break;

			case 2:
			pop();
			break;

			case 3:
			display();
			break;

			default:
			exit(1);
		}

	}
}
	
void pop()
{
	if(front!=-1)
	front++;
}

void push(int data)
{
	rear++;
	a[rear] = data;
} 

void display()
{
	int i;
	for( i = front ; i <= rear ; i++)
	{
		printf("\n%d", a[i]);
	}
}