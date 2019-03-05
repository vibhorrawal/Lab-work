// Naive Pattern Matching
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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
			result[1] = i;
			return result;
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

	// for (int i = 0; i < SIZE; ++i)
	// {
	// 	printf("%d\n", pattern[i]);
	// }
	result = brute_force(template,SIZE,pattern,size);
	printf("The Pattern "); 
	result[0] ? printf("matches at position %d.\n", result[1]) : printf("does not match.\n");
	return 0;
}

