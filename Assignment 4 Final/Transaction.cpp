/*
	TRANSACTIONS.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Implementation file for parent Transaction class.
*/

#include "Transaction.h"

//Constructor
Transaction::Transaction()
{
}

//Constructor with arguments
Transaction::Transaction(string &s, BinTree *&movieTree)
{
	setData(s, movieTree);
}

//Destructor
Transaction::~Transaction()
{
}

//Empty
void Transaction::doTrans()
{
}

//Set data members by parsing through line from file
void Transaction::setData(string & s, BinTree *&movieTree)
{
	int position = 0;
	string delimiter = " ";
	string token = "";

	for (int i = 0; i < 4; i++)
	{
		position = s.find(delimiter);
		token = s.substr(0, position);
		if (i == 0)
		{
			transactionType = token;
		}
		if (i == 1)
		{
			customerID = stoi(token);
		}
		if (i == 2)
		{
			mediaType = token;
		}
		if (i == 3)
		{
			movieType = token; //see if this exists in movietree
		}
		if (i == 4)
		{
			movieData = token;
		}
		s.erase(0, position + delimiter.length());
	}
	parseMovieData(movieType, s, movieTree);
}

//Print
void Transaction::printBorrowOrReturn()
{
	//cout << "BORROW OR RETURN" << endl;
}

//Getter
int Transaction::getCustomerID()
{
	return customerID;
}

//Parse through specific part of above data
void Transaction::parseMovieData(string &type, string &s, BinTree *&movieTree)
{
	Movie *dummyPointer = NULL;
	if (type == "F")  //For Comedies
	{
		int position = 0;
		string delimiter = ", ";
		string token = "";

		for (int i = 0; i < 2; i++)
		{
			position = s.find(delimiter);
			token = s.substr(0, position);
			if (i == 0)
			{
				comedyTitle = token;
			}
			if (i == 1)
			{
				comedyYear = stoi(token);
			}
			s.erase(0, position + delimiter.length());
		}
		Comedy fakeMovie;
		fakeMovie.setTitle(comedyTitle);
		fakeMovie.setYear(comedyYear);
		if (compareMovies(fakeMovie, movieTree, dummyPointer) == true)
		{
			changeStockForSameMovie(dummyPointer);
		}
	}
	else if (type == "D")  //For Dramas
	{
		int position = 0;
		string delimiter = ", ";
		string token = "";

		for (int i = 0; i < 2; i++)
		{
			position = s.find(delimiter);
			token = s.substr(0, position);
			if (i == 0)
			{
				dramaDirector = token;
			}
			if (i == 1)
			{
				dramaTitle = token;
			}
			s.erase(0, position + delimiter.length());
		}
		Drama fakeMovie;
		fakeMovie.setDirector(dramaDirector);
		fakeMovie.setTitle(dramaTitle);
		compareMovies(fakeMovie, movieTree, dummyPointer);
		if (compareMovies(fakeMovie, movieTree, dummyPointer) == true)
		{
			changeStockForSameMovie(dummyPointer);
		}
		else
		{
			cout << "[Invalid Movie]" << endl;
		}
	}
	else if (type == "C")  //For Classics
	{
		int position = 0;
		string delimiter = " ";
		string token = "";

		for (int i = 0; i < 4; i++)
		{
			position = s.find(delimiter);
			token = s.substr(0, position);
			if (i == 0)
			{
				classicMonth = stoi(token);
			}
			if (i == 1)
			{
				classicYear = stoi(token);
			}
			if (i == 2)
			{
				actorFN = token;
			}
			if (i == 3)
			{
				actorLN = token;
			}
			s.erase(0, position + delimiter.length());
		}
		Classic fakeMovie;
		fakeMovie.setYear(classicYear);
		fakeMovie.setMonth(classicMonth);
		fakeMovie.setFirstNameActor(actorFN);
		fakeMovie.setLastNameActor(actorLN);
		compareMovies(fakeMovie, movieTree, dummyPointer);
		if (compareMovies(fakeMovie, movieTree, dummyPointer) == true)
		{
			changeStockForSameMovie(dummyPointer);
		}
	}
	else
	{
		cout << "[Invalid Movie Type]" << endl;
	}
}

//See if movie is already in the tree
bool Transaction::compareMovies(Movie toCompare, BinTree *&movieTree, Movie *&dummyPointer)
{
	return (movieTree->compare(toCompare, dummyPointer));
}

//If above is true stock will be increased
void Transaction::changeStockForSameMovie(Movie *&smartPointer)
{
	smartPointer->addStock(1);
}
