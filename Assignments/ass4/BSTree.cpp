/*
 * BSTree.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "BSTree.h"


BSTree::BSTree() 
{
	root = NULL;
}


BSTree::~BSTree() 
{
	Destroy(root);
}

void BSTree::Destroy(Node * node)
{
    if (node)
    {
        Destroy(node->leftChild);
        Destroy(node->rightChild);
        delete node;
    }
}

bool BSTree::insert(string x, char y, int z) 
{
	Customer * customer = new Customer(x, y, z);

	if (root == NULL)
	{
		root = new Node(customer);
		root->parent = NULL;
		return true;
	}

	Node * currentNode = root;

	while (currentNode != NULL)
	{
		if (*customer <= *currentNode->data)
		{
			if (currentNode->leftChild == NULL)
			{
				currentNode->leftChild = new Node(customer);
				currentNode->leftChild->parent = currentNode;
				return true;
			}

			currentNode = currentNode->leftChild;
		}

		else if (*customer > *currentNode->data)
		{
			if (currentNode->rightChild == NULL)
			{
				currentNode->rightChild = new Node(customer);
				currentNode->rightChild->parent = currentNode;
				return true;
			}

			currentNode = currentNode->rightChild;
		}
	}
}

bool BSTree::remove(string x, char y) 
{
	Customer * customer = new Customer(x, y, 0);

	// Finding the node to be removed
	Node * currentNode = searchForNode(customer); 

	// Check if tree is empty

	if (currentNode == NULL)
	{
		return false;
	}

	// Check if root

	if (currentNode->parent == NULL)
	{
		if (isLeaf(currentNode))
		{
			delete currentNode;
			return true;
		}

		else if (hasOnlyLeftChild(currentNode))
		{
			Node * max = findMax(currentNode->leftChild);
			currentNode->data = max->data;
			
			if (isLeaf(max))
			{
				removeLeaf(max, max->parent);
			}

			else if (hasOnlyLeftChild(max))
			{				
				removeWithLeftChild(max, max->parent);
			}

			return true;
		}

		else if (hasOnlyRightChild(currentNode))
		{
			Node * min = findMin(currentNode->rightChild);
			currentNode->data = min->data;

			if (isLeaf(min))
			{
				
				removeLeaf(min, min->parent);
			}

			else if (hasOnlyRightChild(min))
			{
				
				removeWithRightChild(min, min->parent);
			}

			return true;
		}

		else if (has2Children(currentNode))
		{
			Node * min = findMin(currentNode->rightChild);
			currentNode->data = min->data;

			if (isLeaf(min))
			{
				
				removeLeaf(min, min->parent);
			}

			else if (hasOnlyRightChild(min))
			{
				
				removeWithRightChild(min, min->parent);
			}

			return true;
		}
	}

/*
	4 Cases:
	Case 1: currentNode is a leaf
	Case 2: currentNode has left child only
	Case 2: currentNode has right child only
	Case 3: currentNode has 2 children
*/

	// Case 1

	else if (isLeaf(currentNode))
	{
		removeLeaf(currentNode, currentNode->parent);
	}

	// Case 2

	else if (hasOnlyLeftChild(currentNode))
	{
		removeWithLeftChild(currentNode, currentNode->parent);
	}

	// Case 3

	else if (hasOnlyRightChild(currentNode))
	{
		removeWithRightChild(currentNode, currentNode->parent);
	}

	// Case 4

	else if (has2Children(currentNode))
	{
		removeWith2Children(currentNode, currentNode->parent);
	}

	return true;
}

void BSTree::removeLeaf(Node * currentNode, Node * parent)
{
	if (currentNode == parent->leftChild)
	{
		parent->leftChild = NULL;
		delete currentNode;
	}

	else
	{
		parent->rightChild = NULL;
		delete currentNode;
	}
}

void BSTree::removeWithLeftChild(Node * currentNode, Node * parent)
{
	if (parent->leftChild == currentNode)
	{
		parent->leftChild = currentNode->leftChild;
		delete currentNode;
	}

	else
	{
		parent->rightChild = currentNode->leftChild;
		delete currentNode;
	}
}

void BSTree::removeWithRightChild(Node * currentNode, Node * parent)
{
	if (parent->leftChild == currentNode)
	{
		parent->leftChild = currentNode->rightChild;
		delete currentNode;
	}

	else
	{
		parent->rightChild = currentNode->rightChild;
		delete currentNode;
	}
}

void BSTree::removeWith2Children(Node * currentNode, Node * parent)
{
	Node * min = findMin(currentNode->rightChild);

	currentNode->data = min->data;

	if (isLeaf(min))
	{
		removeLeaf(min, min->parent);
	}

	else if (hasOnlyRightChild(min))
	{
		removeWithRightChild(min, min->parent);
	}
}


Node * BSTree::findMin(Node * node)
{
	if (node->leftChild == NULL)
	{
		return node;
	}

	else
	{
		return findMin(node->leftChild);
	}
}


Node * BSTree::findMax(Node * node)
{
	if (node->rightChild == NULL)
	{
		return node;
	}

	else
	{
		return findMin(node->rightChild);
	}
}

bool BSTree::hasOnlyRightChild(Node * node)
{
	if ((node->leftChild == NULL && node->rightChild != NULL) 
		|| (node->leftChild != NULL && node->rightChild == NULL))
	{
		if (node->leftChild == NULL && node->rightChild != NULL)
		{
			return true;
		}
	}

	return false;
}

bool BSTree::hasOnlyLeftChild(Node * node)
{
	if ((node->leftChild == NULL && node->rightChild != NULL) 
		|| (node->leftChild != NULL && node->rightChild == NULL))
	{
		if (node->rightChild == NULL && node->leftChild != NULL)
		{
			return true;
		}
	}

	return false;
}

bool BSTree::isLeaf(Node * node)
{
	if (node->leftChild == NULL && node->rightChild == NULL)
	{
		return true;
	}

	return false;
}

bool BSTree::has2Children(Node * node)
{
	if (node->leftChild != NULL && node->rightChild != NULL)
	{
		return true;
	}

	return false;
}

bool BSTree::search(string x, char y) 
{
	Customer * customer = new Customer(x, y, 0);
	Node * currentNode = root;

	while(currentNode != NULL)
   	{
      	if (*customer < *currentNode->data)
      	{
         	currentNode = currentNode->leftChild;
      	}

      	else if (*customer > *currentNode->data)
      	{
         	currentNode = currentNode->rightChild;
      	}

      	else if (*customer == *currentNode->data)
      	{
      		return true;
      	}
   	}

	return false;
}

Node * BSTree::searchForNode(Customer * customer) 
{
	Node * currentNode = root;

	while(currentNode != NULL)
   	{
      	if (*customer < *currentNode->data)
      	{
      		currentNode->parent = currentNode;
         	currentNode = currentNode->leftChild;
      	}

      	else if (*customer > *currentNode->data)
      	{
      		currentNode->parent = currentNode;
         	currentNode = currentNode->rightChild;
      	}

      	else if (*customer == *currentNode->data)
      	{
      		return currentNode;
      	}
   	}

	return NULL;
}

vector<Customer> BSTree::rangeSearch(string x, char y, string z, char a) 
{
	Customer * customer1 = new Customer(x, y, 0);
	Customer * customer2 = new Customer(z, a, 0);

	// Check to make sure parameters are correct
	if (*customer1 > *customer2)
	{
		Customer * temp = customer1;
		customer1 = customer2;
		customer2 = temp;
	}

	vector<Customer> customerRange;
	
	rangeHelper(root, customer1, customer2, &customerRange);

	return customerRange;
}

void BSTree::rangeHelper(Node * root, Customer * customer1, Customer * customer2, vector<Customer> * customerRange)
{
	if (root == NULL)
	{
		return;
	}

	rangeHelper(root->leftChild, customer1, customer2, customerRange);

	if (*root->data >= *customer1 && *root->data <= *customer2)
	{
		customerRange->push_back(*root->data);
	}

	rangeHelper(root->rightChild, customer1, customer2, customerRange);
}


void BSTree::inOrderPrint() 
{
	inOrder(root);
}

void BSTree::inOrder(Node * root)
{
	if (root != NULL)
	{
		inOrder(root->leftChild);
		cout << *root->data << endl;
		inOrder(root->rightChild);
	}
}

