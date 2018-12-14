#include <iostream>
using namespace std;
class Object {
};
void pointer_print(const char* const src) {
	//src[0] = 'a'; const在char*之前，无法修改指针指向的内存单元内容

	//char s[] = "AABBCC";
	//src = s;      const在char*之后，无法修改指针的指向

	//前后都有，两者综合

	cout << src << endl;
}
void object_reference(const Object& in) {
	Object b;
	//in = b; 错误
}
//int main()
//{
//	//将字符串赋值给字符数组
//	char s[] = "Hello";
//	pointer_print(s);
//	//对象传递
//	Object a;
//	object_reference(a);
//
//	cin.get();
//	return 0;
//}