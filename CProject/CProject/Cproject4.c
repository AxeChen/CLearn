#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#include "string.h"
#include <Windows.h>


////////////////////�ṹ��////////////////////////
//�ṹ������������
/** �ؼ��֣� struct
1��struct People
2���û����Ž���Ա������
3������������������ṹ��ı�������
**/
struct People {
	char name[10];
	int age;
}lucy = { "dd",2 }; //�����ֳ�ʼ��

struct People2 {
	char name[10];
	int age;
}people3 = {"dd",2};
// people2 Ϊȫ�ֵ������Ľṹ������

struct People3 {
	char *name;
	int age;
};

int test4_1() {
	//��һ�ֳ�ʼ��
	struct People people = {"xl",28};
	printf(" people1 %s   %d \n",people.name,people.age);

	//�ڶ��ֳ�ʼ��
	struct People2 people2;
	people2.age = 15;
	strcpy(people2.name,"axe");

	printf(" people2 %s   %d \n", people2.name, people2.age);
	return 0;
}

////////////////////�ṹ������////////////////////////
void test4_2() {
	//��ʼ��1
	struct People peo[3] = { {"a",30},{"b",20},{"c",60} };
	for (int i = 0;i<3;i++) {
		printf(" people%d    %s   %d \n",i, peo[i].name, peo[i].age);
	}
	//printf("peo address: %#x\n", peo);
	//��ʼ��2
	struct People peo1[4];
	for (int i = 0;i<4;i++) {
		peo1[i].age = 10;
		strcpy(peo1[i].name, "lucy");
	}
	for (int i = 0; i<4; i++) {
		printf(" people%d    %s   %d \n", i, peo1[i].name, peo1[i].age);
	}
	//�ṹָ������

	//�����ṹ��ָ��
	struct People3 *ppeo3;
	ppeo3 = (struct People3 *)malloc(sizeof(struct People3) * 1);
	memset(ppeo3, 0, sizeof(struct People3) * 1);
	ppeo3->age = 10;
	ppeo3->name = "ha sa ki";
	printf(" People3 :   %s   %d \n", ppeo3->name, ppeo3->age);

	//��һ�ֳ�ʼ��
	struct People *ppeo1 = peo;

	// �ڶ��ֳ�ʼ��
	//1������
	struct People3 *ppeo2;
	//2�������ڴ�
	ppeo2 = (struct People3 *)malloc(sizeof(struct People3)*4);
	//3����ʼ����memset��ϵͳ�ڴ���и�ֵ��
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

///////////////////////////////////�ṹ������Ӻ���ָ��///////////////////
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

///////////////////////////////////�ṹ������ӽṹ�����///////////////////
struct Node {
	int data;
	struct Node *next; // �ṹ����ֻ�ܴ��ڽṹ��ָ��
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
///////////////////////////////////�ṹ������ӽṹ�����(������)///////////////////
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

