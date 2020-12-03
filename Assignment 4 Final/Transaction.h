/*
	TRANSACTION.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file for parent Transaction class.
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "BinTree.h"
#include "Movie.h"
#include "Comedy.h"
#include "Drama.h"
#include "Classic.h"
using namespace std;

class Transaction
{
public:
	//Constructors and Destructor
	Transaction();
	Transaction(string &s, BinTree *&movieTree);
	~Transaction();

	//Other methods
	virtual void doTrans();
	virtual void setData(string &s, BinTree *&movieTree);
	virtual void printBorrowOrReturn();
	int getCustomerID();
	void parseMovieData(string &type, string &token, BinTree *&movieTree);
	bool compareMovies(Movie toCompare, BinTree *&movieTree, Movie *&dummyPointer);
	void changeStockForSameMovie(Movie *&smartPointer);
protected:
	//General data members
	string transactionType;
	int customerID;
	string mediaType;
	string movieType;
	string movieData;

	//For Comedies
	string comedyTitle;
	int comedyYear;

	//For Dramas
	string dramaDirector;
	string dramaTitle;

	//For Classics
	int classicMonth;
	int classicYear;
	string actorFN;
	string actorLN;
};

