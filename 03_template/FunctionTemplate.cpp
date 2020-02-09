#include <iostream>
template <typename T>
T const& add(T const& a, T const& b) {//创建函数模板
	return a + b;
}
//int main() {
//	int i1 = add(1, 2);
//	float f2 = add(3.3f, 4.2f);
//	double d3 = add(2,2);
//	std::cout << i1 << std::endl;
//	std::cout << f2 << std::endl;
//	std::cout << d3 << std::endl;
//	std::cin.get();
//}
