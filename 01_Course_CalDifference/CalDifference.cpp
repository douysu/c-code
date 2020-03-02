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

int differentValue(int* a, int n);
void quickSort(int* a, int left, int right);

int minDistance(int* array, int length)
{
	if (array == NULL || length == 0)
		throw exception("Invaild input. \n");

	quickSort(array, 0, length - 1);
	
	return differentValue(array, length);
}

int differentValue(int* a, int n) {
	int dvalue = 100001;
	for (int i = 1; i < n; i++) {
		int elem = a[i] - a[i - 1];

		if (elem < dvalue) {
			dvalue = elem;
		}
	}
	return dvalue;
}

void quickSort(int* a, int left, int right) {
	int i, j, t, pivotkey;

	if (left > right) {
		return;
	}

	pivotkey = a[left];

	i = left;
	j = right;
	while (i != j) {

		while (a[j] >= pivotkey && i < j) {	
			j--;
		}

		while (a[i] <= pivotkey && i < j) {
			i++;
		}

		if (i < j) {
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}

	}
	a[left] = a[i];
	a[i] = pivotkey;

	quickSort(a, left, i - 1);
	quickSort(a, i + 1, right);
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
	 int array[] = { 1, 2, 4, 6, 8, 10, -3 };
	 Test("Test1", array, 7, 1);

	 int array2[] = { 1, -2, 4, -6, 8, -10, -3 };
	 Test("Test2", array2, 7, 1);

	 int array3[] = { 0, 0 };
	 Test("Test3", array3, 2, 0);

	 int* array4 = NULL;
	 Test("Test4", array4, 0, 0);


	return 0;
}