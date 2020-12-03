/*
	BORROW.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file for child Borrow class.
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "BinTree.h"
#include "Transaction.h"
using namespace std;

class Borrow : public Transaction
{
public:
	//Constructors and Destructor
	Borrow();
	Borrow(string &s, BinTree *&movieTree);
	~Borrow();

	//Other methods
	void doTrans() override;
	void display();
	void printBorrowOrReturn() override;
};

