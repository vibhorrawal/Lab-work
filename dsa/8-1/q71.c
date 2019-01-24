#include<stdio.h>
void swap(int *a,int *b){
int t;
t=*a;
*a=*b;
*b=t;
}
void main()
{
int n[8];
int i,j,k=1;
printf("Enter number:");
for(i=0;i<8;i++)
scanf("%d",&n[i]);

for(i=0;i<8;i=i+2,k++)
 {
 for(j=k;j<8;j++)
 {
  if(n[i]>n[j])
   swap(&n[i],&n[j]);
   }
   
 }
for(i=0;i<8;i++)
printf("\n%d \n",n[i]);
k=2;
for(i=1;i<8;i=i+2,k++)
{ for(j=k;j<8;j++)
 {
  if(n[i]<n[j])
   swap(&n[i],&n[j]);
   }
  
 }
for(i=0;i<8;i++)
printf("%d ",n[i]);
}
