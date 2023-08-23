//指针类型 变量名可以简单的理解为指向地址,其值是个地址 ;  这个地址内的值依然可以独立改变
//引用类型	变量名可以简单的理解为引用对象的别名,变量名代表的类型,是根据声明的引用目标类型有关

#include <iostream>
int intArg;
int* Pa;		//定义一个整形指针变量Pa
int& Ra= intArg;		//定义一个整形的引用Ra ,引用需要初始化
int*& Ra1 = Pa;		//声明是一个int*整形指针变量的引用 , (简化理解 相当于是 int* Ra1<当然这种理解是不严谨的>)

void main() {

	//std::cout << "Pa值" << *Pa << std::endl;		
	std::cout << "intArg地址" << &intArg << std::endl;		
	std::cout << "Pa地址" << Pa << std::endl;	
	std::cout << "Ra值" << Ra << std::endl;							
	std::cout << "Ra地址" << &Ra << std::endl;					
	std::cout << "Ra1值" << Ra1 << std::endl;						
	std::cout << "Ra1地址" << &Ra1 << std::endl<<std::endl;				

	intArg = 99;
	//*Pa = intArg;			//Error, 此时*Pa为空指针, 没有指向任何内容
	Pa = &intArg;			//Pa存储的是指针变量指向的地址(并非指针变量自身的地址),所以这里传值也是地址
	std::cout << "Pa = &intArg  后Pa值" << *Pa << std::endl;
	std::cout << "Pa = &intArg  后Pa地址" << Pa << std::endl;
	std::cout << "Pa = &intArg  后Ra值" << Ra << std::endl;
	std::cout << "Pa = &intArg  后Ra地址" << &Ra << std::endl;
	std::cout << "Pa = &intArg  后Ra1值" << *Ra1 << std::endl;
	std::cout << "Pa = &intArg  后Ra1地址" << &Ra1 << std::endl<<std::endl;

	int intArg1 = 1;
	*Pa = 1;
	Ra = intArg1;		
	std::cout << "*Pa = 1  后Pa值" << *Pa << std::endl;		
	std::cout << "*Pa = 1  后Pa地址" << Pa << std::endl;	//赋值后,指针变量Pa指向的地址并没有变,只是地址内的值发生了改变	
	std::cout << "Ra = intArg1  后Ra值" << Ra << std::endl;
	std::cout << "Ra = intArg1  后Ra地址" << &Ra << std::endl;		//赋值后Ra地址并没有改变,仅仅是
	std::cout << "Ra = intArg1  后Ra1值" << *Ra1 << std::endl;			//指针变量的引用Ra1,Ra1指向的地址依然是&Ra,其内部值*Ra1与Ra的值一致
	std::cout << "Pa = &intArg  后Ra1地址" << &Ra1 << std::endl;
	std::cin.get();
}