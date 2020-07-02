#ifndef DATE_H
#define DATE_H

typedef struct date{
	int year;
	int month;
	int day;
}Date;

void printDate(const Date *pd);

#endif
