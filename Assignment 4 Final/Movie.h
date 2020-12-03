/*
	MOVIE.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file for parent Movie class.
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Movie
{
public:
	Movie();
	Movie(string & s);
	~Movie();

	//Setters
	void setType(string newType);
	void setStock(int newStock);
	void setDirector(string newDirector);
	void setTitle(string newTitle);
	void setYear(int newYear);

	//Getters
	string getType() const;
	int getStock() const;
	string getDirector() const;
	string getTitle() const;
	int getYear() const;

	//Stock
	void addStock(int change);
	void removeStock(int change);

	//Overloads
	virtual bool operator<(const Movie &rhs) const;
	virtual bool operator==(const Movie &rhs) const;
	
	//Overrides
	virtual void setData(string &s);
	virtual void display() const;

	//Classic methods
	virtual int getMonth() const;
	virtual string getFirstNameActor() const;
	virtual string getLastNameActor() const;

	//Borrow and return
	void borrowMovie(); 
	void returnMovie();
protected:
	//Data members
	string type;
	int stock;
	string director;
	string title;
	int year;
};

