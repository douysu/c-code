#include <iostream>
using namespace std;
class Data
{
public:
	Data(int dIn):d_int(dIn) {};
	int d_int;
};

//int main() {
//	const int WIDTH = 20;
//	int* p = (int *)&WIDTH;
//	cout << WIDTH << endl;//20
//	*p = 10;
//	cout << WIDTH << endl;//20
//	const Data data(20);
//	Data* d = (Data*)&data;
//	cout << data.d_int << endl;//20
//	d->d_int = 10;
//	cout << data.d_int << endl;//10
//	cin.get();
//}