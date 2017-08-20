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

////////////////////����ָ��////////////////////////
// �������裺1����ȷ��Ҫ���ú����Ĳ������ͺͷ������� int plus(int a,int b)
//           2������Ͳ�����������һ�µ�ָ�룬Ȼ�󽫲����б���ں��� int(*calc)(int b, int c)
//           3��ָ��==������ calc = plus
//           4��ͨ��ָ����ú��� calc(a, b)

void test3_1() {
	//�ӷ�����
	int result;
	int a = 3;
	int b = 5;
	int(*calc)(int b, int c);
	calc = plus;
	result = calc(a, b);
    printf("result: %d\n", result);

	//��������
	int result2;
	int e = 3;
	int f = 4;
	calc = minus;
	result2 = calc(a, b);
	printf("result: %d\n", result2);

	//����ָ�������
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

//����ָ��
int plus2(int *a, int *b) {
	return *a + *b;
}


char plus3(char *a, char *b) {
	return 'v';
}

/////////////////////////�ڴ���� //////////////////////////
//c���Ժ�java��һ����c������ʹ�ô��ڴ�ʱ��Ҫ�ֶ�����
/*
	C���Ե��ڴ��Ϊ���飺
	1��������������Ķ������ļ���
	2����̬�洢����ȫ�ֱ����;�̬������
	3����̬�洢����
	a�����������ڳ���̬����
	b��ջ�����������Զ����䣬�������Զ�������ͷ�
*/
void test3_2() {
	// 40M ������
	//ջ���
	//int t = 1000;
	//int aa[10]; 
	//int ab[100];
	/*while (1) {
		mem();
		Sleep(2000);
	}*/

	//��̬�ڴ���䣨malloc��
	int *a = (int *)malloc(sizeof(int) * 1024 * 1024);
	if (a == NULL)
	{
		printf("�ڴ治����������\n");
	} 
	//�ֶ��ͷ� 1������free���� 2����a = null
	if (a!=NULL) {
		free(a);
		a = NULL;
	}

	//��̬�ڴ���䣨calloc��
		int * b = (int *)calloc(4, 100 * sizeof(int));
		if (b == NULL)
		{
			printf("�ڴ治����������\n");
		}
//		printf("%#x", b);
		if (b!=NULL) {
			free(b);
			b = NULL;
		}
	// malloc �� calloc������
		// void* malloc(size_t size) �����СΪ size�������ռ�
		// void* calloc(size_t _Count,size_t _Size) ����count���ڴ�ռ䣬�ܴ�СΪsize
		// ������������ڴ�ʧ�ܣ�����null
}

/////////////////�ַ���///////////////////////////////////
//1������ c��������û���ַ�����
//2�� �ַ����ı�ʾ��ʽ char *str = "hello word";
//3��char *str = "hello word"; �� char str[20] = "hello word"; ���������������һ������
//   ��һ���� �����*strΪ��ͨ�ַ�ָ�룬 ��char *str = "hello word"ʱ����û�ж���ռ������"abc",���Ա�������Ҫ���Ҹ��ط������"abc".
//   ��Ȼ�����"abc"Ϊ�����������˳����������ȥ�޸����ֵ char *str = "hello word";  *str = "111";�ᱨ��
//   ��char str[20] = "hello word" �Ͳ�һ���ˣ�������ʱ�����˴�С��������޸�����ֵ��

void test3_3() {
	char *str = "hello word";
	//*str = "111";  ������ִ�л���������
	printf("%s\n", str);

	//�ַ����ĳ��÷���
	char destination[25];
	char *blank = "    ", *c = "C++", *Borland = "Borland";
	strcpy(destination, Borland);  // �� *Borland ���� ��destination
	strcat(destination, blank); // �� blankƴ�ӵ� destination����
	strcat(destination, c);
	printf("%s\n", destination);
}