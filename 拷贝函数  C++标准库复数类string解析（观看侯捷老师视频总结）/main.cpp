#include <iostream>
#include "String.h"
using namespace std;
int main() {
	String s1("hello"); 
    String s2("world"); 
    String s3(s2);//s3¸Õ³öÏÖ
    s3 = s1;//s3¸³Öµ
	cin.get();
	return 0;
}