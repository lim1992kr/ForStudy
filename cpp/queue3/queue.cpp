#include "queue.h"
#include <cassert>
#include "array.h"
const int Queue::QUEUESIZE = 100;

Queue::Queue(int size)
: arr_(size), front_(0), rear_(0)
{

}
/*
Queue::Queue(const Queue& rhs)
: arr_(rhs.arr_), tos_(rhs.tos_)
{

}

Queue::~Queue()
{

}


Queue& Queue::operator = (const Queue& rhs)
{
	this->arr_ = rhs.arr_;
	this->tos_ = rhs.tos_;
	
}
*/


bool Queue::operator == (const Queue& rhs) const
{
	if (this->front_ != rhs.front_)
		return false;
	if (this->rear_ != rhs.rear_)
		return false;

		
	return (this->arr_ == rhs. arr_);  //array.h에 있는 == 을 사용
}

int Queue::size() const
{
	return this->arr_.size();
}

void Queue::push(int data)
{
	assert(this->front_!= this->size());
	this->arr_[this->front_] = data;
	++this->front_;
}

int Queue::pop()
{
	assert(this->rear_ != this->front_);
	return this->arr_[this->rear_++];
	
}
