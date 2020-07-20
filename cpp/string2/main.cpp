#include <iostream>
#include "string.h"

int main()
{
	String s1;				//디폴트 생성자.
	String s2 = "hello world"; 		//string s2("hello, world");
	String s3(s2);		//복사생성자.
	
	s1 = s2;
	
	s1 = s2 = s3; //daisy-chain
	//s1 = s1;
	s1 = "wonderful tonight"; 		//s1.operator = ("wonderful tonight");
	
	
	
	if (s2 == s3)
		std::cout << "s2 and s3 are equal" << std::endl;
	else
		std::cout << "s2 and s3 are not equal" << std::endl; 
	
	s1 = s2 + " Ros"; 
	 	
	std::cout << "s1 : " << s1 << std::endl;
	std::cout << "s2 : " << s2 << std::endl;
	std::cout << "s3 : " << s3 << std::endl;
	
	//s1 = s1.c_str();
	
	return 0;
}
