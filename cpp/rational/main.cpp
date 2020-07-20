#include <iostream>
#include "rational.h"

int main()
{
	Rational r1;			// 0/1
	Rational r2(3);		// 3/1
	Rational r3(3,4);		// 3/4
	
	r1.setNum(r3.getNum());
	r1.setDen(r3.getDen());
	
	std::cout << "r1: " << r1.getNum() << "/" << r1.getDen() << std::endl;
	std::cout << "r2: " << r2.getNum() << "/" << r2.getDen() << std::endl;
	std::cout << "r3: " << r3.getNum() << "/" << r3.getDen() << std::endl;

	return 0;
}
