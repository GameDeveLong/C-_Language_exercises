#define _CRT_SECURE_NO_WARNINGS 1

//�ҵ���2
//һ��������ֻ�����������ǳ���һ�Σ������������ֶ����������Ρ�
//��дһ�������ҳ�������ֻ����һ�ε����֡�
//��
//�������Ԫ���ǣ�1��2��3��4��5��1��2��3��4��6
//ֻ��5��6ֻ����1�Σ�Ҫ�ҳ�5��6
 
#include<stdio.h>
#include<assert.h>
#if 0
void FindNum(int arr[], int n, int* num1, int* num2)
{
	//�����������
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		ret ^= arr[i];
	}
	//�ҵ�ret����һλΪ0
	int pos = 0;
	for (int i = 0; i < 32; i++)
	{
		if ((ret >> i) & 1 == 1)
		{
			pos = i;
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if ((arr[i] >> pos) & 1 == 1)
		{
			*num1 ^= arr[i];
		}
		else
		{
			*num2 ^= arr[i];
		}
	}
}
int main()
{
	int arr[] = { 1,2,3,4,5,1,2,3,4,6 };
	int len = sizeof(arr) / sizeof(arr[0]);
	int num1 = 0;
	int num2 = 0;
	FindNum(arr,len, &num1, &num2);
	printf("%d,%d",num1,num2);
	return 0;
}

// ģ��ʵ��strncpy
char* my_strncpy(char* dest, char* src, size_t n)
{
	int i = 0;
	for (i = 0; i < n && src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	if (i < n)
	{
		dest[i] = '\0';
	}
	return dest;
}
int main()
{
	char* dest[30] = {0};
	char* src = "hello";
	my_strncpy(dest, src, 3);
	printf("%s\n", dest);
	return 0;
}
#endif
//atoiģ��ʵ��
int MYatoi(char* str)
{
	assert(str);
	//�ж���û�пո�
	while (isspace(*str))
	{
		str++;
	}
	//������
	int flag = 1;
	if ((*str == '+'))
	{
		flag = 1;
		str++;
	}
	else if ((*str == '-'))
	{
		flag = -1;
		str++;
	}
	int ret = 0;
	 while ((*str != '\0'))
	{
		 if (isdigit(*str))
		 {
			 ret = ret * 10 + (*str - '0') * flag;
		 }
		 else
		 {
			 return ret;
		 }
		 str++;
	}
	 return ret;
}
int main()
{
	//int ret = atoi("-12a3");
	int ret = MYatoi("-12a3");
	printf("%d\n", ret);
	return 0;
}