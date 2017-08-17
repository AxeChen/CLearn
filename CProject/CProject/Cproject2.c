// CProject.cpp : 定义控制台应用程序的入口点。
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

//////////////指针的定义和运算//////////////////////

int test1() {
	int a = 10;
	//int *p = &a;
	//定义一个P指针
	int *p;
	//printf("*p: %#x\n", p);// 直接使用没有初始化的变量会无法编译
	p = &a;
	printf("*p: %#x\n", p);// 可以打印出a的地址
	*p = *p + 10;
	printf("p: %d, a: %d\n", *p, a); // *p 代表a a就是a 都发生改变 都是20

	int y = 1 + *p;
	printf("y: %d\n", y); //21 在上面的计算中 *p等于20 
	*p += 1; // 21 因为上面的计算 *p等于 20 所以 *p等21 同样 a也等于21
	printf("p: %d, a: %d\n", *p, a); // 

	(*p)++;  //22 
	*p++; //指针运算  这里将指针向前移四个字节  *p将变成一个不认识的值  
	printf("p: %d, a: %d, p address: %#x\n", *p, a, p);  // *p22 a 22 但是 p的二进制向前移四个字节
	//*(p++); == p++; *p;
	//1+2 * 3
	printf(" a address: %#x\n",&a); // a的地址还是不变。 为什么上面明明执行了 *p++ 而a的地址任然不变呢？ 因为我是申明一个新的指针变量*p
	                                // 改变的是*p的值,没有去改变&a的地址
	system("pause");
	return 0;
}


/////////////////////////数组与指针/////////////////////////////

int test2() {
	//数组名，就是数组的首地址   a+5 就相当于数组移动到第五个位置
	//因此 a+i = a[i]  
	int a[5] = {1,2,3,4,5};
	int *p;
	p = a;

	int i;
	printf("%#x\n", a);
	// a+5 ，表示a 移动到数组的第5个位置
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

/////////////////////////指针变量名////////////////////////////////
//指针变量都是用于存地址的，而地址都是用4个字节的数字表示的。所以，指针变量都是占用4个字节
int test3(){
	int a = 10;
	int *p = &a;
	printf("p address: %#x\n", p);  // p为指针变量名 输出一个二进制地址
	p++;
	printf("p address: %#x\n", p);   // p向前移动四个字节（一个int）

	//p 是一个指针变量名
	//*p 是从p指针变量里面取出一个int 型数据
	
	char *cp = "Hello Dongnao";
	printf("cp address: %#x\n", cp); //cp 为地址 而地址都是用4个字节的数字表示的。所以，指针变量都是占用4个字节
	cp++;
	printf("cp address: %#x\n", cp);
	printf("sizeof p = %d, sizof cp = %d", sizeof(p), sizeof(cp)); //都是4 因为地址都是用4个字节的数字表示的
	
	system("pause");
	return 0;
}

/////////////////////////////////指针数组，数组指针///////////////////////
int test4() {
	//指针数组， 指针名字为数组的第一个元素的地址。
	char *name[] = { "hello", "dongNao", "Alvin", "world" };

	int i, n = 4;
	sortt(name, n);
	for (i = 0; i < n; i++){
		printf("%s\n", name[i]);
	}

	// 数组指针
	// p2 指向的是？指向的是一个数组，一个有5个元素的数组
	//char(*p2)[5];
	//p2 是一个指针变量名
	system("pause");
	return 0;
}

// 参数，是char 类型的指针数组
//name[i]是一个指针（通过指针地址进行排序）
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

////////////////////////// 二级指针///////////////////////////
// 二级指针，存的内容是一个一级指针的地址
// p 的值就是 p 这个变量，这个变量保存的是p 的地址
// *p 运算，得到的就是a 的值
// *p2 运算，得到的就是p的值
//**p2 运算，得到的就是 p的值的 *运算得到的值 a；
int test5() {
	int a = 100;
	int *p;  // p是a的一级指针
	p = &a;

	int **p2; // p2是p的一级指针是a的二级指针  
	p2 = &p;

	//int ***p3;
	//p3 = &p2;
	//***p3 = p2
	//int * * p3;
	return 0;
}

//////////////////////////////指针和函数参数//////////////////////////////////

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
 //形参的修改不能带来这个实产的修改
 //将a b 的地址copy 给了 形参，然后，将这个份copy 的地址进行了切换，而地址所指的值是没有变的
void swap2(int *a, int *b) {
	printf("swap2 a address: %#x, b address: %#x \n", a, b);
	int *temp;
	temp = a; // a address 给了temp
	a = b;    // a 的地址变成了b的地址
	b = temp;  //b 的地址变成了a 的地址
	printf("swap2 a address: %#x, b address: %#x \n", a, b);
}

void swap3(int *a, int *b) {
	int temp;
	temp = *a;
	*a = *b;  // *a  代表是a所指的地址上面的值
	*b = temp; // 将 b 所在地址的值变成了temp
}
