#include <iostream>
#include "rational.h"

int main()
{
	Rational r1;			// 3/4
	Rational r2(5);		// 3/1
	Rational r3(5,10);		// 3/4
	Rational r4 = r3; 		
	Rational r5;
	Rational r6; 
	Rational r7;
	

	r1 = r3;
	
	if (r1 == r3)		//operator(c1, c3) or c1.operator == (c3)
		std::cout << "r1 and r3 are equal" << std::endl;
	else
		std::cout << "r1 and r3 are not equal" << std::endl;
	
	r4 = r1 + r2;				//c4.operator = (c1.operator+(c2))	
	r5 = r1 - r2;	
	r6 = r1 * r2;
	r7 = r1 / r2;
	
	Rational r8(9,12);
	r8.reduce();
	
	std::cout << "input r4 : "; 
	std::cin >> r4;
	
	r1.setNum(r3.getNum());
	r1.setDen(r3.getDen());
	
	std::cout << "r1: " << r1.getNum() << "/" << r1.getDen() << std::endl;
	std::cout << "r2: " << r2.getNum() << "/" << r2.getDen() << std::endl;
	std::cout << "r3: " << r3.getNum() << "/" << r3.getDen() << std::endl;
	std::cout << "r4 = r1 + r2 : " << r4.getNum() << "/" << r4.getDen() << std::endl;
	std::cout << "r5 = r1 - r2 : " << r5.getNum() << "/" << r5.getDen() << std::endl;
	std::cout << "r6 = r1 * r2 : " << r6.getNum() << "/" << r6.getDen() << std::endl;
	std::cout << "r7 = r1 / r2 : " << r7.getNum() << "/" << r7.getDen() << std::endl;
	std::cout << "r8: " << r8.getNum() << "/" << r8.getDen() << std::endl;

	Rational *pc = new Rational; //스텍상에 객체
 	Rational *pArr[5];
 	pArr[0] = new Rational;
  	pArr[1] = new Rational(1.0);
   	pArr[2] = new Rational(3.0,4.0);
 	pArr[3] = new Rational;
 	pArr[4] = new Rational;   	   		
 	std::cout <<" #Rational object : " << Rational::getNumberOfRational() << std::endl;
 	delete pc;
 	for	(int i = 0; i < 5; ++i)
 		delete pArr[i];
 	std::cout <<" #Rational object : " << Rational::getNumberOfRational() << std::endl;
 	

	return 0;
}
