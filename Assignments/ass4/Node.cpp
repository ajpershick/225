/*
 * Node.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */
#include "Customer.h"
#include "Node.h"

Node::Node(Customer * newCustomer)
{
	leftChild = NULL;
	rightChild = NULL;
	parent = NULL;
	data = newCustomer;
}
