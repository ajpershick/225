/*
 * BSTree.h
 *
 */

#ifndef BSTREE_H_
#define BSTREE_H_
//#define _GLIBCXX_USE_CXX11_ABI 0  // Fixes some linker error I was getting

#include "Customer.h"
#include "Node.h"
#include<vector>
#include<string>
using namespace std;

class BSTree {
public:
	BSTree();
	BSTree(const BSTree & rbt); // Copy constructor
	virtual ~BSTree();

	// Creates and inserts a new customer (with the data shown in the parameters) in the tree, in a new tree node.
	bool insert(string, char, int);

	// Deletes the first node with a matching name and initial from the tree.
	// Returns true if the deletion was successful (that is, if the customer was found).
	// Note that two customers are equal if they have the same name and initial, regardless of the account balance.
	bool remove(string, char);

	//  Searches the tree for the given value, returning true if the customer is found
	bool search(string, char);

	// Returns a vector of Customers where the customer names (initial and last name)
	// are in the range specified in the parameters.  For example rangeSearch("Dobbs", 'A', "Fogg", D)
	// returns all customers whose names are between Dobbs A and Fogg D.
	vector<Customer> rangeSearch(string, char, string , char);

	// Prints the contents of the tree in sorted order.
	void inOrderPrint();

private:

	Node * root;
	
	// Helper methods
	void Destroy(Node * node);
	void insertRecursively(Customer * customer, Node * root);
	void inOrder(Node * root);
	Node * searchForNode(Customer * customer);
	bool isLeaf(Node * node);
	bool hasOnlyLeftChild(Node * node);
	bool hasOnlyRightChild(Node * node);
	bool has2Children(Node * node);
	Node * findMin(Node * node);
	Node * findMax(Node * node);
	void removeLeaf(Node * node, Node * parent);
	void removeWithLeftChild(Node * node, Node * parent);
	void removeWithRightChild(Node * node, Node * parent);
	void removeWith2Children(Node * node, Node * parent);
	void rangeHelper(Node * root, Customer * customer1, Customer * customer2, vector<Customer> * customerRange);

};

#endif /* BSTREE_H_ */
