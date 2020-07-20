#ifndef LIST_H
#define LIST_H
#include <iostream>
class Node{		//Node 자료형
friend class List;

private:
	int data;
	Node *next; //노드타입의 포인터

	Node(int data, const Node *next);
	
	Node(const Node& rhs);						//not use
	Node& operator = (const Node& rhs);		//not use
public:
//	Node* operator&();
//	const Node* operator&() const;
	
	//~Node();	
	int getData() const;
	const Node* getNext() const; 
	
};						

class List {		//List 자료형
friend std::ostream& operator << (std::ostream& out, const List& rhs);

private:
	Node *ptr; //다른 노드 타입의 포인터;
	
	void print(std::ostream& out) const;

	List(const List& rhs);
	List& operator=(const List& rhs);
public:
	List();
	~List();

	void print();

	void insertFirstNode(int data);
	void insertNode(int prevData, int data); 
	void deleteNode(int data);
};

#endif
