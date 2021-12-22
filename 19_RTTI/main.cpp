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
	// dynamic_cast�ṩһ�װ�ȫ��ת������

	// ת���ɹ�������ָ��ָ�����������dynamic_castת��Ϊ������ָ�룬���Գɹ�
	// ת��ʧ�ܣ�����ָ��ָ����ǻ������dynamic_cast����ת��ʧ��
	// ������ȷ�ĳ����߼�

	// C->B C��B�Ĺ���������
	// ����ת���ǰ�ȫ��
	A* pa1 = new C;
	B* pb1 = dynamic_cast<B*>(pa1);

	// B->C B��C�Ĺ��л���
	// ����ת������ȫ
	B* pb2 = new B;
	C* pc2 = dynamic_cast<C*>(pb2);

	// D->B ���ж�����
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

	// ���÷Ƕ�̬����
	pbase->printObejct();

	// ����ָ��ָ��A����
	// ��̬������ָ������麯��print������A��print
	pbase = &a;
	pbase->print();
	// ��Ȼָ����A���󣬵��ǲ����麯������Ȼ����ԭ���ĳ�Ա����
	pbase->printObejct();

	// ת���ɹ�������ǿ������ת����pbaseָ��A����
	pa = dynamic_cast<A*>(pbase);
	if (nullptr != pa) {
		cout << "����ǿ��ת���ɹ�" << endl;
	}
	else {
		cout << "����ǿ��ת��ʧ��" << endl;
	}

	// ת��ʧ�ܣ�pbase����ָ��A�Ķ���pbaseǿ��ת����B����A������ָ��B��
	pb = dynamic_cast<B*>(pbase);
	if (nullptr != pb) {
		cout << "����ǿ��ת���ɹ�" << endl;
	}
	else {
		cout << "����ǿ��ת��ʧ��" << endl;
	}

	pbase = &b;
	// ��������B��print����
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
// ������ʹ�û�������ָ�������ִ��ĳ��������������Ҹò��������麯���������ʹ��RTTI���������������Ӧ�ú����麯��)
// ����������л���ж�����жϣ��ж��Ƿ�ȫ
#endif

// #define PRACTICE_19_6
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

// #define PRACTICE_19_7
#ifdef PRACTICE_19_7
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
		if (typeid(rc) == typeid(C))
			cout << "same type as C" << endl;
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

// #define PRACTICE_19_9
#ifdef PRACTICE_19_9
#include <typeinfo>

class Base
{
	friend bool operator==(const Base&, const Base&);

public:
	Base() = default;
	Base(int i_) : i(i_) {}

protected:
	virtual bool equal(const Base&) const;

private:
	int i;
};

class Derived : public Base
{
public:
	Derived() = default;
	Derived(std::string s_, int i_) : s(s_), Base(i_) { }

protected:
	bool equal(const Base&) const;

private:
	std::string s;
};

bool operator==(const Base& lhs, const Base& rhs)
{
	return typeid(lhs) == typeid(rhs) && lhs.equal(rhs);
}

bool Base::equal(const Base& rhs) const
{
	return this->i == rhs.i;
}

bool Derived::equal(const Base& rhs) const
{
	auto r = dynamic_cast<const Derived&>(rhs);
	return (this->s == r.s) && this->Base::equal(rhs);
}

int main()
{
	Base* pb1 = new Derived();
	Base* pb2 = new Derived();
	Base* pb3 = new Derived("a", 1);
	Base* pb4 = new Base();

	std::cout << std::boolalpha << (*pb1 == *pb2) << std::endl;
	std::cout << std::boolalpha << (*pb1 == *pb3) << std::endl;
	std::cout << std::boolalpha << (*pb1 == *pb4) << std::endl;

	int arr[10];
	Derived d;

	cout << typeid(42).name() << ", "
		<< typeid(arr).name() << ", "
		<< typeid(d).name() << ", "
		<< typeid(std::string).name() << ", "
		<< typeid(pb1).name() << ", "
		<< typeid(*pb1).name() << ", "
		<< typeid(*pb3).name() << endl;

	return 0;
}

#endif

#define PRACTICE_19_10
#ifdef PRACTICE_19_10
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

int main(int argc, char const* argv[])
{
	// ���մ𰸺�ָ���й�ϵ

	 //A *pa = new C;
	 //std::cout << typeid(pa).name() << std::endl;

	 //C cobj;
	 //A &ra = cobj;
	 //std::cout << typeid(&ra).name() << std::endl;

	B* px = new B;
	A& ra = *px;
	std::cout << typeid(ra).name() << std::endl;

	return 0;
}

#endif