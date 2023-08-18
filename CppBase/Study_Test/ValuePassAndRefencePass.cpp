
#include <iostream>
using namespace std;

#pragma region 简单的示例
void swap_pot1(int *x, int *y) {
	cout << "swap_pot1形参int*类型，传入a,b实参后；x，y的值为地址" << x << "," << y << endl;
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
	cout << "swap_pot1执行后x，y的值" << x << "," << y << endl;
}

void swap_pot2(int* x, int* y) {
	cout << "swap_pot2形参int*类型，传入a,b实参后；x，y的值为地址" << x << "," << y << endl;
	int *temp;
	temp = x;
	x = y;
	y = temp;
	cout << "swap_pot2执行后x，y的值" << x << "," << y << endl;
}

void swap_ref(int& x, int& y) {
	cout << "swap_ref形参int&类型，传入a,b实参后；x，y等价于a,b" << x << "," << y << endl;
	cout << "swap_ref执行后x，y的值" << &x << "," << &y << endl;
	int temp;
	temp = x;
	x = y;
	y = temp;
	cout << "swap_ref执行后x，y的值" << &x << "," <<& y << endl;
}
#pragma endregion

int main()
{

	int a = 10;
	int b = 20;
	swap_pot1(&a, &b);
	cout <<"swap_pot1执行结果，交换成功" << a << "," << b << endl;
	cout << "此时a,b的地址" << &a << "," << &b << endl << endl;

	swap_pot2(&a, &b);
	cout <<  "swap_pot2执行结果交换失败" << a << "," << b << endl;
	cout << "此时a,b的地址" << &a << "," << &b << endl << endl;

	swap_ref(a, b);
	cout << "swap_ref执行结果，交换成功" << a << "," << b << endl;
	cout << "此时a,b的地址" << &a << "," << &b << endl << endl;
	cin.get();
}

