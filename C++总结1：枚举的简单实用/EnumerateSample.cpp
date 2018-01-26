#include<iostream>
using namespace std;
/*
笔记：
	1、不能够在其他地方进行赋值，只能在初始化时赋值
	2、枚举元素具有默认值，默认情况下为0，1，2.......
	3、enum  GameResult{WIN=2,LOSE=1,CANEL};以此种情况给定默认值
	4、整数值不能够直接赋值给枚举变量，可以进行强制类型转换

*/
enum  GameResult{//定义枚举类型
	WIN,LOSE,CANEL
};
int main() {
	GameResult result;
	for (int i = WIN; i <= CANEL; i++) {
		result = GameResult(i);//强制类型转换
		if (result == WIN) {
			cout << "WIN";
		}
		if (result == LOSE) {
			cout << "LOSE" ;
		}
		if (result == CANEL) {
			cout << "CANEL";
		}
	}
	cout <<  endl;
	return 0;
}
