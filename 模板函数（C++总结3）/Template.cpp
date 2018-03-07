#include <iostream>
template <class T>
T add(T a, T b) {//创建函数模板
	return a + b;
}
int main() {
	int i1 = add(1, 2);
	float f2 = add(3.3f, 4.2f);
	std::cout << i1 << "||" << f2 << std::endl;
	std::cin.get();
	/*运行结果 3||7.5*/
}
