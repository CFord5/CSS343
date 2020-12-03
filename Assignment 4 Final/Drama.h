/*
	DRAMA.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file for child Drama class
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Movie.h"
using namespace std;

class Drama : public Movie
{
public:
	//Constructors and Destructor
	Drama();
	Drama(string & s);
	~Drama();

	//Operator overloads
	bool operator<(const Movie &rhs) const;
	bool operator==(const Movie &rhs) const;

	//Other methods
	void setData(string &s) override;
	int getMonth() const;
	void display() const override;
};



