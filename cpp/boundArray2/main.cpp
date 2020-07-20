#include <iostream>
#include "boundArray.h"

int main()
{
	int nums1[] = {1,2,3,4,5,6,7,8,9,10};
	BoundArray<int> arr1(10, 20); //인덱스 arr을 10부터 20까지 쓴다.
	BoundArray<int> arr2(2, 7, nums1);
	BoundArray<int> arr3(arr2);
	
	arr1 = arr3;
	if(arr1 == arr3)
		std::cout << "arr1 and arr3 are equal" << std::endl;
	else	
		std::cout << "arr1 and arr3 are not equal" << std::endl;
	
	for(int i = arr2.lower(); i<= arr2.upper(); ++i)
		std::cout << arr2[i] << std::endl;


	double nums2[] = {1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.10};
	BoundArray<double>  arr4(10, 20); //인덱스 arr을 10부터 20까지 쓴다.
	BoundArray<double>  arr5(2, 7, nums2);
	BoundArray<double>  arr6(arr5);
	
	arr4 = arr6;
	if(arr4 == arr6)
		std::cout << "arr4 and arr6 are equal" << std::endl;
	else	
		std::cout << "arr4 and arr6 are not equal" << std::endl;
	
	for(int i = arr5.lower(); i<= arr5.upper(); ++i)
		std::cout << arr5[i] << std::endl;

	return 0;
}
