#ifndef BOOK_H
#define BOOK_h

enum status {ENABLE_RENT, DISABLE_RENT}

typedef struct {
	char title[100];
	char author[20];
	char publisher[20];
	char date[11];
	char isbn[14];
	int status;
	enum status rentStatus;
	//
}book;



#endif
