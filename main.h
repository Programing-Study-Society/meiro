#pragma once
#define WIDTH 49
#define HEIGHT 49

int move(int *x, int *y, int z, int width, int height, bool board[WIDTH][HEIGHT]);
void map_print(int x, int y, int width, int height, bool board[WIDTH][HEIGHT]);
int goal(int x, int y, int width, int height);
void character(bool board[WIDTH][HEIGHT]);