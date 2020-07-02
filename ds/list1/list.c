#include "list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

static Node *createNode(int data,Node *next)		//여기서만 쓸수있고 메인에서는 쓸수없다.
{
	Node *ptr = malloc(sizeof(Node)); //동적할당으로 노드를 만든다.
	assert(ptr );				//동적할당에 실패하면 프로그램을 종료한다.
	ptr->data = data;
	ptr->next = next;
	
	return ptr;
}

void initList(List *pList) //받은 주소를 포인터 변수에 넣는다.
{
//	pList->ptr = malloc(sizeof(Node)); //dummy node
//	assert(pList->ptr);
	//pList->ptr->data = ??;
//	pList -> ptr -> next = NULL;
	pList ->ptr = createNode(-1,NULL);  //더미에 필요없는값 넣어준다.
}

void cleanupList(List *pList)
{
	Node *ptr = pList->ptr;
	while (ptr !=NULL ){
		Node *tmp = ptr; //임시로 만들어서 초기화 시켜준뒤 다음 칸으로 이동한다.
		ptr = ptr->next;
		free(tmp);
		//free(ptr); //해제시킨 공간에 접근해서 넥스트를 쓴다.
		//ptr= ptr->next;
	}
}

void printList(const List *pList)
{
	Node *ptr = pList->ptr->next; //pList->ptr->next가 가지고 있는 주소를 *ptr에 담아준다.
	printf("[");
	while (ptr != NULL) { //ptr이 담는 주소가 0일때 까지
		printf("%d %s", ptr->data , (ptr->next!=NULL)? "," : ""); 
		//ptr->data를 프린트하고 ptr->next이 NULL이 아니면 ,를 출력하고 NULL이면 빈칸을 출력한다.
		ptr = ptr->next;	//다음 주소값을 확인한다.
	}
	printf("]\n");
}

void insertFirstNode(List *pList, int data)
{
	//Node *ptr = malloc(sizeof(Node)); //새로운 *ptr을 만든다.
	//assert(ptr );
	//ptr->data = data; 	//함수에서 받아온 4를 넣는다
	//ptr->next = pList->ptr->next; //더미 노드에 있는 NULL을  ptr->next에 대입한다.
	//pList->ptr->next = ptr;//더미노드가 ptr이 가르키던 4를 가르킨다.
	pList->ptr->next = createNode(data,pList->ptr->next);
	
}

void insertNode(List *pList, int prevData, int data)
{
	Node *ptr = pList->ptr->next;//첫번째에 있는 노드의 주소를 담는다.
	while (ptr ) {
		if (ptr->data == prevData) 	//가르키고 있는 
			break;
		ptr = ptr->next;
	}
	
	if (ptr ){
//		Node *tmp = malloc(sizeof(Node));		//tmp가 가르키는 노드를 만든다.
//		assert(tmp ); 		
//		tmp->data = data;	
//		tmp->next = ptr->next;
//		ptr->next = tmp;
		ptr->next = createNode(data, ptr->next);	
	}
}

void deleteNode(List *pList, int data)
{
	Node *ptr1 = pList->ptr->next; //실제로 데이터가 들어있는 노드
	Node *ptr2 = pList->ptr;	//더미노드를 가르킨다.
	
	while (ptr1 ) {  //값을 못찾으면 넘어간다.
		if (ptr1->data == data) //데이터가 찾는 데이터인지 확인하고 맞으면 나온다.
			break;
		
		ptr1= ptr1-> next; 	//먼저가고
		ptr2= ptr2-> next;	//뒤따라간다.
	}
	
	if (ptr1 ){ //값을 찾은거
	ptr2->next = ptr1->next; //앞에있던 노드에 담아았던 주소값을 뒤에있던 노드에 담아주고 헤제시킨다.
	free(ptr1); 
	}
}

