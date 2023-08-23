//左值 与 右值
// https://zhuanlan.zhihu.com/p/347538369
// https://zhuanlan.zhihu.com/p/335994370
// ------------------------------------------------------------------------------------------
//左值
// 占用一定内存，拥有可辨认的地址的对象 （可以获取地址）
// （简单理解）即可以出现在赋值语句左边和又可以出现在赋值语句右边的
// 是持久性的
// 对象被用作左值的时候，用的是对象的身份（内存中的位置）
// 使用右值的地方可以使用左值，但是使用左值的地方只能使用左值
// 左值引用就是我们平常使用的“引用”；引用一般只能绑定一个左值（绑定后不能改变，某种意义上可以看作常量指针），必须初始化

// ------------------------------------------------------------------------------------------
//右值
//左值以外的对象
// （简单理解）只能出现在赋值语句右边
// 是短暂的（要么是字面常量，要么是表达式过程中创建的临时对象，及将亡值）
// 右值引用，可以绑定右值，不能绑定左值；int &&ref = std::move(a)		std::move返回的"type && a"作为函数返回值是右值，  "ref"直接声明出来是左值；


#include <iostream>

int i = 42;
int j = 10;

int* pt = &i;
int& ref = i;//Error 引用必须初始化
//int& ref = 42; 
//int& ref = i * 24;
//Error ,非常量引用必须为左值 ，加上const作为常量引用后可以绑定右值
const int& ref1 = 42;
const int& ref2 = i * 24;

int&& ref_result=0;		//Error 右值引用必须初始化
//int&& ref = i;		// Error1768 无法将右值引用绑定到左值
int&& ref_result1 = std::move(i);		//可以通过move将左值转化为右值

int funcAdd( int& a, int& b) {
	return a + b;
}

void main() {

	std::cout << ref_result1 << std::endl;

	//ref_result = funcAdd(1, 2);		//Error 函数的参数是引用，实参必须是左值

	//将开辟一个变量a,b用来作为实参传递，但是效率低
	//可以修改函数的形参为 常量引用；int funcAdd( const int& a, const int& b)
	int a = 1, b = 2;
	ref_result = funcAdd(a,b);

	std::cout << ref_result <<"对右值引用取地址"<<&ref_result << std::endl;
	std::cin.get();
}