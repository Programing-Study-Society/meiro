#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "main.h"

#define ROAD false
#define WALL true

void make_maze(int, int);
int rand_odd(int);
void maze();
void maze_init();
void init();
void print();
void output();
void input();
void make();
void load();

bool map[WIDTH][HEIGHT];
struct {
    int x;
    int y;
} dir[] = {
    {0, -1}, // 上
    {0, 1},  // 下
    {-1, 0}, // 左
    {1, 0}   // 右
};

// 迷路作成
void make_maze(int x, int y)
{
    // 掘り進める方向を決める
    int d = rand() % 4;
    int dd = d;

    // 掘り進める処理
    while (1) {
        // 判定用の座標を算出
        int px = x + dir[d].x * 2;
        int py = y + dir[d].y * 2;
        // 掘れない範囲か判定（もし掘れない範囲なら）
        if (px < 0 || px >= WIDTH || py < 0 || py >= HEIGHT || map[px][py] != WALL) {
            d++; // 掘る向きを90度回転
            if (d == 4)
                d = 0;
            // 最初の向きに戻ってきたら = 4方向全滅
            if (d == dd)
                return;
            continue;
        }
        // 道を掘り進める
        map[x + dir[d].x][y + dir[d].y] = ROAD;
        map[px][py] = ROAD;
        make_maze(px, py);
        d = dd = rand() % 4;
    }
}

// 奇数だけの乱数生成
int rand_odd(int mod)
{
    int r = 1 + rand() % mod;
    if (r % 2 == 0)
        r++;
    if (r > mod)
        r -= 2;
    return r;
}

// 迷路作成の起点
void maze()
{
    int x = rand_odd(WIDTH - 2);
    int y = rand_odd(HEIGHT - 2);
    make_maze(x, y);
}

// map変数の初期化(壁で埋める)
void maze_init()
{
    int x, y;

    for (y = 0; y < HEIGHT; y++)
        for (x = 0; x < WIDTH; x++)
            map[x][y] = WALL;
}

// 乱数の初期化
void init()
{
    time_t t;
    time(&t);
    srand(t);
}

// 迷路の表示
void print()
{
    int x, y;
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++)
            printf("%s", (map[x][y] == WALL) ? "■" : " ");
        printf("\n");
    }
}

// 迷路の出力
void output()
{
    FILE* wfp;
    int x, y;

    wfp = fopen("meiro-data.txt", "w");
    if (wfp == NULL)
    {
        printf("迷路の出力処理でファイルがオープンできませんでした");
        return;
    }
    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++)
            fprintf(wfp, "%d", map[x][y]);
        fprintf(wfp, "%s", "\n");
    }
    fclose(wfp);
}

// 迷路の入力
void input()
{
    FILE* ofp;
    char output[WIDTH + 1];
    int x, y;

    ofp = fopen("meiro-data.txt", "r");
    if (ofp == NULL)
    {
        printf("迷路の入力処理でファイルがオープンできませんでした");
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

void make()
{
    init();
    maze_init();
    maze();
    output();
}

void load()
{
    input();
}

void main()
{
    make();
    character(map);
}