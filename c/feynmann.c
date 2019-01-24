//spoj 3410
#include<stdio.h>
void main()
{
int x[10],n[10],i;
i=0;
do{scanf("%d",&x[i]);
  } while(x[i++]);
printf("OUTPUT\n");
i=0;
 while(x[i])
{
 printf("%d\n",( (x[i]) * (x[i] + 1) * (2 * x[i] + 1) ) / 6);
i++;
}
}
