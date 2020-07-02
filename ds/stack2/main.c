#include <stdio.h>     // 유저 밑에 인클루드 에 있는 헤더파일
#include "stack.h"		//"" 내가 만든 헤더파일


int main(void)
{
	push(100);
	push(200);
	push(300);

	printf("1st pop() : %d\n", pop());
	printf("2nd pop() : %d\n", pop());
	printf("3rd pop() : %d\n", pop());
	return 0;
}



