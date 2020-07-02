#include <stdio.h>
#include "date.h"

void printDate(const Date *pd)
{
	//printf("(%d/%d/%d)\n", (*pd).year, (*pd).month, (*pd).day);
	printf("(%d/%d/%d)\n",pd->year, pd->month, pd->day);
}
