#include <stdio.h>
#include "main.h"

// 迷路の表示
void map_print(int x, int y, bool board[WIDTH][HEIGHT]) {
    int i, j;
    for (j = 0; j < HEIGHT; j++) {
        for (i = 0; i < WIDTH; i++) {
            if (i == GOAL_X && j == GOAL_Y)
                printf("\x1b[34;47m終");
            else if (i == x && j == y)
                printf("%s", "\x1b[31;47m我");
            else
                printf("%s", (board[i][j] == true) ? "\x1b[45m　" : "\x1b[47m　");
            printf("\x1b[0m");
        }
        printf("\n");
    }
}