/*
	STORE.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Implementation file for Store object.
*/

#include "Store.h"

//Default constructor
Store::Store()
{	
}

Store::~Store()
{
}


//Uses getLine to read from movie file
void Store::buildMovies(istream &infile) 
{
	string line;
	for (;;)
	{
		getline(infile, line);
		if (infile.eof()) {
			return;
		}
		Movie *newMovie = Factory::createMovie(line);
		if (newMovie != NULL)
		{
			movieTree.insert(newMovie);
		}
	}
}

//Uses getLine to read from customer file
void Store::buildCustomers(istream &infile)
{
	string line;
	for (;;)
	{
		getline(infile, line);
		if (infile.eof()) {
			return;
		}
		Customer newCustomer(line);
		customerHash.insert(newCustomer);
	}
}

//Uses getLine to read from command file
void Store::processTrans(istream &infile)
{
	string line;
	for (;;)
	{
		getline(infile, line);
		if (infile.eof()) {
			return;
		}
		BinTree *tree = getTree();  //Create for Factory method call
		Hashtable *hash = getHashtable();
		Transaction newTransaction = Factory::createTransaction(line, tree, hash);
	}
}

//Accessor for BinTree
BinTree* Store::getTree()
{
	BinTree* holder = &movieTree;
	return holder;
}

//Accessor for Hashtable
Hashtable* Store::getHashtable()
{
	Hashtable* holder = &customerHash;
	return holder;
}

//Print customers
void Store::printHash()
{
	customerHash.displayHash();
}

