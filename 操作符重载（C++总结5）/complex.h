#ifndef COMPLEX_H
#define COMPLEX_H
class complex
{
public:
	complex(double r = 0, double i = 0) :re(r), im(i) {};
	complex& operator += (const complex&);
	double real() const { return re; }
	double imag() const { return im; }
private:
	double re, im;
	friend complex&  doapl(complex*, const complex&);
};
#endif
inline complex&
doapl(complex* ths, const complex& r) {
	ths->re += r.re;
	ths->im += r.im;
	return *ths;
}
inline complex&
complex::operator += (const complex& r) {
	return doapl(this, r);
}
