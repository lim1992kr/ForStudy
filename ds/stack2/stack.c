static int stack[100];		//전역변수는 초기화 된다. 지역변수는 초기화가 안된다.
//int tos = -1; //top of stack 마지막 데이터가 들어갈 위치
static int tos = 0; //데이터가 들어갈위치 
//static 읽기전용 다른함수에서 바꾸면 안되니까.  메인쪽에서 접근할수없게. puch와 pop을이용해야만 접근할수있다.
void push(int data)
{
	stack[tos] = data;
	++tos;
	//이 함수를 불러서 값을 넣으면 인덱스가 1씩 증가 하면서 배열을 체운다.
}
//void의 용도 : 1.리턴값이 없는 함수 반환형, 2매개변수가 없을때,3보이드 포인터


int pop(void)
{ 
	//int index = tos;
	//tos;
	//return stack[index];
	return stack[tos--];
	
	
}

