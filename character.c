#include <stdio.h>
#include "main.h"

void character(bool board[WIDTH][HEIGHT]) {
    int x = 1, y = 1, z = 0, flag = 0;

    do {
        map_print(x, y, WIDTH, HEIGHT, board);
        printf("移動方向を入力してください(1:上, 2:下, 3:右, 4:左)\n入力：");
        scanf("%d", &z);
        if(z < 1 || z > 4)
            printf("\x1b[31m想定外の値が入力されました再入力してください\x1b[0m\n");
        if (move(&x, &y, z, WIDTH, HEIGHT, board) == 0)
            printf("\x1b[33m入力された方向には移動できません\n再入力してください\x1b[0m\n");
    } while (goal(x, y, WIDTH, HEIGHT) == 0);
    printf("ゴール！おめでとうございます！\n");
};