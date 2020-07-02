#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int question[3];
    int answer[3];
   
    srand( time(NULL));

    question[0] = rand() % 9 + 1;
   
    question[1] = rand() % 9 + 1;
    while (question[0] == question[1]){
        question[1] = rand() % 9 + 1;
    }
   
    question[2] = rand() % 9 + 1;
    while (question[0] == question [2] || question[1] == question[2]){
        question[2] = rand() % 9 + 1;
    }
/*   
    //printf("question: %d %d %d\n", question[0], question[1], question[2]);
    int i = 0;
    while (i < 3) {
        printf("%d", question[i]);
        ++i;
    }
    printf("\n");
*/   
    int count = 0;
   
    int strike, ball;
    strike = ball = 0;
   
    while (strike != 3) {
        strike = ball = 0;
       
        printf("input 3 nums: ");
        scanf("%d %d %d", &answer[0], &answer[1], &answer[2]);

        for (int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if (question[i] == answer[j]) {
                    if (i == j){
                        ++strike;
                    } else {
                        ++ball;
                    }
                }
            }
        }
       
        printf("strike : %d\tball: %d\n", strike, ball);
       
        ++count;
    }
   
    printf("Congraturation! Your count : %d\n", count);
   
    return 0;
} 
