#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>

void test3_1();
int plus(int a,int b);
int minus(int c,int b);
int plus2(int *a, int *b);
char plus3(char *a, char *b);
void test3_3();

//int main() {
//	test3_3();
//	system("pause");
//	return 0;
//}

////////////////////函数指针////////////////////////
// 操作步骤：1、明确需要调用函数的参数类型和返回类型 int plus(int a,int b)
//           2、定义和参数返回类型一致的指针，然后将参数列表加在后面 int(*calc)(int b, int c)
//           3、指针==函数名 calc = plus
//           4、通过指针调用函数 calc(a, b)

void test3_1() {
	//加法运算
	int result;
	int a = 3;
	int b = 5;
	int(*calc)(int b, int c);
	calc = plus;
	result = calc(a, b);
    printf("result: %d\n", result);

	//减法运算
	int result2;
	int e = 3;
	int f = 4;
	calc = minus;
	result2 = calc(a, b);
	printf("result: %d\n", result2);

	//传入指针的运算
	int result3;
	int aa = 3;
	int bb = 4;
	int(*calc2)(int *a,int *b);
	//calc2 = plus2;
	calc2 = (int(*)(void *, void *))plus2;
	result3 = calc2(&aa,&bb);
	printf("result: %d\n", result3);

	char result4;
	char cc = '3';
	char dd = '4';
	char(*calc3)(char *cc, char *dd);
	calc3 = plus3;
	result4 = calc3(&cc, &dd);
	printf("result: %c\n", result4);


}

int minus(int a, int b) {
	return a - b;
}

int plus(int a, int b) {
	return a + b;
}

//传入指针
int plus2(int *a, int *b) {
	return *a + *b;
}


char plus3(char *a, char *b) {
	return 'v';
}

/////////////////////////内存分配 //////////////////////////
//c语言和java不一样，c语言在使用大内存时需要手动分配
/*
	C语言的内存分为三块：
	1、程序区：程序的二进制文件。
	2、静态存储区：全局变量和静态变量。
	3、动态存储区：
	a、堆区：用于程序动态分配
	b、栈区：编译器自动分配，编译器自动申请和释放
*/
void test3_2() {
	// 40M 的数组
	//栈溢出
	//int t = 1000;
	//int aa[10]; 
	//int ab[100];
	/*while (1) {
		mem();
		Sleep(2000);
	}*/

	//动态内存分配（malloc）
	int *a = (int *)malloc(sizeof(int) * 1024 * 1024);
	if (a == NULL)
	{
		printf("内存不够，请温柔\n");
	} 
	//手动释放 1、调用free方法 2、将a = null
	if (a!=NULL) {
		free(a);
		a = NULL;
	}

	//动态内存分配（calloc）
		int * b = (int *)calloc(4, 100 * sizeof(int));
		if (b == NULL)
		{
			printf("内存不够，请温柔\n");
		}
//		printf("%#x", b);
		if (b!=NULL) {
			free(b);
			b = NULL;
		}
	// malloc 和 calloc的区别
		// void* malloc(size_t size) 分配大小为 size的连续空间
		// void* calloc(size_t _Count,size_t _Size) 申请count个内存空间，总大小为size
		// 两者如果申请内存失败，返回null
}

/////////////////字符串///////////////////////////////////
//1、首先 c语言中是没有字符串的
//2、 字符串的表示方式 char *str = "hello word";
//3、char *str = "hello word"; 和 char str[20] = "hello word"; 看起来很像，真的是一样的吗？
//   不一样。 定义的*str为普通字符指针， 当char *str = "hello word"时，并没有定义空间来存放"abc",所以编译器需要先找个地方来存放"abc".
//   显然这里的"abc"为常量，放在了常量区，因此去修改这个值 char *str = "hello word";  *str = "111";会报错。
//   而char str[20] = "hello word" 就不一样了，声明的时候定义了大小，因此能修改它的值。

void test3_3() {
	char *str = "hello word";
	//*str = "111";  这句代码执行会立即报错
	printf("%s\n", str);

	//字符串的常用方法
	char destination[25];
	char *blank = "    ", *c = "C++", *Borland = "Borland";
	strcpy(destination, Borland);  // 将 *Borland 复制 给destination
	strcat(destination, blank); // 将 blank拼接到 destination后面
	strcat(destination, c);
	printf("%s\n", destination);
}