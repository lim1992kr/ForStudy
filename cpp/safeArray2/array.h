#ifndef ARRAY_H
#define ARRAY_H

template <typename T>
class Array {   //클래스 이름 생성자 소멸자는 <T>는 안바꾼다.
protected:
	T *pArr_;
	int size_;

private:
	static const int ARRAYSIZE; 

	void set_arr(const T *pArr, int size);
	
public:
	//Array();
	//Array(const Array& rhs);
	//~Array();
	//Array& operator=(const Array& rhs);
	//Array* operator&();
	//const Array* operator&() const;
	
	explicit Array(int size = Array<T>::ARRAYSIZE);	//인자가 하나인 생성자	 //묵시적인 형변환을 막는다.//기본인자로 100개를 줌
	Array(const T *pArr, int size);	//인자가 두개인 생성자
	Array(const Array<T>& rhs);	//복사생성자	
	~Array();		//소멸자.
		
	Array<T>& operator=(const Array<T>& rhs);  //치환연산자
	
	bool operator==(const Array<T>& rhs) const;		//비교연산자
	
	T& operator[](int index);			//대괄호 연산자
	const T& operator[](int index) const;		//두개가 뭐가다름??
	
	int size() const;  //싸이즈를 확인하는 함수.
};

#include <cassert>

template <typename T>
const int Array<T>::ARRAYSIZE = 100;

template <typename T>
void Array<T>::set_arr(const T *pArr, int size)  //중복되는 함수를 빼준다.
{
	this->pArr_ = new T[size]; //할당해주고
	assert(this->pArr_ );
	this->size_ = size;				//사이즈 넣고
	
	for(int i = 0; i < size; ++i)
		this->pArr_[i] = pArr[i];	//데이터 넣고.
}

template <typename T>
Array<T>::Array(int size)  
:pArr_(new T[size]), size_(size)
{
	assert(this->pArr_ );
}

template <typename T>
Array<T>::Array(const T *pArr, int size)
{
	this->set_arr(pArr, size);
}

template <typename T>
Array<T>::Array(const Array<T>& rhs)
{
 	this->set_arr(rhs.pArr_,rhs.size_);
}

template <typename T>
Array<T>::~Array()
{
	delete [] this->pArr_; 
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs) //복사.
{
	if (this != &rhs){ // ex) a1 = a1; 일때 원본이 삭제방지. 
		delete [] this->pArr_; 				//공간을 날리기. 
		
		this->set_arr(rhs.pArr_, rhs.size_); //복사할값. 뒤에 있는거.
	}
	return *this;
}

template <typename T>
bool Array<T>::operator==(const Array<T>& rhs) const //비교 값을 안바꾸니까 const
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

template <typename T>
T& Array<T>::operator[](int index)   // 상수객체에 사용할수 없고.
{
	return this->pArr_[index];
}

template <typename T>
const T& Array<T>::operator[](int index) const  //   <-arr1[i]  상수객체에 사용할수있고  
{
	return this->pArr_[index];  
}

template <typename T>
int Array<T>::size() const
{
	return this->size_;
}


#endif
