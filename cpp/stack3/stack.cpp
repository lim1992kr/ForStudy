#include "stack.h"
#include <cassert>

const int Stack::STACKSIZE = 100;

Stack::Stack(int size)
: arr_(size), tos_(0)
{

}
/*
Stack::Stack(const Stack& rhs)
: arr_(rhs.arr_), tos_(rhs.tos_)
{

}

Stack::~Stack()
{

}


Stack& Stack::operator = (const Stack& rhs)
{
	this->arr_ = rhs.arr_;
	this->tos_ = rhs.tos_;
	
}
*/

bool Stack::operator == (const Stack& rhs) const
{
	if (this->tos_ != rhs.tos_)
		return false;
		
	return this->arr_ == rhs. arr_;  //array.h에 있는 == 을 사용
}

int Stack::size() const
{
	return this->arr_.size();
}

void Stack::push(int data)
{
	assert(this->tos_!= this->size());
	this->arr_[this->tos_] = data;
	++this->tos_;
}

int Stack::pop()
{
	assert(this->tos_ != 0);
	--this->tos_;
	return this->arr_[this->tos_];
	
}









