#ifndef COMPLEX_H
#define COMPLEX_H

class Complex{
private:
	double re;
	double im;
//메인에서 접근 불가능 complex.cpp에서만 수정할수있다.
public:
//생성자 소멸자
	//Complex();//입력값이 없는 생성자. **default constructor
	//생성하는 방법 3가지 생성하는 방법은 여러가지가 될수있지만 소멸하는거는 하나다.
	//c언어는 똑같은 이름의 함수를 만들수없지만 cpp은 할수있다. but 인자의 갯수 인자의 타입이 달라야한다.
	//Complex(double re); //**convert construtor
	Complex(double re = 0.0, double im = 0.0);			
	//Complex(Complex c);		
	Complex(const Complex& ths);//**copy constructor 넘어온 c3를 엘리아싱해서 쓴다.  //right hand side 
									//복사생성자는 인자의 타입이 콘스트 t타입의 레퍼런스다.

	//Complex(const Complex *pc);  모양이 안예뻐서 포인터를 안쓴다.
//소멸자
	~Complex();  		   //destructor 
	
	//void operator = (Complex c); 				//벨류 복사생성자 때문에 오버해드.
	//void operator = (const Complex *pc);		//포인터		모양이 안좋아서 생략.
	void operator= (const Complex& rts); 	//레퍼런스
	
	bool operator== (const Complex& rhs);
	//논리를 나타내는 bool타입.
	
	const Complex operator+(const Complex& rhs);
	const Complex operator-(const Complex& rhs);

	double real();
	double imag();
	
	void real (double re);
	void imag (double im); 
};

#endif

//디폴트 인자든 뒤쪽부터 써야한다.
//Complex  r2(3,0); 








