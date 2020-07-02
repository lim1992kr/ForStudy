
static int seed;    //전역변수가 메인에 영향을 못주게 static을 붙힌다. 
						//이 파일에서만 작동한다. 

void my_srand(int s)
{
	
	seed = s;   //s는 초값, 초 값을 받아서 seed에 넣고 복잡한값으로 연산하여 랜덤한 값을 얻는다
	
}
int my_rand(void)
{
	seed = seed * 1103515245 + 12345;
	return ((unsigned)(seed/65536) % 32768);   // man 3 rand 를 터미널에 입력하면 예제코드나옴

}
