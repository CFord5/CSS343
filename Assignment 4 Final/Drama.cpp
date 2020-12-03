/*
	DRAMA.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Implementation file for child Drama class
*/

#include "Drama.h"

//Constructor
Drama::Drama()
{
}

//Constructor with arguments
Drama::Drama(string &s)
{
	setData(s);
}

//Destructor
Drama::~Drama()
{
}

//Overloads operator< to compare dramas
bool Drama::operator<(const Movie & rhs) const
{
	if (director < rhs.getDirector()) {
		return true;
	}
	else if (director == rhs.getDirector()) {
		if (title < rhs.getTitle()) {
			return true;
		}
		else {
			return false;
		}
	}
}

//Overloads operator== to compare dramas
bool Drama::operator==(const Movie & rhs) const
{
	return (director == rhs.getDirector() && title == rhs.getTitle());
}

//Parses through data to initialize data members
void Drama::setData(string &s)
{
	int position = 0;
	string delimiter = ", ";
	string token = "";

	for (int i = 0; i < 5; i++)
	{
		position = s.find(delimiter);
		token = s.substr(0, position);
		if (i == 0)
		{
			type = token;
		}
		else if (i == 1)
		{
			stock = stoi(token);
		}
		else if (i == 2)
		{
			director = token;
		}
		else if (i == 3)
		{
			title = token;
		}
		else if (i == 4)
		{
			year = stoi(token);
		}
		s.erase(0, position + delimiter.length());
	}
}

//For classic
int Drama::getMonth() const
{
	return -1;
}

//Print out to screen
void Drama::display() const
{
	cout << getType() << ", " << getStock() << ", " << getTitle() << ", " << getDirector() << ", " << getYear() << endl;
}


