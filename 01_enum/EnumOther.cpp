#include<iostream>
using namespace std;
enum  GameResult {//定义枚举类型
	WIN, LOSE, CANEL
};
int main() {
	GameResult result;
	for (int i = WIN; i <= CANEL; i++) {
		result = GameResult(i);//强制类型转换
		if (result == WIN) {
			cout << "WIN";
		}
		if (result == LOSE) {
			cout << "LOSE";
		}
		if (result == CANEL) {
			cout << "CANEL";
		}
	}
	cout << endl;
	return 0;
}