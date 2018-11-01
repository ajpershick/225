#pragma once

// linkedlist.h
// Header file for linked list class
#include "node.h"

class LinkedList{
public:
	// Constructors and Destructors
	/* Generally every class should have at least two construtors, a
	 * default constructor and a copy constructor that creates a copy
	 * of the given object*/

	LinkedList();                        // default construtor
	LinkedList(const LinkedList& lst);   // copy constructor

	/* Every class should have a destructor, which is responsible for
	 * cleaning  up any dynamic memory allocation performed by the class.
	 * Note the special syntax for the destructor */
	~LinkedList();                       // destructor

	// Query that tells you if the list is empty
	bool isEmpty();
	
	// Insert a new node containing the given data at the end of the list
	void add(int data);

	// Print the contents of the list to the screen, in order, formatted nicely
	void printList();

private:
	Node *head;		// Pointer to the first node in the list
}; 
