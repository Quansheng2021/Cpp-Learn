#include<iostream>
using namespace std;

template <typename type1>void A(type1  a, type1  b) {
	cout << "A(a,b)" << endl;
};
template <typename type1>void A(type1& a, type1& b) {
	cout << "A(&,&)" << endl;
};
template <typename type1>void A(type1* a, type1* b) {
	cout << "A(*,*)" << endl;
};
template <typename type1>void A(type1 a, type1 b, type1 c) {
	cout << "A(a,b,c)" << endl;
};
template <typename type1>void A(type1& a, type1& b,type1& c) {
	cout << "A(&,&,&)" << endl;
};


void A(char&  a, char&  b) {
	cout << "A(char&,char&)" << endl;
};
void A(char* a, char* b) {
	cout << "A(char,char)" << endl;
}
void A(int a, int b) {
	cout << "A(int,int)" << endl;
}

template void A(string, string);

int main() {
	int a = 1, b = 2; 
	char i = 'i', j = 'j';

	//1，优先级最高的匹配数量和类型的普通函数
	A(i, j);				//A(char&, char&)
	A(&i, &j);			 //A(char, char)
	A(100, 200);		 //A(int, int)

	//2，匹配数量和类型的模板函数
	A(a, b, 3);			//A(a, b, c)
	A(a,b); 				 //A(int, int)
	A(&a, &b);		//A(*, *)
	A("e", "c");		 //A(*, *)
	A<>("e", "c");	//A(*, *)

	cin.get();
}
