/*
	BINTREE.CPP
	Authors: Chandler Ford and Catherine Santos
	Date: March. 14, 2018
	Last Modified: March. 14, 2018
	Description: Implementation file for Binary Tree class
*/

#include "BinTree.h"

const int ARRAYSIZE = 100;

//------------------------- BinTree: DEFAULT CONSTRUCTOR ----------------------
BinTree::BinTree()
{
	this->root = NULL; // sets root to null
}

//------------------------- BinTree: COPY CONSTRUCTOR -------------------------
// uses assignment operator to set this to rhs
BinTree::BinTree(const BinTree &rhs)
{
	this->root = NULL; // sets root to null
	*this = rhs;
}

//------------------------- BinTree: DESTRUCTOR -------------------------------
// destroys this bintree
BinTree::~BinTree()
{
	this->makeEmpty();
}

//------------------------- isEmpty -------------------------------------------
// returns true if bintree is empty, returns false otherwise;
bool BinTree::isEmpty() const
{
	return (this->root == NULL);
}

//------------------------- makeEmpty -----------------------------------------
// destroys bintree
void BinTree::makeEmpty()
{
	Node * current = root;
	if (current != NULL) {
		makeEmptyHelper(current); //destroys left and right 
	}
}

//------------------------- makeEmptyHelper -----------------------------------
// helper method for makeEmpty
// recursively destroys left and right nodes of node n
void BinTree::makeEmptyHelper(Node * n)
{
	if (n != NULL) {
		makeEmptyHelper(n->left); // destroys left node
		makeEmptyHelper(n->right); // destroys right node
		delete n->data; // deletes nodedata
		n->data = NULL;
		delete n; // deletes node
		n = NULL;
	}
	this->root = NULL; // destroys root
}

//------------------------- printThreeTypes -----------------------------------
//Print Comedy, Drama, and Classic movies in their respective orders
void BinTree::printThreeTypes(string type)
{
	if (root == NULL)
	{
		return;
	}
	Node *superTemp = root;
	printThreeTypesHelper(superTemp->left, type);
	if (superTemp->data->getType() == type)
	{
		superTemp->data->display();
	}
	printThreeTypesHelper(superTemp->right, type);
}

//------------------------- compare -----------------------------------
//Compares movie to movie already in tree, if found updates pointer
bool BinTree::compare(Movie fakeMovie, Movie *&dummyPointer)
{
	if (root == NULL)
	{
		return false;
	}
	bool found = false;
	Node *superTemp = root;
	found = compareHelper(superTemp->left, fakeMovie, dummyPointer);

	if (fakeMovie == *superTemp->data)
	{
		retrieve(*superTemp->data, dummyPointer);
		return true;
	}

	found = compareHelper(superTemp->right, fakeMovie, dummyPointer);
}

//Recursive helper
void BinTree::printThreeTypesHelper(Node * temp, string type)
{
	if (temp == NULL)
	{
		return;
	}
	printThreeTypesHelper(temp->left, type);
	if (temp->data->getType() == type)
	{
		temp->data->display();
	}
	printThreeTypesHelper(temp->right, type);
}

//Recursive helper
bool BinTree::compareHelper(Node * temp, Movie fakeMovie, Movie *&dummyPointer)
{
	if (temp == NULL)
	{
		return false;
	}
	Node *superTemp = temp;
	return compareHelper(superTemp->left, fakeMovie, dummyPointer);
	if (fakeMovie == *superTemp->data)
	{
		//retrieve(*superTemp->data, dummyPointer);
		return true;
	}
	return compareHelper(superTemp->right, fakeMovie, dummyPointer);
}

//------------------------- insert --------------------------------------------
// inserts node with nodedata rhs per BST rules
// returns true if Node is inserted successfully, returns false otherwise
bool BinTree::insert(Movie *rhs)
{
	bool isInserted = false;

	if (root == NULL) {
		root = new Node;
		root->data = rhs;
		root->left = NULL;
		root->right = NULL;
		isInserted = true;
	}
	else {
		Node *tempRoot = root;
		while (!isInserted) {
			if (rhs->getTitle() == tempRoot->data->getTitle())
			{
				tempRoot->data->addStock(rhs->getStock());
				isInserted = true;
			}
			else
			{
				if (*rhs < *tempRoot->data) { // insert to left
					if (tempRoot->left == NULL) {
						Node *l = new Node;
						l->data = rhs;
						l->left = NULL;
						l->right = NULL;
						tempRoot->left = l;
						isInserted = true;
					}
					else {
						tempRoot = tempRoot->left;
					}
				}
				else if (!(*rhs < *tempRoot->data)) {
					if (tempRoot->right == NULL) { // insert to right
						Node *r = new Node;
						r->data = rhs;
						r->left = NULL;
						r->right = NULL;
						tempRoot->right = r;
						isInserted = true;
					}
					else {
						tempRoot = tempRoot->right;
					}
				}
				else {
					return false;
				}
			}
		}
	}
	return isInserted;
}

//------------------------- retrieve ------------------------------------------
// retrieves NodeData target, found points to target if found
// returns true if nodedata is retrieved successfully, returns false otherwise
bool BinTree::retrieve(const Movie &target, Movie *&found)
{
	if (root == NULL) {
		return false;
	}
	return retrieveHelper(root, target, found);
}

//------------------------- retrieveHelper ------------------------------------
// helper method for retrieve
// returns true if nodedata is retrieved successfully, returns false otherwise
bool BinTree::retrieveHelper(Node *n, const Movie &target, Movie *&found) const {

	if (n == NULL) {
		return false;
	}
	if (target == *n->data) {
		found = n->data;
		return true;
	}
	//recursively traverses tree to find target
	else if (target < *n->data) { // to the left
		retrieveHelper(n->left, target, found);
	}
	else { // to the right
		retrieveHelper(n->right, target, found);
	}
}

// outputs bst contents in in-order traversal
ostream & operator<<(ostream &o, const BinTree &rhs)
{
	if (rhs.root == NULL) {
		return o;
	}
	else {
		rhs.inorderHelper(rhs.root);
	}
	o << endl;
	return o;
}

//------------------------- inorderHelper -------------------------------------
// helper method for printing bst contents in-order
// gets left data, prints data, gets right data
void BinTree::inorderHelper(Node* root) const
{
	if (root == NULL) {
		return;
	}
	else {
		inorderHelper(root->left); // get left
		//cout << (*root->data).getType() << *root->data << endl; // print data
		inorderHelper(root->right); // get right
	}

}