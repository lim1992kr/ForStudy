#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
friend std::istream& operator >>(std::istream& in, Rational& rhs);
friend std::ostream& operator << (std::ostream& out, const Rational& rhs); //전역함수 
private:
	static int numberOfRational; //전역변수는 초기화 되서 0이다.
	static const int BLOCK_SIZE;
	static Rational * headOfFreeList;
	
	union {
		struct{	
			mutable int num_;
			mutable int den_; //denominate
		};	
		Rational *next;
	};
	//void reduce(); //리듀스는 생성자에 의해서만 사용.  helper func. tool func.
public:
	static int getNumberOfRational();	
	//생성자는 맴버함수, 이름은 class이름과 같다. 
	//Rational();//입력값이 없는 생성자. default constructor 반환값을 안쓴다.
	//생성하는 방법 3가지 생성하는 방법은 여러가지가 될수있지만 소멸하는거는 하나다.
	//c언어는 똑같은 이름의 함수를 만들수없지만 cpp은 할수있다. but 인자의 갯수 인자의 타입이 달라야한다.
	//Rational(int num); //convert construtor
	
	static void *operator new (size_t size);
	static void operator delete(void *ptr, size_t size); 
	
	Rational(int num = 0, int den = 1); //디폴트 인자는 뒤에부터 준다.
	Rational(const Rational& rhs);
	
	~Rational(); //소멸자도 제공해주는거 쓴다.
	//복사연산자와 치환연산자는 자동생성되니까 안만들어도 괜찮다.
	//Rational& operator= (const Rational& rts); 	//레퍼런스
	bool operator== (const Rational& rhs) const; //레퍼런스가 상수객체로 실행하냐 
															//레퍼런스가 리드온니냐

	const Rational operator+(const Rational& rhs) const;//지역공간에 객체만들어서 넘기니까 벨류밖에 안됨.
	
	const Rational operator-(const Rational& rhs) const;
	const Rational operator*(const Rational& rhs) const;
	const Rational operator/(const Rational& rhs) const;
	
	void reduce()const;
	 
	int getNum() const;//바꾸는거 아니니까 const를 붙혀준다.	
	int getDen() const;
	
	void setNum (int num);
	void setDen (int mo); 
};

#endif
