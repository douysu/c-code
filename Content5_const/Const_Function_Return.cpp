#include <iostream>
using namespace std;
class Object
{
public:
	Object() {};
};

const char*  getCharPointer  (char* in) {
	 return in;
}

Object& getObjectReference(Object& ob)
{
	return ob;
}

//int main()
//{
//	char c[] = "Hello";
//	const char* newc = getCharPointer(c);
//	cout << newc << endl;
//
//	Object a;
//	Object b = getObjectReference(a) = a;
//
//	std::cin.get();
//}