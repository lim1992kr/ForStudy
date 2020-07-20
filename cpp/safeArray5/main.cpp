#include <iostream>
#include "array.h"
#include "safeArray.h"
#include "invaildIndex.h"


int main()
{
	int nums[] = {1,2,3,4,5};
	Array arr1(nums, 5);
	
	for(int i=0; i < arr1.size(); ++i)
		std::cout << arr1[i] << " ";
	std::cout << std::endl;
	
	SafeArray arr3; 				//SafeArray arr3(100);
	SafeArray arr4(10);
	SafeArray arr5(arr4);	
	
	SafeArray arr2(nums,5);
	
	for(int i=0; i < arr2.size(); ++i)
		std::cout << arr2[i] << " ";
	std::cout << std::endl;
	
	try { //exception 이 발생할만한 위치를 묶어준다.
		Array *pArr = new SafeArray(arr2);	
		(*pArr)[5] = 10;		//pArr->operator[] (5) = 10;
		//...
		delete pArr;
	} catch ( const InValidIndex &r ) {
		std::cerr << "boundary exception is occured. error code : " << r.getInvalidIndex() << std::endl;
		return 1;
	}
	/*
	스테틱 바인딩 다이나믹 바인딩
	static binding - compile time에 결정 
	dynamic binding - run time에 결정
		
	포인터타입을 보고 결정나는데 실행시간에 객체의 타입을 보고 결정하고싶을때 버추얼을 쓴다.	
	*/	
	
	delete pArr;
	return 0;
}
