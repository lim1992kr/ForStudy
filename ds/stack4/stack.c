#include <assert.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack *ps, int size)
{
	ps->pArr = malloc (sizeof(int) * size);  // 하나당 크기를 배열의 갯수와 곱해서 동적할당을 해준다.
	assert(ps->pArr );//조건이 참이면 진행, 거짓이면 프로그램이 죽는다.  !=NULL 생략
	ps->size = size;
	ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
	free(ps->pArr);
}

void push(Stack *ps, int data)
{
	assert(ps->tos != ps->size);
	
	/*if (ps->tos == ps->size){
		fprintf(stderr, "stack is full\n");
		//stdout 버퍼를 쓴다. stderr 버퍼를 쓰지 않는다.
		exit(1);
		}
	*/
	
	
	ps->pArr[ps->tos] = data;
	++ps->tos;		
}

int pop(Stack *ps)
{
		assert(ps->tos );   //!=NULL생략, 포인터에 적용,
`/*if (ps->tos ==0){
		fprintf(stderr, "stack is empty\n");
		exit(2);
	}
	*/
	
	--ps->tos;
	return ps->pArr[ps->tos];
}
