/*
	STORE.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file to keep track of Store object.
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "BinTree.h"
#include "Hashtable.h"
#include "Factory.h"
using namespace std;

class Store
{
public:
	//Constructor and Destructor
	Store();
	~Store();

	//Read from three files
	void buildMovies(istream &infile);
	void buildCustomers(istream &infile);
	void processTrans(istream &infile);

	//Other
	BinTree* getTree();
	Hashtable* getHashtable();
	void printHash();

private:
	//Data members
	Hashtable customerHash;
	BinTree movieTree;
};

