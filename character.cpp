#include <stdio.h>
#include<stdlib.h>
#include "main.h"
#include "timescore.h"

void character(bool board[WIDTH][HEIGHT]) {
    int x = START_X, y = START_Y, z = 0;
    startTimer();
    do {
        // ���H�̕\��
        map_print(x, y, board);
        // �ړ������̓���
        printf("�ړ���������͂��Ă�������(1:��, 2:��, 3:�E, 4:��)\n���́F");
        scanf("%d", &z);
        system("cls"); // mac�Ȃ�clrscr()
        // ���̗͂�O����
        if (z < 1 || z > 4)
            printf("\x1b[31m�z��O�̒l�����͂���܂����ē��͂��Ă�������\x1b[0m\n");
        // �ړ������A�ړ��s�Ȃ�G���[
        if (move(&x, &y, z, board) == 0)
            printf("\x1b[33m���͂��ꂽ�����ɂ͈ړ��ł��܂���\n�ē��͂��Ă�������\x1b[0m\n");
        // �S�[������܂Ń��[�v
    } while (goal(x, y) == 0);
    stopTimer();
    printf("�S�[���I���߂łƂ��������܂��I\n");
    showScoreRegist();
};