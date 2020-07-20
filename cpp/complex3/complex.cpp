#include "complex.h"
#include <cassert>
#include <sstream>

//deprecated 지금은 지원하지만 빠질수있다.
int Complex::numberOfComplex;
const int Complex::BLOCK_SIZE = 256;
Complex *Complex::freeOfHeadList = NULL;

//생성자에서 증가시키고 소멸자에서 감소시킨다.
std::istream& operator >> (std::istream& in, Complex& rhs)
{
	double re = 0.0;
	double im = 0.0;
	
	char c = 0;
	
	in >> c;
	if (c == '(') {
		in >> re >> c;
		if(c == ',') in >> im >>c;
		if(c == 'i') in >> c;
		if(c != ')') in.clear(std::ios::failbit);
	}else {
		in.putback(c);
		in >> re;
	} 
	if (in ) rhs = Complex (re, im);
	return in;
}

std::ostream& operator << (std::ostream& out, const Complex& rhs)
{
	std::ostringstream buf;
	buf.flags(out.flags());
	buf.precision(out.precision());
	
	buf << "(" << rhs.re_ << ", " << rhs.im_ << "i)" << std::ends;
	out << buf.str();
//	buf.freeze(0);
	
	return out; 
}

//static member func.
void *Complex::operator new(size_t size)
{
	 if(size != sizeof(Complex))
	 	return ::operator new(size);
	 	
	 Complex *ptr = freeOfHeadList;
	 
	 if (ptr ) {
	 	freeOfHeadList = ptr->next;
	 } else {
	 	Complex *pArr = reinterpret_cast <Complex *>
	 	(::operator new(Complex::BLOCK_SIZE  * sizeof(Complex)));
	 	assert(pArr );
		
		for (int i = 0; i < Complex::BLOCK_SIZE - 1; ++i)
			pArr[i].next = &pArr[i+1];
		pArr[Complex::BLOCK_SIZE-1].next = NULL;
		
		freeOfHeadList = &pArr[1];
		
		ptr = pArr;	
	}
	return ptr;
}

void Complex::operator delete(void *ptr, size_t size)
{
	if (ptr == 0) 
		return;
		
	if (size != sizeof(Complex)) {
		::operator delete(ptr);
	}
	
	Complex *deletNode = reinterpret_cast <Complex *> (ptr);
	deletNode->next = freeOfHeadList;
	freeOfHeadList = deletNode;
}


int Complex::getNumberOfComplex()
{
	return Complex::numberOfComplex;
}

//int i = 100;
//int i(100);

Complex::Complex(double re, double im)
:re_(re), im_(im)  //constructor initialization list
{
//	re_ = re;
//	im_ = im; //멤버변수와 인자 이름이 같으면 생략불가.
	++Complex::numberOfComplex;
}

Complex::Complex(const Complex& rhs)
:re_(rhs.re_), im_(rhs.im_)
{
	++Complex::numberOfComplex;
}
Complex::~Complex()
{
	--Complex::numberOfComplex;
}

bool Complex::operator==(const Complex& rhs) const
{
	return re_ == rhs.re_ && im_ == rhs.im_;
}

const Complex Complex::operator+(const Complex& rhs) const
{
	Complex result(re_ + rhs.re_, im_ + rhs.im_);
	return result;

}

const Complex Complex::operator-(const Complex& rhs) const
{
	Complex result(re_ - rhs.re_, im_ - rhs.im_);
	return result;
}

double Complex::real() const
{
	return re_;
}
double Complex::imag() const
{
	return im_;
}

void Complex::real(double re)
{
	re_ = re;
}

void Complex::imag(double im)
{
	im_ = im;
}




/*
int g_a;

void f(void)
{
	int a;
	
	g_a = 100;
}
int g_a;

//c++  
void f()
{
	int a;
	
	::a = 100; //전역변수 공간을 접근할수있다.
}

*/
