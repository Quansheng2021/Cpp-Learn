//这两种方法都可以实例化一个对象，但是这两种方法有很大的区别，区别在于对象内容所在的内存空间不同，众所周知，内存的分配方式有三种
//（1）从静态存储区域分配。内存在程序编译的时候就已经分配好，这块内存在程序的整个运行期间都存在。例如全局变量，static 变量。
//（2）  在栈上创建。在执行函数时，函数内局部变量的存储单元都可以在栈上创建，函数执行结束后在将这些局部变量的内存空间回收。在栈上分配内存空间效率很高，但是分配的内存容量有限。
//（3） 从堆上分配的。程序在运行的时候用 malloc 或 new 申请任意多少的内存，程序员自己负责在何时用 free 或 delete 释放内存。

#include <iostream>  
using namespace std;

class TestNew
{
private:
    int ID;
public:
    TestNew(int ID);
    ~TestNew();
};

TestNew::TestNew(int ID)
{
    this->ID = ID;
}

TestNew::~TestNew()
{
    std::cout << "对象 " << this->ID << " 执行析构函数" << std::endl;
}
void Test()
{
    TestNew test(1);//创建对象1,不使用new  
    TestNew* pTest = new TestNew(1);//创建对象2，使用new  
}

int main()
{
    Test();
    //输出结果 "对象 1 执行析构函数" 只打印了一次
    //这个地方有点问题，pTest没有进行处理，会导致内存泄露，实际应用中要注意呀  
}
