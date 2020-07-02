#include <stdio.h>

int main(void)
{
	int year;
	printf("input year : ");
	scanf("%d", &year);
	
	if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
			printf("%d year is leap year", year);//leap year
	}else{
			printf("%d year is ordinary year", year);// ordinary year
	}
	

	return 0;
	}

