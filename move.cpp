#include <stdio.h>
#include "main.h"

//  boardの見方
//  0,0 0,1
//  1,0 1,1
// startは1,1固定、Goalはwidth-1,height-1固定

// move()    boardはboolean型
// 引数：x=キャラ横座標、y=キャラ縦座標、z=移動方向、width=迷路の横幅、heigth=迷路の縦幅、board[]=迷路配列
// (補足) z　=　(1:上, 2:下, 3:右, 4:左)

// 変数：xy[0]=計算用の横の座標、xy[1]=計算用の縦の座標
// board配列でtrueが通路、falseが壁、外周は必ず壁で囲まれている

// 返り値
// 移動不可：返り値0
// 移動可能：x,y変数を更新し、返り値1を返す
int move(int *x, int *y, int z, int width, int height, bool board[WIDTH][HEIGHT]) {
    int xy[2];
    xy[0] = *x;
    xy[1] = *y;

    printf("%d:%d\n", xy[0], xy[1]);

    // z == 1の場合　　1 % 2 == 1なのでz % 2 == 0に当てはまらないから、xy[1 % 2]++;
    // z == 2の場合　　2 % 2 == 0なのでz % 2 == 0に当てはまるから、xy[2 % 2]--;
    // z % 2 == 0 ? xy[z / 2 - 1]-- : xy[z / 2]++;
    if (z == 1)
        xy[1]--;
    else if (z == 2)
        xy[1]++;
    else if (z == 3)
        xy[0]++;
    else if (z == 4)
        xy[0]--;

    printf("%d:%d\n", xy[0], xy[1]);

    // キャラクターの移動先がboard配列、つまり迷路の中かどうかを判定している
    if ((width > xy[0] && xy[0] > 0) && (height > xy[1] && xy[1] > 0)) {
        // キャラクターの移動先が通路であるか判定している
        if (board[xy[0]][xy[1]] == false) {
            *x = xy[0];
            *y = xy[1];
            return 1;
        }
    }
    
    return 0;
}