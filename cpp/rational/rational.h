#ifndef RATIONAL_H
#define RATIONAL_H

class Rational {
private:
	int num;
	int den; //denominate
	
public:
	//생성자는 맴버함수, 이름은 class이름과 같다. 
	Rational();//입력값이 없는 생성자. default constructor 반환값을 안쓴다.
	//생성하는 방법 3가지 생성하는 방법은 여러가지가 될수있지만 소멸하는거는 하나다.
	//c언어는 똑같은 이름의 함수를 만들수없지만 cpp은 할수있다. but 인자의 갯수 인자의 타입이 달라야한다.
	Rational(int num); //convert construtor
	Rational(int num, int den);
	
	~Rational(); 
	
	int getNum();
	int getDen();
	
	void setNum (int num);
	void setDen (int mo); 
};

#endif
