/*
 * ATM.cpp
 *
 */
#include "ATM.h"
#include "ATMQueue.h"
#include <iostream>
using namespace std;


// TO DO:: Fill in.
ATM::ATM()
{
	remainingTime = 0;
	availability = true;
	customerWaitTime = 0;
	queue = new ATMQueue();
} 

ATM::ATM(int remTime, bool avail, int waitTime)
{
	remainingTime = remTime;
	availability = avail;
	customerWaitTime = waitTime;
}

ATM::~ATM()
{
	delete queue;
}

void ATM::insertCustomer(Node * CurrCustomer)
{
	cout << "Inserting customer into queue..." << endl;
	queue->enqueue(CurrCustomer);
}

void ATM::processCustomer(int currMin)
{
	cout << "Processing ATM..." << endl;

	if (remainingTime > 0)
	{
		remainingTime--;
		cout << "Decrementing remaining time... = " << remainingTime << endl;
	}

	else
	{
		
		availability = true;
		cout << "ATM is now available!" << endl;
		if (queue->getLen() == 0)
		{
			cout << "ATM queue is empty" << endl;
			return;
		}
		cout << "Removing customer from queue..." << endl;
		Node * node = queue->dequeue();
		availability = false;
		// Setting the remaining wait time for the ATM
		remainingTime = node->getTransactionTime();
		cout << "Transaction time = " << remainingTime << endl;
		cout << "Current time = " << currMin << endl;

		// Adding to the total wait time of the ATM
		customerWaitTime = customerWaitTime + (currMin - node->getArrivalTime());
		cout << "Arrival time = " << node->getArrivalTime() << endl;
		cout << "Wait time = " << customerWaitTime << endl;
		remainingTime--;
		cout << "Decrementing remaining time... = " << remainingTime << endl;
	}
}

int ATM::getLength()
{
	return queue->getLen();
}

int ATM::getRemainingTime()
{
	return remainingTime;
}

int ATM::getWaitTime()
{
	return customerWaitTime;
}

bool ATM::getAvailability()
{
	return availability;
}

std::ostream& operator<<(std::ostream& os, ATM& atm){
	os << "Remaining time: " << atm.getRemainingTime() << ", Availability: " << atm.getAvailability() << ", Wait time: " << atm.getWaitTime() << std::endl;
	return os;
}