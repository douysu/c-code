#include "complex.h"
int main() {
	complex c1(2, 1);
	complex c2(5);
	c2 += c1;
	cout << c2;
	cin.get();
}