#include <iostream>
#include "array.h"
#include "safeArray.h"

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
	
	return 0;
}
