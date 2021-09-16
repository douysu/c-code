#include <iostream>
using namespace std;

#define TEST2

#ifdef TEST1

#include "String.h"

int main() {
	String s1("hello");
	String s2("world");
	String s3(s2);//s3刚出现
	s3 = s1;//s3赋值
	cin.get();
	return 0;
}

#endif // TEST1

#ifdef TEST2

int main()
{
	// 注意两种初始化的方式
	// 第一种不会再后面加上'\0',也就是说不知道什么时候才会停止
	// 第二种会在后面加上'\0'
	char array1[] = { 'a', 'b', 'd', 'e', '\0'};
	char array2[] = "hello";
	const char* p = "hello";

	cout << sizeof(array1) << endl; // 5
	cout << strlen(array1) << endl; // 4
	cout << sizeof(array2) << endl; // 6
	cout << strlen(array2) << endl; // 5
	cout << sizeof(p) << endl;
	cout << strlen(p) << endl;

	return 0;
}

#endif // TEST2
