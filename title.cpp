#include<iostream>
#include<stdio.h>
#include<string>
#include "meiro_create.h"
#include "timescore.h"

using namespace std;

// main�֐�
int main(void)
{
    //make();
    //print();

    int select; // �I����
    void (*func_ptr[])(void) = {make, load, showScoreRanking}; // �֐�(�|�C���^)��v�f�Ɏ��z��
    int length = sizeof(func_ptr) / sizeof(func_ptr[0]); // �z��(func_ptr)�̑傫��

    // �I�����̓���
    do
    {
        printf("�I�����𐔎��œ��͂��Ă�������\n");
        printf("0�F���H�𐶐����ăv���C\n1�F���H��ǂݍ���Ńv���C\n2�F�����L���O��\��\n>>");
        scanf("%d", &select);
    } while (select < 0 || (length - 1) < select);

    // �I�΂ꂽ�I�����̊֐������s
    func_ptr[select]();

    return 0;
}