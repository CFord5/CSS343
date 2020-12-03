/*
	FACTORY.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file for Factory that creates movies and transactions
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "BinTree.h"
#include "Hashtable.h"
#include "Transaction.h"
#include "Borrow.h"
#include "Return.h"
#define MAXITEMS 100
using namespace std;

class Factory
{
public:
	//Constructor and Destructor
	Factory();
	~Factory();

	//Static methods to create movies and transactions
	static Movie* createMovie(string &s);
	static Transaction createTransaction(string &s, BinTree *&movieTree, Hashtable *&hashy);
};

