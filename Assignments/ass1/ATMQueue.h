/*
 * ATMQueue.h
 *
 */
#include "Customer.h"
#include "Node.h"
#ifndef ATMQUEUE_H_
#define ATMQUEUE_H_

class ATMQueue {
  // TO DO:: Fill in.
	private:
		int len;
		Node * head;
		Node * tail;

	public:
		ATMQueue();
		~ATMQueue();
		void enqueue(Node * currCustomer);
		Node* dequeue();
		int getLen();

};

#endif /* ATMQUEUE_H_ */
