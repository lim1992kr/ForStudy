#include "array.h"
#include <cassert>


const int Array::ARRAYSIZE = 100;

void Array::set_arr(const int *pArr, int size)  //중복되는 함수를 빼준다.
{
	this->pArr_ = new int[size]; //할당해주고
	assert(this->pArr_ );
	this->size_ = size;				//사이즈 넣고
	
	for(int i = 0; i < size; ++i)
		this->pArr_[i] = pArr[i];	//데이터 넣고.
}

Array::Array(int size)  
:pArr_(new int[size]), size_(size)
{
	assert(this->pArr_ );
}

Array::Array(const int *pArr, int size)
{
	this->set_arr(pArr, size);
}

Array::Array(const Array& rhs)
{
 	this->set_arr(rhs.pArr_,rhs.size_);
}

Array::~Array()
{
	delete [] this->pArr_; 
}

Array& Array::operator=(const Array& rhs) //복사.
{
	if (this != &rhs){ // ex) a1 = a1; 일때 원본이 삭제방지. 
		delete [] this->pArr_; 				//공간을 날리기. 
		
		this->set_arr(rhs.pArr_, rhs.size_); //복사할값. 뒤에 있는거.
	}
	return *this;
}

bool Array::operator==(const Array& rhs) const //비교 값을 안바꾸니까 const
{
	if (this->size_ != rhs.size_)    //this size_ 는 좌항의 값 rhs.size_는 우항의값
		return false; //싸이즈가 다르면 두개가 다른거니까 바로 false				 // 0				
		
	int i;
	for (i = 0; i < rhs.size_; ++i)		//우항의 사이즈만큼 for문을 돌려서
		if (this->pArr_[i] != rhs.pArr_[i])   //좌항의 0번배열과 우항이 0배열부터 차례로 비교하고 두값이 다르면 if 문을 빠져나온다.
			break; 
	
	return (i == rhs.size_); //i0가 rhs.size의 값(배열의 마지막)까지 가지못하고 나오면 값이 다르니까 0을 리턴하고
								 //i가 rhs.size의 값까지 가서 같은값이면 1을 리턴해준다.
}

int& Array::operator[](int index)   // 상수객체에 사용할수 없고.
{
	return this->pArr_[index];
}

const int& Array::operator[](int index) const  //   <-arr1[i]  상수객체에 사용할수있고  
{
	return this->pArr_[index];  
}

int Array::size() const
{
	return this->size_;
}

