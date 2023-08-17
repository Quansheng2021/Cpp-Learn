/*
-----------------------------------------------------------------------------------------
定义一个可以输入任意类型任意个数的变量为函数fun的实参，其函数定义如下
    template<typename... T>
    func (T... argsName) {
        // define
    }
这个函数模板的参数argsName前面的省略号，被成为模板参数包TemplateParemeterPack的可变模板参数
...包含了0~n个模板参数，我们无法通过参数argsName直接获取其中的每个参数，只能通过参数包展开的方式获取参数包中的每个参数
如果要获取参数的个数，可以用sizefo...(argsName)
-----------------------------------------------------------------------------------------
|
解析参数的方式一般为两种：
1，基于范围的for循环
       template<typename T,typename...T1>
      T func(T1...argsName){
            for(auto x:{argsName}){
                    Do_something(x);
            }
       }

上述中 x:{argsName...}的理解，是在（C++11）中，for语句允许简单的范围迭代；
例如：
         // 每个数组元素乘于 2
        int my_array[5] = {1, 2, 3, 4, 5};       
        for (int &x : my_array)
        {
            x *= 2;
            cout << x << endl;
        }
         // auto 类型也是 C++11 新标准中的，用来自动获取变量的类型
        for (auto &x : my_array) {
            x *= 2;
            cout << x << endl;
        }

2,递归方式展开
3,逗号表达式展开
            // 1.用作输出每个参数
        template<typename T>
        void show_arg(const T& t)
        {
	        std::cout << t <<std::endl;
        }

        // 2.用作展开参数包
        template <typename ... Args>
        void expand(const Args&... args)
        {
	        int arr[] = {(show_arg(args), 0)...}; /// ①
        }

       ①处的逗号表达式展开结果如下
        int arr[] = { (show_arg(1), 0) , (show_arg(2), 0), (show_arg(3), 0), (show_arg(4), 0) };

*/


#include <iostream>

#pragma region 递归开展可变参数包
template<typename T>
void print(const T& t)
{
    std::cout << t << std::endl;
}
// 递归执行函数
template<typename T, typename... Args>
void print(T head, Args... args)
{
    std::cout << head << (sizeof...(args) > 0 ? ", " : "");
    print(args...);
}

//展开调用的堆栈如下：
//Study_Test.exe!print<int>(const int& t) 行 59	C++
//Study_Test.exe!print<char const*, int>(const char* head, int <args_0>) 行 68	C++
//Study_Test.exe!print<char const*, char const*, int>(const char* head, const char* <args_0>, int <args_1>) 行 68	C++
//Study_Test.exe!print<int, char const*, char const*, int>(int head, const char* <args_0>, const char* <args_1>, int <args_2>) 行 68	C++
#pragma endregion

#pragma region 可变函数运用的简单的例子  
class student {
public:
    int age;
    float scoresEnglish = 88;
    float scoresMath = 92;
    float scoresChinese = 94;
} XiaoMing;
student XiaoHong{ 10,100,100,100 };

class teacher {
public:
    int age;
    float teachingTime = 30;
} LaoWang;

template<typename T>
class educateConvertRate {
public:
    T finalScores;
    T educateCvRate;

    T GeteducateCvRate(const T& a, const T& b) {
        return educateCvRate = a / b;
    }

    template<typename... endArgs>
    T GetfinalScores(const T a, endArgs&... args) {
        finalScores = a + GetfinalScores(args...);
        return finalScores;
    }

    T GetfinalScores(T value) {
        return value;
    }
};
#pragma endregion

int main() {
    educateConvertRate<float> instanceEducateConvrate;

    std::cout << "Educational Conversion Rate: " <<instanceEducateConvrate.GeteducateCvRate(
        (instanceEducateConvrate.GetfinalScores(
            XiaoMing.scoresChinese, XiaoMing.scoresEnglish, XiaoMing.scoresMath)), LaoWang.teachingTime) 
        << std::endl;

    std::cout << "Educational Conversion Rate: " << instanceEducateConvrate.GeteducateCvRate(
        (instanceEducateConvrate.GetfinalScores(
            XiaoHong.scoresChinese, XiaoHong.scoresEnglish, XiaoHong.scoresMath)), LaoWang.teachingTime)
        << std::endl;

    print(1, "hello", "C++", 11);

    std::cin.get();
    return 0;
}