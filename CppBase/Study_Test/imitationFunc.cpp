#include <iostream>

/*仿函数由来
函数的入参除了是普通变量之外，还可以是函数指针（C 语言中就经常这么用）。那有没有什么手段能代替函数指针呢？答案是有。

定义一个类，类里面定义了某个方法，将该类的对象作为函数的入参，那么在函数中就能调用这个类中的方法

还有更简单的方法吗？答案还是有。
定义一个类，类里面重载函数运算符（），将该类的对象作为函数的入参，那么在函数中同样能调用重载符（）里面的方法
所以说，仿函数就是仿造的函数，它并不是一个真正意义上的函数。它是一个类中的运算符（）重载，但它具有函数的功能。*/

class Compare {
private:
	int m_Number;
public:

	//其实构造函数有无冒号后面的初始化就相当于我们普通赋值变量的两种方式。
	// 所以带冒号的可以看作是括号赋值，无冒号的则是赋值运算符赋值。
	//而这两种方式的区别就在于，括号赋值是在给变量分配内存空间的同时对它进行初始化，
	//而赋值运算符赋值则是先分配内存空间，然后再初始化。说到底就是初始化的时机不同。
	
	Compare(int num) : m_Number(num) {}

	int b;

	bool operator()(int other)
	{
		b = other;
		return m_Number > other;
	}

	int PriVal() {
		return m_Number;
	}

	int otherVal() {
		return b;
	}

};


void swapFunc(int a, int b);

int main()
{
	Compare cmp(10);
	std::cout <<cmp.PriVal()<< std::endl;
	std::cout << cmp.otherVal() << std::endl;

	std::cout << cmp(11) << std::endl;
	std::cout << cmp.PriVal() << std::endl;
	std::cout << cmp.otherVal() << std::endl;
	std::cout << cmp(9) << std::endl;
	std::cout << cmp.PriVal() << std::endl;
	std::cout << cmp.otherVal() << std::endl;


	std::cout << "--------------" << std::endl;
	int swapAA = 1;
	int swapBB = 9;
	swapFunc(swapAA, swapBB);
	std::cout << "swap函数交换后" << std::endl;
	std::cout << swapAA << swapBB << std::endl;

	std::cin.get();
	return 0;


}