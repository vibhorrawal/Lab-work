#include<stdio.h>
void main()
{
 int a[3];
int *p,*q,*r;
p=&a[0];
q=&a[1];
r=q-p;
printf("p is %u\nq is %u",p,q);
printf("\np-q is %u",r);
p=p+1;
printf("\np+1 is %u",p);
p=p+4;
printf("\n+4 is %u",p);
}
