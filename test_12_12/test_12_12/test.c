#define _CRT_SECURE_NO_WARNINGS 1
//��һ���ַ���str�����ݵߵ��������������
//����
//I am a student
//���
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


//ʵ��һ�����������������ַ����е�k���ַ���
//���磺
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
//str��Ҫ��ת���ַ���n����ת���ַ�����
#if 0
void Reverse_part(char* str, int n)
{
	int len = strlen(str);
	n = n % len;//Ų������
	for (int i = 0; i < n; i++)//��ʼŲ��
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
void leftReverse1(char* str, int n)//���ηַ�
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

//���0��100000֮������С�ˮ�ɻ������������
//��ˮ�ɻ�������ָһ��nλ�������λ���ֵ�n�η�֮��ȷ�õ��ڸ�������
// �� : 153��1 ^ 3��5 ^ 3��3 ^ 3����153��һ����ˮ�ɻ���
void Func()
{
	for (int i = 0; i < 9999999; i++)
	{
		//1.������ж���λ
		int count = 0;
		int temp = i;
		while (temp != 0)
		{
			count++;
			temp = temp / 10;
		}
		//���ÿһλ����
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