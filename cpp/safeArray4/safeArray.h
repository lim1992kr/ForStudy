#ifndef SAFEARRAY_H
#define SAFEARRAY_H
#include "array.h"

template <typename T>
class SafeArray : public Array<T> { 
private:
	static const int SAFE_ARRAY_SIZE;
public:
	explicit SafeArray(int size = SafeArray<T>::SAFE_ARRAY_SIZE);	
	
	SafeArray(const T *pArr, int size);
	SafeArray(const SafeArray<T>& rhs);
	virtual ~SafeArray();
	
	SafeArray<T>& operator=(const SafeArray<T>& rhs);
	
	bool operator==(const SafeArray<T>& rhs) const;

	virtual T& operator[](int index);  
	virtual const T& operator[](int index) const;
	 
	
};

#include <cassert>

template <typename T>
const int SafeArray<T>::SAFE_ARRAY_SIZE = 100;

template <typename T>
SafeArray<T>::SafeArray(int size)
: Array<T>(size) //부모쪽에 있는 생성자 호출
{

}

template <typename T>
SafeArray<T>::SafeArray(const T *pArr, int size)
: Array<T>(pArr, size)
{

}

template <typename T>
SafeArray<T>::SafeArray(const SafeArray<T>& rhs)
: Array<T>(static_cast<Array<T>>rhs)
{

}

template <typename T>
SafeArray<T>::~SafeArray() //자동으로 부모쪽에있는 소멸자 생성
{

}

template <typename T>
SafeArray<T>& SafeArray<T>::operator=(const SafeArray<T>& rhs)
{
	//부모쪽에 있는 치환연산 실행
	this->Array<T>::operator=((static_cast<Array<T> >rhs);
	// 
	return *this;
}

template <typename T>
bool SafeArray<T>::operator==(const SafeArray<T>& rhs) const
{
	return this->Array<T>::operator==(static_cast<Array<T> >rhs);
}

template <typename T>
T& SafeArray<T>::operator[](int index)
{
	assert(index >= 0 && index < this->Array<T>::size_);
	
	return this->Array<T>::operator[](index);
}

template <typename T>
const T& SafeArray<T>::operator[](int index) const
{
	assert(index >= 0 && index < this->size());
	
	return this->Array<T>::operator[](index);
}



#endif
