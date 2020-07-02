#include <stdio.h>

int main()
{
	// 총 10번 프레임을 돌아가는데 1~9프레임은 2번씩던지고 10프레임은 3번던진다.
	// 각각의 프레임별 합을 계산해야된다.
	int frame[10][3] = {0, };
	int frame10[4] = {0, };
	int frameScore[11] = {0, };
	int i;
	
	for(i = 1 ; i <= 9 ; ++i)
	{
		//첫번째 투구
		// 이상한값?(-값, 10보다 큰값)
		while(1)
		{
			printf("%d game first score : ", i);
			scanf("%d", &frame[i][1]);
			
			if(frame[i][1] < 0 || frame[i][1] > 10)
				printf("Error\n");
			else
				break;
		}

		// 보너스점수들 계산(전전프레임의 총 스코어 + 전프레임 스코어 + 첫번째 투구의 값)
		// 전 프레임에서 스페어 한경우
		if(i > 1 && frame[i-1][1] + frame[i-1][2] == 10 && frame[i][1] != 10)
		{
			frameScore[i-1] = frameScore[i-2] + 10 + frame[i][1];
			printf("%d frame score : %d\n", i-1, frameScore[i-1]);
		}
			
		// 전 프레임이 스트라이크 / 전전 프레임도 스트라이크
		if(i > 2 && frame[i-2][1] == 10 && frame[i-1][1] == 10)
		{
			frameScore[i-2] = frameScore[i-3] + 20 + frame[i][1];
			printf("%d frame score : %d\n", i-2, frameScore[i-2]);
		}
		
		// 두번째 투구
		if(frame[i][1] != 10)
		{
			while(1)
			{
				printf("%d game second score : ", i);
				scanf("%d", &frame[i][2]);
				
				if(frame[i][2] < 0 || frame[i][2] > 10)
					printf("error!\n");
				else if(frame[i][1] + frame[i][2] > 10)
					printf("error!\n");
				else
					break;
			}
		}
		
		// 전 프레임이 스트라이크인가?
		if(i > 1 && frame[i-1][i] == 10)
		{
			frameScore[i-1] = frameScore[i-2] + 10 + frame[i][1] + frame[i][2];
			printf("%d frame score : %d\n", i-1, frameScore[i-1]);
		}
		// 스페어 처리를 못한경우
		if(frame[i][1] + frame[i][2] < 10)
		{
			frameScore[i] = frameScore[i-1] + frame[i][1] + frame[i][2];
			printf("%d frame score : %d\n", i, frameScore[i]);
		}	
	}
	// 10프레임
	// 첫번째 투구
	while(1)
	{
		printf("%d game first score : ", 10);
		scanf("%d", &frame10[1]);
		
		if(frame10[1] < 0 || frame10[1] > 10)
			printf("Error\n");
		else
			break;
	}
	// 직전 프레임이 스페어냐?
	if(frame[i-1][1] + frame[i-1][2] == 10 && frame10[1] != 10)
	{
		frameScore[i-1] = frameScore[i-2] + 10 + frame10[1];
		printf("%d frame socre : %d\n", i-1, frameScore[i-1]);
	}
	// 직전 프레임 스트라이크 && 전전 프레임도 스트라이크
	if(frame[i-2][1] == 10 && frame[i-1][1] == 10)
	{
		frameScore[i-2] = frameScore[i-3] + 20 + frame10[1];
		printf("%d frame socre : %d\n", i-2, frameScore[i-2]);	
	}
	
	
	//두번째 투구
	if(frame10[1] == 10)	// 10프레임의 첫 투구가 스트라이크인 경우
	{
		while(1)
		{
			printf("10 game second score : ");
			scanf("%d", &frame10[2]);
			if(frame10[2] < 0 || frame10[2] > 10)
				printf("error!\n");
			else
				break;
		}
	}
	else					// 10프레임의 첫 투구가 스트라이크가 아닌 경우
	{
		while(1)
		{
			printf("10 game second score : ");
			scanf("%d", &frame10[2]);
			if(frame10[2] < 0 || frame10[2] > 10 || frame10[1] + frame10[2] > 10)
				printf("error!\n");
			else
				break;
		}
	}
	
	//frameScore를 구할 때 전 프레임이 스트라이크!
	if(frame[i-1][1] == 10)
	{
		frameScore[i-1] = frameScore[i-2] + 10 + frame10[1] + frame10[2];
		printf("%d frame score : %d\n", i-1, frameScore[i-1]);
	}
	
	//세번째 투구 -> frame10[1] + frame10[2] >= 10
	if(frame10[1] + frame10[2] >= 10)
	{
		while(1)
		{
			printf("10 game 3rd score : ");
			scanf("%d", &frame10[3]);
			
			if(frame10[3] < 0 || frame10[3] > 10)
				printf("error\n");
			else
				break;
		}
	}
	
	frameScore[10] = frameScore[i-1] + frame10[1] + frame10[2] + frame10[3];
	printf("%d frame score : %d\n", 10, frameScore[10]);
	return 0;
}
