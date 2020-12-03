/*
	CUSTOMER.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file for Customer class.
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Transaction.h"
using namespace std;

class Customer
{
public:
	//Constructors and Destructor
	Customer();
	Customer(string &s);
	~Customer();

	//Overloads
	bool operator==(const Customer &rhs) const;
	bool operator!=(const Customer &rhs) const;

	//Getters and setters
	string getFirstName() const;
	void setFirstName(string newFirstName);
	string getLastName() const;
	void setLastName(string newLastName);
	int getCustomerID();
	void setCustomerID(int newCustomerID);
	
	//Other methods
	void setData(string &s);
	void addToHistory(const Transaction &trans);
	void printHistory();
private:
	//Data members
	string firstName;
	string lastName;
	int customerID;
	vector<Transaction> customerHistory;
};

