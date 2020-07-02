#include "serial.h"


int getSerialNumber(void)
{
	static int count = 1;
	return count++;
}
