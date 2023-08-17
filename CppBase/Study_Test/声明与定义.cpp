#include<iostream>
using namespace std;

int a=5; //定义一个整型数
int* p; //定义一个指向整型数的指针
int** pp; //定义一个指向指针的指针，它指向的指针指向一个整型数​

int arr[] = {11,22,33,44,55,66,77,88,99,00}; //定义一个包含10个整型数的数组
int(*pArr)[size(arr)];
//定义一个指向整型数数组的指针,长度等于arr数组长度,使用size的对象必须初始化


int main() {
	cout<<(p = &a)<<endl;   // p指向整数a所在的地址
	cout<<(pp = &p)<<endl;  // pp指向指针p

	pArr = &arr; 
	cout << size(arr) << endl;
	cout << arr[8] << endl;; //定义一个包含10个整型数的数组
	cout<<(*pArr)[8]<<endl; //

	cin.get();
}






