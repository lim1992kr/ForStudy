#ifndef BOUNDARRAY_H
#define BOUNDARRAY_H
#include "safeArray.h"

template <typename T>
class BoundArray : public SafeArray<T> {
private:
	int lower_;
//	int upper_;	
public:
	BoundArray(int lower , int upper );
	BoundArray(int lower , int upper, const T *pArr);
	
	bool operator == (const BoundArray<T>& rhs) const;
	
	T& operator[](int index);
	const	T& operator[](int index) const;
	
	int lower() const;
	int upper() const;
};

template <typename T>
BoundArray<T>::BoundArray(int lower, int upper)
: SafeArray<T>(upper - lower + 1), lower_(lower)
{
 
}

template <typename T>
BoundArray<T>::BoundArray(int lower , int upper , const T *pArr)
: SafeArray<T>(pArr + lower, upper - lower +1), lower_(lower)
{

}

template <typename T>
bool BoundArray<T>::operator == (const BoundArray<T>& rhs) const
{
	if (lower_ != rhs.lower_)
		return false;
	
	return this->SafeArray<T>::operator==(static_cast<SafeArray<T>>rhs);
}

template <typename T>
T& BoundArray<T>::operator[](int index)
{
	return this->SafeArray<T>::operator[](index - lower_);
}

template <typename T>
const T& BoundArray<T>::operator[](int index) const
{
	return this->SafeArray<T>::operator[](index - lower_);	
}

template <typename T>	
int BoundArray<T>::lower() const
{
	return lower_;
}

template <typename T>
int BoundArray<T>::upper() const
{
	return lower_ + this->Array<T>::size_ -1; //protected 멤머는 증손자도 접근가능하다. this->Array<T>::size_ -1 ;
}



#endif
