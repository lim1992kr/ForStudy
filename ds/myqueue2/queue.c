static int queue[100];  //static을 넣으면 다른 .c파일에서 접근할수없다. 여기 안에서만 사용할수있다.
static int front; 	//뺄자리
static int rear; // 들어갈자리

//함수정의는 다른 c파일에 있을수있다.
void push(int data)
{
	queue[rear] = data;
	++rear;
}
int pop(void)
{
	//int index = front;
	//++front;
	//return queue[front];
	return queue[front++];
}
 
