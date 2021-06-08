#include <cmath>
#include "Complex.h"
using std::cout;
using std::endl;

// z = a + bi

// default construct
Complex::Complex(const double re, const double im)
{
	real = re;
	imag = im;
}

// copy constructor
Complex::Complex(const Complex& c)
{
	real = c.real;
	imag = c.imag;
}

// copy assignment constructor
Complex& Complex::operator=(const Complex& c)
{
	if(this == &c)
		return *this;
	real = c.real;
	imag = c.imag;
	return *this;
}

// polar = abs*(cos(arg)+i*sin(arg))
Complex Complex::Polar(const double leng, const double arg)
{
	real = leng*(cos(arg));
	imag = leng*(sin(arg));
	return Complex(real, imag);
}

// real = a
double Complex::Real()
{
	return real;
}

// imag = b
double Complex::Imag()
{
	return imag;
}

// norm = a^2 - b^2
double Complex::Norm()
{
	return pow(real, 2)+pow(imag, 2);
}

// abs = sqrt(norm)
double Complex::Abs()
{
	return sqrt(Norm());
}

// arg = arc tan(abs)
double Complex::Arg()
{
	return atan(imag / real);
}

// prefix increment
Complex Complex::operator++()
{
	return Complex(real+1, imag+1);
}

// postfix increment
Complex Complex::operator++(int)
{
	double temp1 = real++;
	double temp2 = imag++;
	return Complex(temp1, temp2);
}

// prefix decrement
Complex Complex::operator--()
{
	return Complex(real-1, imag-1);
}

// postfix decrement
Complex Complex::operator--(int)
{
	double temp1 = real--;
	double temp2 = imag--;
	return Complex(temp1, temp2);
}

// destructor
Complex::~Complex()
{
	;
}

// calculate polar
Complex Polar(const double leng, const double arg)
{
	return Complex(leng*(cos(arg)), leng*(sin(arg)));
}

// calculate norm
double Norm(const Complex& x)
{
	Complex temp(x);
	return temp.Norm();
}

// calculate absolute
double Abs(const Complex& x)
{
	Complex temp(x);
	return temp.Abs();
}

// calculate argument
double Arg(const Complex& x)
{
	Complex temp(x);
	return temp.Arg();
}

// z = x + y
Complex operator+(const Complex& x, const Complex& y)
{
	Complex temp1(x);
	Complex temp2(y);
	return Complex(temp1.Real()+temp2.Real(), temp1.Imag()+temp2.Imag());
}

// z = x - y
Complex operator-(const Complex& x, const Complex& y)
{
	Complex temp1(x);
	Complex temp2(y);
	return Complex(temp1.Real()-temp2.Real(), temp1.Imag()-temp2.Imag());
}

// z = x * y
Complex operator*(const Complex& x, const Complex& y)
{
	double real_part = (x.real*y.real)-(x.imag*y.imag);
	double imag_part = (x.real*y.imag)+(x.imag*y.real);
	return Complex(real_part, imag_part);
}

// z = x / y
Complex operator/(const Complex& x, const Complex& y)
{
	Complex ytemp(y);
	double denominator = ytemp.Norm();
	Complex temp(y.real, -y.imag);
	return Complex((x*temp).real/denominator, (x*temp).imag/denominator);
}

// x = x + y
Complex operator+=(Complex& x, const Complex& y)
{
	x.real = x.real + y.real;
	x.imag = x.imag + y.imag;
	return Complex(x.real, x.imag);
}

// x = x - y
Complex operator-=(Complex& x, const Complex& y)
{
	x.real = x.real - y.real;
	x.imag = x.imag - y.imag;
	return Complex(x.real, x.imag);
}

// x = x * y
Complex operator*=(Complex& x, const Complex& y)
{
	double temp_x_real = x.real;
	x.real = (x.real*y.real)-(x.imag*y.imag);
	x.imag = (temp_x_real*y.imag)+(x.imag*y.real);
	return Complex(x.real, x.imag);
}

// x = x / y
Complex operator/=(Complex& x, const Complex& y)
{
	Complex ytemp(y);
	double denominator = ytemp.Norm();
	Complex mul(x*Complex(y.real, -y.imag));
	x.real = (mul).real/denominator;
	x.imag = (mul).imag/denominator;
	return x;
}

// if x == y
bool operator==(const Complex& x, const Complex& y)
{
	return ((x.real == y.real) && (x.imag == y.imag));
}

// if x != y
bool operator!=(const Complex& x, const Complex& y)
{
	return ((x.real != y.real) || (x.imag != y.imag));
}

// print the form of complex x
ostream& operator<<(ostream& o, const Complex& x)
{
	o << "(" << x.real << "," << x.imag << ")";
	return o;
}
