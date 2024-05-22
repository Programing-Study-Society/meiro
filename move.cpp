#include <stdio.h>
#include "main.h"

// �L�����̈ړ�����
int move(int* x, int* y, int z, bool board[WIDTH][HEIGHT]) {
    int xy[2] = { *x, *y };

    // ���͕����Ɉړ�
    if (z == 1)
        xy[1]--;
    else if (z == 2)
        xy[1]++;
    else if (z == 3)
        xy[0]++;
    else if (z == 4)
        xy[0]--;

    // ���͕����Ɉړ��\������
    if ((WIDTH > xy[0] && xy[0] > 0) && (HEIGHT > xy[1] && xy[1] > 0)) {
        // �ړ��\�Ȃ�ړ�
        if (board[xy[0]][xy[1]] == false) {
            *x = xy[0];
            *y = xy[1];
            return 1;
        }
    }

    return 0;
}