#include <iostream>
using namespace std;
char* GetMemory3() {
	char* p = (char*)malloc(sizeof(char) * 100);
	return p;
}
int main()
{
	char *str = NULL;
	str=GetMemory3();
	strcpy_s(str, 100, "Hello world ");
	cout << str << endl;
	cin.get();
}