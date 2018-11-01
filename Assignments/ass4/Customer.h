/*
 * Customer.h
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include <string>
#include <iostream>
using namespace std;

class Customer {
public:
	Customer();
	Customer(string lastName, char firstInitial, int accountBalance);
	string getLastName();
	char getFirstInitial();
	int getAccountBalance();
	void setAccountBalance(int balance);
	bool operator > (Customer c) const;
	bool operator >= (Customer c) const;
	bool operator < (Customer c) const;
	bool operator <= (Customer c) const;
	bool operator == (Customer c) const;
	bool operator != (Customer c) const;

	
private:
	string lastName;
	char firstInitial;
	int accountBalance;
	friend ostream& operator<<(ostream & os, Customer & c);
};

#endif /* CUSTOMER_H_ */
