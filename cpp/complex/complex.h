#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
private:
	double re;
	double im;
//메인에서 접근 불가능 complex.cpp에서만 수정할수있다.
public:
//생성자 소멸자
	Complex();//입력값이 없는 생성자. default constructor
	//생성하는 방법 3가지 생성하는 방법은 여러가지가 될수있지만 소멸하는거는 하나다.
	//c언어는 똑같은 이름의 함수를 만들수없지만 cpp은 할수있다. but 인자의 갯수 인자의 타입이 달라야한다.
	Complex(double re); //convert construtor
	Complex(double re, double im);			
//소멸자
	~Complex();  		   //destructor 
	
	double real();
	double imag();
	
	void real (double re);
	void imag (double im); 
};

#endif
