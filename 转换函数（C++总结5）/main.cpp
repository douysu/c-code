#include <iostream>
#include "Fraction.h"
int main() {
	Fraction f(3, 5);
	double d = 4.0 + f;
	std::cout << d << std::endl;
	std::cin.get();
}
