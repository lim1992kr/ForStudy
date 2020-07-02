#include <stdio.h>
#include "serial.h"

int main (void)
{
	for (int i = 1 ; i <= 10 ; ++i)
		printf("HYUNDAI_GENESIS_%010d\n", getSerialNumber());

	return 0;
}

