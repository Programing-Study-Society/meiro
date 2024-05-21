#include <stdio.h>
#include "main.h"

void map_print(int x, int y, int width, int height, bool board[WIDTH][HEIGHT]) {
    int i, j;
    for (j = 0; j < height; j++) {
        for (i = 0; i < width; i++) {
            if (i == x && j == y)
                printf("%s", "m");
            else
                printf("%s", (board[i][j] == true) ? "■" : " ");
        }
        printf("\n");
    }
}