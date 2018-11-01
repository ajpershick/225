/*
 * Node.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef NODE_H_
#define NODE_H_
#include <cstddef>
#include "Customer.h"


class Node {

	public:

		Node(Customer * newCustomer);
		Customer * data;
		Node * leftChild;
		Node * rightChild;
		Node * parent;

	private:


};

#endif /* NODE_H_ */
