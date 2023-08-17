//错误(活动)	E0300	指向绑定函数的指针只能用于调用函数	
//尝试通过使用实例变量而不是类类型来限定成员用来创建指向成员的指针时，通常会导致错误
// 如果尝试使用错误的语法调用成员函数，也可能会看到此错误。

#include <iostream>

class A {
public:
	int func1() {
		return 0;
	}
}a;

class B : public A {
public:
	void mf() {
		//auto x = &this->func1; //Error
		// try the following line instead
		 auto x = &B::func1;
	}
};

int main() {
	//int(* pf)() = &(a.func1);  	//Error
	int (A::*pf)() = &A::func1;

	A a3;
	//auto pmf1 = &a3.func1; //Error
	auto pmf1 = &A::func1;
}