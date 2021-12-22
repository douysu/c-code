#include <iostream>

using namespace std;

// #define PRACTICE_19_3
#ifdef PRACTICE_19_3

class A {
public:
	A() { }
	virtual ~A() { }
};

class B : public A {
public:
	B() { }
	virtual ~B() { }
};

class C : public B {
public:
	C() { }
	virtual ~C() { }
};

class D : public B, public A {
public:
	D() { }
	virtual ~D() { }
};

int main()
{
	// dynamic_cast提供一套安全的转换机制

	// 转换成功，基类指针指向派生类对象，dynamic_cast转换为派生类指针，可以成功
	// 转换失败，基类指针指向的是基类对象，dynamic_cast将会转换失败
	// 符合正确的程序逻辑

	// C->B C是B的公有派生类
	// 向上转换是安全的
	A* pa1 = new C;
	B* pb1 = dynamic_cast<B*>(pa1);

	// B->C B是C的公有基类
	// 向下转换不安全
	B* pb2 = new B;
	C* pc2 = dynamic_cast<C*>(pb2);

	// D->B 具有二义性
	A* pa3 = new D;
	B* pb3 = dynamic_cast<B*>(pa3);

	cout << pb1 << endl;
	cout << pc2 << endl;
	cout << pb3 << endl;
}

#endif

// #define	PARCTICE_19_3A
#ifdef PARCTICE_19_3A

class Base
{
public:
	Base() {}
	virtual void print() const
	{
		cout << "Print virtual base" << endl;
	}

	void printObejct()
	{
		cout << "Print base" << endl;
	}
};

class A : public Base {
public:
	A() {}
	virtual void print() const {
		cout << "Print virtual AAA" << endl;
	}

	void printObejct()
	{
		cout << "Print AAA" << endl;
	}
};

class B : public Base {
public:
	B() {}
	virtual void print() const {
		cout << "Print virtual BBB" << endl;
	}

	void printObejct()
	{
		cout << "Print BBB" << endl;
	}
};

int main() {
	Base base;
	Base* pbase = &base;
	A a;
	A* pa = nullptr;
	B b;
	B* pb = nullptr;

	// 调用非多态函数
	pbase->printObejct();

	// 基类指针指向A对象
	// 多态：基类指针调用虚函数print，调用A的print
	pbase = &a;
	pbase->print();
	// 虽然指向了A对象，但是不是虚函数，仍然调用原来的成员函数
	pbase->printObejct();

	// 转换成功：向下强制类型转换，pbase指向A对象
	pa = dynamic_cast<A*>(pbase);
	if (nullptr != pa) {
		cout << "向下强制转换成功" << endl;
	}
	else {
		cout << "向下强制转换失败" << endl;
	}

	// 转换失败：pbase还是指向A的对象，pbase强制转换成B对象，A对象变成指向B的
	pb = dynamic_cast<B*>(pbase);
	if (nullptr != pb) {
		cout << "向下强制转换成功" << endl;
	}
	else {
		cout << "向下强制转换失败" << endl;
	}

	pbase = &b;
	// 调用子类B的print函数
    pbase->print();
	pbase->printObejct();

	return 0;
}

#endif

// #define PRACTICE_19_4
#ifdef PRACTICE_19_4
class A {
public:
	A() { }
	virtual ~A() { }
};

class B : public A {
public:
	B() { }
};

class C : public B {
public:
	C() { }
};

class D : public B, public A {
public:
	D() { }
};

int main()
{
	A* pa = new C();
	try
	{
		const C& c = dynamic_cast<const C&>(*pa);
	}
	catch(std::bad_cast& e)
	{
		cout << e.what() << endl;
	}

	return 0;
}

#endif

// #define PRACTICE_19_5
#ifdef PRACTICE_19_5
// 我们想使用基类对象的指针或引用执行某个派生类操作并且该操作不是虚函数，则可以使用RTTI运算符（该类类型应该含有虚函数)
// 在这个过程中会进行对象的判断，判断是否安全
#endif

#define PRACTICE_19_6
#ifdef PRACTICE_19_6
#include <typeinfo>
class A
{
public:
	virtual ~A() {}
};

class B : public A
{};

class C : public B
{};

class D : public B, public A
{};

int main()
{
	A* pa1 = new C();
	if (C* qc = dynamic_cast<C*>(pa1))
	{
		cout << "success" << endl;
	}
	else
	{
		cout << "fail" << endl;
	}

	A* pa2 = new C();
	try
	{
		const C& rc = dynamic_cast<const C&>(*pa2);
	}
	catch (std::bad_cast& e)
	{
		cout << e.what() << endl;
	}

	C c;
	if (typeid(*pa1) == typeid(*pa2))
		cout << "same type" << endl;
	if (typeid(*pa1) == typeid(c))
		cout << "same type as C" << endl;
	if (typeid(*pa1) == typeid(C))
		cout << "same type as C" << endl;

	return 0;
}

#endif