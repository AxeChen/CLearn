// CProject.cpp : 定义控制台应用程序的入口点。
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
	printf("p address: %#x\n", p); 
	p++;
	printf("p address: %#x\n", p);

	//p 是一个指针变量名
	//*p 是从p指针变量里面取出一个int 型数据
	
	char *cp = "Hello Dongnao";
	printf("cp address: %#x\n", cp);
	cp++;
	printf("cp address: %#x\n", cp);
	printf("sizeof p = %d, sizof cp = %d", sizeof(p), sizeof(cp));
	
	system("pause");
	return 0;
}