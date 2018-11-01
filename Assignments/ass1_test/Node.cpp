/*
 * Node.cpp
 *
 */
#include "Customer.h"
#include "Node.h"
#include <cstddef>



// TO DO:: Fill in.
Node::Node(Customer * newCustomer)
{
	ArrivalTime = newCustomer->getArrTime();
	TransactionTime = newCustomer->getTransTime();
	next = NULL;
	data = newCustomer;
}

int Node::getArrivalTime()
{
	return ArrivalTime;
}

int Node::getTransactionTime()
{
	return TransactionTime;
}
