#ifndef QUEUE_H //만약 정의가 안되어있으면 불러와라. 해더파일을 두번 불러오지 않게하는거
#define QUEUE_H// 정의하면서 불러온다,.
#include "array.h"	//해즈어 관계
//#define QUEUESIZE 100

template <typename T>
class Queue {
private:
	static const int QUEUESIZE;
		
	Array<T> arr_;
	int front_;
	int rear_;	

public:

	explicit Queue (int size = Queue<T>::QUEUESIZE);  //constructor 함수중복하지않고 

	bool operator==(const Queue<T>& rhs)const;	
	
	int size() const;
	
	
	void push(const T& data); // 클래스 단위의 객체가 넘어올수도 있기때문에
	const T pop();

};

#include <cassert>

template <typename T>
const int Queue<T>::QUEUESIZE = 100;

template <typename T>
Queue<T>::Queue(int size)
: arr_(size), front_(0), rear_(0)
{

}

template <typename T>
bool Queue<T>::operator == (const Queue<T>& rhs) const
{
	if (this->front_ != rhs.front_)
		return false;
	if (this->rear_ != rhs.rear_)
		return false;

		
	return (this->arr_ == rhs. arr_);  //array.h에 있는 == 을 사용
}

template <typename T>
int Queue<T>::size() const
{
	return this->arr_.size();
}

template <typename T>
void Queue<T>::push(const T& data)
{
	assert(this->front_!= this->size());
	this->arr_[this->front_] = data;
	++this->front_;
}

template <typename T>
const T Queue<T>::pop()
{
	assert(this->rear_ != this->front_);
	return this->arr_[this->rear_++];
	
}

#endif	//	정의가 되어있으면 종료해라.

