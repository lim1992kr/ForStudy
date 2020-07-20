#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>




class Complex {
friend std::istream& operator >> (std::istream& in, Complex& rhs);
friend std::ostream& operator << (std::ostream& out, const Complex& rhs); //전역함수  

private:
	static int numberOfComplex; //전역변수는 초기화 되서 0이다.
	static const int BLOCK_SIZE;
	static Complex *freeOfHeadList;
		//생성자에서 증가시키고 소멸자에서 감소시킨다. 전역변수.
	union {
		struct {
			double re_; //m_re mRe re_ 맴버변수와 지역변수의 이름이 다르면 this->를 생략할수있다.
			double im_;
		};
		Complex *next;
	};
	
public:
	static int getNumberOfComplex();
	static void *operator new(size_t size);
	static void  operator delete(void *ptr, size_t size);


	Complex(double re = 0.0, double im = 0.0);
	Complex(const Complex& rhs);
	~Complex();
	
	// Compelx& operator=(const Complex& rhs);
	bool operator==(const Complex& rhs) const;//상수객체에도 호출가능
	
	const Complex operator+(const Complex& rhs) const;
	const Complex operator-(const Complex& rhs) const;
	
	double real() const;
	double imag() const;
	
	void real(double re);
	void imag(double im);
};

#endif
