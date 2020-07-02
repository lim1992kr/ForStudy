#include<stdio.h>

int main(void)
{
	const char grades[] ={'F','F','F','F','F','F','D','C','B','A','A'};
	
	int score;
	printf("input score : ");
	scanf("%d", &score);
	
	
		printf("score: %d --- grade : %c\n", score,grades [score/10]);
	return 0;
}
