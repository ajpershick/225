/*
 * Customer.cpp
 *
 */

#include "Customer.h"


// TO DO:: Fill in.
Customer::Customer()
{
	arrivalTime = 0;
	transactionTime = 0;
}

Customer::Customer(int aT, int tT)
{
	arrivalTime = aT;
	transactionTime = tT;
}

int Customer::getArrTime() const
{
	 return arrivalTime;
}

int Customer::getTransTime() const
{
	return transactionTime;
}