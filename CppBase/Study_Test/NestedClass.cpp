//类的嵌套
#include<iostream>
int b;
int& Money=b;

class MM {
public:
	int age = 22;
	int& MmMoney;
	//static std::string FirstName="Li";		   错误: 无法在类或结构体中初始化静态数据成员
	//在 C++ 中，static 关键字用于类成员或函数时表示该成员或函数属于类本身，而不是类的实例。
	//然而，你在全局作用域中使用 static 是不正确的，因为 static 在全局作用域中表示内部链接，而不是类成员。
	//	①如果你在类中定义静态成员变量，需要在类外初始化。
	//	②如果你在全局作用域中定义变量，通常不需要 static，除非你有特定的链接性需求。
	static std::string FirstName ;

	MM(int ageArg, int& MmMoneyArg) :age(ageArg), MmMoney(MmMoneyArg) {};//这里 : 是在构造函数中快速初始化参数列表
	void printLog(){ std::cout << "全局变量Money在MM类中地址" << &Money << std::endl; }

	class Son {
		public:
			
		int SonAge;
		int& SonMoney;
		Son(int SonAgeArg, int& SonMoneyArg) :SonAge(SonAgeArg), SonMoney(SonMoneyArg) {};

		std::string SecondName = FirstName; //如果静态成员变量没有初始化,则会出现奇怪的报错, "无法解析的外部符号"	 ,所以在36行初始化
		//std::string SName = MM::FName 嵌套类的,内部类访问外部类的静态成员可以不加定义域 
		void printLog() { std::cout << "全局变量Money在Son类中地址" << &Money << std::endl; }
	};

};

std::string FirstName = "Li";

int main() {
	std::cout << "全局变量b地址" << &b << std::endl;
	std::cout << "全局变量b的值" << b << std::endl;
	std::cout << "全局变量Money = &b后，Money的地址" << &Money << std::endl;

	b = 1000;

	MM LiHong(25, Money);
	std::cout << LiHong.MmMoney<< std::endl;
	std::cout << "对象LiHong.MmMoney地址" << &LiHong.MmMoney << std::endl;

	MM::Son XiaoMing(6,Money);
	std::cout <<XiaoMing.SonMoney<< std::endl;
	std::cout << "对象XiaoMing.SonMoney地址" << &XiaoMing.SonMoney << std::endl;
	std::cout << "对象XiaoMing.SName的值" << XiaoMing.SecondName << std::endl;
	std::cin.get();
}