#define N 3
#include<bits/stdc++.h>
using namespace std;

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
	return 0;
}