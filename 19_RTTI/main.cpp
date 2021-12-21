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

#define	PARCTICE_19_3A
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

	// ת��ʧ�ܣ�pbase����ָ��A�Ķ���pbaseǿ��ת����B����
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
