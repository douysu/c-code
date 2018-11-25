#include <stdio.h>
//定义枚举类型
enum  Week { Monday, Tuesday, Wednesday };
class Person {
public:
	Person(Week inArriveDate) {
		this->arriveDate = inArriveDate;
	}
	Week arriveDate;
};
//int main() {
//	Person p(Monday);
//	return 0;
//}