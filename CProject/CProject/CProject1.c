// CProject.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>



/////////������������///////////////////
//������������
//int short long float double char bool 
//�ַ�ת��
//short int %d
//long %ld
//floag %f
//double %lf
//char %c

//////////�����÷�///////
//c���Ե����飬��������ʱ�����ȷ����С�ͻ�������
//void a() {
//	//int[] arr; ����java��д������C���в�ͨ
//	//int[] arr; ���û���ƶ���С��Ҳ�޷�����ͨ��
//	int arrt[10];
//	//��c������ ������һ���ǳ���Ҫ�ĸ��
//	char *b = "sdfsdfd";
//}

///////����ʹ��ָ��///////
//& ȡ��ַ���������������ڴ��еĶ������棬������������Ԫ��
//* ���Ѱַ���������������
//��Ŀ�����

int maissn() {
	int i = 10;
	int *p;
	p = &i;

	printf("i value: %d\n", i); // 10
	printf("i �ĵ�ַ��%#x \n", &i); // ��ַ������
	printf("p �ĵ�ַ��%#x \n", &p); // ָ��ĵ�ַ ������
	printf("i ����*ȡֵ%d\n",*p);  //10



	printf("sizeof(*p) %d\n", sizeof(*p));// int��ռ�ĸ��ֽ� Ϊ4

	double f = 23.99f;
	double * fp;
	fp = &f;
	printf("f ���ڴ棺%d \n", sizeof(f)); // doubleռ8���ֽ� 8
	// fp ��һ��������ָ��double ���͵����ݵı���
	// fp �Ǵ洢�� ��ַ����ַ��ռ��4���ֽڵġ�32 λ 4 * 8
	
	printf("sizeof(fp) %d\n", sizeof(fp)); //���еĵ�ַ����int���� ռ�ĸ��ֽ� 4
	printf("f �ĵ�ַ��%#x \n", &f);  // �����Ƶ�ַ
	printf("fp ��ֵ��%#x \n", fp);  // �����Ƶ�ַ
	printf("*fp ��ֵ��%#x \n", *fp);  // �����Ƶ�ַ
	printf("fpi �ĵ�ַ��%#x \n", &fp); // ��ַ�ĵ�ַ 

	system("pause");

	//����֪ʶ�㣬 1��* �� & ������   2��ָ��ĵ�ַ����ռ�ĸ��ֽ�


	return 0;
}
