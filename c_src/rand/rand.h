#ifndef RAND_H  
#define RAND_H

void my_srand(int);  //s 는 seed의 약자 srand는 시간을 기준으로 계속 값이 바뀐다.
int my_rand(void); 		//rand 함수는 종료하고 다시 하면 같은값을 갖는다.

#endif   //한번만 복붙될수있도록
