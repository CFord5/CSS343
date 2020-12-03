/*
	BINTREE.H
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Header file for Binary Tree class.
*/

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Movie.h"
using namespace std;


class BinTree {
	friend ostream & operator<<(ostream &, const BinTree &);
public:
	BinTree();										// constructor
	BinTree(const BinTree &);						// copy constructor
	~BinTree();										// destructor, calls makeEmpty	

	bool isEmpty() const;							// true if tree is empty, otherwise false
	void makeEmpty();								// makes the tree empty so isEmpty returns true

	bool insert(Movie *);						//true if inserted, false otherwise
	bool retrieve(const Movie &, Movie * &);	//true if retrieved, false otherwise
	void printThreeTypes(string type);			//prints three types of movie in appropriate order
	bool compare(Movie fakeMovie, Movie *&dummyPointer);  //Compares movie from file to movies already in tree

private:
	struct Node {
		Movie* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};

	Node* root;								// root of the tree

	//utility functions
	void inorderHelper(Node*) const;
	bool retrieveHelper(Node *, const Movie &, Movie *&) const;
	void makeEmptyHelper(Node *);
	void printThreeTypesHelper(Node *temp, string type);  //Recursive helper
	bool compareHelper(Node *temp, Movie fakeMovie, Movie *&dummyPointer);  //Recursive helper
};

