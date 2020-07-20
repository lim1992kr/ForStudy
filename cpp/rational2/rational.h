#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
	int num;
	int den; //denominate
	
	//void reduce(); //리듀스는 생성자에 의해서만 사용.  helper func. tool func.
public:
	//생성자는 맴버함수, 이름은 class이름과 같다. 
	//Rational();//입력값이 없는 생성자. default constructor 반환값을 안쓴다.
	//생성하는 방법 3가지 생성하는 방법은 여러가지가 될수있지만 소멸하는거는 하나다.
	//c언어는 똑같은 이름의 함수를 만들수없지만 cpp은 할수있다. but 인자의 갯수 인자의 타입이 달라야한다.
	//Rational(int num); //convert construtor
	Rational(int num = 0, int den = 1); //디폴트 인자는 뒤에부터 준다.
	Rational(const Rational& rhs);
	
	~Rational(); 
	
	void operator= (const Rational& rts); 	//레퍼런스
	bool operator== (const Rational& rhs);
	
	const Rational operator+(const Rational& rhs);//지역공간에 객체만들어서 넘기니까 벨류밖에 안됨.
	const Rational operator-(const Rational& rhs);
	const Rational operator*(const Rational& rhs);
	const Rational operator/(const Rational& rhs);
	
	void reduce();
	 
	int getNum();	
	int getDen();
	
	void setNum (int num);
	void setDen (int mo); 
};

#endif
