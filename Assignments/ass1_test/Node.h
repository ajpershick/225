/*
 * Node.h
 *
 */
#include "Customer.h"
#ifndef NODE_H_
#define NODE_H_

class Node {

  // TO DO:: Fill in.
	private:
		int ArrivalTime;
		int TransactionTime;
	public:
		Customer * data;
		Node* next;
		Node(Customer * newCustomer);
		int getArrivalTime();
		int getTransactionTime();

};

#endif /* NODE_H_ */
