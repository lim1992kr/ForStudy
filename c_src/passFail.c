#include<stdio.h>

int main(void){

	int score;
	printf("input score : ");
	scanf("%d", &score);
	
	printf("score : %d ----", score);
		if(score>=60){
			printf("pass");
		}else {
			printf("fail");
			}
			printf("\n");



return 0;
}
