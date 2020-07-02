
#include "string.h"


int my_strlen ( const char *str)
{
	while (*str++ )
		++count;
		
	
	return count;
	
}

void my_strcpy(char *des, const char *src)
{			

	while (*des++ = *src++;)
		;
	
}

void my_strcat(char *des, const char *src)
{
	mu_strcpy(des + strlen(des), src);
}

int my_strcmp(const char *s1, const char *s2)   			// 배열배열비교
{
	while (*s1++ == *s2++ )
		;
		return *s1 - *s2;	
		
}
