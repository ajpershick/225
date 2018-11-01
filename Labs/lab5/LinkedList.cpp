// Implementation of the LinkedList class

#include "LinkedList.h"
#include <string>
#include <iostream>

using namespace std;

// Default constructor
LinkedList::LinkedList(){
	head = NULL;
	size = 0;		// Don't forget to do this!!!
}

/* Copy constructor to copy an existing list.  Note that the compile
 * will generate a copy constructor automatically.  However, this
 * constructor only creates a SHALLOW COPY (so would only copy the
 * size and head variables).  In this case this would NOT CREATE A
 * NEW LIST, just a new reference to one list.  It is therefore
 * necessary to write a constructor that makes a DEEP COPY. */

/* Also note the parameter.  C++ functions use pass-by-value by
 * default.  This means that the functions make copies of the given
 * arguments.  This is inefficient (particularly for large objects).
 * Therefore it is normal to pass the address (using &) of the parameter,
 * but, if the parameter should not be changed, it is good practice to 
 * make it const, which prevents it from being changed. */

LinkedList::LinkedList(const LinkedList& lst){
	if (lst.head == NULL){
		head = NULL;
		size = 0;
	}
	else{
		// Copy first node and assign head
		/* OK, what's with the '->'?  The -> operator accesses the attribute
		 * or method of the object (or struct) that is refererred to by a
		 * pointer.  So "head -> data" is the contents of the data variable
		 * of the object that head points to.  Note that this is synonomous
		 * with "(*head).data" but the latter syntax is rarely used. */
		head = new Node(lst.head);

		/* Now copy the rest of the list.  To do this we'll need to create two
		 * temporary pointers, one to go through the old list, one node at a
		 * time, and one to keep pace in the new list, creating new nodes. */

		/* Here's the way that the implementation of that last comment
		 * used to look.  It's a while loop. */
		
		 /*
		Node *newNode = head;
		Node *oldNode = lst.head->next;
		// Repeat until the entire list is copied
		while (oldNode != NULL){
			newNode->next = new Node(oldNode);
			newNode = newNode->next;
			oldNode = oldNode->next;
		}
		*/
		
		/* Compare that to the following version, where all of the 
		 * loop control has been consolidated into a for statement.
		 * Here, the code should be easier to read because the programmer
		 * gathered all of that loop information--one can read it to
		 * understand the extent of the loop, and then separately consider
		 * what the "body" of the loop does.  In the while version, the
		 * body is mixed in with the increment, and the initialization is
		 * set before the loop. Some people find the long for-statement below
		 * ugly, and therefore use the while form above.  Both are standard. */

		Node *newNode = head;

		// Repeat until the entire list is copied
		for (Node* oldNode = lst.head->next; oldNode != NULL; oldNode = oldNode->next) {
			newNode->next = new Node(oldNode);
			newNode = newNode->next;
		}

		newNode->next = NULL;
		size = lst.size;
	}
}

/* The destructor is responsible for deleting any dynamic memory that 
 * is held by an object.  If there is no such memory no destructor needs to
 * be created (the compiler automatically creates one).  Because this class
 * holds a list of dynamically-allocated Nodes it is necessary to write a destructor.
 * Destructors are identified by the '~' preceding the class name.  There can
 * be only one destructor for a class, and it cannot have parameters. */
LinkedList::~LinkedList(){
	removeAll();
}

/**************************************************************************/
// LinkedList Operations

// Adds a node to the start of the list, making it the new head
void LinkedList::add(int x){
	Node *newNode = new Node(x); 
	// Assign appropriate values to the new node
	newNode -> next = head;
	// Make the head point to the new node
	head = newNode;	
	size++;
}

// Inserts a new node at the given position (or index) in the list
// This is more complex than I (shermer) would ever write a function:
// there are 4 nested statements, giving 5 indentation levels.  It's more
// than a human mind should have to take.

void LinkedList::insertAt(int pos, int x){
	Node *newNode;
		
	// Check that pos is a valid index
	if (0 <= pos && pos <= size){
		newNode = new Node(x);

		// Deal with case when item is to be inserted at the head of the list
		if (pos == 0) {
			newNode->next = head;
			head = newNode;
		}// if(pos == 0)
		else{
			Node* p = head;
			// Move to position BEFORE insertion point
			for(int i = 0; i < pos-1; i++){
				// Check that p points to a node
				// Note using exception handling should throw an exception here
				if(p == NULL){
					return;
				}
				p = p->next;
			}
			// Insert node
			newNode->next = p->next;
			p->next = newNode;
		}
		size++;
	}//else (pos >= size) do nothing
}

// Removes the first node containing the given data, returns true
// iff data is found (and deleted).
bool LinkedList::remove(int x){
	Node *p = head;
	Node *temp;
	// Check to see if the list exists
	if (head == NULL){
		return false;
	}
	// Check to see if target is at the head of the list
	else if (head->data == x){
		head = head->next;
		delete p; //currently assigned head
		size--;
		return true;
	}
	// Otherwise iterate through list
	else{
		while(p->next != NULL){
			// Check next node for target
			if(p->next->data == x){
				temp = p->next;
				p->next = p->next->next;
				size--;
				delete temp;
				return true;
			}
			p = p->next;
		}
	}
	return false;
}

// Empties the list by deleting each node, starting at the head
void LinkedList::removeAll(){
	Node *p = head;

	while (p != NULL){
		p = head->next; // Mustn't "lose" the next node
		delete head;    // De-allocate memory
		head = p;       // Go to next node
	}
	head = NULL;
	size = 0;
}

// Prints the entire list (head first) to the given output stream.

void LinkedList::printList(ostream& out) {
	Node *p = head;
	out << "["; 

	while (p != NULL) {
		out << p -> data;
		p = p -> next;
		if (p != NULL) {
			out << ", ";
		}
	}
	out << "]"; 
}
