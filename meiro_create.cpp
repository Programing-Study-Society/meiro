// �Q�l�����Fhttps://qiita.com/zurazurataicho/items/1435b7236b6b1ca34334

// �t�@�C���̃C���N���[�h
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

// �}�N���̒�`
#define ROAD false
#define WALL true
#define MEIRO_FILENAME "meiro_data.txt"

// ���H�����i���@��@�j
void make_maze(int, int);
int rand_odd(int);
void maze();
void maze_init();
void init();

// ���H�̓��o��
void output();
void input();
void make();
void load();

// �O���[�o���ϐ��̒�`
bool map[WIDTH][HEIGHT];

// �\���̂��g�p�����z��̒�`
struct {
    int x;
    int y;
} dir[] = {
    {0, -1}, // ��
    {0, 1},  // ��
    {-1, 0}, // ��
    {1, 0}   // �E
};

// ���H�쐬
void make_maze(int x, int y)
{
    // �@��i�߂���������߂�
    int d = rand() % 4;
    int dd = d;

    // �@��i�߂鏈��
    while (1) {
        // ����p�̍��W���Z�o
        int px = x + dir[d].x * 2;
        int py = y + dir[d].y * 2;
        // �@��Ȃ��͈͂�����i�����@��Ȃ��͈͂Ȃ�j
        if (px < 0 || px >= WIDTH || py < 0 || py >= HEIGHT || map[px][py] != WALL) {
            d++; // �@�������90�x��]
            if (d == 4)
                d = 0;
            // �ŏ��̌����ɖ߂��Ă����� = 4�����S��
            if (d == dd)
                return;
            continue;
        }
        // �����@��i�߂�
        map[x + dir[d].x][y + dir[d].y] = ROAD;
        map[px][py] = ROAD;
        make_maze(px, py);
        d = dd = rand() % 4;
    }
}

// ������̗�������
int rand_odd(int mod)
{
    int r = 1 + rand() % mod;
    if (r % 2 == 0)
        r++;
    if (r > mod)
        r -= 2;
    return r;
}

// ���H�쐬�̋N�_
void maze()
{
    int x = rand_odd(WIDTH - 2);
    int y = rand_odd(HEIGHT - 2);
    make_maze(x, y);
}

// map�ϐ��̏�����(�ǂŖ��߂�)
void maze_init()
{
    int x, y;

    for (y = 0; y < HEIGHT; y++)
        for (x = 0; x < WIDTH; x++)
            map[x][y] = WALL;
}

// �����̏�����
void init()
{
    time_t t;
    time(&t);
    srand(t);
}

// ���H�̏o��
void output()
{
    FILE* wfp;
    int x, y;

    wfp = fopen(MEIRO_FILENAME, "w");
    if (wfp == NULL)
    {
        printf("���H�̏o�͏����Ńt�@�C�����I�[�v���ł��܂���ł���");
        return;
    }
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++)
            fprintf(wfp, "%d", map[x][y]);
        fprintf(wfp, "%s", "\n");
    }
    fclose(wfp);
}

// ���H�̓���
void input()
{
    FILE* ofp;
    char output[WIDTH + 1];
    int x, y;

    ofp = fopen(MEIRO_FILENAME, "r");
    if (ofp == NULL)
    {
        printf("���H�̓��͏����Ńt�@�C�����I�[�v���ł��܂���ł���");
        return;
    }
    for (y = 0; fscanf(ofp, "%s", &output) != EOF && y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
        {
            map[x][y] = output[x] - '0';
        }
    }
    fclose(ofp);
}

// ���H�̍쐬
void make()
{
    init();
    maze_init();
    maze();
    output();
    character(map);
}

// ���H�̓ǂݍ���
void load()
{
    input();
    character(map);
}