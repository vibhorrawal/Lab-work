//7974
#include<stdio.h>
void main()
{
float a[10],b[10],c[10],n;
int i=-1;
do{
i++;
scanf("%f %f %f",&a[i],&b[i],&c[i]);
}while( a[i]*a[i] + b[i]*b[i] + c[i]*c[i] );
printf("\nOUTPUT\n");
i=0;
while( a[i]*a[i] + b[i]*b[i] + c[i]*c[i] )
{
if(b[i] == ( a[i] + c[i] ) / 2 )
{
n = c[i] + b[i] - a[i] ;
printf("\nAP ");
}
else
{
n = c[i] * b[i] / a[i] ;
printf("\nGP ");
}
printf("%f",n);
i++;
}
}
  
