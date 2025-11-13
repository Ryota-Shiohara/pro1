#include <stdio.h>
#include <stdlib.h>

#define N 8
int board[N] = {0};
int solutions = 1;

void solve_queen(int col) {
    if (col == -1) {
        int i, j;
        printf("solution = %d\n", solutions++);
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                if (board[j] == i) {
                    printf("Q");
                } else {
                    printf(".");
                }
            }
            printf("\n");
        }
        return;
    } else {
        int row;
        for (row = 0; row < N; row++) {
            int i, canPlace = 1;
            for (i = col + 1; i < N; i++) {
                if (board[i] == row || abs(board[i] - row) == abs(i - col)) {
                    canPlace = 0;
                    break;
                }
            }
            if (canPlace) {
                board[col] = row;
                solve_queen(col - 1);
                board[col] = 0;
            }
        }
    }
}


int main() {
    solve_queen(N - 1);
    return 0;
}