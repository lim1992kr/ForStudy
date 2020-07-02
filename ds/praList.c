#include <stdio.h>

typedef struct Node{
	int data;
	struct Node * next;
}node;

int main(void)
{
	//생성
	node *ptr;
	ptr = malloc(sizeof(node));
	ptr->data = 1;
	ptr->next=malloc(sizeof(node)); 
	ptr->next->data = 3;
	ptr->next->next=malloc(sizeof(node)); 
	ptr->next->next->data = 4;
	ptr->next->next->next=NULL;
	
	//삽입
	node * tmp;
	tmp = malloc(sizeof(node));
	
	
	//삭제
	
	
	// 출력
	node * p;
	p = &ptr;
	while( p != NULL){
	printf("%d",ptr->data);
	p=p->next;	
	}
	
	
	
	return 0;
}





