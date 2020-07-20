#include <cassert>  //name space 가 적용된 헤더파일. .h가 빠졌을때
#include "stack.h"
//#include <stdlib.h>

Stack::Stack(int size)
{
	//this->pArr = (int *) malloc (sizeof(int) * size);  // 하나당 크기를 배열의 갯수와 곱해서 동적할당을 해준다.
	this->pArr = new int[size];
	assert(this->pArr );
	this->size = size;
	this->tos = 0;
}

Stack::~Stack()
{
	//free(this->pArr);
	delete[] this -> pArr;
}

void Stack::push(int data)
{
	assert(this->tos != this->size);
	this->pArr[this->tos] = data;
	++this->tos;		
}

int Stack::pop()
{
	assert(this->tos );   	
	--this->tos;
	return this->pArr[this->tos];
}
