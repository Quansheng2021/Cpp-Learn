#include <iostream>
//#变量的可见性和作用域：
//变量的可见性指的是变量在程序中能否被访问和使用的范围。
//变量的作用域指的是变量的有效范围，即变量在代码中的可见性区域。
// -全局作用域中的变量在整个程序中可见
// -类作用域中的变量由对象进行访问 class A{ int b }     A::b
// -块作用域中的变量在其所在的代码块内部可见
// -main函数的作用域中声明的局部变量，只能在main函数中使用
//变量的可见性和作用域由其声明的位置和存储类别（如全局变量、静态变量、局部变量等）决定

//#函数的可见性和作用域：
//函数的可见性指的是函数在程序中能否被调用和使用的范围。
//函数的作用域指的是函数的有效范围，即函数在代码中的可见性区域。
// -全局作用域中声明的全局函数，可以在整个程序中调用。
// -类作用域中声明的成员函数，也只能通过类的对象(实例化)进行调用。
//函数的可见性和作用域由其声明的位置、访问修饰符（如 private、protected、public）以及命名空间等因素决定。

void globFunc() {
	std::cout << " globFunc() 这是一个全局函数" << std::endl;
} //全局函数，可以在整个程序中调用

class globClass {
	public:
	class innerClass {
	public:	void innerClassInnerFunc() {
			std::cout << "innerClassInnerFunc() 这个是一个嵌套类内部的函数" << std::endl;
		}
	};

	static void globClassInnerFunc();//静态函数的定义必须在外部
	//为什么静态成员（函数，变量...）不能在类内部定义
	//因为静态成员属于整个类，而不属于某个对象，如果在类内初始化，会导致每个对象都包含该静态成员，这是矛盾的。
	//static const 可以在类里面初始化，是因为它既然是const的，那程序就不会再去试图初始化了。

};

void globClass::globClassInnerFunc() {
	std::cout << "globClassInnerFunc() 这是一个全局类内部的函数" << std::endl;
}//静态函数的定义必须在外部，定义的时候不用加上static, 直接通过域限定符进行定义

void main() {

	int x = 10; //全局变量，全局作用域中声明
	{
		int y = 20;
		std::cout << "Inner Block" << x << "," << y << std::endl;
	}
	std::cout << "Out Block" << x << std::endl;
	//std::cout << "Out Block" <<  y << std::endl; 
	//Error E0020	未定义标识符 "y"
	//无法访问变量 y

	globClass::globClassInnerFunc();//静态函数的调用，可以不用实例化类的对象

	globClass::innerClass innerClassInstance;//通过域限定符:: 来访问内部函数
	innerClassInstance.innerClassInnerFunc();

	std::cin.get();
}