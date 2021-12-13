#include <iostream>
#include <string>
#include "geometry.h"

using namespace std;

// #define TEM_16_1
#ifdef TEM_16_1
// 实例化：当编译器实例化一个模版时，它使用实际的模版参数代替对应的模版参数来创建出模版的一个新“实例”。
#endif // TEM_16_1

// #define TEM_16_2
#ifdef TEM_16_2

template <typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs) return -1;
	if (lhs > rhs) return 1;
	return 0;
}

int main()
{
	unsigned int a = 1;
	unsigned int b = 5;
	cout << compare(a, b) << endl;
}

#endif // TEM_16_2

// #define TEM_16_3
#ifdef TEM_16_3
// 因为Sales_data是自定义数据类型，没有对运算符<重载，导致错误error: no match for 'operator<'出现

struct Sales_data
{
	int a = 3;
};

template <typename T>
int compare(const T& lhs, const T& rhs)
{
	if (lhs < rhs) return -1;
	if (lhs > rhs) return 1;
	return 0;
}

int main()
{
	Sales_data s1;
	Sales_data s2;
	cout << compare(s1, s2) << endl;
}
#endif // TEM_16_3

// #define TEM_16_4
#ifdef TEM_16_4
template<typename Iterator, typename Value>
Iterator find(Iterator first, Iterator last, const Value& v)
{
	for (; first != last && *first != value; ++first);
	return first;
}
#endif // TEM_16_4

// 16_5 print函数编写模版版本，它接受一个数组的引用，能处理任意大小、任意元素类型的数组。
// #define TEM_16_5
#ifdef TEM_16_5
//void print(int(&arr)[10])
//{
//	for (auto elem : arr)
//		cout << elem << endl;
//}

template <typename Array>
void print(const Array& arr)
{
	for (auto elem : arr)
		cout << elem << endl;
}

int main()
{
	int a[] = { 1, 2, 3 };
	print(a);
}

#endif // TEM_16_5

// TEM_16_6 你认为接受一个数组实参的标准库函数 begin 和 end 是如何工作的？定义你自己版本的 begin 和 end。
// #define TEM_16_6
#ifdef TEM_16_6
template <typename T, unsigned int N>
T* begin(const T(&arr)[N])
{
	return arr;
}

template <typename T, unsigned int N>
T* end(const T(&arr)[N])
{
	return arr + N;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };

	cout << begin(a) << endl;
	cout << end(a) << endl;
}

#endif // TEM_16_6

// TEM_16_7
// #define TEM_16_7
#ifdef TEM_16_7

template <typename T, unsigned int N> constexpr
unsigned int my_size(const T(&arr)[N])
{
	return N;
}

int main()
{
	int a[] = { 1, 2, 3, 4, 5 };

	cout << my_size(a) << endl;
}

#endif // TEM_16_7

// TEM_16_8
// #define TEM_16_8
#ifdef TEM_16_8
// 因为大多数类只定义了 != 操作而没有定义 < 操作，使用 != 可以降低对要处理的类型的要求。
#endif // TEM_16_8

// TEM_16_9
// #define TEM_16_9
#ifdef TEM_16_9
// 一个函数模版就是一个公式，可用来生成针对特定类型的函数版本。类模版是用来生成类的蓝图的，与函数模版的不同之处是，
// 编译器不能为类模版推断模版参数类型。如果我们已经多次看到，为了使用类模版，我们必须在模版名后的尖括号中提供额外信息。
#endif // TEM_16_9

// TEM_16_10
// #define TEM_16_10
#ifdef TEM_16_10
// 一个类模版的每个实例都形成一个独立的类。
#endif // TEM_16_10

// TEM_16_11
// #define TEM_16_11
#ifdef TEM_16_11

template <typename elemType> class ListItem;
template <typename elemType> class List {
public:
	List<elemType>();
	List<elemType>(const List<elemType>&);
	List<elemType>& operator=(const List<elemType>&);
	~List();
	void insert(ListItem<elemType>* ptr, elemType value);
private:
	ListItem<elemType>* front, * end;
};

#endif // TEM_16_11

// TEM_16_12
// #define TEM_16_12
#ifdef TEM_16_12
// Blob.h BlobPtr.h
#endif // TEM_16_12

// TEM_16_13
// #define TEM_16_13
#ifdef TEM_16_13

#include "Blob.h"

int main()
{
	return 0;
}

#endif // TEM_16_13