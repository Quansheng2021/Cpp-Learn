#include<iostream>
using namespace std;

template <typename type1>void A(type1  a, type1  b) {
	cout << "A(a,b)" << endl;
};
template <typename type1>void B(type1  a, type1  b) {
	cout << "B(a,b)" << endl;
};
template void B(string a, string b); //Visual Studio 显示声明函数模板， 会出现警告（只是编译器的问题而已）

template <typename type1>void A(type1* a, type1* b) {
	cout << "A(*,*)" << endl;
};
template <typename type1>void A(type1 a, type1 b, type1 c) {
	cout << "A(a,b,c)" << endl;
};
template <typename type1>void A(type1& a, type1& b,type1& c) {
	cout << "A(&,&,&)" << endl;
};

void A(char* a, char* b) {
	cout << "A(char,char)" << endl;
}
void A(int a, int b) {
	cout << "A(int,int)" << endl;
}

// 通过函数指针 ，完成函数调用
void invoke(void (*func)(string, string)) {
	func("e", "c");
	(*func)("e", "c");
}
void InvokeTemplate(void(*func)(string, string), void(*func1)(string, string)) {
	func("e", "c");
	func1("e", "c");
}

int main() {
	int a = 1, b = 2; 
	char i = 'i', j = 'j';
#pragma region 根据函数名，和参数推演，模板实参 隐式/显示调用
	//隐式调用
	//1，优先级最高的匹配数量和类型的普通函数
	A(i, j);				//A(char&, char&)
	A(&i, &j);			 //A(char, char)
	A(100, 200);		 //A(int, int)
	//2，其次匹配数量和类型的模板函数
	A(a, b, 3);				//A(a, b, c)
	A(a,b); 					//A(int, int)
	A("e", "c");			//A(*, *)
	B('c', 'c');				//A(char,char)
	B('cc', 'cc');			//B(a,b)

	//显示调用
	A<int>(&a, &b);			//A(*, *)
	A<string>("e", "c");		//A(*, *)
#pragma endregion

#pragma region 使用函数指针 ，传递调用模板函数
	//函数指针 传递的不是一个普通的函数，传递的是模板函数 ，编译器就会寻找同名的模板函数进行参数推演
	invoke(A);			//A(a,b)  A(a,b)
	invoke(B);				//B(a,b) B(a,b)
	InvokeTemplate(A,A);		//结果是3个A(a,b）； InvokeTemplate调用一次模板函数，2个函数指针A分别调用一次模板函数
#pragma endregion 

	cin.get();
}