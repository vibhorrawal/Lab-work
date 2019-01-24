#include<stdio.h>
float power(float a,int b)
{
float f=1;
while(b>0)
{
f=f*a;
b=b-1;
}
return f;
}
void main()
{
float a;
int b;
scanf("%f %d",&a,&b);
printf("%f",power(a,b));
}       
