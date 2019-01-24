#include<stdio.h>
#include<stdlib.h>

struct node
{
 int data;
 struct node *next;
} *head,*temp,*a,*tail,*new;


void create(int n)
{
 int i;
 for(i=1;i<=n;i++)
 {
  temp=(struct node *)malloc(sizeof(struct node));
  temp->data=i;
  temp->next=NULL;

   if(i==1)
   {
    head=temp;
    a=head;
   }
   a->next=temp;
   a=temp;
  }
  tail=temp;
}
 
void insertHead(int data)
{
 temp=(struct node *)malloc(sizeof(struct node));
 temp->data=data;
 temp->next=head;
 head=temp;
}

void insertTail (int data)
{
 temp=(struct node *)malloc(sizeof(struct node)); 
 temp->data=data;
 tail->next=temp;
 tail=temp;
}
  
void insert (int data, int position)
{  
  int i;
  
  if(position==1)
    insertHead(data);
    
   else if (position>1)
  {

temp=(struct node*)malloc(sizeof(struct node));
a=(struct node*)malloc(sizeof(struct node));
    temp=head;
   
for(i=2;i<position;i++)
{
 temp = temp ->next;
 }
a->data=data;
a->next= temp->next;
temp->next=a;
  }
  else printf("\nIncorrect Input!");
}
  
void deleteHead()
{
head = head->next; 
}

void delete(int n)
{
  int i;
  if(n==1)
    deleteHead();
    
    else if (n>1)
    {
      temp=(struct node *)malloc(sizeof(struct node));
      temp=head;
      new=head->next;
      for(i=n;i>2;i--)
       {
        temp=temp->next;
        new = new -> next;
       }
       
      temp->next = new -> next;
    }
    else printf("\nIncorrect Input!");
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
 int i=1;
 temp=(struct node *)malloc(sizeof(struct node));
 temp=head;
 while(temp!=NULL)
 {
 printf("\nAt node %d data is %d",i,temp->data);
 temp=temp->next;
 i++;
 }
}
  
void main()
{
 int n,r,p;
 do{
 printf("\n\n\t\t\t********** MAIN MENU **********\n\n 1) Create List\n 2) Insert data at beginning\n 3) Insert data at end\n 4) Insert data elsewhere\n 5) Delete beginning\n 6) Delete at position\n 7) Search\n 8) Display Contents of list\n 9) Exit\n\n");
 scanf("%d",&n);
 
 switch(n)
 {
 case 1:
 printf("\nEnter number of nodes you want to create: ");
 scanf("%d",&r);
 create(r);
 break;
 
 case 2:
 printf("\nEnter data: ");
 scanf("%d",&r);
 insertHead(r);
 break;
 
 case 3:
 printf("\nEnter data: ");
 scanf("%d",&r);
 insertTail(r);
 break;
 
 case 4:
 printf("\nEnter data: ");
 scanf("%d",&r);
 printf("\nNow Enter position: ");
 scanf("%d",&p);
 insert(r,p);
 break;
 
 case 5:
 deleteHead();
 break;
 
 case 6:
 printf("\nEnter position: ");
 scanf("%d",&p);
 delete(p);
 break;
 
 case 7:
 printf("\nEnter data: ");
 scanf("%d",&r);
 search(r);
 break;
 
 case 8:
 display();
 break; 
 }
 
 }while(n!=9);

}
