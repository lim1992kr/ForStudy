#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
	int lotto[7];
	
	srand( time(NULL));
	
	lotto[0] = rand() % 45 + 1;
    
	for(int i = 0; i < 7 ; ++i){
		lotto[i] = rand() % 45 + 1;
		for(int j = 0; j < 7 ; ++j){
			if(lotto[i]==lotto[j]}
				break;
				}
				
		printf("%d\n", lotto[i]);
	}       
	return 0;
}
