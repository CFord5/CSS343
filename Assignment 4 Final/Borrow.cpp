/*
	BORROW.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description:
*/

#include "Borrow.h"

//Constructor
Borrow::Borrow()
{
}

//Constructor with arguments
Borrow::Borrow(string &s, BinTree *&movieTree)
{
	setData(s, movieTree);
}

//Destructor
Borrow::~Borrow()
{
}

//Empty
void Borrow::doTrans()
{
	//Don't print unless for incorrect data/command
}

//Empty
void Borrow::display()
{
}

//Print
void Borrow::printBorrowOrReturn()
{
	cout << "Borrow";
}
