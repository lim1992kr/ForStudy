#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

int main(void)
{
	Node *ptr;
	ptr = malloc(sizeof(Node));
	ptr->data = 1;
	ptr->next = malloc(sizeof(Node));
	ptr->next->data = 3;
	ptr->next->next = malloc(sizeof(Node));
	ptr->next->next->data = 4;
	ptr->next->next->next = NULL;
	
	Node *tmp = malloc(sizeof(Node));
	tmp->data =2;
	tmp->next = ptr->next;
	ptr->next = tmp;
	
	tmp = ptr->next->next;
	ptr->next->next = tmp->next;
	free(tmp);
	
	Node *p = ptr;
	while (p ){
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
	
	return 0;
}
