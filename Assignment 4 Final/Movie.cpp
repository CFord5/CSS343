/*
	MOVIE.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Implementation file for parent Movie class.
*/

#include "Movie.h"

//Constructor
Movie::Movie()
{
	type = "";
	stock = 0;
	director = "";
	title = "";
	year = 0;
}

//Empty
Movie::Movie(string &s)
{
}

//Destructor
Movie::~Movie()
{
}

//Setter
void Movie::setType(string newType)
{
	type = newType;
}

//Setter
void Movie::setStock(int newStock)
{
	stock = newStock;
}

//Setter
void Movie::setDirector(string newDirector)
{
	director = newDirector;
}

//Setter
void Movie::setTitle(string newTitle)
{
	title = newTitle;
}

//Setter
void Movie::setYear(int newYear)
{
	year = newYear;
}

//Getter
string Movie::getType() const
{
	return type;
}

//Getter
int Movie::getStock() const
{
	return stock;
}

//Getter
string Movie::getDirector() const
{
	return director;
}

//Getter
string Movie::getTitle() const
{
	return title;
}

//Getter
int Movie::getYear() const
{
	return year;
}

//Adds to stock
void Movie::addStock(int change)
{
	stock += change;
}

//Subtracts from stocks
void Movie::removeStock(int change)
{
	stock -= change;
}

//Empty
bool Movie::operator<(const Movie & rhs) const
{
	return false;
}

//Empty
bool Movie::operator==(const Movie & rhs) const
{
	return false;
}

//Empty
void Movie::setData(string & s)
{
}

//Removes from stock
void Movie::borrowMovie()
{
	stock = stock - 1;
}

//Adds to stock
void Movie::returnMovie()
{
	stock = stock + 1;
}

//Empty (for Classic)
int Movie::getMonth() const
{
	return -1;
}

//Empty (for Classic)
string Movie::getFirstNameActor() const
{
	return "";
}

//Empty (for Classic)
string Movie::getLastNameActor() const
{
	return "";
}

//Empty
void Movie::display() const
{
}