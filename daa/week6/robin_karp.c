#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define PRIME 13

int horner(int* pattern, int size)
{
	int number = 0;
	for (int i = 0; i < size; ++i)
	{
		number+= pattern[i];
		number *= 10;
	}
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
		t = horner(template + i, size);
		if(t % PRIME)
		{
			if(t == p){
				result[0] = 1;
				result[1] = i;
				return result;
			}
		}
	}
	return result; 
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
	
	int* result = (int*) malloc(2*sizeof(n)); //result,position
	result = robin_karp(template,SIZE,pattern,size);
	printf("The Pattern "); 
	result[0] ? printf("matches at position %d.\n", result[1]) : printf("does not match.\n");
	return 0;
}
