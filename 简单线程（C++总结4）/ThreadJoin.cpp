#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>   
#include <string>
/*
C++的线程案例，参考C++ Reference
1、添加join后可以保证线程的内容执行完毕，不会在主线程结束后，自定义线程中的打印内容还没有执行完毕
*/
using namespace std;
void printThread(string s) {//线程打印方法
	std::this_thread::sleep_for(std::chrono::milliseconds(30));
	for (int i = 0; i < 50; i++) {
		cout << s;
	}
	cout << "\n";
}
int main() {
	cout << "主线程开始" << endl;
	thread t1(printThread, "*");//创建线程t1
	t1.join();
	cout << "主线程结束" << endl;
	std::cin.get();
}
