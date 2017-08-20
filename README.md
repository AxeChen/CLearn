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

           


