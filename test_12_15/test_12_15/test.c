#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#include<stdlib.h>
//#include<time.h>
//void game()
//{
//	int guess = 0;
//	int ret = rand() % 100 + 1;
//	while (1)
//	{
//		printf("输入数字->:");
//		scanf("%d", &guess);
//		if (guess > ret)
//		{
//			printf("猜大了\n");
//		}
//		else if (guess < ret)
//		{
//			printf("猜小了\n");
//		}
//		else
//		{
//			printf("猜对了\n");
//			break;
//		}
//	}
//}
//void menu()
//{
//	printf("*************************\n");
//	printf("*************************\n");
//	printf("*******1.开始游戏********\n");
//	printf("*******0.退出游戏********\n");
//	printf("*************************\n");
//	printf("*************************\n");
//}
//int main()
//{
//	int input = 0;//选择开始或者退出
//	srand((unsigned int)time(NULL));
//	do
//	{
//		menu();
//		printf("请选择->");
//		scanf("%d", &input);
//		switch (input)
//		{
//		case 1:
//			game();
//			break;
//		case 0:
//			printf("游戏结束\n");
//			break;
//		default:
//			printf("选择错误，请重新选择\n");
//			break;
//		}
//	} while (input);
//	return 0;
//}

//练习1：多个字符从两端移动，向中间汇聚
//编写代码，演⽰多个字符从两端移动，向中间汇聚
#include<stdio.h>
#include<windows.h>
#include<string.h>
int main()
{
	char arr1[] = "xxxxxxxxxxx";
	char arr2[] = "hello world";
	int left = 0;
	int right = strlen(arr1)-1;
	printf("%s\n", arr1);
	while (left <= right)
	{
		Sleep(1000);
		arr1[left] = arr2[left];
		arr1[right] = arr2[right];
		left++;
		right--;
		Sleep(1000);
		printf("%s\n", arr1);
	}
	return 0;
}
//#include <stdio.h>
//int main()
//{
//	char arr1[] = "welcome to bit...";
//	char arr2[] = "#################";
//	int left = 0;
//	int right = strlen(arr1) - 1;
//	printf("%s\n", arr2);
//	while (left <= right)
//	{
//		Sleep(1000);
//		arr2[left] = arr1[left];
//		arr2[right] = arr1[right];
//		left++;
//		right--;
//		printf("%s\n", arr2);
//	}
//	return 0;
//}