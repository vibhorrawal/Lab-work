#include<iostream>
using namespace std;
void lcs(char* x, char* y);
int len(char* c){
	int i;
	for ( i = 0; ; ++i)
	{
		if(c[i] == '\0')
			break;
	}
	return i;
}
int main(int argc, char const *argv[])
{
	char x[50];
	char y[50];
	scanf("%s",x);
	scanf("%s",y);
	lcs(x,y);
	return 0;
}

void lcs(char* x, char* y){
	int M = len(x)+1;
	int N = len(y)+1;
	printf("%d %d\n",M,N );
	char res[N];
	int iterater = 0;
	char sign[N][M] = {0};
	// printf("%d\n", sign[5][4]);
	int weight[N][M] = {0};
	for (int i = 1; i < N; ++i)
	{
		for (int j = 1; j < M; ++j)
		{
			// printf("%d %d\n", i,j);
			if(x[j-1] == y[i-1]){
				weight[i][j] = weight[i-1][j-1] + 1;
				sign[i][j] = 'd';
				// printf("d");
			}
			else{
				if(weight[i-1][j] < weight[i][j-1]){
					sign[i][j] = 'u';
					weight[i][j] = weight[i][j-1];
				}
				else{
					sign[i][j] = 'l';
					weight[i][j] = weight[i-1][j];
				}
			}
		}
	}
	// printf("Here\n");
	int i = N-1,j = M-1;
	while(i>0 && j>0){
			if(sign[i][j] == 'd'){
				res[iterater++] = y[i-1];
				i--;
				j--;
			}

			else if(sign[i][j] == 'l'){
				i--;
			}
			else if(sign[i][j] == 'u'){
				j--;
			}
		}
		iterater--;
		do{
			printf("%c", res[iterater--]);
		}while(iterater >= 0);

}
