#include <stdio.h>
#include <stdbool.h>
#define N 8 
void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%2d ", board[i][j]);
        }
        printf("\n");
    }
}

bool isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}
bool solveQueens(int board[N][N], int col) {
    if (col >= N) {
        return true; 
    }
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1; 

            if (solveQueens(board, col + 1)) {
                return true;
            }
            board[i][col] = 0;
        }
    }

    return false; 
}

int main() {
    int board[N][N] = {0}; 

    if (solveQueens(board, 0)) {
        printf("Solution:\n");
        printBoard(board);
    } else {
        printf("No solution exists.\n");
    }

    return 0;
}
