#include <iostream>


#pragma region 最简单的仿函数应用
class compare {
private:
    int m_Number;
public:
    compare(int Num) :m_Number(Num) {}
    bool operator () (int inputor) {
        return m_Number > inputor;
    }
};
#pragma endregion

#pragma region 仿函数与模板实例
template <typename T, typename predicate>
T findFirst(const T* array, size_t size, predicate pred) {
    for (size_t i = 0; i < size; ++i) {
        if (pred(array[i])) {
            return array[i];
        }
    }
    return T();  // Default value if not found
}

struct IsNotZero {
    bool operator()(int value) const {
        return value != 0;
    }
};
#pragma endregion

int main() {

#pragma region 最简单的仿函数应用
    //这里调用的是构造函数compare(int Num) :m_Number(Num) {}
    compare comp(10);

    //这里调用的是()的重载, 即bool operator () (int inputor){……}
    std::cout << comp(11) << std::endl;
    std::cout << comp(9) << std::endl;
#pragma endregion

#pragma region 仿函数与模板实例
    int v[5] = { 0, 0, 0, 98, 0 };
    IsNotZero predicate;
    int firstNonZero = findFirst(v, 5, predicate);

    std::cout << "The first non-zero value is: " << firstNonZero << std::endl;
#pragma endregion

    std::cin.get();
    return 0;
}

