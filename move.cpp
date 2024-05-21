#include <stdio.h>
#include "main.h"

// キャラの移動処理
int move(int* x, int* y, int z, bool board[WIDTH][HEIGHT]) {
    int xy[2] = { *x, *y };

    // 入力方向に移動
    if (z == 1)
        xy[1]--;
    else if (z == 2)
        xy[1]++;
    else if (z == 3)
        xy[0]++;
    else if (z == 4)
        xy[0]--;

    // 入力方向に移動可能か判定
    if ((WIDTH > xy[0] && xy[0] > 0) && (HEIGHT > xy[1] && xy[1] > 0)) {
        // 移動可能なら移動
        if (board[xy[0]][xy[1]] == false) {
            *x = xy[0];
            *y = xy[1];
            return 1;
        }
    }

    return 0;
}