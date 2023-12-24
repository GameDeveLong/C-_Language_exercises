#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROW 3
#define COL 3
//1.函数的声明
//初始化棋盘.
void Initboard(char board[ROW][COL], int row, int col);
//打印棋盘
void Displayboard(char board[ROW][COL], int row, int col);
//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col);
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col);
//判断输赢
//玩家赢--'*'
//电脑赢--'#'
//平局-- 'Q'
//继续--'c'
char IsWin(char board[ROW][COL], int row, int col);
