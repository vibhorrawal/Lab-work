#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct student
{
	int id;
	char name;
	char grade[2];
	struct student *next;
}stud[5];

void search(int id);
void display();

void main()
{
	int n,r,i,id,grade[2],name[10];

	// printf("Enter id: ");
	// scanf("%d",&id);
	// printf("Enter name: \n");
	// scanf("%s",name);
	// printf("Enter grade: \n");
	// scanf("%s",grade);
	// head->id = id;
	// strcpy(head->name , name );
	// strcpy(head->grade , grade);
	// temp = (struct student *)malloc(sizeof(struct student));
	// head->next = temp;
	// for(i=1;i<3;i++)
	// {
	// printf("Enter id: ");
	// scanf("%d",&id);
	// printf("Enter name: \n");
	// scanf("%s",name);
	// printf("Enter grade: \n");
	// scanf("%s",grade);	

	// temp->id = id;
	// strcpy(temp->name , name);
	// strcpy(temp->grade , grade);
	// temp2 = (struct student *)malloc(sizeof(struct student));
	// temp->next = temp2;

	// printf("Enter id: ");
	// scanf("%d",&id);
	// printf("Enter name: \n");
	// scanf("%s",name);
	// printf("Enter grade: \n");
	// scanf("%s",grade);	

	// temp2->id = id;
	// strcpy(temp2->name , name);
	// strcpy(temp2->grade , grade);
	// temp = (struct student *)malloc(sizeof(struct student));
	// temp2->next = temp;
//}
	



	// temp->id = 2;
	// temp->name = 'b';
	// temp.grade = 'AB';
	// temp2 = (struct student *)malloc(sizeof(struct student));
	// temp->next = temp2;

	// temp2->id = 3;
	// temp2->name = 'c';
	// temp2.grade = 'AA';
	// temp = (struct student *)malloc(sizeof(struct student));
	// temp2->next = temp;

	// temp->id = 4;
	// temp->name = 'd';
	// temp.grade = 'BC';
	// temp2 = (struct student *)malloc(sizeof(struct student));
	// temp->next = temp2;

	// temp2->id = 5;
	// temp2->name = 'e';
	// temp2.grade = 'BB';
	// temp2->next = NULL;

	
	while(1)
		{
			printf("\n\t\t**MAIN MENU**\n1)Display\n2)Search\n3)exit");
			scanf("%d",&n);
			switch(n)
			{
				case 1:
				display();
				break;

				case 2:
				printf("Enter id: ");
				scanf("%d",&r);
				search(r);
				break;

				default:
				exit(1);
			}
		}
}

void display()
{
	int i;
	temp = (struct student *)malloc(sizeof(struct student));
	temp = head;
	printf("\t\t\tID\t NAME\t GRADE\n");
	for(i = 0; i<5; i++)
	{
		printf("\t\t\t %d \t %s \t %s",temp->id,temp->name,temp->grade);
		temp = temp->next;
	}

}

void search(int data)
{

	temp = (struct student *)malloc(sizeof(struct student));
	temp = head;
	while(temp!=NULL)
	{
		if(temp->id == data){
			printf("\t\t\tID\t NAME\t GRADE\n");
			printf("\t\t\t %d \t %s \t %s",temp->id,temp->name,temp->grade);
			return;
		}

	}
	printf("No data found with this id!\n");
}