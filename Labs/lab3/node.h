// #pragma once is shorthand for the #include guards you've seen before.
#pragma once

class Node
{
public:
	// Constructors and destructor
	Node();
	Node(int x);
	Node(int x, Node* nd);
	~Node();

	// getters
	int getData();
	Node* getNext();

	// setter 
	void setNext(Node * node);

	// there's no need for a setData().  
	// Only create mutators when there is a need.

private:
	int data;
	Node* next;
};
