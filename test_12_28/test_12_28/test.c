#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#if 0
//数组名的理解
//一般来说 数组名表示首元素的地址，但有两个例外
//1.sizeof(数组名)，sizeof括号内部单独放数组名，这时候数组名表示整个数组，计算的是
//整个数组的大小，单位是字节
//2.&数组名，这里的数组名表示整个数组，取出的是整个数组的地址
int main()
{
	int a[] = { 1,2,3,4 };//a数组里有4个元素
	printf("%zd\n", sizeof(a));
	//16- sizeof(数组名)，计算的是整个数组的大小，单位是字节，所以是16
	printf("%zd\n", sizeof(a + 0));//sizeof里面，没有单独放数组名，这时候a表示的是数组首地址
	//a+0也表示的是地址(int*)类型，结果是-4/8(环境不同，值就不同)
	printf("%zd\n", sizeof(*a));
	//a表示的是数组首地址，*a就是首元素，大小就是4个字节
	printf("%zd\n", sizeof(a + 1));
	//a+1表示的是数组第二个元素的地址，地址大小就是4/8个字节
	printf("%zd\n", sizeof(a[1]));
	//a[1]表示的是数组第二个元素，大小是4个字节
	printf("%zd\n", sizeof(&a));
	//&a取出整个数组的地址，sizeof计算的是地址，也就是4/8个字节
	printf("%zd\n", sizeof(*&a));
	//sizeof(*&a)==sizeof(a),计算结果是16 单位是字节
	printf("%zd\n", sizeof(&a + 1));
	//&a + 1是跳过整个数组，但是也是表示地址，地址的大小是 4/8个字节
	printf("%zd\n", sizeof(&a[0]));
	//&a[0]表示的是数组首元素的地址，地址的大小是 4/8个字节
	printf("%zd\n", sizeof(&a[0] + 1));
	//&a[0] + 1表示的是数组的二个元素的地址，地址的大小是 4/8个字节
	return 0;
}
#include<stdio.h>
int main()
{
	char* p = "abcdef";
	printf("%zd\n", sizeof(p));
	//计算p这个指针变量的大小，4/8个字节
	printf("%zd\n", sizeof(p + 1));
	//是字符b的地址，是地址就是4/8个字节
	printf("%zd\n", sizeof(*p));
	//*p表示的是字符a，大小是1个字节
	printf("%zd\n", sizeof(p[0]));
	//p[0]==*p，大小就是1个字节
	printf("%zd\n", sizeof(&p));
	//&p也是地址，是指针变量p的地址，大小是4/8个字节
	printf("%zd\n", sizeof(&p + 1));
	//&p + 1跳过的*p这个指针变量，指向的p后面的空间，也是地址，大小是4/8个字节
	printf("%zd\n", sizeof(&p[0] + 1));
	//&p[0] + 1是字符b的地址，是地址是4/8个字节
	return 0;
}

#include<stdio.h>
int main()
{
	int a[3][4] = { 0 };
	printf("%zd\n", sizeof(a));
	//a数组有12个元素，sizeof计算结果是48单位是字节
	printf("%zd\n", sizeof(a[0][0]));
	//a[0][0]表示第一个元素，大小是4个字节
	printf("%zd\n", sizeof(a[0]));
	//a[0]表示的是第一行的数组名，计算的是第一行的大小，单位是字节，16个字节
	printf("%zd\n", sizeof(a[0] + 1));
	//a[0]表示的是第一行的数组名，这里表示的是数组首元素
	//a[0] + 1是a[0][1]的地址，大小是4/8个字节
	printf("%zd\n", sizeof(*(a[0] + 1)));
	//a[0] + 1是a[0][1]的地址，*(a[0] + 1)就是a[0][1]，大小就是4个字节
	printf("%zd\n", sizeof(a + 1));
	//a是数组首元素的地址，a+1就是第二行的地址，大小是4/8个字节
	printf("%zd\n", sizeof(*(a + 1)));
	//*(a + 1)==a[1]-第二行的数组名，sizeof(a[1])，计算的是第二行的大小，16字节
	printf("%zd\n", sizeof(&a[0] + 1));
	//&a[0] + 1-第二行的地址，大小是4/8个字节
	printf("%zd\n", sizeof(*(&a[0] + 1)));
	//&a[0] + 1-第二行的地址，*(&a[0] + 1)访问的是第二行，大小是16个字节
	printf("%zd\n", sizeof(*a));
	//a是第一行的地址，*a是第一行，sizeof(*a)计算的是第一行的大小，大小是16单位是字节
	printf("%zd\n", sizeof(a[3]));
	//这里并不会越界，因为sizeof并不会参与运算，sizeof只会分析类型
    //sizeof(a[3])计算的是第四行的大小，大小是16个字节
	return 0;
}
#include <stdio.h>
int main()
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int* ptr = (int*)(&a + 1);
	printf("%d,%d", *(a + 1), *(ptr - 1));
	return 0;
}
#include <stdio.h>
int main()
{
	int a[5][5];
	int(*p)[4];
	//p是数组指针，指向的是数组4个int类型的元素
	p = a;
	printf("%p,%d\n", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	return 0;
}
#endif
#include <stdio.h>
int main()
{
	int aa[2][5] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int* ptr1 = (int*)(&aa + 1);
	int* ptr2 = (int*)(*(aa + 1));
	printf("*(ptr1 - 1)= %d\n", *(ptr1 - 1));
	printf("*(ptr2 - 1)= %d\n", *(ptr2 - 1));
	return 0;
}