#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>   
#include <string>
/*
C++的线程案例，参考C++ Reference

1、打印方法结束后，如果不解锁，那么第二个线程的打印是无法进行的。
2、加锁后出现的结果为
*****************************
&&&&&&&&&&&&&&&&&&&&&&&&&&&&&

不加锁的结果可能为
************&&&&&&&&&&&&********
******&&&&&&&&&
不加锁不会保持线程的同步
*/
std::mutex myLock;//资源锁
using namespace std;
void printThread(string s) {//线程打印方法
	myLock.lock();
	std::this_thread::sleep_for(std::chrono::milliseconds(30));
	for (int i = 0; i < 50; i++) {
		cout << s;
	}
	cout << "\n";
	myLock.unlock();
}
void printThread2(string s) {//线程打印方法
	myLock.lock();
	for (int i = 0; i < 50; i++) {
		cout << s;
	}
	cout << "\n";
	myLock.unlock();
}
int main() {
	cout << "主线程开始" << endl;
	thread t1(printThread,"*");//创建线程t1
	thread t2(printThread2, "&");//创建线程t2
	t1.join();
	t2.join();
	cout << "主线程结束" << endl;
	std::cin.get();
}
