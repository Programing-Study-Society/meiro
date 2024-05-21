#pragma once
#define WIDTH 49
#define HEIGHT 49
#define START_X 1
#define START_Y	1
#define GOAL_X WIDTH - 1
#define GOAL_Y HEIGHT - 1

int move(int* x, int* y, int z, bool board[WIDTH][HEIGHT]);
void map_print(int x, int y, bool board[WIDTH][HEIGHT]);
int goal(int x, int y);
void character(bool board[WIDTH][HEIGHT]);