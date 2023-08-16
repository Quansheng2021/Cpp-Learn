
#include <iostream>
#include <functional>
using namespace std;


typedef int(*FuncAddPtr)(int, int);
//using FuncAddPtr = int(*)(int, int);

int FuncAdd(int a, int b) {
	
	int c = a + b;
	std::cout << c << std::endl;
	return c;
}



int main() {
	auto FuncExecute=std::bind(FuncAdd,10,10);
	FuncExecute();
	FuncAddPtr methAddPtr = FuncAdd;
	methAddPtr(5, 6);
	system("pause");
}