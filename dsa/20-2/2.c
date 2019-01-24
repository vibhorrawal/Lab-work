#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next;
}*temp,*prev,*current,*head,*a;
int flag = 0;

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
	int d;
	scanf("%d",&d);
	if (flag == 0)
	{
	head = malloc(sizeof(struct node));
	//head = temp;
	head ->data = d;
	head ->next = NULL;
	prev = head;
	flag = 1;
	temp = head;
	}

	else if (flag == 1)
	{
	current = malloc(sizeof(struct node));
	current->data = d;
	current -> next = NULL;
	prev -> next = current;
	prev = current;
	temp = head;
	flag = 2;
	}

	else
	{
	current = malloc(sizeof(struct node));
	current->data = d;
	current -> next = NULL;
	prev -> next = current;
	prev = current;	
	temp = temp->next;
	}
}

void pop()
{
	temp = malloc(sizeof(struct node));
	a = malloc(sizeof(struct node));
			if(head == NULL)
				printf("Nothing left!\n");
			else if(head->next == NULL)
				head = NULL;
			else if (head->next->next == NULL)
				head->next = NULL;
			else{
			a = head;
			while(a->next != current)
				a = a->next;
			a -> next = NULL;
		}
}

void display()
{
	a = malloc(sizeof(struct node));
	a = head;
	while(a != NULL)
	{
		printf("%d\n", a->data );
		a = a->next;
	}
}