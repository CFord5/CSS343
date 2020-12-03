/*
	CLASSIC.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file for child Classic class
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Movie.h"
using namespace std;

class Classic : public Movie
{
public:
	//Constructors and Destructor
	Classic();
	Classic(string &s);
	~Classic();

	//Setters
	void setMonth(int newMonth);
	void setFirstNameActor(string newFirstName);
	void setLastNameActor(string newLastName);

	//Getters
	int getMonth() const;
	string getFirstNameActor() const;
	string getLastNameActor() const;

	//Overloads
	bool operator<(const Movie &rhs) const override ;
	bool operator==(const Movie &rhs) const override ;
	
	//Overrides
	void setData(string &s) override;
	void display() const override;
private:
	//Data members
	string firstNameActor;
	string lastNameActor;
	int month;
};

