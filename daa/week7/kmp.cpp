#include <bits/stdc++.h> 
using namespace std;
void compute_array(char* pat, int M, int* arr) 
{ 
	int len = 0; 

	arr[0] = 0;
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			arr[i] = len; 
			i++; 
		} 
		else 
		{ 
			if (len != 0) { 
				len = arr[len - 1]; 
			} 
			else 
			{ 
				arr[i] = 0; 
				i++; 
			} 
		} 
	}
	for (int i = 0; i < M; ++i)
	 {
	 	printf("%d", arr[i]);
	 }printf("\n"); 
} 

void KMPSearch(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt);
	int arr[M]; 
 
	compute_array(pat, M, arr); 

	int i = 0; 
	int j = 0;
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			printf("Found pattern at index %d \n", i - j); 
			j = arr[j - 1]; 
		} 

		else if (i < N && pat[j] != txt[i]) { 
			if (j != 0) 
				j = arr[j - 1]; 
			else
				i = i + 1; 
		} 
	} 
} 



int main() 
{
	char txt[50],pat[50];
	scanf("%s", txt);
	scanf("%s", pat); 
	KMPSearch(pat, txt); 
	return 0; 
} 
