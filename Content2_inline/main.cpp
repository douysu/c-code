#include "InlineSample.h"
#include<iostream>
using namespace std;
int main() {
	InlineSample ns;
	ns.setValue(2.0f);
	printf("当前的值%f", ns.value);
	cin.get();
}