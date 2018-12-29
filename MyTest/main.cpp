#include "complex.h"
#include <iostream>
using namespace std;
int main() {
	complex c1(2, 1);
	complex c2(5);
	printf("%d", sizeof(c2));
		c2 += c1;
	cout << c2;
	cin.get();
}