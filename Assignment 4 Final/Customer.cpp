/*
	CONSTRUCTOR.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Implementation file for Customer class.
*/

#include "Customer.h"

//Constructor
Customer::Customer()
{
	firstName = "";
	lastName = "";
	customerID = -1;
}

//Constructor with arguments
Customer::Customer(string & s)
{
	setData(s);
}

//Destuctor
Customer::~Customer()
{
}

//Overloads operator== to compare Customers
bool Customer::operator==(const Customer & rhs) const
{
	return (firstName == rhs.firstName && lastName == rhs.lastName && customerID == rhs.customerID);
}

//Overloads operator!= to compare Customers
bool Customer::operator!=(const Customer & rhs) const
{
	return !(*this == rhs);
}

//Getter
string Customer::getFirstName() const
{
	return firstName;
}

//Setter
void Customer::setFirstName(string newFirstName)
{
	firstName = newFirstName;
}

//Getter
string Customer::getLastName() const
{
	return lastName;
}

//Setter
void Customer::setLastName(string newLastName)
{
	lastName = newLastName;
}

//Getter
int Customer::getCustomerID()
{
	return customerID;
}

//Setter
void Customer::setCustomerID(int newCustomerID)
{
	customerID = newCustomerID;
}

//Parse through line from file to initialize data members
void Customer::setData(string &s)
{
	int position = 0;
	string delimiter = " ";
	string token = "";

	for (int i = 0; i < 3; i++)
	{
		position = s.find(delimiter);
		token = s.substr(0, position);
		if (i == 0)
		{
			customerID = stoi(token);
		}
		if (i == 1)
		{
			lastName = token;
		}
		if (i == 2)
		{
			firstName = token;
		}
		s.erase(0, position + delimiter.length());
	}
}

//Add transaction to history vector
void Customer::addToHistory(const Transaction &trans)
{
	customerHistory.push_back(trans);
}

//Print vector
void Customer::printHistory()
{
	for (int i = customerHistory.size() - 1; i >= 0; i--)
	{
		customerHistory[i].printBorrowOrReturn();
	}
}


