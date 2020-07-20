#ifndef STRINGREP_H
#define STRINGREP_H


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


#endif
