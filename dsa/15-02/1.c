#include<stdio.h>
#include<stdlib.h>
 
struct node
 {
 	struct node *prev;
 	int data;
 	struct node *next;
 } *head,*temp,*tail,*a,*temp2;
int num;

 void create(int n)
 {
  if(n>1)
 	{
  int i;
  head = malloc(sizeof(struct node));
 	head->data = 1;
 	a = malloc(sizeof(struct node));
 	a = head;
  head->prev = NULL;
 	for (int i = 2; i <= n; i++)
 	{
  	 temp = malloc(sizeof(struct node));
 	   temp->data = i;
     temp->prev = a;
     a->next = temp;
     a = temp;
 	}
 	tail = temp;
 	tail->next = NULL;
 }
  else
  {
   head = malloc(sizeof(struct node));
   head->data = 1;
   head->prev = NULL;
   head->next = NULL;
  }
 } 

  void insert(int data,int prev)
 {
  temp = (struct node *)malloc(sizeof(struct node));
  temp = head;
  a= head;
  a=a->next;
    while( temp->data != prev)
    {
     temp = temp->next;
     a=a->next;
  }
  temp2 = (struct node *)malloc(sizeof(struct node));
  temp2->data = data;
  temp2->prev = temp;
  temp->next = temp2;
  temp2->next = a;
  a->prev = temp2;
  }
  
  void delete(int data)
  {
if(head->next == NULL && head->prev == NULL)
{
 //printf("\nCant delete the only element of list!!!");
 head = NULL;
}

else 
{
temp = (struct node *)malloc(sizeof(struct node));
a = (struct node *)malloc(sizeof(struct node));
temp=head;
a=head;
a=a->next;
 if( head->data == data)
 {
  head = a;
  head->prev = NULL;
 }
 else if (tail->data == data)
 {
  tail = tail->prev;
  tail->next = NULL;
 }
 else {
  while(a->data!=data)
  {
    temp=temp->next;
    a=a->next;
  }
  temp->next=a->next;
  a = a->next;
  a->prev = temp;
}
}
}

void search(int data)
{
int i=1,k=0;
 temp=(struct node *)malloc(sizeof(struct node));
 temp=head;
 while(temp != NULL)
 {
 if(temp->data==data)
 {
  printf("\nMatch found at node %d",i);
  k=1;
  break;
  }
 i++;
 temp=temp->next;
 }
 if(k==0) 
  printf("\nNo Match Found!!!");
}

void display()
{
	a = (struct node *)malloc(sizeof(struct node));
	a = head;
if(a == NULL)
  return;

else{
	while ( a->next != NULL )
	{
		printf("\n%d", a->data );
		a = a->next;
	}
		printf("\n%d\n", a->data );
}
}

void reversedisplay()
{
  a = malloc(sizeof(struct node));
  a = tail;

  while ( a != NULL)
  {
    printf("\n%d", a->data );
    a = a->prev;
  }
}

void main()
{
 int n,r,p;
 do{
 printf("\n\n\t\t\t********** MAIN MENU **********\n\n 1) Create List\n 2) Insert data\n 3) Delete\n 4) Display Contents of list\n 5) Display Contents of list in reverse\n 6) Search\n 7) Exit\n\n");
 scanf("%d",&n);
 
 switch(n)
 {
 case 1:
 printf("\nEnter number of nodes you want to create: ");
 scanf("%d",&num);
 create(num);
 break;
 
 case 2:
 printf("\nEnter data: ");
 scanf("%d",&r);
 printf("\nNow Enter data after which you want to add: ");
 scanf("%d",&p);
 insert(r,p);
 break;
 
 case 3:
 printf("\nEnter data: ");
 scanf("%d",&p);
 delete(p);
 break;
 
 case 4:
 display();
 break; 

 case 5:
 reversedisplay();
 break;

case 6:
 printf("\nEnter data: ");
 scanf("%d",&r);
 search(r);
 break; 


}
 }while(n!=7);

}

