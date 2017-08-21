#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#include "string.h"
#include <Windows.h>


////////////////////结构体////////////////////////
//结构体声明方法，
/** 关键字： struct
1、struct People
2、用花括号将成员包起来
3、可以起别名（匿名结构体的变量名）
**/
struct People {
	char name[10];
	int age;
}lucy = { "dd",2 }; //第三种初始化

struct People2 {
	char name[10];
	int age;
}people3 = {"dd",2};
// people2 为全局的匿名的结构体名称

struct People3 {
	char *name;
	int age;
};

int test4_1() {
	//第一种初始化
	struct People people = {"xl",28};
	printf(" people1 %s   %d \n",people.name,people.age);

	//第二种初始化
	struct People2 people2;
	people2.age = 15;
	strcpy(people2.name,"axe");

	printf(" people2 %s   %d \n", people2.name, people2.age);
	return 0;
}

////////////////////结构体数组////////////////////////
void test4_2() {
	//初始化1
	struct People peo[3] = { {"a",30},{"b",20},{"c",60} };
	for (int i = 0;i<3;i++) {
		printf(" people%d    %s   %d \n",i, peo[i].name, peo[i].age);
	}
	//printf("peo address: %#x\n", peo);
	//初始化2
	struct People peo1[4];
	for (int i = 0;i<4;i++) {
		peo1[i].age = 10;
		strcpy(peo1[i].name, "lucy");
	}
	for (int i = 0; i<4; i++) {
		printf(" people%d    %s   %d \n", i, peo1[i].name, peo1[i].age);
	}
	//结构指针数组

	//单个结构体指针
	struct People3 *ppeo3;
	ppeo3 = (struct People3 *)malloc(sizeof(struct People3) * 1);
	memset(ppeo3, 0, sizeof(struct People3) * 1);
	ppeo3->age = 10;
	ppeo3->name = "ha sa ki";
	printf(" People3 :   %s   %d \n", ppeo3->name, ppeo3->age);

	//第一种初始化
	struct People *ppeo1 = peo;

	// 第二种初始化
	//1、定义
	struct People3 *ppeo2;
	//2、分配内存
	ppeo2 = (struct People3 *)malloc(sizeof(struct People3)*4);
	//3、初始化（memset给系统内存进行赋值）
	memset(ppeo2, 0, sizeof(struct People3) * 4);

	for (int i = 0; i < 4; i++) {
		(ppeo2 + i)->age = 20 + i;
		(ppeo2 + i)->name = "lucy";
	
		/*	ppeo[i].age = 20 + i;
			strcpy(peo1[i].name, "lucy");*/
	}

    for (int i = 0; i<4; i++) {
		printf(" people%d    %s   %d \n", i, ppeo2[i].name, ppeo2[i].age);
	}
}

///////////////////////////////////结构体中添加函数指针///////////////////
struct Man {
	int age;
	char *name;
	int(*Msg)(char *, int);
};

int message(char * str, int age) {
	MessageBox(0, TEXT("hello"), TEXT("Lijian"), 0);
	return 0;
}

void test4_3() {
	struct Man man;
	man.age = 10;
	man.Msg = message;
	man.name = "hehe";
	man.Msg("aa", 10);
}

///////////////////////////////////结构体中添加结构体变量///////////////////
struct Node {
	int data;
	struct Node *next; // 结构体中只能存在结构体指针
};

void test4_4() {
	struct Node node;
	node.data = 0;

	struct Node node2;
	node2.data = 1;
	node2.next = NULL;

	node.next = &node2;
	printf("%d",((node.next)->data));
}
///////////////////////////////////结构体中添加结构体变量(单链表)///////////////////
int enqueNode(struct Node *head, int data) {
	struct Node * node = (struct Node *)malloc(sizeof(struct Node));
	if (node == NULL) {
		return 0;
	}
	node->data = data;
	node->next = NULL;

	struct Node *p = head;
	while(p->next != NULL) {
		p = p->next;
	}

	p->next = node;
    /*	while (head->next != NULL) {
		head++;
	}*/
    return 1;
}

void test4_5() {
	struct Node * list;
	list = (struct Node *)malloc(sizeof(struct Node));
	list->data = 0;
	list->next = NULL;

	for (int i = 0; i < 10; i++) {
		enqueNode(list, i+1);
	}

	while (list->next != NULL)
	{
		printf("%d \n", list->data);
		list = list->next;
	}
}

//int main() {
//	//test4_1();
//	//test4_2();
//	//test4_3();
//	//test4_4();
//	test4_5();
//	system("pause");
//	return 0;
//}

