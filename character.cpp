#include <stdio.h>
#include "main.h"

void character(bool board[WIDTH][HEIGHT]) {
    int x = START_X, y = START_Y, z = 0;

    do {
        // 迷路の表示
        map_print(x, y, board);
        // 移動方向の入力
        printf("移動方向を入力してください(1:上, 2:下, 3:右, 4:左)\n入力：");
        scanf("%d", &z);
        // 入力の例外処理
        if (z < 1 || z > 4)
            printf("\x1b[31m想定外の値が入力されました再入力してください\x1b[0m\n");
        // 移動処理、移動不可ならエラー
        if (move(&x, &y, z, board) == 0)
            printf("\x1b[33m入力された方向には移動できません\n再入力してください\x1b[0m\n");
    // ゴールするまでループ
    } while (goal(x, y) == 0);
    printf("ゴール！おめでとうございます！\n");
};