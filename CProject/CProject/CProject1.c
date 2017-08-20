// CProject.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>



/////////基本数据类型///////////////////
//基本数据类型
//int short long float double char bool 
//字符转义
//short int %d
//long %ld
//floag %f
//double %lf
//char %c

//////////基础用法///////
//c语言的数组，再申明的时候必须确定大小和基本类型
//void a() {
//	//int[] arr; 这是java的写法，在C中行不通
//	//int[] arr; 如果没有制定大小，也无法编译通过
//	int arrt[10];
//	//在c语言中 数组是一个非常重要的概念。
//	char *b = "sdfsdfd";
//}

///////初次使用指针///////
//& 取地址操作符。运用在内存中的对象上面，即变量与数组元素
//* 间接寻址或者引用运算符。
//单目运算符

int maissn() {
	int i = 10;
	int *p;
	p = &i;

	printf("i value: %d\n", i); // 10
	printf("i 的地址：%#x \n", &i); // 地址二进制
	printf("p 的地址：%#x \n", &p); // 指针的地址 二进制
	printf("i 根据*取值%d\n",*p);  //10



	printf("sizeof(*p) %d\n", sizeof(*p));// int的占四个字节 为4

	double f = 23.99f;
	double * fp;
	fp = &f;
	printf("f 的内存：%d \n", sizeof(f)); // double占8个字节 8
	// fp 是一个变量，指向double 类型的数据的变量
	// fp 是存储的 地址，地址是占用4个字节的。32 位 4 * 8
	
	printf("sizeof(fp) %d\n", sizeof(fp)); //所有的地址都是int类型 占四个字节 4
	printf("f 的地址：%#x \n", &f);  // 二进制地址
	printf("fp 的值：%#x \n", fp);  // 二进制地址
	printf("*fp 的值：%#x \n", *fp);  // 二进制地址
	printf("fpi 的地址：%#x \n", &fp); // 地址的地址 

	system("pause");

	//几个知识点， 1、* 和 & 的区别   2、指针的地址都是占四个字节


	return 0;
}
