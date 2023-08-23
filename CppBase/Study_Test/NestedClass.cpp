#include<iostream>
int b;
int& Money=b;

class MM {
public:
	int age = 22;
	int& MmMoney;
	static std::string FName;
	MM(int ageArg, int& MmMoneyArg) :age(ageArg), MmMoney(MmMoneyArg) {};
	void printLog(){ std::cout << "全局变量Money在MM类中地址" << &Money << std::endl; }

	class Son {
		public:
			Son(int SonAgeArg,int& SonMoneyArg) :SonAge(SonAgeArg), SonMoney(SonMoneyArg) {};
		int SonAge;
		int& SonMoney;
		std::string SName = FName; //如果静态成员变量没有初始化,则会出现奇怪的报错, "无法解析的外部符号"
		//std::string SName = MM::FName 嵌套类的,内部类访问外部类的静态成员可以不加定义域 
		void printLog() { std::cout << "全局变量Money在Son类中地址" << &Money << std::endl; }
	};

};

std::string MM::FName = "Li";


int main() {
	std::cout << "全局变量b地址" << &b << std::endl;
	std::cout << "全局变量b的值" << b << std::endl;
	std::cout << "全局变量Money = &b后的地址" << &Money << std::endl;

	b = 1000;

	MM LiHong(25, Money);
	std::cout << LiHong.MmMoney<< std::endl;
	std::cout << "对象LiHong.MmMoney地址" << &LiHong.MmMoney << std::endl;

	MM::Son XiaoMing(6,Money);
	std::cout <<XiaoMing.SonMoney<< std::endl;
	std::cout << "对象XiaoMing.SonMoney地址" << &XiaoMing.SonMoney << std::endl;
	std::cout << "对象XiaoMing.SName的值" << XiaoMing.SName << std::endl;
	std::cin.get();
}