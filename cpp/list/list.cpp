#include "list.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

Node::Node(int data, const Node *next)
{
	this->data = data;
	this->next = (Node *)next;
}

int Node::getData() const
{
	return this->data;
}

const Node* Node::getNext() const
{
	return this->next;
}
std::ostream& operator << (std::ostream& out, const List& rhs)
{
	rhs.print(out);	
		
	return out;
}
void List::print(std::ostream& out) const
{
	Node *ptr = this->ptr->next;
	out << "[";
	while (ptr ) {
		out << ptr->data << ((ptr->next) ? ", ": " ");
		ptr = ptr->next;
	}
	out << "]"; 
}

List::List() //받은 주소를 포인터 변수에 넣는다.
{
	this->ptr = new Node(-1,NULL);  //더미에 필요없는값 넣어준다.
}

List::~List()
{
	Node *ptr = this->ptr;
	while (ptr !=NULL ){
		Node *tmp = ptr; //임시로 만들어서 초기화 시켜준뒤 다음 칸으로 이동한다.
		ptr = ptr->next;
		delete tmp;
		//free(ptr); //해제시킨 공간에 접근해서 넥스트를 쓴다.
		//ptr= ptr->next;
	}
}


void List::insertFirstNode(int data)
{
	this->ptr->next = new Node(data,this->ptr->next);	
}

void List::insertNode(int prevData, int data)
{
	Node *ptr = this->ptr->next;//첫번째에 있는 노드의 주소를 담는다.
	while (ptr ) {
		if (ptr->data == prevData) 	//가르키고 있는 
			break;
		ptr = ptr->next;
	}
	
	if (ptr ){

		ptr->next = new Node(data, ptr->next);	
	}
}

void List::deleteNode(int data)
{
	Node *ptr1 = this->ptr->next; //실제로 데이터가 들어있는 노드
	Node *ptr2 = this->ptr;	//더미노드를 가르킨다.
	
	while (ptr1 ) {  //값을 못찾으면 넘어간다.
		if (ptr1->data == data) //데이터가 찾는 데이터인지 확인하고 맞으면 나온다.
			break;
		
		ptr1= ptr1-> next; 	//먼저가고
		ptr2= ptr2-> next;	//뒤따라간다.
	}
	
	if (ptr1 ){ //값을 찾은거
	ptr2->next = ptr1->next; //앞에있던 노드에 담아았던 주소값을 뒤에있던 노드에 담아주고 헤제시킨다.
	delete ptr1;
	}
}

