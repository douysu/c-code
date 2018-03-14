#include <iostream>
#include "TemplateSample.h"
using namespace std;
int main() {
	TemplateSample<int > s1(1,2);
	int area=s1.CalculateArea();
	cout << "计算出的面积是" << area << endl;
	std::cin.get();
}