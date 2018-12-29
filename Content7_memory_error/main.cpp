#include <iostream>
using namespace std;
int main()
{
	int *p = new int[2];
	cout << p[0] << endl;//À¬»øÖµ
	p[0] = 2;
	cout << p[0] << endl;//2
	delete [] p;
	cin.get();
}