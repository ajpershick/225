/*
 * ATMQueue.cpp
 *
 */
#include "Customer.h"
#include "Node.h"
#include "ATMQueue.h"
#include <cstddef>
#include <iostream>
using namespace std;

// TO DO:: Fill in.

ATMQueue::ATMQueue()
{
	head = NULL;
	tail = NULL;
	len = 0;
}

ATMQueue::~ATMQueue()
{
	// loop thru and delete all nodes individually

	delete head;
	delete tail;
}

void ATMQueue::enqueue(Node * currCustomer)
{

	currCustomer->next = NULL;
	if (head == NULL)
	{
		head = currCustomer;
		tail = head;
	}
	else
	{
		tail->next = currCustomer;
		tail = tail->next;
	}
	len++;
	cout << "length is now: " << len << endl;
}

Node* ATMQueue::dequeue()
{
	Node* temp = NULL;

	if (head == NULL)
	{
		return NULL;
	}

	else
	{
		temp = head;
		head = head->next;
	}
	len--;
	cout << "length is now: " << len << endl;
	return temp;
	
}

int ATMQueue::getLen()
{	
	if( len < 0 ) 
	{
		return 0;
	}
	return len;
}

