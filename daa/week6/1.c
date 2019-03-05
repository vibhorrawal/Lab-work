#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#define PRIME 13

int horner(int* pattern, int size);
int* robin_karp(int* template, int SIZE, int* pattern, int size);
int* brute_force(int* template, int SIZE, int* pattern, int size);

int new_horner(int num, int* template, int size){
	int b = pow(10,size);
	b = num / b;
	int number = num - b;
	number*= 10;
	number+= *(template + size - 1);
	return number;
}

int main(int argc, char const *argv[])
{
	int size,SIZE,n;
	
	scanf("%d", &SIZE);
	int* template = (int*) malloc(SIZE*sizeof(n));
	for (int i = 0; i < SIZE; ++i)
	{
		scanf("%d",&n);
		template[i] = n;
	}

	scanf("%d",&size);
	int* pattern = (int*) malloc(size*sizeof(n));
	for (int i = 0; i < size; ++i)
	{
		scanf("%d",&n);
		pattern[i] = n;
	}
	int choice;
	scanf("%d", &choice);

	int* result = (int*) malloc(2*sizeof(n)); //result,position
	result = (choice == 1) ? robin_karp(template,SIZE,pattern,size): brute_force(template,SIZE,pattern,size); // 1 is robin and 2 is brute force

	result[0] ? : printf("The Pattern does not match.\n");
	return 0;
}

int horner(int* pattern, int size)
{
	int number = 0;
	for (int i = 0; i < size; ++i)
	{
		number+= pattern[i];
		number *= 10;
	}
	// printf("%d\n", number);
	return number;
}

int* robin_karp(int* template, int SIZE, int* pattern, int size)
{
	int t, p = horner(pattern,size);
	int m = p % PRIME;
	bool flag = true;
	int* result = (int*) malloc(2*sizeof(size));
	result[0] = 0;

	for (int i = 0; i < SIZE - size + 1; ++i)
	{
		t = new_horner(t,template + i, size);
		if(t % PRIME)
		{
			if(t == p){
				result[0] = 1;
				result[1] = i + 1;
				printf("The Pattern "); 
				result[0] ? printf("matches at position %d.\n", result[1]) : printf("does not match.\n");
				//return result;
			}
		}
	}
	return result; 
}

int* brute_force(int* template, int SIZE, int* pattern, int size)
{
	bool flag;
	int* result = (int*) malloc(2*sizeof(size));
	result[0] = 0;

	for (int i = 0; i < SIZE - size + 1; ++i)
	{
		flag = true;
		for (int j = 0; j < size; ++j)
		{
			if(pattern[j] != template[j+i]){
				flag = false;
				break;
			}

		}
		if(flag){
			result[0] = 1;
			result[1] = i + 1;
			printf("The Pattern "); 
			result[0] ? printf("matches at position %d.\n", result[1]) : printf("does not match.\n");
			//return result;
		}
	}
	return result;
}

