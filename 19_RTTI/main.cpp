#include <iostream>

using namespace std;

#define PRACTICE_19_3
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
	A* pa = new C;
	B* pb = dynamic_cast<B*>(pa);

	//B* pb = new B;
	//C* pc = dynamic_cast<C*>(pb);

	//A* pa = new D;
	//B* pb = dynamic_cast<B*>(pa);
}

#endif
