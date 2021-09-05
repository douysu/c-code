#include <iostream>
#include <string>
#include "geometry.h"

using namespace std;

int main() {
	Vec2i vec1(1, 2);
	Vec2i vec2(vec1);
	cout << vec1.x;
}