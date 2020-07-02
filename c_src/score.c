#include<stdio.h>

int main(void)
{
	//int score1,score2,score3,score4,score5,score6,score7,score8,score9,score10;
	int scores[10];
	
	/*scanf("%d",&score1);
	scanf("%d",&score2);
	scanf("%d",&score3);
	scanf("%d",&score4);
	scanf("%d",&score5);
	scanf("%d",&score6);
	scanf("%d",&score7);
	scanf("%d",&score8);
	scanf("%d",&score9);
	scanf("%d",&score10);*/
	
	for (int i=0; i < 10; ++i){
			scanf("%d",&scores[i]);
	}
		
	//int sum = score1 + score2 + score3 + score4 + score5 + score6 + score7 
		//			+ score8 + score9 + score10;
	
	int sum = 0;
	for (int i=0; i < 10; ++i)
		sum = sum+scores[i];  //sum += scores[i];
		
	double average = (double)sum/10;
			
	printf("sum : %d\t average : %.2f\n", sum, average);
					
	return 0;
}
