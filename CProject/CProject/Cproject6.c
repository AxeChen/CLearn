#include "stdafx.h"
#include <stdlib.h>
#include <stdio.h>

#include "string.h"
#include <Windows.h>

//////////////////////文件操作//////////////////////

/*
 读文件
*/
void test6_1() {
	// 获取文件路径
	char *path = "F:\\ctest\\testone.txt";

	//获取文件句柄
	FILE *fp = fopen(path, "r");

	//读文件
	char buff[500];
	while (fgets(buff, 50, fp))
	{
		printf("%s", buff);
	}
	// 完成文件操作后一定要关闭文件流
	fclose(fp);
}
/*
 写文件
*/
void test6_2() {
	//获取路径（如果该文件不存在，会自动创建）
	char *path = "F:\\ctest\\testtwo.txt";
	//获取文件句柄
	FILE *fp = fopen(path, "w");

	if (fp == NULL) {
		printf("failed。。。。");
		return 0;
	}
	
	char *text = "哈塞给，托里呀开通";
	//直接将文件写入
	fputs(text, fp);
	fclose(fp);
}

/*
  读写二进制文件（读写二进制文件（图片）和读写文本文件有很大的区别）
*/
void test6_3() {
	// 首先确定读写的路径
	char * read_path = "F:\\ctest\\damimi.jpeg";
	char * write_path = "F:\\ctest\\yangmi.jpeg";

	//读的句柄
	FILE * read_fp = fopen(read_path, "rb");
	//写的句柄
	FILE * write_fp = fopen(write_path, "wb");
	char buff[50];
	int len = 0;
	//读
	while ((len = fread(buff, sizeof(char), 50, read_fp)) != 0) 
	{
		// 写 
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