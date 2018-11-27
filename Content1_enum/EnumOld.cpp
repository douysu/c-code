#include <stdio.h>
const int Monday = 0;
const int Tuesday = 1;
const int Wednesday = 2;
class Person {
public:
	Person(const int inArriveDate) {
		this->arriveDate = inArriveDate;
	}
	int arriveDate;
};
//int main() {
//	Person p(Monday);
//	printf("%d", p.arriveDate);
//	return 0;
//}