/*
 * Customer.h
 *
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

class Customer {
  // TO DO:: Fill in.
	private:
		int arrivalTime;
		int transactionTime;
	public:
		Customer();
		Customer(int aT, int tT);
		int getArrTime() const;
		int getTransTime() const;
};

#endif /* CUSTOMER_H_ */
