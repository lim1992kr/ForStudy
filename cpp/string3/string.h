#ifndef STRING_H 
#define STRING_H
#include "stringRep.h"
#include <iostream>

class String {
friend std::ostream& operator << (std::ostream& out, const String& rhs); 
//맴버함수 아니고 전역함수다.
private:
	//char *str;
	//int len;
	StringRep *ptr_;
/*	
	StringRep *ptr_; 을 호출하면 아래 세개가 호출된다.
	char *str_;
	int len_;
	int rc_;  //참조 계수 reference counting
*/

	//void set_str(const char *str);				// helper func. tool func.
	String(const char *str, bool); //bool은 의미없는 인자.
	
public:
	//String();
	String(const char *str = 0);  //String s1이 맴버함수를 호출한다. 디폴트 값은 0 
	String(const String& rhs);
	~String();
	
	String& operator=(const String& rhs);
	//오퍼레이트= 연산은  이렇게 생김 데이지 체인연산을하려면 필요하다.,결과값이 s1
	String& operator=(const char *str);
	
	bool operator==(const String& rhs) const;	
	
	const String operator+(const String& rhs) const;
		
	const char *c_str() const {return ptr_->str_;}
	int length() const {return ptr_->len_;}
	//이 함수를 인라인으로 만들어주세요!

	
};

inline std::ostream& operator<<(std::ostream& out,const String& rhs)
{
	return out << rhs.c_str();
}

inline String::String(const char *str, bool)
{
	ptr_ = new StringRep(str, true);
	ptr_->rc_ = 1;
}


inline String::String(const char *str)
{
	if (str ) {
		ptr_ = new StringRep(str);
	}else {
		ptr_ = new StringRep();
	}
	ptr_->rc_ = 1;
}

inline String::String(const String& rhs)
{
	ptr_ = rhs.ptr_;
	++ptr_->rc_;
}

inline String::~String()
{
	--ptr_->rc_;
	if (ptr_-> rc_ = 0)
		delete ptr_;
}


#endif
