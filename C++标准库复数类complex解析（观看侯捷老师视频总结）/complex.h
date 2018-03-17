#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>
using namespace std;
class complex
{
public:
	complex(double r = 0, double i = 0) :re(r), im(i) {};
	complex& operator += (const complex&);
	double real() const { return re; }
	double imag() const { return im; }
private:
	double re, im;
	friend complex&  _doapl(complex*, const complex&);
};
inline complex&
_doapl(complex* ths, const complex& r) {
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}
inline complex&
complex::operator += (const complex& r) {
	return _doapl(this, r);
}
inline double
imag(const complex& x)
{
	return x.imag();
}

inline double
real(const complex& x)
{
	return x.real();
}

ostream&
operator << (ostream& os, const complex& x)
{
	return os << '(' << real(x) << ',' << imag(x) << ')';
}
#endif
