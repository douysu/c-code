#include <iostream>
using namespace std;



// #define TEST1
#ifdef TEST1

#include "String.h"

int main() {
	String s1("hello");
	String s2("world");
	String s3(s2);//s3�ճ���
	s3 = s1;//s3��ֵ
	cin.get();
	return 0;
}

#endif // TEST1

#define TEST2
#ifdef TEST2

// �ַ����顢�ַ�ָ�롢�ַ���������ʹ�÷�ʽ
int main()
{
	// ע�����ֳ�ʼ���ķ�ʽ
	// ��һ�ֲ����ٺ������'\0',Ҳ����˵��֪��ʲôʱ��Ż�ֹͣ
	// �ڶ��ֻ��ں������'\0'
	char array1[] = { 'a', 'b', 'd', 'e', '\0'};
	char array2[] = "hello";
	const char* p = "hello";

	cout << sizeof(array1) << endl; // 5
	cout << strlen(array1) << endl; // 4
	cout << sizeof(array2) << endl; // 6
	cout << strlen(array2) << endl; // 5
	cout << sizeof(p) << endl; // 8 64λָ���С
	cout << strlen(p) << endl; // 5

	return 0;
}

#endif // TEST2

// #define TEST3
#ifdef TEST3

int main()
{
	return 0;
}

#endif // TEST3
