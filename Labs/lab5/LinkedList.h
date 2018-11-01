// Header file for linked list class
#include <ostream>
using namespace std;
template <class Type>
class LinkedList{
public:
	// Constructors and Destructors
	/* Generally every class should have at least two construtors, a
	 * default constructor and a copy constructor that creates a copy
	 * of the given object*/
	LinkedList(); //default construtor
	LinkedList(const LinkedList& lst); //copy constructor
	/* Every class should have a destructor, which is responsible for
	 * cleaning  up any dynamic memory allocation performed by the class.
	 * Note the special syntax for the destructor */
	~LinkedList();//destructor
	
	// PRE:
	// POST: A new node containing the given data is inserted at the front
	//       of the list
	// PARAM: data is the data to be stored
	
	void add(Type data);

	// PRE:
	// POST: A new node containing the given data is inserted at the given
	//       position in the list
	// PARAM: pos specifies the (index) position to insert the new node
	//        data is the data to be stored
	
	void insertAt(int pos, Type data);
	
	// PRE:
	// POST: The first incidence of the given data is removed from the list.
	//       Returns true if data is found (and removed), false otherwise
	// PARAM: data specifies the data to be removed from the list
	
	bool remove(Type data );
	
	// PRE:
	// POST: Empties the list, freeing up dynaically allocated memory
	// PARAM: 
	
	void removeAll();

	// PRE:
	// POST: Prints the contents of the list to the stream, in order
	// PARAM:
	
	void printList(ostream& out);

private:
	/* A class for a node of the list.  It contains the data variable.*/
	// List node
	class Node {
	public:
		Type data;   //list data
		Node *next; //pointer to next item in the list

		Node(Type d) { data = d; }
		Node(const Node* node) { data = node->data; }
	};

	Node *head; //Pointer to the first node in the list
	int size; //Records the number of nodes in the list
};

// Default constructor
template <class Type>
LinkedList<Type>::LinkedList(){
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
template <class Type>
LinkedList<Type>::LinkedList(const LinkedList& lst){
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
template <class Type>
LinkedList<Type>::~LinkedList(){
	removeAll();
}

template <class Type>
void LinkedList<Type>::add(Type x)
{
	Node *newNode = new Node(x); 
	// Assign appropriate values to the new node
	newNode -> next = head;
	// Make the head point to the new node
	head = newNode;	
	size++;
}


template <class Type>
void LinkedList<Type>::insertAt(int pos, Type x){
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
		for(Type i = 0; i < pos-1; i++){
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


template <class Type>
	bool LinkedList<Type>::remove(Type x){
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
template <class Type>
void LinkedList<Type>::removeAll(){
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
template <class Type>
void LinkedList<Type>::printList(ostream& out) {
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