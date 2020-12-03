/*
	CLASSIC.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Implementations file for child Classic class
*/

#include "Classic.h"

//Constructor
Classic::Classic()
{
}

//Constructor with arguments
Classic::Classic(string &s)
{
	setData(s);
}

//Destructor
Classic::~Classic()
{
}

//Setter
void Classic::setMonth(int newMonth)
{
	month = newMonth;
}

//Setter
void Classic::setFirstNameActor(string newFirstName)
{
	firstNameActor = newFirstName;
}

//Setter
void Classic::setLastNameActor(string newLastName)
{
	lastNameActor = newLastName;
}

//Getter
int Classic::getMonth() const
{
	return month;
}

//Getter
string Classic::getFirstNameActor() const
{
	return firstNameActor;
}

//Getter
string Classic::getLastNameActor() const
{
	return lastNameActor;
}

//Overloads operator< to compare Classics
bool Classic::operator<(const Movie & rhs) const
{
	if (year < rhs.getYear())
	{
		return true;
	}
	else if (year == rhs.getYear() && month < rhs.getMonth())
	{
		return true;
	}
	else if (year == rhs.getYear() && month == rhs.getMonth() && firstNameActor < rhs.getFirstNameActor())
	{
		return true;
	}
	else if (year == rhs.getYear() && month == rhs.getMonth() && firstNameActor == rhs.getFirstNameActor() && lastNameActor < rhs.getLastNameActor())
	{
		return true;
	}
	else {
		return false;
	}
}

//Overloads operator== to compare Classics
bool Classic::operator==(const Movie &rhs) const
{
	return (year == rhs.getYear() && month == rhs.getMonth());
}

//Parse through data from line (from file) to set data members
void Classic::setData(string &s)
{
	int position = 0;
	string delimiter = ", ";
	string token = "";

	for (int i = 0; i < 4; i++)
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
		s.erase(0, position + delimiter.length());
	}

	position = 0;
	delimiter = " ";
	token = "";

	for (int i = 0; i < 4; i++)
	{
		position = s.find(delimiter);
		token = s.substr(0, position);
		if (i == 0)
		{
			firstNameActor = token;
		}
		else if (i == 1)
		{
			lastNameActor = token;
		}
		else if (i == 2)
		{
			month = stoi(token);
		}
		else if (i == 3)
		{
			year = stoi(token);
		}
		s.erase(0, position + delimiter.length());
	}
}

//Print to screen
void Classic::display() const
{
	cout << getType() << ", " << getStock() << ", " << getTitle() << ", " << getDirector() << ", " << getYear() << endl;
}



