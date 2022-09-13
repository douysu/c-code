

// #define TEST_1
#ifdef TEST_1

#include <iostream>
#include "ClassTemplate.h"
using namespace std;

int main() {
	ClassTemplate<int> s1(1,2);
	ClassTemplate<float> s2(1.0f, 2.0f);
	int area=s1.CalculateArea();
	float areaf = s2.CalculateArea();
	cout << "计算出的int面积是" << area<< "计算出的float面积是" << areaf << endl;
	std::cin.get();
}
#endif // !TEST_1

#define TEST_2
#ifdef TEST_2

#include <iostream>

template<class T1, class T2>
class Foo {
public:
    void foo() {
        printf("无特化 \n");
    }
};

template<class T1>
class Foo<T1, int> {
public:
    void foo() {
        printf("偏特化 \n");
    }
};

template<>
class Foo<int, int> {
public:
    void foo() {
        printf("全特化 \n");
    }
};

template<class T>
void f() { T a; }

template<>
//void f() { int a; } // 有歧义，无法推断T的类型
void f<int>() { int a; } // 显示制定模板参数类型

int main() {
    Foo<int, double> foo1; // 无特化
    Foo<double, int> foo2; // 偏特化
    Foo<int, int> foo3; // 全特化

    foo1.foo();
    foo2.foo();
    foo3.foo();

    std::cin.get();
}
#endif // !TEST_1

