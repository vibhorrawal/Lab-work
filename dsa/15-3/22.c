#include<stdio.h>
#include<stdlib.h>
 
struct node
 {
 	int data;
 	struct node *next;
 } *head,*temp,*tail,*a,*temp2,*head2,*temp3;
int arr[100]={0};
int num;

 void create(int n)
 {
  int r;
  if(n>1)
 	{
  int i,r;
  head = malloc(sizeof(struct node));
  scanf("%d",&r);
 	head->data = r;
 	a = malloc(sizeof(struct node));
 	a = head;
 	for (int i = 2; i <= n; i++)
 	{
  	 temp = malloc(sizeof(struct node));
     scanf("%d",&r);
 	   temp->data = r;
     a->next = temp;
     a = temp;
 	}
 	tail = temp;
 	tail->next = NULL;
 }
  else
  {
   head = malloc(sizeof(struct node));
   scanf("%d",&r);
   head->data = r;
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


void nodetoarr()
{
  int i,k,j,r,sum=0;
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

    for(j=0;j<100;j++)
    {
      sum+=arr[j];
      if(sum==0)
        break;
    }


    for(j;j>=0;j--)
    {
      head = head->next;
    }
}
void main()
{
  int n,r,p;
 while(1){
 printf("\n\n\t\t\t********** MAIN MENU **********\n\n 1) Create List\n 2) Display Contents of list\n 3) remove zeroes\n 4) Exit\n\n");
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
nodetoarr();
display();
break;

default:
exit(1);
}
}
}


    