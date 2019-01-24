#include<stdio.h>
#include<stdlib.h>
 
struct node
 {
 	int data;
 	struct node *next;
 } *head,*temp,*tail,*a,*temp2,*head2,*temp3;
int arr[100];
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
 	for (int i = 2; i <= n; i++)
 	{
  	 temp = malloc(sizeof(struct node));
 	   temp->data = i;
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
   head->next = NULL;
  }
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

 void display2()
{
  a = (struct node *)malloc(sizeof(struct node));
  a = head2;
if(a == NULL)
  return;

else{
  while ( a->next != NULL )
  {
    printf("\n%d", a->data );
    a = a->next;
  }
    printf("\n%d\n", a->data );
}}

void reverse()
{
  int i,k;
  temp = (struct node *)malloc(sizeof(struct node));
  //temp3 = (struct node *)malloc(sizeof(struct node));
  temp = head;
  for(i=0;i<100;i++)
  {
    if(temp->next== NULL)
    break;
    arr[i] = temp->data;
    temp = temp->next;

    }
    arr[i] = temp->data;
    k=i;
    //printf("%d",i);
    for(i;i>=0;i--)
    {
      if(k==i)
      {
        head2 = (struct node *)malloc(sizeof(struct node));
        head2->data = arr[i];
        temp3 = head2;
      }
      else{
      temp = (struct node *)malloc(sizeof(struct node));
      temp3->next = temp;
      temp->data = arr[i];
      temp->next = NULL;
      temp3= temp;
    }
    head2->data = arr[k];
    }
  }

void main()
{
 int n,r,p;
 while(1){
 printf("\n\n\t\t\t********** MAIN MENU **********\n\n 1) Create List\n 2) Display Contents of list\n 3) Display Contents of reverse list\n 4) Exit\n\n");
 scanf("%d",&n);
 
 switch(n)
 {
 case 1:
 printf("\nEnter number of nodes you want to create: ");
 scanf("%d",&num);
 create(num);
 break;

 case 2:
 display();
  break;

case 3:
reverse();
display2();
break;

default:
exit(1);
}
}
}

