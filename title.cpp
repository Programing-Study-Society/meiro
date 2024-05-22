#include<iostream>
#include<stdio.h>
#include<string>
#include "meiro_create.h"
#include "timescore.h"

using namespace std;

// main関数
int main(void)
{
    //make();
    //print();

    int select; // 選択肢
    void (*func_ptr[])(void) = {make, load, showScoreRanking}; // 関数(ポインタ)を要素に持つ配列
    int length = sizeof(func_ptr) / sizeof(func_ptr[0]); // 配列(func_ptr)の大きさ

    // 選択肢の入力
    do
    {
        printf("選択肢を数字で入力してください\n");
        printf("0：迷路を生成してプレイ\n1：迷路を読み込んでプレイ\n2：ランキングを表示\n>>");
        scanf("%d", &select);
    } while (select < 0 || (length - 1) < select);

    // 選ばれた選択肢の関数を実行
    func_ptr[select]();

    return 0;
}