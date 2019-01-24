#include <stdio.h>
#include <stdlib.h>
#include<string.h>
struct student
{
	int id;
	char name;
	char grade;
}stud[5];

int search(int , int);
void display();
void fun(int);

void main()
{
	int n,r,i,id,grade[2],name[10],middle,first=0,last=4;

	stud[0].id = 1;
	stud[0].name = 'a';
	stud[0].grade = 'A';

	stud[1].id = 2;
	stud[1].name = 'b';
	stud[1].grade = 'A';

	stud[2].id = 3;
	stud[2].name = 'c';
	stud[2].grade = 'B';

	stud[3].id = 4;
	stud[3].name = 'd';
	stud[3].grade = 'A';

	stud[4].id = 5;
	stud[4].name = 'e';
	stud[4].grade = 'B';
	
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
				 
  				 middle = (first+last)/2;
 
  					 while (first <= last) {
    				  if (stud[middle].id < r)
					first = middle + 1;    
     				 else if (stud[middle].id == r) 
     				 {
      				   printf("id:%d name: %c grade: %c" ,stud[middle].id,stud[middle].name,stud[middle].grade);
      						   break;
     						 }
     				 else
        				 last = middle - 1;
 
     						 middle = (first + last)/2;
  					 }
  							 if (first > last)
   						   printf("Not found! %d is not present in the list.\n", r);

				break;

				default:
				exit(1);
			}
		
		}
}

void display()
{
	int i;

	printf("\t\t\tID\t NAME\t GRADE\n");
	for(i = 0; i<5; i++)
	{
		printf("\t\t\t %d \t %c \t %c\n",stud[i].id,stud[i].name,stud[i].grade);
	}

}


int search(int x, int n)
// {int mid = n/2;
//         if (stud[mid].id == x)  
//             return mid;
//         else if (stud[mid].id > x) 
//             return search(x, mid-1);
//         else return search(x, mid+1);
   {

   }
 void fun(int i)
 {
 	printf("\t\t\tID\t NAME\t GRADE\n");
 	printf("\t\t\t %d \t %c \t %c",stud[i].id,stud[i].name,stud[i].grade);
 }  