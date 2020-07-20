#include <iostream>
#include "boundArray.h"

int main()
{
	int nums[] = {1,2,3,4,5,6,7,8,9,10};
	BoundArray arr1(10, 20); //인덱스 arr을 10부터 20까지 쓴다.
	BoundArray arr2(2, 7, nums);
	BoundArray arr3(arr2);
	
	arr1 = arr3;
	if(arr1 == arr3)
		std::cout << "arr1 and arr3 are equal" << std::endl;
	else	
		std::cout << "arr1 and arr3 are not equal" << std::endl;
	
	for(int i = arr1.lower(); i<= arr2.upper(); ++i)
		std::cout << arr1[i] << std::endl;
	return 0;
}
