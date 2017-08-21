#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#include "string.h"
#include <Windows.h>

///////////////////////////typedef 指令////////////////////////
/*
通俗来讲就是起别名
下面的例子：
第一步： typedef int _in; 将int类型去别名 _in
第二步：_in a = 20; _in 就相当于 int
第三步：printf("%d", a); 就是输出一个int类型的值
*/
typedef int _in;

typedef char * string;

void test5_1() {
	_in a = 20;
	printf("%d", a);
}

////////////////////////////// 定义函数指针
typedef int(*PFI)(char *,char *);

void test5_2() {
	PFI pf = strcmp;
}

////////////////////////定义结构体指针

typedef struct Tnode * Treeptr;

//BinaryTreeNode 就代表这个结构体
typedef struct Tnode {
	char *word;
	int count;

	/*Tnode * left;
	Tnode * right;*/
	Treeptr left;
	Treeptr right;
} BinaryTreeNode;


// 稍微有点面向对象思维
void test5_3() {
	PFI pf = strcmp;
	BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
}



////////////////////共用体/////////////////////////
//将不同的数据类型的数据放到同一段内存里面。
// 共用体占用的内存取决于成员中最大的内存
// MyUnion 最大占用成员内存是 float 。
union MyUnion
{
	int a;
	char b;
	float c;
};

void test5_4() {

	union MyUnion unio;
	
	unio.a = 10;
	unio.b = 'a';
	unio.c = 1.2f;
	printf("a: %#x, b: %#x, c: %#x\n", &unio.a, &unio.b, &unio.c);
	printf("a: %d, b: %c, c: %f\n", unio.a, unio.b, unio.c);
}

//int main() {
//	test5_4();
//	system("pause");
//	return 0;
//}

///////枚举
enum {
	monday = 10,
    saturday,
    sunday,
};