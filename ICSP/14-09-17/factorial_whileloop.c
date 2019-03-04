#include<stdio.h>
void main()
{
	printf("Enter the number to calculate its factorial: ");
	float f,c;
	int b,n=1;
	scanf("%f",&f);
	b=(int)f;
	c=f-b;
	if(f>0)
	 {
	 	
	   if(c!=0)
       printf("Type only positive number");
	    
		else
		{	while(b>1)
	          {
	          n=b*n;
	          b--;
              }
            printf("\n %d",n);
        
        }
	}
    else
    printf("It is not acceptable");
}
