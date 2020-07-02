#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include "stack.h"

void initStack(Stack *ps, int size, int eleSize)
{
	ps->pArr = malloc (eleSize * size);
	assert(ps->pArr );//조건이 참이면 진행, 거짓이면 프로그램이 죽는다.  ==NULL 생략
	ps->eleSize = eleSize;
	ps->size = size;
	ps->tos = 0;
}

void cleanupStack(Stack *ps)
{
	free(ps->pArr);
}

void push(Stack *ps, const void *pData)
{
	assert(ps->tos != ps->size);
	
	/*if (ps->tos == ps->size){
		fprintf(stderr, "stack is full\n");
		//stdout 버퍼를 쓴다. stderr 버퍼를 쓰지 않는다.
		exit(1);
		}
	*/
	
	
	//ps->pArr[ps->tos] = data;
	//memcpy(&ps->pArr[ps->tos], pData, ps->eleSize);
	memcpy((unsigned char *) ps -> pArr + ps->tos * ps->eleSize, pData, ps->eleSize);
	//1바이트만큼씩 움직일려고 unsigned char *를 사용한다.
	++ps->tos;		
}

void pop(Stack *ps, void *pData)
{
		assert(ps->tos );   //==NULL생략
	/*if (ps->tos ==0){
		fprintf(stderr, "stack is empty\n");
		exit(2);
	}
	*/
	
	--ps->tos;
	//return ps->pArr[ps->tos];
	//memcpy(pData, &ps->pArr[ps->tos], ps->eleSize);
	memcpy(pData,(unsigned char *)ps->pArr + ps->tos * ps->eleSize, ps->eleSize);
}
