#include "NeilianSample.h"
#include<iostream>
using namespace std;
int main() {
	float rect = 2;
	NeilianSample* ns = new NeilianSample();
	float area = ns->calArea(rect);
	printf("当前的面积是%f", area);
	cin.get();
}
inline float NeilianSample::calArea(float rect) {
	return (float)rect*rect;
}
NeilianSample::NeilianSample()
{
}

NeilianSample::~NeilianSample()
{
}
