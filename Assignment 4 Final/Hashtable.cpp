/*
	HASHTABLE.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Implementation file for the hash table that stores customers.
*/

#include "Hashtable.h"

//Constructor
Hashtable::Hashtable()
{
	for (int i = 0; i < size; i++)
	{
		Customer blank;
		table.push_back(blank);
	}
}

//Destructor
Hashtable::~Hashtable()
{
}

//Inserts Customer by modding their unique ID to get a hash (uses linear closed hashing)
void Hashtable::insert(Customer &target)
{
	int hashedID = target.getCustomerID() % 10;
	if (table[hashedID].getCustomerID() == -1)
	{
		table[hashedID] = target;
	}
	else
	{
		while (table[hashedID].getCustomerID() != -1)
		{
			hashedID++;
		}
		table[hashedID] = target;
	}
}

//Prints out contents of history vector for each customer
void Hashtable::displayCustomerHistory(int customerID)
{
	Customer blank;
	for (int i = 0; i < size; i++)
	{
		if (table[i] != blank)
		{
			if (table[i].getCustomerID() == customerID)
			{
				table[i].printHistory();
			}
		}
	}
}

//Shows all the customers in the hash table
void Hashtable::displayHash()
{
	cout << "Customers" << endl;
	cout << "----------------------------------------------------------" << endl;
	for (int i = 0; i < size; i++)
	{
		if (table[i].getCustomerID() != -1 && !(i > 12))
		{
			cout << "Name: " << table[i].getFirstName() << " " << table[i].getLastName() << " ";
			cout << "Customer ID: " << table[i].getCustomerID() << endl;
		}
	}
	cout << "----------------------------------------------------------" << endl;
}

//Return a Customer object given a customer ID
Customer Hashtable::getCustomerWithID(int customerID)
{
	bool found = false;
	for (int i = 0; i < table.size(); i++)
	{
		if (table[i].getCustomerID() == customerID)
		{
			found = true;
			Customer holder = table[i];
			return holder;
		}
	}
	if (found == false)
	{
		cout << "[Incorrect Customer ID]" << endl;
	}
}
