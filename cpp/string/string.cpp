#include "string.h"
#include <cassert>
#include <cstring>
//컴파일러가 주는 복사생성자를 쓰면 안된다. 포인터멤버를 가지고 힘영역에 자료를 넣엇 ㅓ사용하는 경ㅇ우에 복사생성자 치환연산
//복사생성자는 쉘로카피 딮카피가 되도록 오퍼레이터
//컴플렉스는 컴파일러가 제공하는거 써도 상관없다.


std::ostream& operator << (std::ostream& out, const String& rhs)
{
	out << "(" << rhs.str << " " << rhs.len << "i) ";
	
	return out; 
}//

String::String(const char *str,bool ) //이름과 인자와 타입이 다 같으면 안되니까 의미없는 인자를 준다.
{
	this->str = (char *)str;
	this->len = strlen(str);
}  

void String::set_str(const char *str)
{
	if (str ){
		this->len = strlen(str);
		this->str = new char[this->len + 1];
		assert(this->str );
		strcpy(this->str, str);
	} 	else {
		this->len = 0;
		this->str = new char [1];
		//this->str = new char;  못쓴다 딜리트 대괄호를 썻기 때문에. 하나의 공간 딜리트 , 공간할당 딜리트 []
		assert(this->str );
		this->str[0] = '\0';
		}
}

 /*
String::String()
{

	this->len = 0;
	this->str = new char [1];
	//this->str = new char;  못쓴다 딜리트 대괄호를 썻기 때문에. 하나의 공간 딜리트 , 공간할당 딜리트 []
	assert(this->str );
	this->str[0] = '\0';
	
	this->set_str(NULL);
	
}  
*/
String::String(const char *str)
{
	this->set_str(str);
}

String::String(const String& rhs)
{
/*	this->len = strlen(rhs.len);
	//this->len = rhs.len;
	this->str = new char[this->len + 1];
	assert(this->str );
	strcpy(this->str, rhs,str);
*/
	this->set_str(rhs.str); //반복되는걸 함수로만들어줌
}

String::~String()
{
	delete [] this->str;
}
String& String::operator=(const String& rhs)
{
	if (this != &rhs) { 		//self assignment test.
		delete [] this -> str;
		this->set_str(rhs.str);
	}
	return *this;  //자기자신 객체 
}

String& String::operator=(const char *str)
{
	if (this->str != str){
		delete [] this->str;
		this->set_str(str);	
	}
	return *this;
}

bool String::operator==(const String& rhs)
{
	return strcmp(this->str, rhs.str) == 0; 
}
/*
const String String::operator+(const String& rhs)
{
	char *buf = new char[this->len + rhs.len + 1];
	strcpy(buf, this->str);
	strcat(buf, rhs.str);
	
	String result(buf);
	delete [] buf;
	
	return result;
}
*/
const String String::operator+(const String& rhs)
{
	char *buf = new char[this->len + rhs.len + 1];
	strcpy(buf, this->str);
	strcat(buf, rhs.str);
	
	String result(buf);
	//delete [] buf;
	
	return result;
}

const char *String::c_str()
{
	return this->str;
}

int String::length()
{
	return this->len;
}

/*
char *p = new char;

delete p;

char *p = new char[1];

delete [] p;
*/


