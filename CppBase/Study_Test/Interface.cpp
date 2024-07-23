#include <iostream>
using namespace std;

class IF_Consume
{
public:
	virtual void consume() = 0;
};

class little_Ming :public IF_Consume {
public:
	virtual void consume() override {
		cout << "小明消费了" << endl;
	}
};

class Mam
{
public:
	void GiveAllowance(IF_Consume* MoneyTar) {
		cout << "妈妈给钱了" << endl;
		MoneyTar->consume();
	}
};


void main() {
	Mam InsMam1;
	little_Ming* InsMing1=new little_Ming();
	InsMam1.GiveAllowance(InsMing1);
};


