#include <stdio.h>
#include "main.h"

// ƒS[ƒ‹”»’è
int goal(int x, int y) {
    // ƒLƒƒƒ‰‚ªƒS[ƒ‹‚É‚¢‚é‚©”»’è
    if (x == GOAL_X && y == GOAL_Y)
        return 1;
    return 0;
}