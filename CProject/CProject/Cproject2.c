// CProject.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>

int test1();
int test2();
int test3();
int test4();
int test5();
int test5();

void sortt();
void swap();
void swap2();
void swap3();

//int main() {
//
//	test3();
//	return 0;
//}

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
	printf("p address: %#x\n", p);  // pΪָ������� ���һ�������Ƶ�ַ
	p++;
	printf("p address: %#x\n", p);   // p��ǰ�ƶ��ĸ��ֽڣ�һ��int��

	//p ��һ��ָ�������
	//*p �Ǵ�pָ���������ȡ��һ��int ������
	
	char *cp = "Hello Dongnao";
	printf("cp address: %#x\n", cp); //cp Ϊ��ַ ����ַ������4���ֽڵ����ֱ�ʾ�ġ����ԣ�ָ���������ռ��4���ֽ�
	cp++;
	printf("cp address: %#x\n", cp);
	printf("sizeof p = %d, sizof cp = %d", sizeof(p), sizeof(cp)); //����4 ��Ϊ��ַ������4���ֽڵ����ֱ�ʾ��
	
	system("pause");
	return 0;
}

/////////////////////////////////ָ�����飬����ָ��///////////////////////
int test4() {
	//ָ�����飬 ָ������Ϊ����ĵ�һ��Ԫ�صĵ�ַ��
	char *name[] = { "hello", "dongNao", "Alvin", "world" };

	int i, n = 4;
	sortt(name, n);
	for (i = 0; i < n; i++){
		printf("%s\n", name[i]);
	}

	// ����ָ��
	// p2 ָ����ǣ�ָ�����һ�����飬һ����5��Ԫ�ص�����
	//char(*p2)[5];
	//p2 ��һ��ָ�������
	system("pause");
	return 0;
}

// ��������char ���͵�ָ������
//name[i]��һ��ָ�루ͨ��ָ���ַ��������
void sortt(char *name[], int n) {
	char *temp;
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n - 1 - i; j++) {
			if (strcmp(name[j], name[j+1]) > 0)
			{
				temp = name[j];
				name[j] = name[j + 1];
				name[j + 1] = temp;
			}
		}
	}
}

////////////////////////// ����ָ��///////////////////////////
// ����ָ�룬���������һ��һ��ָ��ĵ�ַ
// p ��ֵ���� p �����������������������p �ĵ�ַ
// *p ���㣬�õ��ľ���a ��ֵ
// *p2 ���㣬�õ��ľ���p��ֵ
//**p2 ���㣬�õ��ľ��� p��ֵ�� *����õ���ֵ a��
int test5() {
	int a = 100;
	int *p;  // p��a��һ��ָ��
	p = &a;

	int **p2; // p2��p��һ��ָ����a�Ķ���ָ��  
	p2 = &p;

	//int ***p3;
	//p3 = &p2;
	//***p3 = p2
	//int * * p3;
	return 0;
}

//////////////////////////////ָ��ͺ�������//////////////////////////////////

int test6() {
	int a, b;
	a = 10;
	b = 5;
	printf("a address: %#x, b address: %#x \n", &a, &b);
	swap(a, b);//e = a; d = b;
	printf("a = %d, b = %d\n", a, b);
	swap2(&a, &b);//e = a; d = b;
	printf("a = %d, b = %d\n", a, b);
	swap3(&a, &b);//e = a; d = b;
	printf("a = %d, b = %d\n", a, b);
	system("pause");
	return 0;
}

void swap(int d, int e) {
	printf("d address: %#x, e address: %#x \n", &d, &e);
	int temp;
	temp = d;
	d = e;
	e = temp;
}
 //�βε��޸Ĳ��ܴ������ʵ�����޸�
 //��a b �ĵ�ַcopy ���� �βΣ�Ȼ�󣬽������copy �ĵ�ַ�������л�������ַ��ָ��ֵ��û�б��
void swap2(int *a, int *b) {
	printf("swap2 a address: %#x, b address: %#x \n", a, b);
	int *temp;
	temp = a; // a address ����temp
	a = b;    // a �ĵ�ַ�����b�ĵ�ַ
	b = temp;  //b �ĵ�ַ�����a �ĵ�ַ
	printf("swap2 a address: %#x, b address: %#x \n", a, b);
}

void swap3(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;  // *a  ������a��ָ�ĵ�ַ�����ֵ
	*b = temp; // �� b ���ڵ�ַ��ֵ�����temp
}
