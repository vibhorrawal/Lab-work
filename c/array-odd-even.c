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
for(i=0;i<num;i++)
if(a[i]%2==0)
a[i]=0;
else a[i]=1;
for(i=0;i<num;i++)
printf("Element no.%d of array becomes %d\n",i+1,a[i]);
}
