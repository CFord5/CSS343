/*
	ASSIGNMENT4.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Contains the main method for the class. Reads in from three files
				 to create movie store.
*/

#include "Store.h"
#include "BinTree.h"
#include <iostream>
#include <string>
#include <fstream>

int main()
{
	//Movies
	Store test;
	ifstream movieFile("data4movies.txt");
	if (!movieFile) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	test.buildMovies(movieFile);

	//Customers
	ifstream customerFile("data4customers.txt");
	if (!customerFile) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	test.buildCustomers(customerFile);

	//Transactions
	ifstream commandFile("data4commands.txt");
	if (!commandFile) {
		cout << "File could not be opened." << endl;
		return 1;
	}
	test.processTrans(commandFile);  

	test.printHash();
	//system("PAUSE");
}

