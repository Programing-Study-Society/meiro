#include <stdio.h>
#include "main.h"

// ゴール判定
int goal(int x, int y) {
    // キャラがゴールにいるか判定
    if (x == GOAL_X && y == GOAL_Y)
        return 1;
    return 0;
}