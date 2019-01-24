#include<stdio.h>
void swap(int *a,int *b){
int t;
t=*a;
*a=*b;
*b=t;
}
void main()
{
int n[8],new[8];
int i,j;
printf("Enter number:");
for(i=0;i<8;i++)
scanf("%d",&n[i]);

for(i=0;i<7;i=i++)
{
 //new[i]=n[i];
 for(j=i+1;j<8;j++)
 {
  if(n[i]>n[j])
   swap(&n[i],&n[j]);
 }

}
for(i=0;i<8;i++)
printf("%d",n[i]);
}
