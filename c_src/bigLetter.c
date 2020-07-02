#include <stdio.h>

int main(void){
	
	char ch;
	printf("input char : ");
	scanf("%c", &ch);
	
	if (ch >= 'A' && ch <= 'Z'){
		printf("ch : %c --- bigletter \n",ch);	
	}


	return 0;
}
