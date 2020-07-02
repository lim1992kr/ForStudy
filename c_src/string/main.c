#include<stdio.h>
#include "string.h"

int main(void)
{
	char *str1 = "hello,world";
	
	int len = my_strlen(str1);  //12
	printf("len : %d\n", len);
	
	char str2[20];
	my_strcpy(str2, str1);
	
	my_strcat(str2, "ROS");

	if (my_strcmp(str2, "hello,world ROS" ) == 0 )
		printf("str1 and str2 are equal\n");
	else
		printf("str1 and str2 are not equal\n");

	return 0;
}
