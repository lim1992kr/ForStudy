#include <stdio.h>

int stack[100];		//전역변수는 초기화 된다. 지역변수는 초기화가 안된다.
int tos = -1; //top of stack 마지막 데이터가 들어갈 위치
//tos = 0; =데이터가 들어갈위치 

void push(int data)
{
	++tos;
	stack[tos] = data;
}
//void의 용도 : 1.리턴값이 없는 함수 반환형, 2매개변수가 없을때,3보이드 포인터


int pop(void)
{ 
	//int index = tos;
	//--tos;
	//return stack[index];
	return stack[index--];
}


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
