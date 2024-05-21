#include <stdio.h>

// Goalなら1、まだなら0

// 引数：x=キャラの横座標, y=キャラの縦座標, widthは迷路の横幅、heightは迷路の高さ
// ゴールの座標はwidth-1, heigth-1固定
int goal(int x, int y, int width, int height) {
    if (x == width - 1 && y == height - 1)
        return 1;
    return 0;
}