#include <iostream>
#include "complex.h"

int main()
{
	Complex c1;
	Complex c2(3.0);
	Complex c3(3.0,4.0);
	Complex c4(c3);
	
	c1 = c3;
	if(c1 == c3)
		std::cout << "c1 and c3 are equal" << std::endl;
	else
		std::cout << "c1 and c3 are not equal" << std::endl;

	c4 = c1 + c2;
	c4 = c1 - c2;	
	
	std::cout << "inpput c4 : " ;	
	std::cin >> c4;
		
	const Complex c5 = c4;
//	c5.real(5,0); 불가능	
	
//	std::cout <<" c1 : ( " << c1.real() << ", " << c1.imag() << "i)" << std::endl;
	std::cout << "c1 : " << c1 << std::endl; 	//cout,operator<<(c1) operator << (cout,c1)
	std::cout << "c2 : " << c2 << std::endl;
	std::cout << "c3 : " << c3 << std::endl;
 	std::cout << "c4 : " << c4 << std::endl;
 	std::cout << "c5 : " << c5 << std::endl;
 	
 	Complex *pc = new Complex; //스텍상에 객체
 	Complex *pArr[5];
 	pArr[0] = new Complex;
  	pArr[1] = new Complex(1.0);
   	pArr[2] = new Complex(3.0,4.0);
 	pArr[3] = new Complex;
 	pArr[4] = new Complex;   	   		
 	std::cout <<" #Complex object : " << Complex::getNumberOfComplex() << std::endl;
 	delete pc;
 	for	(int i = 0; i < 5; ++i)
 		delete pArr[i];
 	std::cout <<" #Complex object : " << Complex::getNumberOfComplex() << std::endl;
  		
 	return 0;
}

