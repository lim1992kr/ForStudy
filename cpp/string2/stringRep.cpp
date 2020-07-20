#include <cstring>
#include <cassert>
#include "stringRep.h"

StringRep::StringRep()
: str_(new char[1]), len_(1)
{
	str_[0] = '\0';
}
StringRep::StringRep(const char *s)
:str_(new char[strlen(s)+1]), len_(strlen(s))
{
	strcpy(str_, s);
	assert(str_);
}

StringRep::StringRep(const char *s, bool )
: str_((char*)s), len_(strlen(s))
{
	
}
StringRep::~StringRep()
{
	delete [] str_;
}
