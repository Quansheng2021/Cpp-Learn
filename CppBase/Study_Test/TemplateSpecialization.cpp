#include<stdio.h>
#include<malloc.h>
#include<iostream>

using namespace std;

//模板特化
//template<>
//int compare<const char*>(const char* const p1, const char* const p2)
//{
//	return strcmp(p1, p2);
//}


template<typename  T> void swapAA(T& t1, T& t2) {
	T tmpT;
	tmpT = t1;
	t1 = t2;
	t2 = tmpT;
}

template<typename T, int N>
void FunTest(T(&_array)[N])
{
	for (int indx = 0; indx < N; ++indx) {
		_array[indx] = 0;
	}
}


template<class T, int nlength>
void Sort(T(&_array)[nlength])
{
	int i, j;
	for (j = 0; j < nlength - 1;j++)
	{
		for (i = 0; i < nlength - 1 - j;i++)
		{
			if (_array[i] > _array[i + 1])
			{
				T temp;
				temp = _array[i];
				_array[i] = _array[i + 1];
				_array[i + 1] = temp;
			}
		}
	}
}

int main(int argc, char* argv[])
{
	int arr[] = { 14,15,7,2,4,78 };
	int i, n;
	n = sizeof(arr) / sizeof(int);
	Sort(arr);
	cout << "------FunTest -------" << endl;
	int a[5];
	float b[5];
	FunTest(a);
	FunTest(b);
	cout << "------Test int-------" << endl;
	int j = 0;
	for (j = 0; j < n;j++)
	{
		cout << " int[" << j << "] " << arr[j] << endl;
	}

	char arr1[] = { 'a','d',7,2,4,78 };
	Sort(arr1);

	cout << "------Test char-------" << endl;
	for (j = 0; j < n;j++)
	{
		cout << " char[" << j << "] " << (int)arr1[j] << endl;
	}


	double arr2[] = { 14.21,15.256,7.648,2,4.25,78.21 };
	Sort(arr2);

	cout << "------Test double-------" << endl;
	for (j = 0; j < n;j++)
	{
		cout << " double[" << j << "] " << arr2[j] << endl;
	}

	cout << "------Test swap-------" << endl;
	int aaa = 900;
	int bbb = 800;
	cout << "1 aaa " << aaa << " bbb " << bbb << endl;
	swapAA(aaa, bbb);
	cout << "2 aaa " << aaa << " bbb " << bbb << endl;
	cin.get();
	return 0;
}
//————————————————
//版权声明：本文为csdn博主「zggxyx2004」的原创文章，遵循cc 4.0 by - sa版权协议，转载请附上原文出处链接及本声明。
//原文链接：https ://blog.csdn.net/zggxyx2004/article/details/102691089