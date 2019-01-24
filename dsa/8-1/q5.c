#include<stdio.h>
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
 //i--;
 i/=2;
 
 for(j=i-1;j>=0;j--)
 printf("%c",c[j]);
 
 
 for(j=i*2;j>=i;j--)
  printf("%c",c[j]);

}
