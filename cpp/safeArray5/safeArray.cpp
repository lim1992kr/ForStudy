#include <cassert>
#include "safeArray.h"
#include "invalidIndex.h"

const int SafeArray::SafeArray::SAFE_ARRAY_SIZE = 100;

SafeArray::SafeArray(int size)
: Array(size) //부모쪽에 있는 생성자 호출
{

}

SafeArray::SafeArray(const int *pArr, int size)
: Array(pArr, size)
{

}

SafeArray::SafeArray(const SafeArray& rhs)
: Array(static_cast<Array>rhs)
{

}

SafeArray::~SafeArray() //자동으로 부모쪽에있는 소멸자 생성
{

}

SafeArray& SafeArray::operator=(const SafeArray& rhs)
{
	//부모쪽에 있는 치환연산 실행
	this->Array::operator=(static_cast<Array>rhs);
	// 
	return *this;
}

bool SafeArray::operator==(const SafeArray& rhs) const
{
	return this->Array::operator==(static_cast<Array>rhs);
}

int& SafeArray::operator[](int index)
{
	//assert(index >= 0 && index < this->Array::size_);
	if (index < 0 || index >= this->Array::size_)
	throw InvalidIndex(index);
	
	
	return this->Array::operator[](index);
}

const int& SafeArray::operator[](int index) const
{
	//assert(index >= 0 && index < this->size());
	if (index < 0 || index >= this->Array::size_)
	throw InvalidIndex(index);
	
	return this->Array::operator[](index);
}


