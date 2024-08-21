#include <iostream>

class Vector {
    int num;
    int* a;

public:
    Vector(int n) : num(n), a(new int[n]()) {} // Constructor with initialization
    Vector(const Vector& v) { DeepCopy(v); } // Copy Constructor
    ~Vector() { delete[] a; } // Destructor

    void ShallowCopy(Vector& v) {
        num = v.num;
        a = v.a; // This is shallow copy
    }

    void DeepCopy(const Vector& v) {
        num = v.num;
        a = new int[num]; // Allocate new memory
        for (int i = 0; i < num; ++i) {
            a[i] = v.a[i]; // Copy the elements
        }
    }

    // Adding a method to display the values for visualization
    void Display() {
        for (int i = 0; i < num; ++i) {
            std::cout << a[i] << ' ';
        }
        std::cout << std::endl;
    }
};

int main() {
    Vector v1(5); // Construct Vector of size 5
    Vector v2 = v1; // Copy v1 to v2 using Copy Constructor

    v1.Display();
    v2.Display();

    return 0;
}
