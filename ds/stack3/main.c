/*
push함수를 그냥 호출하면 s1의 인자값 전부를 복사해가서 메모리를 많이 쓴다.
*/

#include <stdio.h>
#include "stack.h"

int main(void)
{
//구조체 : 사용자 정의형. 내가 원하는 자료를 찍어내고싶을때 구조체를 정의해서 쓴다.
	Stack s1,s2;	
	
	//s1.tos = 0;
	//s2.tos = 0;
	
	initStack(&s1);  //s1.tos 와 s2.tos를 초기화 해주는 함수.
	initStack(&s2);
	
	push(&s1,100); /push 함수로 넣을 위치의 주소와 값을 설정해준다.
	push(&s1,200);
	push(&s1,300);		
	
	//어느스택에 넣을꺼냐 = 인자로 전달한다.
	
	printf("s1 1st pop(): %d\n", pop(&s1)); //주소에 있는 값을 읽어온다.
	printf("s1 2nd pop(): %d\n", pop(&s1));
	printf("s1 3rd pop(): %d\n", pop(&s1));

	push(&s2,900);
	push(&s2,800);
	push(&s2,700);		
	
	printf("s2 1st pop(): %d\n", pop(&s2));
	printf("s2 2nd pop(): %d\n", pop(&s2));
	printf("s2 3rd pop(): %d\n", pop(&s2));

	return 0;
}


