#include <stdio.h>
#include <stdlib.h>

void displayBoard(char board[][4], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int isSafe(int row, int col, char board[][4], int n)
{
    int duprow = row;
    int dupcol = col;
    // Checking left side
    while (col >= 0)
    {
        if (board[row][col] == 'Q')
            return 0;
        col--;
    }
    row = duprow;
    col = dupcol;
    // Checking Left Upper diagonal
    while (row >= 0 && col >= 0)
    {
        if (board[row][col] == 'Q')
            return 0;
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    // Checking Left Lower diagonal
    while (row < n && col >= 0)
    {
        if (board[row][col] == 'Q')
            return 0;
        row++;
        col--;
    }
    return 1;
}

void solve(int col, char board[][4], int n)
{
    if(col == n)
    {
        displayBoard(board,n);
        printf("\n"); //For next combination of board
        return;
    }
    for(int row =0; row<n;row++)
    {
        if(isSafe(row,col,board,n))
        {
            board[row][col] ='Q';
            solve(col+1,board,n);
            board[row][col] = '.'; //Backtracking step
        }
    }
}

int main()
{
    int n;
    printf("Enter the dimension of chessBoard\n");
    scanf("%d", &n);
    if(n==2 || n==3)
    {
        printf("No solution exists\n");
        exit(0);
    }
    char board[n][n];
    // Initialising board with No queen
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            board[i][j] = '.';
        }
    }
    solve(0, board,n); // 0th col is called
    return 0;
}
