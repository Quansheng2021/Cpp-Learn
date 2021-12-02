#include <iostream>
using namespace std;

template <typename T ,int N>  

//关于template 与 class用作模板区别.
//C++的一般规则是，除了使用typename修饰之外，template内的任何标识符号都被视为一个值而不是一个类别(对象)。

//typename在下面情况下禁止使用：
//1,模板定义之外，即typename只能用于模板的定义中
//2,非限定类型，比如int，vector<int>之类
//3,基类列表中，比如template <class t> class c1 : t::innertype不能在t::innertype前面加typename
//4,构造函数的初始化列表中
//----------------------------------------------------
//class Mydata {
//    static int value;
//    static int function();
//    typedef string str;
//};

//template <class T>
//void function()
//{
//    T::iterator* iter;  //这里产生歧义.歧义一:T::iterator *iter;实现乘法，iterator是类T的一个成员；歧义二：定义一个指针，指针指向的类型为T::iterator；
//    .....
//}
//
//template <class T>
//class myData()
//{
//    typename T::iterator* iter;//定义一个指针,这里不能使用class
//    typedef typename iterator_traits<_Iter>::value_type  value _type;//定义一个别名
//    .....
//};
//----------------------------------------------------


void main() {
    //template <typename T ,int N>  
    //Error:template只能在全局，命名空间和类内声明。
    //对于template的实现，需要template中的所有符号都能够被外部链接。
}