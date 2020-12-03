#include "nodedata.h"

class BinTree {				// you add class/method comments and assumptions
	friend ostream & operator<<(ostream &o, const BinTree &rhs);  //Display tree using inorder traversal
public:
	BinTree();								// constructor
	BinTree(const BinTree &toCopy);				// copy constructor
	~BinTree();								// destructor, calls makeEmpty	
	bool isEmpty() const;					// true if tree is empty, otherwise false
	void makeEmpty();						// make the tree empty so isEmpty returns true
	BinTree& operator=(const BinTree &rhs);	//Assign one tree to another
	bool operator==(const BinTree &rhs) const; //Return true if same data and structure
	bool operator!=(const BinTree &rhs) const; //Return true if different
	bool insert(NodeData *rhs);					//???
	bool retrieve(const NodeData &target, NodeData *&foundObject);  //Get NodeData* of given object in tree and report if found (t/f), 2nd pointer garbage until object found
	void displaySideways() const;			// provided below, displays the tree sideways
	int getHeight(const NodeData &rhs) const;	//Solve for general binary tree, find height of given value in tree
	void bstreeToArray(NodeData *rhs[]);		//Fill an array of NodeData* using inorder traversal of tree, leaves tree empty
	void arrayToBSTree(NodeData *rhs[]);		//Builds a balanced BinTree from sorted array of NodeData* leaving array filled with NULLs
private:
	struct Node {
		NodeData* data;						// pointer to data object
		Node* left;							// left subtree pointer
		Node* right;						// right subtree pointer
	};
	Node* root;								// root of the tree

											// utility functions
	void inorderHelper(Node *root) const;
	void retrieveHelper(Node *temp, bool &isFound, const NodeData &target, NodeData* &foundObject) const;
	int getHeightHelper(Node *temp, const NodeData &rhs, int &height) const;
	void makeEmptyHelper(Node *temp);
	Node* assignmentHelper(Node *toCopyNode);
	void equalityHelper(Node *temp, Node *rhs, bool &areEqual) const;
	void bstreeToArrayHelper(NodeData * rhs[], Node *temp, int &size);
	void sideways(Node*, int) const;			// provided below, helper for displaySideways()
};