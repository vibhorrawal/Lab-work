//exponential averaging 
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
	int size;
	float a = 0.5;

	printf("How many processes?\n");
	scanf("%d",&size);
	float t[size],tau[size];
	printf("Enter BT of the processes:\n");
	for (int i = 0; i < size; ++i)
			scanf("%f",&t[i]);

	tau[0] = a * t[0];
	//printf("%f\n",tau[0] );
	for (int i = 1; i < size; ++i)
		tau[i] = a * t[i-1] + (1 - a) * tau[i-1];

	printf("Exponential averaging:\n");
	for (int i = 0; i < size; ++i)
		printf("Tau(%d): %.2f\n", i,tau[i]);
	
	return 0;
}