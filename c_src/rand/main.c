#include <stdio.h>						//기본적으로 라이브러리에 있는 것 가져오는거
#include <time.h>
#include "rand.h"     					//내가 만든 헤더파일

int main(void)
{
	my_srand(time(NULL));
	
	for (int i=1; i<=10; ++i)
		printf("%d\n", my_rand());

	return 0;
}	


