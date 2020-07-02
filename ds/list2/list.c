#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>

static Node *createNode(const void *pData, int eleSize, Node *next)
{
	Node *ptr = malloc(sizeof(Node) + eleSize);
	assert(ptr );
	
	memcpy(ptr + 1, pData, eleSize);
	ptr->next = next;
	
	return ptr;
}

void initList(List *pList, int eleSize) //받은 주소를 포인터 변수에 넣는다.
{
	//pList->ptr = malloc(sizeof(Node)); //dummy node
	//assert(pList->ptr );
	pList->eleSize = eleSize;	
	//pList -> ptr -> next = NULL;
	
	pList->ptr = createNode(NULL, 0 ,NULL);
}

void cleanupList(List *pList)
{
	Node *ptr = pList->ptr;
	while (ptr !=NULL ){
		Node *tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		//free (ptr); //해제시킨 공간에 접근해서 넥스트를 쓴다.
		//ptr= ptr->next;
	}
}

void printList(const List *pList, void (*print)(const void *))
{
	Node *ptr = pList->ptr->next; //pList->ptr->next가 가지고 있는 주소를 *ptr에 담아준다.
	printf("[");
	while (ptr != NULL) { 	//ptr이 담는 주소가 0일때 까지
		(*print)(ptr+1); 	//printf(ptr+1);
		printf("%s",(ptr->next )? "," : ""); 
		//ptr->data를 프린트하고 ptr->next이 NULL이 아니면 ,를 출력하고 NULL이면 빈칸을 출력한다.
		ptr = ptr->next;		//다음 주소값을 확인한다.
	}
	printf("]\n");
}

void insertFirstNode(List *pList, const void *pData)
{
/*
	Node *ptr = malloc(sizeof(Node)+ pList->eleSize); //포인터를 저장할 노트크기 + 엘리먼트 사이즈 해서 
	assert(ptr );
	//ptr->data = data; 	//함수에서 받아온 4를 넣는다
	//memcpy((unsigned char*)ptr+pList->eleSize,pData,pList->eleSize); //저수준에서
	memcpy(ptr + 1,pData, pList->eleSize);
	ptr->next = pList->ptr->next; //더미 노드에 있는 NULL을  ptr->next에 대입한다.
	pList->ptr->next = ptr;//더미노드가 ptr이 가르키던 4를 가르킨다.
*/

	pList->ptr->next = createNode(pData, pList->eleSize, pList->ptr->next);
}

void insertNode(List *pList, const void * prevData, const void *pData)
{
	Node *ptr = pList->ptr->next;//첫번째에 있는 노드의 주소를 담는다.
	while (ptr ) {
		//if (ptr->data == prevData) 	//가르키고 있는 
		if(memcmp(ptr + 1, prevData, pList->eleSize)==0)
			break;
		ptr = ptr->next;
	}
	
	if (ptr ){
	/*	Node *tmp = malloc(sizeof(Node)+ pList->eleSize);		//tmp가 가르키는 노드를 만든다.
		assert(tmp );		//!=NULL
		//tmp->data = data;	
		memcpy(tmp + 1, pData, pList->eleSize); 		
		tmp->next = ptr->next;
		ptr->next = tmp;
	*/
	ptr -> next = createNode(pData, pList->eleSize, ptr->next);
		
	}
}

void deleteNode(List *pList, const void *pData)
{
	Node *ptr1 = pList->ptr->next; //실제로 데이터가 들어있는 노드
	Node *ptr2 = pList->ptr;	//더미노드를 가르킨다.
	
	while (ptr1 ) {  //값을 못찾으면 넘어간다.
		//if (ptr1->data == data) //데이터가 찾는 데이터인지 확인하고 맞으면 나온다.
		if(memcmp(ptr1 + 1, pData, pList->eleSize) == 0)
			break;
		
		ptr1= ptr1-> next; 	//먼저가고
		ptr2= ptr2-> next;	//뒤따라간다.
	}
	
	if (ptr1 ){ //값을 찾은거
	ptr2->next = ptr1->next; //앞에있던 노드에 담아았던 주소값을 뒤에있던 노드에 담아주고 헤제시킨다.
	free(ptr1); 
	}
}
