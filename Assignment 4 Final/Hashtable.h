/*
	HASHTABLE.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file for the hash table that stores customers.
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Customer.h"
using namespace std;

class Hashtable
{
public:
	//Constructor and Destructor
	Hashtable();
	~Hashtable();

	//Other functinos
	void insert(Customer &item);
	void displayCustomerHistory(int customerID);
	void displayHash();
	Customer getCustomerWithID(int customerID); //Get customer, then insert into history vector
private:
	//Data members
	static const int size = 100;
	vector<Customer> table;
};

