# CLearn
学习c语言的一些代码  
为学习jni这块做准备。  
开发工具：vs2015
#### 8月16号
c语言基本类型、数组、指针基本运用等。  

#### 8月17号
函数指针、字符串、内存分配等。
* 函数指针  
> 操作步骤：1、明确需要调用函数的参数类型和返回类型 int plus(int a,int b)
          2、定义和参数返回类型一致的指针，然后将参数列表加在后面 int(*calc)(int b, int c)  
           3、指针==函数名 calc = plus  
           4、通过指针调用函数 calc(a, b)   
```
void test3_1() {
	//加法运算
	int result;
	int a = 3;
	int b = 5;
	int(*calc)(int b, int c);
	calc = plus;
	result = calc(a, b);
    printf("result: %d\n", result);
}

int plus(int a, int b) {
	return a + b;
}
```

* 内存分配  
> C语言的内存分为三块：  
> 1、程序区：程序的二进制文件。  
> 2、静态存储区：全局变量和静态变量。  
> 3、动态存储区：  
> a、堆区：用于程序动态分配  
> b、栈区：编译器自动分配，编译器自动申请和释放  

* 字符串  
> 1、首先 c语言中是没有字符串的  
> 2、 字符串的表示方式 char *str = "hello word";  
> 3、char *str = "hello word"; 和 char str[20] = "hello word"; 看起来很像，真的是一样的吗？  
>   不一样。 定义的*str为普通字符指针， 当char *str = "hello word"时，并没有定义空间来存放"abc",所以编译器需要先找个地方来存放"abc".  
>   显然这里的"abc"为常量，放在了常量区，因此去修改这个值 char *str = "hello word";  *str = "111";会报错。  
>   而char str[20] = "hello word" 就不一样了，声明的时候定义了大小，因此能修改它的值。  
```
void test3_3() {
	char *str = "hello word";
	//*str = "111";  这句代码执行会立即报错
	printf("%s\n", str);

	//字符串的常用方法
	char destination[25];
	char *blank = "    ", *c = "C++", *Borland = "Borland";
	strcpy(destination, Borland);  // 将 *Borland 复制 给destination
        strcat(destination, blank); // 将 blank拼接到 destination后面
	strcat(destination, c);
	printf("%s\n", destination);
}
```
#### 8月20号
* 结构体  
三种初始化方式：  
```
//第一种
struct People {
	char name[10];
	int age;
}lucy = { "dd",2 };


int test4_1() {
	//第二种
        struct People people = {"xl",28};
	printf(" people1 %s   %d \n",people.name,people.age);

	//第三种
        struct People2 people2;
	people2.age = 15;
	strcpy(people2.name,"axe");

	printf(" people2 %s   %d \n", people2.name, people2.age);
	return 0;
}

```
* 结构体数组
```
void test4_2() {
	//初始化1
	struct People peo[3] = { {"a",30},{"b",20},{"c",60} };
	for (int i = 0;i<3;i++) {
		printf(" people%d    %s   %d \n",i, peo[i].name, peo[i].age);
	}
	//printf("peo address: %#x\n", peo);
	//初始化2
	struct People peo1[4];
	for (int i = 0;i<4;i++) {
		peo1[i].age = 10;
		strcpy(peo1[i].name, "lucy");
	}
	for (int i = 0; i<4; i++) {
		printf(" people%d    %s   %d \n", i, peo1[i].name, peo1[i].age);
	}
}
```

* 结构体指针  
```
void test4_2() {
        struct People3 *ppeo3;
	ppeo3 = (struct People3 *)malloc(sizeof(struct People3) * 1);
	memset(ppeo3, 0, sizeof(struct People3) * 1);
	ppeo3->age = 10;
	ppeo3->name = "ha sa ki";
	printf(" People3 :   %s   %d \n", ppeo3->name, ppeo3->age);
}
```

* 结构体指针数组  
两种初始化：
1、直接等于一个数组  
2、定义一个新的数组  
a）定义一个指针结构体数组  struct People3 *ppeo2;  
b）分配内存 ppeo2 = (struct People3 *)malloc(sizeof(struct People3)*4);  
c） 初始化memset(ppeo2, 0, sizeof(struct People3) * 4);  

```
void test4_2() {
	//初始化1
	struct People peo[3] = { {"a",30},{"b",20},{"c",60} };

	//第一种初始化
	struct People *ppeo1 = peo;

	// 第二种初始化
	//1、定义
	struct People3 *ppeo2;
	//2、分配内存
	ppeo2 = (struct People3 *)malloc(sizeof(struct People3)*4);
	//3、初始化（memset给系统内存进行赋值）
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
```

* 结构体中添加函数指针 

用法和函数指针一样，只是这个是在结构体中使用。  
```
struct Man {
	int age;
	char *name;
	int(*Msg)(char *, int);
};
```
* 结构体中添加结构体指针
注意： 为什么是结构体指针 ? 因为结构体中只能包含结构体指针！！  
具体实现：源码中单链表的实现。  
```
struct Node {
	int data;
	struct Node *next; // 结构体中只能存在结构体指针
};
```
           


