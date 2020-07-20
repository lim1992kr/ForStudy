#ifndef STRINGREP_H
#define STRINGREP_H
#include <cassert>
#include <cstring>
class StringRep {
friend class String;  //String이 StringRep에 맴버변수에 접근할수있다. string은 stringRep 객체를 만들수있다.
private:
	char *str_;
	int len_;
	int rc_;

	StringRep();
	StringRep(const char *s);
	StringRep(const char *s, bool );
	~StringRep();	

	StringRep(const StringRep& rhs);					//not use
	StringRep& operator=(const StringRep& rhs);			//not use
public:

};


inline StringRep::StringRep()
: str_(new char[1]), len_(1)
{
	str_[0] = '\0';
}
inline StringRep::StringRep(const char *s)
:str_(new char[strlen(s)+1]), len_(strlen(s))
{
	strcpy(str_, s);
	assert(str_);
}

inline StringRep::StringRep(const char *s, bool )
: str_(const_cast<char*>s), len_(strlen(s))
{
	
}
inline StringRep::~StringRep()
{
	delete [] str_;
}

#endif
