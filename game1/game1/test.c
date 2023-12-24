#define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
void menu()
{
	printf("******************\n");
	printf("*******1.play*****\n");
	printf("*******0.exit*****\n");
	printf("******************\n");
}
void game()
{
	char ch = 0;
	char board[ROW][COL] = { 0 };
	//初始化棋盘.
	Initboard(board, ROW, COL);
	//打印棋盘
	Displayboard(board, ROW, COL);
	//下棋
	while (1)
	{
		PlayerMove(board, ROW, COL);//玩家
		ch=IsWin(board, ROW, COL);
		if (ch != 'c')
		{
			break;
		}
		Displayboard(board, ROW, COL);
		ComputerMove(board, ROW, COL);//电脑
		ch = IsWin(board, ROW, COL);
		if (ch != 'c')
		{
			break;
		}
		Displayboard(board, ROW, COL);
	}
	if (ch == '*')
	{
		printf("玩家赢了\n");
	}
	else if (ch == '#')
	{
		printf("电脑赢了\n");
	}
	else
	{
		printf("平局\n");
	}

}
int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:->");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		}
	} while (input);
	return 0;
}