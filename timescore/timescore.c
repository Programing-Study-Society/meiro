#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include "timescore.h"
unsigned int startTime = 0;
unsigned int stopTime = 0;

int getSecondsFromScore(int score);
int getScoreSeconds();
void printFormattedTime(int milliseconds);
int getScoreFromFile(int* score, char name[][RANKING_NAME_MAX]);
void sortScore(int* score, char name[][RANKING_NAME_MAX], int rankingNum);
int insertScore(int* score, char name[][RANKING_NAME_MAX], int rankingNum, int newScore, char* newName, int index);
int canRegist(int newScore);
int registScoreToFile(int newScore, char* newName);

//public

void startTimer() {
	startTime = (unsigned int)time(NULL);
}

void stopTimer() {
	stopTime = (unsigned int)time(NULL);
}

void showScoreRegist() {
	system("cls");
	int score = getScoreSeconds(), doContinueInt, doRegistInt;
	char name[RANKING_NAME_MAX];
	if (score < 0) {
		printf("error code = %d\n", score);
		return;
	}
	printf("クリアタイム: ");
	printFormattedTime(score);

	doRegistInt = canRegist(score);
	if (doRegistInt == -1) {
		printf("\nランキングファイル(%s)を読み込めませんでした。\n", SCORE_FILENAME);
	}

	if (doRegistInt >= 0) {
		printf("\nあなたの名前を入力してください: ");
		scanf("%s", name);
		printf("クリアタイム: ");
		printFormattedTime(score);
		printf("\n名前: %s\n以上の情報をランキングに登録します。よろしいですか？ (1 = 登録する | それ以外 = 登録しない): ", name);
		scanf("%d", &doContinueInt);
		if (doContinueInt == 1) {
			int exitCode = registScoreToFile(score, name);
			if (exitCode == -1) printf("ランキングファイル(%s)を読み込めませんでした。\n", SCORE_FILENAME);
			getchar();
		}
		else {
			printf("ランキングに登録しませんでした。\n");
		}
	}
	printf("Enterを押して続行: ");
	getchar();
}

void showScoreRanking() {
	int score[RANKING_NUM], rankingNum;
	char name[RANKING_NUM][RANKING_NAME_MAX];
	rankingNum = getScoreFromFile(score, name);
	if (rankingNum == -1) {
		printf("ランキングファイル(%s)を読み込めませんでした。\n", SCORE_FILENAME);
		printf("Enterを押して続行: ");
		getchar();
		return;
	}
	printf("順位\t時間\t名前\n");
	for (int i = 0; i < rankingNum; i++) {
		printf("%d位: ", i + 1);
		printFormattedTime(score[i]);
		printf(": %s\n", name[i]);
	}
	printf("Enterを押して続行: ");
	getchar();
}

//private

int getScoreSeconds() {
	if (startTime == 0 || stopTime == 0) return -1;
	return getSecondsFromScore(stopTime - startTime);
}

int getSecondsFromScore(int score) {
	return score;
}

void printFormattedTime(int seconds) {
	int hours, minutes, remainingSeconds;

	hours = seconds / 3600;  // 1時間 = 3600秒
	seconds = seconds % 3600;  // 残りの秒数を計算
	minutes = seconds / 60;  // 1分 = 60秒
	remainingSeconds = seconds % 60;

	printf("%d時間%d分%d秒", hours, minutes, remainingSeconds);
}

int getScoreFromFile(int* score, char name[][RANKING_NAME_MAX]) {
	FILE* fp;
	int scoreTemp, rankingNum = 0;
	char nameTemp[RANKING_NAME_MAX];

	fp = fopen(SCORE_FILENAME, "r");
	if (fp == NULL) return -1;

	for (int i = 0; i < RANKING_NUM && fscanf(fp, "%d", &scoreTemp) != EOF; i++) {
		rankingNum = i + 1;

		score[i] = scoreTemp;

		fscanf(fp, "%s", nameTemp);

		strcpy(name[i], nameTemp);
	}

	fclose(fp);
	return rankingNum;
}

int writeScoreToFile(int* score, char name[][RANKING_NAME_MAX], int rankingNum) {
	FILE* fp;
	fp = fopen(SCORE_FILENAME, "w");
	if (fp == NULL) return -1;

	for (int i = 0; i < rankingNum; i++) {
		fprintf(fp, "%d %s\n", score[i], name[i]);
	}

	fclose(fp);
	return 0;
}

void sortScore(int* score, char name[][RANKING_NAME_MAX], int rankingNum) {
	char nameTemp[RANKING_NAME_MAX];
	for (int i = 0; i < rankingNum; i++) {
		for (int j = i; j < rankingNum; j++) {
			if (score[j] < score[i]) {
				//スコア入れ替え
				//XOR Swap
				score[j] ^= score[i];
				score[i] ^= score[j];
				score[j] ^= score[i];

				//名前入れ替え
				strcpy(nameTemp, name[i]);
				strcpy(name[i], name[j]);
				strcpy(name[j], nameTemp);
			}
		}
	}
}

int insertScore(int* score, char name[][RANKING_NAME_MAX], int rankingNum, int newScore, char* newName, int index) {
	if (rankingNum < RANKING_NUM) {
		rankingNum += 1;
	}
	if (rankingNum == 0) {
		score[0] = newScore;
		strcpy(name[0], newName);
	}
	else if (index == rankingNum) {
		score[index] = newScore;
		strcpy(name[index], newName);
	}
	else {
		for (int i = rankingNum - 1; i > index; i--) {
			score[i] = score[i - 1];
			strcpy(name[i], name[i - 1]);
		}
		score[index] = newScore;
		strcpy(name[index], newName);
	}
	return rankingNum;
}

int canRegist(int newScore) {
	FILE* fp;
	int score[RANKING_NUM], i;
	char name[RANKING_NUM][RANKING_NAME_MAX];

	int rankingNum = getScoreFromFile(score, name);
	if (rankingNum == -1) return -1;
	if (rankingNum == 0) return 0;

	for (i = 0; i < rankingNum; i++) {
		if (score[i] > newScore) {
			return i;
		}
	}

	if (i < RANKING_NUM) {
		return i;
	}

	return -2;
}

int registScoreToFile(int newScore, char* newName) {
	int score[RANKING_NUM], index, writeResult;
	char name[RANKING_NUM][RANKING_NAME_MAX];
	bool didRegist = false;

	int rankingNum = getScoreFromFile(score, name);
	if (rankingNum == -1) return -1;

	sortScore(score, name, rankingNum);

	index = canRegist(newScore);
	if (index == -2) return 0;
	if (index == -1) return -1;

	rankingNum = insertScore(score, name, rankingNum, newScore, newName, index);
	writeResult = writeScoreToFile(score, name, rankingNum);
	if (writeResult == -1) return -1;

	return 1;
}