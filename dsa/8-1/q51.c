#include<stdio.h>
void swap(char *a,char *b){
char t;
t=*a;
*a=*b;
*b=t;
}
void main()
{
char c[20];
int i,j,k;
scanf("%s",&c);
for(i=0;i<20;i++)
 {
  if(c[i]=='\0')
  break;
 }
 printf("\n %d\n",i);
 i/=2;
for(j=0;j<i/2;j++)
swap(&c[j],&c[i-j-1]);

for(j=0;j<i/2;j++)
swap(&c[i+j],&c[2*i-j-1]);

printf("\n%s",&c);
}
