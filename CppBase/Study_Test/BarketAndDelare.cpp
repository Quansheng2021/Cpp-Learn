#include<iostream>
using namespace std;
			  
//�������ֳ�ʼ����ʽ�ȼ�
int a{ 5 };
int b = 5;

//�������ֳ�ʼ����ʽ�ȼ�
int arrA[5]{ 6,7,8,9,10 };
int arrB[5] = { 1,2,3,4,5 };				

class barketDeclareClass {
public:
	int a;
	string b;
	barketDeclareClass(int aPar,string bPar):a(aPar),b(bPar) {};
};		

struct barketDeclarestruct
{
	int a;
	string b;
	char c;
	barketDeclarestruct(int aPar, string bPar,char cPar) :a(aPar), b(bPar),c(cPar) {};
};



int main(){
	cout << a << endl;

	cout << arrA[1]<< endl;
	cout << arrB[1] << endl;

#pragma region	��ĳ�ʼ��
	barketDeclareClass InstanceClassBarket0 = { 0,"b0" };
	cout << InstanceClassBarket0.a << endl;
	barketDeclareClass InstanceClassBarket1{ 1,"b1" };
	cout << InstanceClassBarket1.a << endl;
	//�����2����ʼ�������ӿ���ʹ��Ĭ�Ϲ��캯��
	//�����������,��������ʾ���������캯��,�����ȱ�ٶ�Ӧ�ĺ�������
	barketDeclareClass InstanceClassBarket2(2, "b2");
	cout << InstanceClassBarket2.a << endl;

	//struct�������������
	barketDeclarestruct InstanceStructBarket0 = { 0,"a0", 'b' };
	barketDeclarestruct InstanceStructBarket1{ 1,"a1", 'b' };
	barketDeclarestruct InstanceStructBarket2(1, "a1", 'b');
#pragma endregion

	
}