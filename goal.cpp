#include <stdio.h>
#include "main.h"

// �S�[������
int goal(int x, int y) {
    // �L�������S�[���ɂ��邩����
    if (x == GOAL_X && y == GOAL_Y)
        return 1;
    return 0;
}