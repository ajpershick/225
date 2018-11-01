// linkedlist.cpp
// Implementation of the LinkedList class

#include "linkedlist.h"
#include <string>
#include <iostream>

using namespace std; //needed for cout, cin to be recognized

// Default constructor
LinkedList::LinkedList(){
	head = 0;
}


/* Copy constructor to copy an existing list.  Note that the compiler
 * will generate a copy constructor automatically.  However, this
 * constructor only creates a SHALLOW COPY (so would only copy the
 * size and head variables).  In this case this would NOT CREATE A
 * NEW LIST, just a new reference to one list.  It is therefore
 * necessary to write a constructor that makes a DEEP COPY.*/

/* Also note the parameter.  C++ functions use pass-by-value by
 * default.  This means that the functions make copies of the given
 * arguments.  This is inefficient (particularly for large objects).
 * Therefore it is normal to pass the address (using &) of the parameter,
 * but, if the parameter should not be changed, it is good practice to 
 * make it const, which prevents it from being changed.*/

LinkedList::LinkedList(const LinkedList& list) 
{

	Node* temp = list.head;
	head = 0;

	while (temp != NULL)
	{
		add(temp->getData());
		temp = temp->getNext();
	}


	//head = list.head; //shallow copy - you need to fix this!
}


/* The destructor is responsible for deleting any memory that was dynamically
 * allocated by an object.  If there is no such memory no destructor needs to
 * be created (the compiler automatically creates one).  Because this class
 * uses pointers to create new Nodes it is necessary to write a destructor.
 * Destructors are identified by the '~' preceding the class name.  There can
 * be only one destructor for a class, and it cannot have parameters. */

LinkedList::~LinkedList(){
	// You need to write this!

}


/**************************************************************************/
// LinkedList Queries 
// answers the question: "is this list empty?"
bool LinkedList::isEmpty() {
	return head == 0;
}


/**************************************************************************/
// LinkedList Operations (Mutators)
// Adds a node to the end of the list
void LinkedList::add(int x) {
	Node *newNode = new Node(x);	   // new node with data x

	if (isEmpty()) {
		head = newNode;
	}
	else {
		// Put new node at the end of the list (the slow way)
		// the fast way would be to store and use a tail pointer.
		Node* p = head;
		while (p->getNext() != 0) {
			p = p->getNext();
		}
		p->setNext(newNode);
	}	
}

// Prints the entire list (head first) to the screen.
/* Note that there is some debate about whether or not this type of
 * method belongs in a class.  The argument (briefly) is that a class
 * shouldn't be responsible for its own display as it cannot foresee
 * how it is to be displayed. 
 * 
 * A better solution to this is provided by Java, which allows a class
 * to declare a "toString" function, which converts an object of the class
 * to a human-readable string.  (Specifically, human-readable.  Not program-
 * readable.)  This solves the problem--a class knows how to display itself
 * *as a string*.  It also removes the troublesome references to "cout" in
 * the routine below.  One should be able to write one routine that works
 * on cout, on cin, and on any output stream (such as the file streams we
 * created in Lab 0).
 *
 * One can easily implement "toString" in C++, but that involves String
 * manipulations, which we haven't covered yet.
 */

void LinkedList::printList() {
	Node *p = head;
	cout << "{";

	// Traverse the list
	while (p != 0) {
		cout << p -> getData(); // Print data
		p = p -> getNext();     // Go to next node
		if (p != 0){
			cout << ", ";       // Print a comma and space unless at the end of the list
		}
	}
	cout << "}";                // Don't print a newline - it might not be wanted
}
