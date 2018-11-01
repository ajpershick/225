/*
 * ATM.h
 *
 */
#include "ATMQueue.h"
#include "Customer.h"
#include <iostream>
#ifndef ATM_H_
#define ATM_H_

class ATM 
{
  // TO DO:: Fill in.
	private:
		int remainingTime;
		bool availability;
		int customerWaitTime;
		ATMQueue * queue;

	public:
		ATM();
		ATM(int remTime, bool avail, int waitTime);
		~ATM();
		void insertCustomer(Node * CurrCustomer);
		void processCustomer(int currMin);
		int getLength();
		int getRemainingTime();
		void printATM();
		bool getAvailability();
		int getWaitTime();

		friend std::ostream& operator<<(std::ostream& os, ATM& atm);

};

#endif /* ATM_H_ */
