#pragma once
#define RANKING_NUM 3
#define RANKING_NAME_MAX 32
#define SCORE_FILENAME "meiro_score.txt"

//�^�C�}�[�O���[�o���ϐ�
extern unsigned int startTime;
extern unsigned int stopTime;

//�^�C�}�[�X�^�[�g/�X�g�b�v
void startTimer();
void stopTimer();

//�X�R�A�\��/�o�^�@��ʓ]��
void showScoreRegist();
void showScoreRanking();