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