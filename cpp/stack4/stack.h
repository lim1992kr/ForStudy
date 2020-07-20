#ifndef STACK_H
#define STACK_H
#include "array.h"

template <typename T>
class Stack{
private:
	static const int STACKSIZE;

	Array<T> arr_;
	int tos_;	

	
public:
	explicit Stack (int size = Stack<T>::STACKSIZE);  //constructor 함수중복하지않고 

	bool operator==(const Stack<T>& rhs)const;	
	
	int size() const;
	
	void push (const T& data);
	const T pop ();
};

#include <cassert>

template <typename T>
const int Stack<T>::STACKSIZE = 100;

template <typename T>
Stack<T>::Stack(int size)
: arr_(size), tos_(0)
{

}

template <typename T>
bool Stack<T>::operator == (const Stack<T>& rhs) const
{
	if (this->tos_ != rhs.tos_)
		return false;
		
	return this->arr_ == rhs. arr_;  //array.h에 있는 == 을 사용
}

template <typename T>
int Stack<T>::size() const
{
	return this->arr_.size();
}

template <typename T>
void Stack<T>::push(const T& data)
{
	assert(this->tos_!= this->size());
	this->arr_[this->tos_] = data;
	++this->tos_;
}

template <typename T>
const T Stack<T>::pop()
{
	assert(this->tos_ != 0);
	--this->tos_;
	return this->arr_[this->tos_];
	
}
#endif
