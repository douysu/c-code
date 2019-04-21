#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
int main() {
	char data[100] = { '1', '2', '3' };
	// 以写模式打开文件
	ofstream outfile;
	outfile.open("afile.txt");
	// 向文件写入用户输入的数据
	outfile << data << endl;
	// 关闭打开的文件
	outfile.close();
}