/*
	RETURN.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Implementaion file for child Return class.
*/

#include "Return.h"

//Constructor
Return::Return()
{
}

//Constructor with arguments
Return::Return(string & s, BinTree *&movieTree)
{
	setData(s, movieTree);
}

//Destructor
Return::~Return()
{
}

//Empty
void Return::doTrans()
{
	//Don't print unless for incorrect data/command
}

//Empty
void Return::display()
{
}

//Empty
void Return::printBorrowOrReturn()
{
	cout << "Return";
}
