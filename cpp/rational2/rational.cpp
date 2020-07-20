#include <cassert>
#include "rational.h"

static int getGcd (int a, int b)
{//rational.cpp에서만 쓴다.
	int tmp=0;
	if (a == 0||b == 0)
	return 1;
	while(1){ 
		if(a < b){
		 tmp = a;
		 a = b;
		 b = tmp;	 
		 }	
		if (a % b == 0)
			return b;
		else if(a % b != 0 )
			a = a % b;								 		 
	}
}	


/*
Rational::Rational() //생성자 1
{
	this->num = 0;
	this->den = 1;
}

Rational::Rational(int num) //생성자 2
{
	this->num = num;
	this->den = 1;
}
*/
Rational::Rational(int num, int den) // 생성자 3
{
	assert(den != 0);
	this->num = num;
	this->den = den;
	
}
Rational::Rational(const Rational& rhs)
{
	this->num = rhs.num;
	this->den = rhs.den;
}

Rational::~Rational()	//소멸자
{

}

void Rational::operator= (const Rational& rhs)
{
	this->num = rhs.num;
	this->den = rhs.den; 
}

bool Rational::operator==(const Rational& rhs)
{
/*	if (this->re == ths.re && this -> im == ths.im)
		return true;
	else
		return false; 
*/		
	return (this->num == rhs.num && this->den == rhs.den);	
}

const Rational Rational::operator+(const Rational& rhs)
{/*
	int num = this->num * rhs.den + rhs.num * this->den ;
	int den = this-> den * rhs.den;
	
	Rational result(num,den);    // 3 + 3/4	
	result.reduce();
	return result;
	*/
	Rational result;
	result.den = this->den*rhs.den;
	result.num = rhs.den*this->num + this->den*rhs.num;
	result.reduce();
	return result;
}
const Rational Rational::operator-(const Rational& rhs)
{
	int num = this->num * rhs.den - rhs.num * this->den ;
	int den = this-> den * rhs.den;

	 
	Rational result(num,den);    	 
	result.reduce();
	return result;
}

const Rational Rational::operator*(const Rational& rhs)
{	
	int num = this->num * rhs.num ;
	int den = this-> den * rhs.den;
	 
	Rational result(num, den);    // 3/1 * 3/4	
	result.reduce();
	return result;
}

const Rational Rational::operator/(const Rational& rhs)
{
	int num = this->num * rhs.den ;
	int den = this->den * rhs.num;
	 	 
	Rational result(num, den); // 3/1 / 3/4	
	result.reduce();
	return result; 
}

int Rational::getNum()
{
	return this -> num;
}

int Rational::getDen()
{
	return this-> den;
}

void Rational::setNum(int num)
{
	this->num = num;
}

void Rational::setDen(int den)
{
	this->den = den;
}
void Rational::reduce()
{
	int gcd = getGcd(this->num, this ->den);
	
	this->num = this->num /gcd;
	this->den = this->den /gcd;

}

