#define N 8
#include<bits/stdc++.h>
using namespace std;
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

#include <ctime>
time_t t = time(NULL);
clock_t start = clock(); 
void print_clock(){
	fprintf(stderr, "------------------------------------------\n Clock ticks: %ld \t Time elapsed: %lds\n------------------------------------------\n\a", clock() - start, time(NULL) - t);
	// fprintf(stderr, "----------------------------------------------------------------------------\n Clock ticks: %ld\t Time taken on CPU: %.3fs\t Time elapsed: %lds\n----------------------------------------------------------------------------\n\a", clock() - start, ((double)clock() - start)/ CLOCKS_PER_SEC, time(NULL) - t);
}
void delay(int number_of_seconds) 
{ 
    // Converting time into milli_seconds 
    int milli_seconds = CLOCKS_PER_SEC * number_of_seconds; // 6 zeroes
  
    // Stroing start time 
    clock_t start_time = clock(); 
  
    // looping till required time is not acheived 
    while (clock() < start_time + milli_seconds); 
} 
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------

void displayBoard(int board[N][N]){
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j)
			printf(" %c ", board[i][j]? 'X': '-');
		printf("\n");
	}

}

bool isSafe(int board[N][N], int row, int col){
	// check row on left
	for (int i = 0; i < col ; ++i)
		if(board[row][i])
			return false;

	// check upper left diagonal
	for (int i = row,j = col ; i>=0 && j>= 0; --j, --i)
		if(board[i][j])
			return false;

	// check lower left diagonal
	for (int i = row,j = col ; i<N && j>= 0; --j, ++i)
		if(board[i][j])
			return false;

	return true;

}

bool solveNQ(int board[N][N], int col){
	if(col >= N)
		return true;

	for (int i = 0; i < N; ++i)
	{
		if(isSafe(board,i,col))
		{
			board[i][col] = 1;
			if(solveNQ(board, col+1))
				return true;

			board[i][col] = 0;

		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int board[N][N] = {0};
	if(!solveNQ(board,0)) printf("There doesn't exist a solution for N = %d\n", N);
	displayBoard(board);
	print_clock();	
	return 0;
}