#ifndef LIST_H
#define LIST_H

typedef struct node{		//Node 자료형
	//int data;	
	struct node *next; //노드타입의 포인터
} Node;						

typedef struct {		//List 자료형
	Node *ptr; //다른 노드 타입의 포인터;
	int eleSize;		//엘리먼트 싸이즈
} List;

void initList(List *pList, int eleSize);
void cleanupList(List *pList);

void printList(const List *pList,void (*print)(const void *));

void insertFirstNode(List *plist, const void *pData);
void insertNode(List *pList, const void *prevData, const void *pData);
void deleteNode(List *pList, const void *pData);

#endif
