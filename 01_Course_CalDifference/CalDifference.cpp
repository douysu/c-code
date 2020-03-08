// @author 憨豆酒 YinDou https://github.com/ModestBean
//
// @description
// 算法： MinDistance(A[0..n-1])
// 输入:数字数组 A[0..n-1]
// 输出:数组中两个大小相差最少的元素的差值
// dmin < -∞
//     for i < -0 to n - 1 do
//         for j < -0 to n - 1 do
//             if i≠j and | A [[i]- A[j] | < dmin
//                 dmin < -| A[i] - A[j] |
//                 return dmin
// 尽可能改进该算法(如果有必要，完全可以抛弃该算法；否则，请改进该算法)
//
// @version1 20200302 YinDou 完成题目

#include <cstdio>
#include <exception>

using namespace std;

int minDistance(int* array, int length)
{
	if (array == NULL || length == 0)
		throw exception("Invaild input. \n");

	int leftValue, rightValue;
	leftValue = array[0];
	rightValue = array[0];

	for (int i = 0; i < length; i++) {
		if (array[i] > rightValue) {
			rightValue = array[i];
		}

		if (array[i] < leftValue) {
			leftValue = array[i];
		}
	}

	for (int i = 0; i < length; i++) {
		int value = array[i];
		int result = rightValue - leftValue;

		if (value > rightValue && result > (value - rightValue))
		{
			leftValue = rightValue;
			rightValue = value;
		}

		if (value < leftValue && result > (leftValue - value)) {
			rightValue = leftValue;
			leftValue = value;
		}
		
		if (value > leftValue&& value < rightValue)
		{
			if (2 * value > (leftValue + rightValue))
				leftValue = value;
			else
				rightValue = value;
		}
	}

	return rightValue - leftValue;
}

void Test(const char* testName, int* array, int length, int expected)
{
	if (testName != NULL)
		printf("%s begins:\n", testName);

	int result = NULL;
	try
	{
		result = minDistance(array, length);

		if (result == expected)
			printf("Passed.\n");
		else
			printf("Failed.\n");
	}
	catch (const std::exception& e)
	{
		printf(e.what());
	}
}

int main()
{
	//// 正常数组
	//int array[] = { 1, 2, 4, 6, 8, 10, -3 };
	//Test("Test1", array, 7, 1);

	//// 差为0
	//int array2[] = { 1, 10, 10, 3, 4, 3, 5 };
	//Test("Test2", array2, 7, 0);

	//// 全部一样
	//int array3[] = { 1, 1, 1, 1, 1, 1, 1 };
	//Test("Test3", array3, 7, 0);

	// 全部一样
	int array4[] = { 10, 5, -6, 2, 7, 9, 8 };
	Test("Test4", array4, 7, 1);

	/*int array3[] = { 0, 0 };
	Test("Test3", array3, 2, 0);

	int* array4 = NULL;
	Test("Test4", array4, 0, 0);*/
	return 0;
}