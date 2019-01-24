#include<stdio.h>
void main()
{
int num,i,large,small,choice;
printf("Enter how many numbers you want to input: ");
scanf("%d",&num);
int a[num];
printf("\nNow input values\n");
for(i=0;i<num;i++)
scanf("%d",&a[i]);
printf("\nIf you want to calculate smallest type 0, if largest type 1,if both type 2: ");
scanf("%d",&choice);
small=a[0];
large=a[0];
for(i=0;i<num;i++)
if(small>a[i])
small=a[i];
for(i=0;i<num;i++)
if(large<a[i])
large=a[i];
if(choice==0)
printf("\nSmallest is %d\n",small);
else if(choice==1)
printf("\nLargest is %d\n",large);
else if(choice==2)
{
printf("\nSmallest is %d\n",small);
printf("\nLargest is %d\n",large);
}
}
