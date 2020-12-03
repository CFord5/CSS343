/*
	COMEDY.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file for child Comedy class
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Movie.h"
using namespace std;

class Comedy : public Movie
{
public:
	//Constructors and Destructor
	Comedy();
	Comedy(string &s);
	~Comedy();

	//Overloads
	bool operator<(const Movie &rhs) const override;
	bool operator==(const Movie &rhs) const;

	//More methods
	void setData(string &s) override;
	int getMonth() const;
	void display() const override;
};


