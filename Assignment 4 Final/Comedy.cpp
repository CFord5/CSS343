/*
	COMEDY.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Implementation file for child Comedy class
*/

#include "Comedy.h"

//Constructor
Comedy::Comedy()
{

}

//Constructor with arguments
Comedy::Comedy(string &s)
{
	setData(s);

}

//Destructor
Comedy::~Comedy()
{
}

//Overloads operator< to sort Comedies
bool Comedy::operator<(const Movie & rhs) const
{
	if (title < rhs.getTitle()) {
		return true;
	}
	else if (title == rhs.getTitle()) {
		if (year < rhs.getYear()) {
			return true;
		}
		else {
			return false;
		}
	}
}

//Overloads == to compare Comedies
bool Comedy::operator==(const Movie & rhs) const
{
	return (title == rhs.getTitle() && year == rhs.getYear());
}

//Parses through data to initialize data members
void Comedy::setData(string &s)
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
int Comedy::getMonth() const
{
	return -1;
}

//Print out to screen
void Comedy::display() const
{
	cout << getType() << ", " << getStock() << ", " << getTitle() << ", " << getDirector() << ", " << getYear() << endl;
}
