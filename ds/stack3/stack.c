#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack *ps)
{
	ps->tos = 0; //포인터로 받아온 값 구조체 자료 s에 tos(index)값을 초기화한다.
}

void push(Stack *ps, int data)
{
	if (ps->tos == STACKSIZE){  		//인덱스는 무조건 배열의 크기보다 하나 작아햐 하는데 인덱스가 배열의 크기와 같아지면 오류를 보낸다.
		fprintf(stderr, "stack is full\n");
		//stdout 버퍼를 쓴다. stderr 버퍼를 쓰지 않는다.
		exit(1);
	}
	ps->arr[ps->tos] = data; //push함수에서 주소를 보냈으니까 ps로 그 주소를 받아와서
								 //->로 arr[0]에다가 첫번째 data를 넣는다.
	++ps->tos;	  //(ps->tos+1)을 해줘서 arr[1] 번째로 이동시킨다.
}

int pop(Stack *ps)
{
	if (ps->tos ==0){     //인덱스가 0이면 다음 출력할때 인덱스 값이 -1이 되기 때문에 0이면 종료한다.
		fprintf(stderr, "stack is empty\n");
		exit(2);
	}
	
	--ps->tos;
	return ps->arr[ps->tos];
}
