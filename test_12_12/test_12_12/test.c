#define _CRT_SECURE_NO_WARNINGS 1
//将一个字符串str的内容颠倒过来，并输出。
//输入
//I am a student
//输出
//tneduts a ma I
#include <stdio.h>
#include<string.h>
//void Reverse(char* str)
//{
//    char* left = str;
//    char* right = str + strlen(str) - 1;
//    while (left < right)
//    {
//        char tmp = *left;
//        *left = *right;
//        *right = tmp;
//        left++;
//        right--;
//    }
//}
//int main() {
//    char arr[10000] = { 0 };
//    while (gets(arr) != NULL) 
//    { 
//        Reverse(arr);
//        printf("%s\n", arr);
//    }
//    return 0;
//}


//实现一个函数，可以左旋字符串中的k个字符。
//例如：
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
//str是要旋转的字符，n是旋转的字符个数
#if 0
void Reverse_part(char* str, int n)
{
	int len = strlen(str);
	n = n % len;//挪动次数
	for (int i = 0; i < n; i++)//开始挪动
	{
		char tmp = str[0];
		int j = 0;
		for (j = 0; j < len-1; j++)
		{
			str[j] = str[j + 1];
		}
		str[j] = tmp;
	}
}
void leftReverse(char* str, int n)
{
	int len = strlen(str);
	 int pos = n % len;
	char tmp[256] = { 0 };
	strcpy(tmp, str + pos);
	strncat(tmp, str, pos);
	strcpy(str,tmp);
}
void Reverse1(char* str,int start ,int end)
{
	int left = start;
	int right = end;
	while (left < right)
	{
		int temp = str[left];
		str[left] = str[right];
		str[right] = temp;
		left++;
		right--;
	}
}
void leftReverse1(char* str, int n)//三段分法
{

	int len = strlen(str);
	n = n % len;
	Reverse1(str, 0, n - 1);
	Reverse1(str, n, len - 1);
	Reverse1(str, 0, len-1);
}
int main()
{
	char arr[] = "ABCD";
	//Reverse_part(arr, 2);
	//printf("%s\n", arr);
	//leftReverse(arr, 2);
	leftReverse1(arr, 2);
	printf("%s\n", arr);
	return 0;
}
#endif

#include <stdio.h>
#include <math.h>
#include<string.h>
//void PrintMulTable(int n)
//{
//	int i = 0;
//	for (i = 0; i <= n; i++)
//	{
//		int j = 1;
//		for (j = 1; j <=i; j++)
//		{
//			printf("%d*%d=%2d  ", j, i, i * j);
//		}
//		printf("\n");
//	}
//}
//int main()
//{
//	PrintMulTable(9);
//	return 0;
//}

//求出0～100000之间的所有“水仙花数”并输出。
//“水仙花数”是指一个n位数，其各位数字的n次方之和确好等于该数本身，
// 如 : 153＝1 ^ 3＋5 ^ 3＋3 ^ 3，则153是一个“水仙花数
void Func()
{
	for (int i = 0; i < 9999999; i++)
	{
		//1.先求出有多少位
		int count = 0;
		int temp = i;
		while (temp != 0)
		{
			count++;
			temp = temp / 10;
		}
		//求出每一位的数
		temp = i;
		int sum = 0;
		while (temp != 0)
		{
			sum += pow(temp % 10, count);
			temp /= 10;
		}
		if (sum == i)
		{
			printf("%d\n", i);
		}
	}
}
int main()
{
	Func();
	return 0;
}