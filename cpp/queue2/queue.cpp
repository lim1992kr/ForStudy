#include <cassert>
#include "queue.h"

const int Queue::QUEUESIZE = 100;

Queue::Queue (int size)
: pArr_(new int[size]), size_(size), front_(0),rear_(0) //초기화 리스트
{
	assert(this->pArr_ );
}

Queue::Queue(const Queue& rhs)
: pArr_(new int[rhs.size_]),size_(rhs.size_), front_(rhs.front_),rear_(rhs.rear_)
{
	assert(this->pArr_ );

	for(int i = rhs.rear_; i < rhs.front_ ; ++i)
		this->pArr_[i] = rhs.pArr_[i];
}
Queue::~Queue()		 
{
	delete[] this -> pArr_;
}

Queue& Queue::operator=(const Queue& rhs)
{
	if (this != &rhs) { 		//self assignment test.
		delete [] this->pArr_;		//원본날리고
		this->pArr_ = new int[rhs.size_]; //새로 할당
		assert(this->pArr_ );
		this->front_ = rhs.front_;
		this->rear_ = rhs.rear_;
		this->size_ = rhs.size_;		
		
		for(int i = rhs.rear_ ; i < rhs.front_; ++i)
			this->pArr_[i] = rhs.pArr_[i];		
	}
	return *this;  //자기자신 객체 
}
bool Queue::operator==(const Queue& rhs)const
{
	if (this->rear_ != rhs.rear_) 
		return false; 		
	if (this->front_ != rhs.front_)  
		return false;
		
	int i;
	for (i = rhs.rear_; i < rhs.front_; ++i)		//우항의 사이즈만큼 for문을 돌려서
		if (this->pArr_[i] != rhs.pArr_[i])   //좌항의 0번배열과 우항이 0배열부터 차례로 비교하고 두값이 다르면 if 문을 빠져나온다.
			break; 
	
	return (i == rhs.front_); //i0가 rhs.size의 값(배열의 마지막)까지 가지못하고 나오면 값이 다르니까 0을 리턴하고
								 //i가 rhs.size의 값까지 가서 같은값이면 1을 리턴해준다.
}
int Queue::size() const
{
	return this->size_;
}

void Queue::push(int data)
{
	assert(this->front_ != this->size_);
	this->pArr_[this->front_] = data;
	++this->front_;	
}

int Queue::pop()
{
	assert(this->front_ != this->rear_);   	
	return this->pArr_[this->rear_++];
}
