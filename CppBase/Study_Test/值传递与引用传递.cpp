
#include <iostream>
using namespace std;

void swap_pot1(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

void swap_pot2(int* x, int* y) {
	int *temp;
	temp = x;
	x = y;
	y = temp;
}

void swap_ref(int& x, int& y) {
	int temp;
	temp = x;
	x = y;
	y = temp;
}

int main()
{

	int a = 10;
	int b = 20;
	swap_pot1(&a, &b);
	cout << a << endl;
	cout << b << endl;

	swap_pot2(&a, &b);
	cout << a << endl;
	cout << b << endl;

	swap_ref(a, b);
	cout << a << endl;
	cout << b << endl;
	cin.get();
}

