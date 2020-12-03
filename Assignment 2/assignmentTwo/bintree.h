/*
	BINTREE.H
	Author: Chandler Ford
	Date: Jan. 28, 2018
	Last Modified: Jan. 28, 2018
	Description: This is the header file for the BinTree class. This class creates
	a Binary Search Tree containing NodeData pointers to integer values. The tree
	can be transferred to an array and vice versa, anong other actions.
*/

#include "nodedata.h"

class BinTree 
{				
	//------------------------------- << ----------------------------------------
	// Operator overload to display inorder traversal of BinTree
	// Preconditions: BinTree exists and is valid
	// Postconditions: Contents of BinTree will be printed with inorder traversal
	friend ostream & operator<<(ostream &o, const BinTree &rhs); 
public:
	//--------------------------- Constructor -----------------------------------
	// Default constructor for BinTree
	// Preconditions: None
	// Postconditions: Root will be initialized to NULL
	BinTree();			

	//------------------------------ Copy ---------------------------------------
	// Copy Constructor for BinTree
	// Preconditions: BinTree exists and is valid
	// Postconditions: New BinTree will be initialized using argument contents
	BinTree(const BinTree &toCopy);		

	//---------------------------- Destructor -----------------------------------
	// Destructor for BinTree that calls makeEmpty to deallocate memory
	// Preconditions: makeEmpty() exists and is a valid method
	// Postconditions: BinTree contents will be deallocated
	~BinTree();	

	//------------------------------ isEmpty ------------------------------------
	// Boolean method that determines if the BinTree is empty 
	// Preconditions: None
	// Postconditions: Returns true or false depending on root 
	bool isEmpty() const;

	//------------------------------ makeEmpty -----------------------------------
	// Called by the destructor to help delete BinTree
	// Preconditions: None
	// Postconditions: Recursively calls helper to delete left and right subtrees
	void makeEmpty();	

	//---------------------------------- = ----------------------------------------
	// Overloads the assignment operator for BinTree
	// Preconditions: BinTree exists and is valid
	// Postconditions: Value of BinTree will be set to the argument's values
	BinTree& operator=(const BinTree &rhs);	

	//--------------------------------- == ----------------------------------------
	// Overloads the eqaulity operator for BinTree
	// Preconditions: BinTree exists and is valid
	// Postconditions: Will return true if both BinTrees are the same, false if not
	bool operator==(const BinTree &rhs) const; 

	//-------------------------------- != -----------------------------------------
	// Overloads the ineqaulity operator for BinTree
	// Preconditions: BinTree exists and is valid
	// Postconditions: Will return false if both BinTrees are the same, true if not
	bool operator!=(const BinTree &rhs) const; 

	//----------------------------- Insert ---------------------------------------
	// Inserts NodeData into the Binary Search Tree by value
	// Preconditions: NodeData exists and is valid
	// Postconditions: Will return true if inserted, false if not
	bool insert(NodeData *rhs);	

	//----------------------------- Retrieve ---------------------------------------
	// Gets pointer to NodeData of target object, if found point to it
	// Preconditions: NodeData exists and is valid
	// Postconditions: Returns true or false if found, foundObject set if true
	bool retrieve(const NodeData &target, NodeData *&foundObject); 

	//------------------------- displaySideways ------------------------------------
	// Displays a binary tree as though you are viewing it from the side;
	// hard coded displaying to standard output.
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	void displaySideways() const;	

	//---------------------------- getHeight ---------------------------------------
	// Finds height of target value in tree
	// Preconditions: NodeData exists and is valid
	// Postconditions: Returns integer value for height
	int getHeight(const NodeData &target) const;

	//---------------------------bstreeToArray -------------------------------------
	// Fills array of NodeData pointers using values from BinTree
	// Preconditions: NodeData and NodeData array exists and are valid
	// Postconditions: Returns nothing but initializes array of NodeData pointers
	void bstreeToArray(NodeData *rhs[]);

	//---------------------------arrayToBSTree -------------------------------------
	// Fills BinTree using array of NodeData pointers, sets array pointers to NULL
	// Preconditions: NodeData array exists and are valid
	// Postconditions: Returns nothing, initializes BinTree with NodeData pointers
	void arrayToBSTree(NodeData *rhs[]);	
private:
	struct Node {
		NodeData* data;  //Pointer to data object
		Node* left;		 //Left subtree pointer
		Node* right;	 //Right subtree pointer
	};
	Node* root;	//Root of the tree

	//--------------------------- inorderHelper ------------------------------------
	// Called by operator<< to help print out the contents of BinTree in order
	// Preconditions: BinTree exists and has valid Nodes
	// Postconditions: Contents will be printed out with help of inorder traversal
	void inorderHelper(Node *temp) const;

	//------------------------- makeEmptyHelper ------------------------------------
	// Called by makeEmpty to help destroy BinTree
	// Preconditions: BinTree exists and has valid Nodes
	// Postconditions: Root, along with  left and right subtrees, will be destroyed
	void makeEmptyHelper(Node *temp);

	//------------------------- assignmentHelper ------------------------------------
	// Called by operator= to help assign value on right hand side to left
	// Preconditions: BinTree exists and has valid Nodes
	// Postconditions: Returns root of new BinTree, recursively fills left and right
	Node* assignmentHelper(Node *toCopyNode);

	//------------------------- equalityHelper --------------------------------------
	// Called by operator== to help determine if two BinTrees are equal
	// Preconditions: BinTree exists and has valid Nodes
	// Postconditions: Boolean value will switch to false if data sets don't match
	void equalityHelper(Node *temp, Node *rhs, bool &areEqual) const;

	//------------------------- retrieveHelper --------------------------------------
	// Called by retrieve to help recursively go through BinTree
	// Preconditions: BinTree exists and is valid
	// Postconditions: Will return true if target found and point to it with pointer
	void retrieveHelper(Node *temp, bool &isFound, const NodeData &target, NodeData* &foundObject) const;

	//------------------------- getHeightHelper --------------------------------------
	// Called by getHeight to help recursively go through BinTree
	// Preconditions: BinTree exists and is valid
	// Postconditions: Will return int value of largest height, reference keeps track
	int getHeightHelper(Node *temp, const NodeData &target, int &height) const;

	//---------------------------- Sideways -------------------------------------
	// Helper method for displaySideways
	// Preconditions: NONE
	// Postconditions: BinTree remains unchanged.
	void sideways(Node*, int) const;

	//------------------------- bstreeToArrayHelper --------------------------------------
	// Called by  bstreeToArray to help recursively go through BinTree
	// Preconditions: BinTree and array of NodeData pointers exists and are valid
	// Postconditions: Uses inorder traversal to fill array with NodeData pointers
	void bstreeToArrayHelper(NodeData * rhs[], Node *temp, int &size);
};