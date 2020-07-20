#include "string.h"
#include <cstring>
#include <cassert>




String& String::operator=(const String& rhs)
{
	if (this != &rhs) {
		--ptr_->rc_;
		if(ptr_ -> rc_ == 0)
			delete ptr_;

		ptr_ = rhs.ptr_;
		++ptr_ ->rc_;
	}
	
	return *this;
}

String& String::operator=(const char *str)
{
	if (ptr_ -> str_ != str) {
		--ptr_ -> rc_;
		if (ptr_ ->rc_ == 0)
			delete ptr_;
			
		ptr_ = new StringRep(str);
	}
	return *this; 
} //s1 = s1.c_str();

bool String::operator==(const String& rhs)const
{
	if (ptr_ == rhs.ptr_)
		return true;
		
	return strcmp(ptr_ ->str_, rhs.ptr_->str_) == 0;
}

const String String:: operator+(const String& rhs)const
{
	char *buf = new char[ptr_->len_ + rhs.ptr_-> len_ +1];
	assert(buf );
	strcpy(buf, ptr_->str_);
	strcat(buf, rhs.ptr_->str_);
	
	String result(buf, true); 
//	delete [] buf;
	
	return result;
}










