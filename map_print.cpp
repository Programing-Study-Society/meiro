#include <stdio.h>
#include "main.h"

// 迷路の表示
void map_print(int x, int y, bool board[WIDTH][HEIGHT]) {
    int i, j;
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            if (i == x && j == y)
                printf("%s", "m");
            else
                printf("%s", (board[i][j] == true) ? "■" : " ");
        }
        printf("\n");
    }
}