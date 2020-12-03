/*
	FACTORY.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Implementation file for Factory that creates movies and transactions
*/

#include "Factory.h"

//Constructor
Factory::Factory()
{
}

//Destructor
Factory::~Factory()
{
}

//Creates Comedy, Drama, or Classic
Movie * Factory::createMovie(string& s)
{
	Movie* movieType = NULL;
	if (s[0] == 'F') {
		movieType = (Movie*) new Comedy(s);
	}
	else if (s[0] == 'D') {
		movieType = (Movie*) new Drama(s);
	}
	else if (s[0] == 'C') {
		movieType = (Movie*) new Classic(s);
	}
	else {
		movieType = NULL;
		cout << "[Invalid Movie]" << endl;
	}
	return movieType;
}

//Determines whether the action is Borrow, Return, Inventory, or History
Transaction Factory::createTransaction(string &s, BinTree *&movieTree, Hashtable *&hashy)
{
	Transaction transactionType;
	if (s[0] == 'B') {  //Borrow
		transactionType = (Transaction) Borrow(s, movieTree);
		Customer person = hashy->getCustomerWithID(transactionType.getCustomerID());
		person.addToHistory(transactionType);
	}
	else if (s[0] == 'R') {  //Return
		transactionType = (Transaction) Return(s, movieTree);
		Customer person = hashy->getCustomerWithID(transactionType.getCustomerID());
		person.addToHistory(transactionType);
	}
	else if (s[0] == 'I') {  //Inventory
		cout << "----------------------------------------------------------" << endl;
		cout << "Comedy Movies in Inventory" << endl;
		cout << "----------------------------------------------------------" << endl;
		movieTree->printThreeTypes("F");
		cout << "----------------------------------------------------------" << endl;
		cout << "Drama Movies in Inventory" << endl;
		cout << "----------------------------------------------------------" << endl;
		movieTree->printThreeTypes("D");
		cout << "----------------------------------------------------------" << endl;
		cout << "Classical Movies in Inventory" << endl;
		cout << "----------------------------------------------------------" << endl;
		movieTree->printThreeTypes("C");
		cout << "----------------------------------------------------------" << endl;
	}
	else if (s[0] == 'H') {  //History
		int position = 0;
		string delimiter = " ";
		string token = "";
		int customerID = 0;
		for (int i = 0; i < 2; i++)
		{
			position = s.find(delimiter);
			token = s.substr(0, position);
			if (i == 0)
			{
			}
			if (i == 1)
			{
				customerID = stoi(token);
			}
			s.erase(0, position + delimiter.length());
		}
		hashy->displayCustomerHistory(customerID);
	}
	else {
		transactionType;
		cout << "[Invalid Command]" << endl;
	}
	return transactionType;
}


