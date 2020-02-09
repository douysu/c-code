#include <iostream>
using namespace std;
void GetMemory(char *p) {
	p = (char*)malloc(sizeof(char) * 100);
}
void GetMemory2(char **p) {
	*p = (char*)malloc(sizeof(char) * 100);
}
//int main() 
//{
//	char *str = NULL;
//	GetMemory2(&str);
//	strcpy_s(str,100, "Hello world ");
//	cout << str << endl;
//	cin.get();
//}