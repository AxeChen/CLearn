#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#include "string.h"
#include <Windows.h>

///////////////////////////typedef ָ��////////////////////////
/*
ͨ���������������
��������ӣ�
��һ���� typedef int _in; ��int����ȥ���� _in
�ڶ�����_in a = 20; _in ���൱�� int
��������printf("%d", a); �������һ��int���͵�ֵ
*/
typedef int _in;

typedef char * string;

void test5_1() {
	_in a = 20;
	printf("%d", a);
}

////////////////////////////// ���庯��ָ��
typedef int(*PFI)(char *,char *);

void test5_2() {
	PFI pf = strcmp;
}

////////////////////////����ṹ��ָ��

typedef struct Tnode * Treeptr;

//BinaryTreeNode �ʹ�������ṹ��
typedef struct Tnode {
	char *word;
	int count;

	/*Tnode * left;
	Tnode * right;*/
	Treeptr left;
	Treeptr right;
} BinaryTreeNode;


// ��΢�е��������˼ά
void test5_3() {
	PFI pf = strcmp;
	BinaryTreeNode *node = (BinaryTreeNode *)malloc(sizeof(BinaryTreeNode));
}



////////////////////������/////////////////////////
//����ͬ���������͵����ݷŵ�ͬһ���ڴ����档
// ������ռ�õ��ڴ�ȡ���ڳ�Ա�������ڴ�
// MyUnion ���ռ�ó�Ա�ڴ��� float ��
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

///////ö��
enum {
	monday = 10,
    saturday,
    sunday,
};