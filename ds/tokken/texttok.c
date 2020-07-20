#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[] = "aaa bbb ccc\tddd\nfff";
	
	char *token = strtok(str, "\t\n");
	printf("%s\n", token);
	
	while (token = strtok(NULL, "\t\n"))
		printf("%s\n", token);
			
	return 0;
}
