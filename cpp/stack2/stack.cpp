#include <cassert>  //name space 가 적용된 헤더파일. .h가 빠졌을때
#include "stack.h"
//#include <stdlib.h>

const int Stack::STACKSIZE = 100;

Stack::Stack(int size)
: pArr_(new int[size]), size_(size), tos_(0) //초기화 리스트
{
	assert(this->pArr_ );
}

Stack::Stack(const Stack& rhs)
: pArr_(new int[rhs.size_]),size_(rhs.size_), tos_(rhs.tos_)
{
	this->pArr_ = new int[rhs.size_];
	assert(this->pArr_ );
	this->size_ = rhs.size_;
	this->tos_ = rhs.tos_;
	
	for(int i = 0; i < rhs.tos_ ; ++i)
		this->pArr_[i] = rhs.pArr_[i];
}

Stack::~Stack()
{
	delete[] this -> pArr_;
}

Stack& Stack::operator=(const Stack& rhs)
{
	if (this != &rhs) { 		//self assignment test.
		delete [] this->pArr_;		//원본날리고
		this->pArr_ = new int[rhs.size_]; //새로 할당
		assert(this->pArr_ );
		this->tos_ = rhs.tos_;
		this->size_ = rhs.size_;		
		
		for(int i = 0 ; i < rhs.tos_; ++i)
			this->pArr_[i] = rhs.pArr_[i];		
	}
	return *this;  //자기자신 객체 
}

bool Stack::operator==(const Stack& rhs)
{
	if (this->size_ != rhs.size_) 
		return false; 		
	if (this->tos_ != rhs.tos_)  
		return false;
		
	int i;
	for (i = 0; i < rhs.tos_; ++i)		//우항의 사이즈만큼 for문을 돌려서
		if (this->pArr_[i] != rhs.pArr_[i])   //좌항의 0번배열과 우항이 0배열부터 차례로 비교하고 두값이 다르면 if 문을 빠져나온다.
			break; 
	
	return (i == rhs.tos_); //i0가 rhs.size의 값(배열의 마지막)까지 가지못하고 나오면 값이 다르니까 0을 리턴하고
								 //i가 rhs.size의 값까지 가서 같은값이면 1을 리턴해준다.
}

int Stack::size() const
{
	return this->size_;
}

void Stack::push(int data)
{
	assert(this->tos_ != this->size_);
	this->pArr_[this->tos_] = data;
	++this->tos_;		
}

int Stack::pop()
{
	assert(this->tos_ != 0);   	
	--this->tos_;
	return this->pArr_[this->tos_];
}
