#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#include "string.h"
#include <Windows.h>

//////////////////////�ļ�����//////////////////////

/*
 ���ļ�
*/
void test6_1() {
	// ��ȡ�ļ�·��
	char *path = "F:\\ctest\\testone.txt";

	//��ȡ�ļ����
	FILE *fp = fopen(path, "r");

	//���ļ�
	char buff[500];
	while (fgets(buff, 50, fp))
	{
		printf("%s", buff);
	}
	// ����ļ�������һ��Ҫ�ر��ļ���
	fclose(fp);
}
/*
 д�ļ�
*/
void test6_2() {
	//��ȡ·����������ļ������ڣ����Զ�������
	char *path = "F:\\ctest\\testtwo.txt";
	//��ȡ�ļ����
	FILE *fp = fopen(path, "w");

	if (fp == NULL) {
		printf("failed��������");
		return 0;
	}
	
	char *text = "������������ѽ��ͨ";
	//ֱ�ӽ��ļ�д��
	fputs(text, fp);
	fclose(fp);
}

/*
  ��д�������ļ�����д�������ļ���ͼƬ���Ͷ�д�ı��ļ��кܴ������
*/
void test6_3() {
	// ����ȷ����д��·��
	char * read_path = "F:\\ctest\\damimi.jpeg";
	char * write_path = "F:\\ctest\\yangmi.jpeg";

	//���ľ��
	FILE * read_fp = fopen(read_path, "rb");
	//д�ľ��
	FILE * write_fp = fopen(write_path, "wb");
	char buff[50];
	int len = 0;
	//��
	while ((len = fread(buff, sizeof(char), 50, read_fp)) != 0) 
	{
		// д 
		fwrite(buff, sizeof(char), len, write_fp);
	}
	fclose(read_fp);
	fclose(write_fp);
	system("pause");
	return 0;
}


int main() {
	test6_3();
	system("pause");
	return 0;
}