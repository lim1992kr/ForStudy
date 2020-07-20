#include <cassert>
#include "queue.h"


Queue::Queue(int size)
{
	//this->pArr = (int *)malloc (sizeof(int) * size);
	this->pArr = new int[size];
	assert(this->pArr );//조건이 참이면 진행, 거짓이면 프로그램이 죽는다.  !=NULL 생략
	this->size = size;	
	this->front = 0;
	this->rear = 0;
}

Queue::~Queue()
{
	//free(this->pArr);
	delete[] this -> pArr;
}
void Queue::push(int data)
{
	assert(this->front != this->size); 	
	this->pArr[this->front] = data;
	++this->front;		
}
int Queue::pop()
{
	assert(this->rear != this->front);  
	return this->pArr[this->rear++];
}
