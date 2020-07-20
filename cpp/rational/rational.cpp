#include <cassert>
#include "rational.h"

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

Rational::Rational(int num, int den) // 생성자 3
{
	assert(den != 0);
	this->num = num;
	this->den = den;
}

Rational::~Rational()	//소멸자
{

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


