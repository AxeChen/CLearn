// CProject.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>

int test1();
int test2();
int test3();

int main() {

	test3();
	return 0;
}

//////////////ָ��Ķ��������//////////////////////

int test1() {
	int a = 10;
	//int *p = &a;
	//����һ��Pָ��
	int *p;
	//printf("*p: %#x\n", p);// ֱ��ʹ��û�г�ʼ���ı������޷�����
	p = &a;
	printf("*p: %#x\n", p);// ���Դ�ӡ��a�ĵ�ַ
	*p = *p + 10;
	printf("p: %d, a: %d\n", *p, a); // *p ����a a����a �������ı� ����20

	int y = 1 + *p;
	printf("y: %d\n", y); //21 ������ļ����� *p����20 
	*p += 1; // 21 ��Ϊ����ļ��� *p���� 20 ���� *p��21 ͬ�� aҲ����21
	printf("p: %d, a: %d\n", *p, a); // 

	(*p)++;  //22 
	*p++; //ָ������  ���ｫָ����ǰ���ĸ��ֽ�  *p�����һ������ʶ��ֵ  
	printf("p: %d, a: %d, p address: %#x\n", *p, a, p);  // *p22 a 22 ���� p�Ķ�������ǰ���ĸ��ֽ�
	//*(p++); == p++; *p;
	//1+2 * 3
	printf(" a address: %#x\n",&a); // a�ĵ�ַ���ǲ��䡣 Ϊʲô��������ִ���� *p++ ��a�ĵ�ַ��Ȼ�����أ� ��Ϊ��������һ���µ�ָ�����*p
	                                // �ı����*p��ֵ,û��ȥ�ı�&a�ĵ�ַ
	system("pause");
	return 0;
}


/////////////////////////������ָ��/////////////////////////////
int test2() {
	//������������������׵�ַ   a+5 ���൱�������ƶ��������λ��
	//��� a+i = a[i]  
	int a[5] = {1,2,3,4,5};
	int *p;
	p = a;

	int i;
	printf("%#x\n", a);
	// a+5 ����ʾa �ƶ�������ĵ�5��λ��
	for (i = 0; p < a + 5; p++)
	{
		*p = i;
		i++;
	}
	p = p + 1;
	p++;

	
	printf("p: %d\n", *p);

	/*a[i]  == *(p+i)
	&a[i] ==  a+i*/
	//p + i == &a[i] == a+i


	system("pause");
	return 0;
}

/////////////////////////ָ�������////////////////////////////////
//ָ������������ڴ��ַ�ģ�����ַ������4���ֽڵ����ֱ�ʾ�ġ����ԣ�ָ���������ռ��4���ֽ�
int test3(){
	int a = 10;

	int *p = &a;
	printf("p address: %#x\n", p); 
	p++;
	printf("p address: %#x\n", p);

	//p ��һ��ָ�������
	//*p �Ǵ�pָ���������ȡ��һ��int ������
	
	char *cp = "Hello Dongnao";
	printf("cp address: %#x\n", cp);
	cp++;
	printf("cp address: %#x\n", cp);
	printf("sizeof p = %d, sizof cp = %d", sizeof(p), sizeof(cp));
	
	system("pause");
	return 0;
}