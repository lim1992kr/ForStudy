#include <iostream>
#include "array.h"


int main()
{
	Array arr1;
	Array arr2(10);					
	//Array arr2 = 10;  
	
	int num[] = {1, 2, 3, 4, 5};
	
	const Array arr3(num, 5); //포인터로 배열을 받아줌. const를 쓰면 상수가 된다. 그래서 좌항에는 사용할수없다.
	Array arr4 = arr3;  // 	Array arr4(arr3);  복사생성자.
	//arr4는 &num을 가지고 있고, 싸이즈가 5인 배열을 가지고있다.
	
	
	arr1 = arr3; // 치환 arr3을 arr1에 복사한다. 딥카피가 될수있도록 오퍼레이터=를 정의한다.
//	
//	for (int i = 0; i < arr3.size(); ++i)
//		arr1[i] = arr3[i];
	
	//arr1 = 10; 안예뻐서 안됨 
	if (arr1 == arr3)
		std::cout << "arr1 and arr3 are equal" << std::endl;
	else
		std::cout << "arr1 and arr3 are not equal" << std::endl;
	
	//arr3[0] = 1;	const를 붙혀서 안됨.
	
	for (int i = 0; i < arr1.size(); ++i)
		std::cout << arr1[i] << " ";		//arr1.operator[](i) //객체에다가 대괄호연산.
	std::cout << std::endl;

	return 0;
}
