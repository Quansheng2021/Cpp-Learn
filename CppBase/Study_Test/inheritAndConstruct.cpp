#include<iostream>


class people {
public:
	int age;
	float heigh;
	//people(int agePar,float heighPar){
	//	age = agePar;
	//	heigh = heighPar;
	//	std::cout << "people构造函数" << std::endl;
	//}
	//上述与下面这个构造函数等价
	people(int agePar, float heighPar) :age(agePar), heigh(heighPar) {
		std::cout << "people构造函数" << std::endl;
	}

};

class stduent:public people {
public:
	int score;
	stduent(int agePar, float heighPar, int scorePar)
		:people(agePar, heighPar), score(scorePar)
	{
		std::cout << "stduent构造函数" << std::endl;
	}
};

class YoungStudent :public stduent {
public:
	bool hasToy=true;
	YoungStudent(bool hasToyPar,int a,float b, int c):stduent(a,b,c), hasToy(hasToyPar)
	{
		std::cout << "YoungStudent构造函数" << std::endl;
	}
};

void main() {
	people persona (36,168);
	stduent lihua(15,162,560);
	YoungStudent xiaoMing (false,10,20,30);
	std::cout << "-----------------------" << std::endl;
	std::cout <<"persona.age=" << persona.age <<"		persona.heigh=" << persona.heigh << std::endl;
	std::cout << " lihua.age=" << lihua.age << "		lihua.heigh=" << lihua.heigh <<"	lihua.score=" << lihua.score << std::endl;
	std::cout << " xiaoMing.age=" << xiaoMing.age << "		xiaoMing.heigh=" << xiaoMing.heigh << "		xiaoMing.score=" << xiaoMing.score <<"		xiaoMing.hasToy=" << xiaoMing .hasToy<< std::endl;

	std::cin.get();
}
