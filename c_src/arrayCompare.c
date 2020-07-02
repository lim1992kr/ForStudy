#include<stdio.h>

int main(void)
{
	int nums1[] = {1,2,3,4,5};
	int nums2[5];
	
	//nums2 = nums1 ;
	
	for (int i = 0; i < 5; ++i)
		nums2[i] = nums1[i] ;
	
/*   if (nums1 == nums2)
		printf("nums1 = nums2\n");
	else
		printf(("nums1 != nums2\n");
*/

	int i;
	for ( i =0; i<5; ++i)
		if (nums1[i] != nums2[i])
		break;
		
	if (i ==5)
	printf("nums1 = nums2\n");
	else
		printf("nums1 != nums2\n");
	return 0;
}
