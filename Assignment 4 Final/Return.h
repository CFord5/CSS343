/*
	RETURN.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file for child Return class.
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "BinTree.h"
#include "Transaction.h"
using namespace std;

class Return : public Transaction
{
public:
	//Constructors and Destructor
	Return();
	Return(string &s, BinTree *&movieTree);
	~Return();

	//Other methods
	void doTrans() override;
	void display();
	void printBorrowOrReturn() override;
};

