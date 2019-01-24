#include<stdio.h>
int main()
{
int num,n,i,s=0,avg=0,pro=1;
printf("Enter how many numbers you want to input: ");
scanf("%d",&num);
int a[num];
printf("\nNow input values\n");
for(i=0;i<num;i++)
scanf("%d",&a[i]);

for(i=0;i<num;i++)
s+=a[i];
avg=s/num;
for(i=0;i<num;i++)
pro*=a[i];
printf("\nSum=%d\nAverage=%d\nProduct=%d\n",s,avg,pro);
}

