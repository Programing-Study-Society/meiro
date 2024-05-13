#pragma once
#define RANKING_NUM 3
#define RANKING_NAME_MAX 32
#define SCORE_FILENAME "meiro_score.txt"

//タイマーグローバル変数
extern unsigned int startTime;
extern unsigned int stopTime;

//タイマースタート/ストップ
void startTimer();
void stopTimer();

//スコア表示/登録　場面転換
void showScoreRegist();
void showScoreRanking();