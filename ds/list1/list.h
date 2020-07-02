#ifndef LIST_H
#define LIST_H

typedef struct node{		//Node 자료형
	int data;
	struct node *next; //노드타입의 포인터
} Node;						

typedef struct {		//List 자료형
	Node *ptr; //다른 노드 타입의 포인터;
} List;

void initList(List *pList);
void cleanupList(List *pList);

void printList(const List *pList);

void insertFirstNode(List *plist, int data);
void insertNode(List *pList, int prevData, int data); //들어갈 위치까지 알아야하니까 인자가 3개넘어온다.
void deleteNode(List *pList, int data);

#endif
