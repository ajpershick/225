/*
 * Customer.cpp
 *
 *  Created on: Mar 5, 2010
 *      Author: mori
 */

#include "Customer.h"

Customer::Customer()
{
	lastName = "";
	firstInitial;
	accountBalance = 0;
}

Customer::Customer(string x, char y, int z) 
{
	lastName = x;
	firstInitial = y;
	accountBalance = z;
}

string Customer::getLastName()
{
	return lastName;
}

char Customer::getFirstInitial()
{
	return firstInitial;
}

int Customer::getAccountBalance()
{
	return accountBalance;
}

void Customer::setAccountBalance(int balance)
{
	accountBalance = balance;
}

bool Customer::operator > (Customer c) const
{
	if (lastName == c.lastName)
	{
		if (firstInitial > c.firstInitial)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	else if (lastName > c.lastName)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Customer::operator >= (Customer c) const
{
	if (lastName == c.lastName)
	{
		if (firstInitial >= c.firstInitial)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	else if (lastName >= c.lastName)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Customer::operator < (Customer c) const
{
	if (lastName == c.lastName)
	{
		if (firstInitial < c.firstInitial)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	else if (lastName < c.lastName)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Customer::operator <= (Customer c) const
{
	if (lastName == c.lastName)
	{
		if (firstInitial <= c.firstInitial)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	else if (lastName <= c.lastName)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Customer::operator == (Customer c) const
{
	if (lastName == c.lastName)
	{
		if (firstInitial == c.firstInitial)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

bool Customer::operator != (Customer c) const
{
	if (lastName != c.lastName)
	{
		if (firstInitial != c.firstInitial)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

ostream& operator<<(ostream &os, Customer &c) 
{
	os << c.lastName << ", " << c.firstInitial << ". (" 
	<< c.accountBalance << ")";
}
