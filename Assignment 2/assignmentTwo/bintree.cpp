/*
	BINTREE.CPP
	Author: Chandler Ford
	Date: Jan. 28, 2018
	Last Modified: Jan. 28, 2018
	Description: This is the implmentation file for the BinTree class. This class creates
	a Binary Search Tree containing NodeData pointers to integer values. The tree
	can be transferred to an array and vice versa, anong other actions.
*/

#include "bintree.h"

//------------------------------- << ----------------------------------------
// Operator overload to display inorder traversal of BinTree
// Preconditions: BinTree exists and is valid
// Postconditions: Contents of BinTree will be printed with inorder traversal
ostream & operator<<(ostream &o, const BinTree &rhs)
{
	if (rhs.root == NULL) return o;  //Break if node is null

	rhs.inorderHelper(rhs.root->left);  //Recursively traverse left
	o << *rhs.root->data << " ";  //Print node data
	rhs.inorderHelper(rhs.root->right);  //Recursively traverse right
	o << endl;
	return o;
}

//--------------------------- Constructor -----------------------------------
// Default constructor for BinTree
// Preconditions: None
// Postconditions: Root will be initialized to NULL
BinTree::BinTree()
{
	root = NULL;  //Creates empty tree
}

//------------------------------ Copy ---------------------------------------
// Copy Constructor for BinTree
// Preconditions: BinTree exists and is valid
// Postconditions: New BinTree will be initialized using argument contents
BinTree::BinTree(const BinTree &toCopy)
{
	root = NULL;  //Creates empty tree
	*this = toCopy;  //Return a pointer that initalizes with the operator=
}

//---------------------------- Destructor -----------------------------------
// Destructor for BinTree that calls makeEmpty to deallocate memory
// Preconditions: makeEmpty() exists and is a valid method
// Postconditions: BinTree contents will be deallocated
BinTree::~BinTree()
{
	makeEmpty();  //Call method
}

//------------------------------ isEmpty ------------------------------------
// Boolean method that determines if the BinTree is empty 
// Preconditions: None
// Postconditions: Returns true or false depending on root 
bool BinTree::isEmpty() const
{
	bool empty = false;  //Declare and initialize bool
	if (root == NULL)  //If the root is NULL, the tree is empty
	{
		empty = true;
	}
	return empty;
}

//------------------------------ makeEmpty -----------------------------------
// Called by the destructor to help delete BinTree
// Preconditions: None
// Postconditions: Recursively calls helper to delete left and right subtrees
void BinTree::makeEmpty()
{
	if (root == NULL)  //If tree empty do nothing
	{
		return;
	}

	makeEmptyHelper(root->left);  //Recursive calls
	makeEmptyHelper(root->right);

	delete root->data;  //Take care of the root and its data
	root->data = NULL;
	delete root;
	root = NULL;
}

//---------------------------------- = ----------------------------------------
// Overloads the assignment operator for BinTree
// Preconditions: BinTree exists and is valid
// Postconditions: Value of BinTree will be set to the argument's values
BinTree & BinTree::operator=(const BinTree &rhs)
{
	if (this != &rhs)  //If the don't already match
	{ 
		makeEmpty();  //Clear the tree
		root = NULL;  //Set the tree to empty
		root = assignmentHelper(rhs.root);  //Find new root with helper method
	}
	return *this;  //Return a pointer to the BinTree
}

//--------------------------------- == ----------------------------------------
// Overloads the eqaulity operator for BinTree
// Preconditions: BinTree exists and is valid
// Postconditions: Will return true if both BinTrees are the same, false if not
bool BinTree::operator==(const BinTree &rhs) const
{
	bool areEqual = false;  //Declare and initialize boolean
	if (root == NULL && rhs.root == NULL)  //If both are NULL they are the same
	{
		return true;
	}
	if (root == NULL && rhs.root != NULL)  //If only one is NULL they are false
	{
		return false;
	}
	if (root != NULL && rhs.root == NULL)
	{
		return false;
	}
	if (*root->data == *rhs.root->data)  //If roots equal each other, set true
	{
		areEqual = true;
	}
	else
	{
		equalityHelper(root, rhs.root, areEqual);  //Call recursive helper
	}
	return areEqual;  //Return boolean value
}

//-------------------------------- != -----------------------------------------
// Overloads the ineqaulity operator for BinTree
// Preconditions: BinTree exists and is valid
// Postconditions: Will return false if both BinTrees are the same, true if not
bool BinTree::operator!=(const BinTree & rhs) const
{
	return !(*this == rhs);  //Uses the equality operator and ! to return bool
}

//----------------------------- Insert ---------------------------------------
// Inserts NodeData into the Binary Search Tree by value
// Preconditions: NodeData exists and is valid
// Postconditions: Will return true if inserted, false if not
bool BinTree::insert(NodeData *rhs)
{
	if (root == NULL)  //If the root doesn't exists
	{
		root = new Node;  //Make it exist
		root->data = rhs;  //Initialize data with argument
		root->left = NULL;  //Set left and right to NULL
		root->right = NULL;
		return true;  //Return boolean
	}
	else
	{
		Node *newNode = new Node;  //Make a new node
		Node *temp = root;  //Make temp node to go through BinTree to compare
		bool inserted = false;  //While loop control boolean
		while(!inserted)  //While the new node has not been inserted
		{
			if (*rhs < *temp->data)  //If argument value < current value
			{
				if (temp->left == NULL)  //If there is space for it to left
				{
					newNode->data = rhs;  //Initialize new node with argument
					newNode->left = NULL;  //Set left and right to NULL
					newNode->right = NULL;
					temp->left = newNode;  //Assign newNode to the left subtree
					inserted = true;  //Break loop
					return inserted;  //Return boolean
				}
				else  //If not, keep traversing through BinTree
				{ 
					temp = temp->left;  //Keep traversing
				}
			}
			else if (*rhs > *temp->data)  //If argument value > current value
			{
				if (temp->right == NULL)  //If there is space for it to right
				{
					newNode->data = rhs;  //Initialize new node with argument
					newNode->left = NULL;  //Set left and right to NULL
					newNode->right = NULL;  
					temp->right = newNode;  //Assign newNode to the right subtree
					inserted = true;  //Break loop
					return inserted;  //Return boolean
				}
				else  //If not, keep traversing through BinTree
				{
					temp = temp->right;  //Keep traversing
				}
			}
			else  //If equal
			{
				delete newNode;  //Delete so it doesn't cause a memory leak
				newNode = NULL;  //Set dangling pointer to NULL
				inserted = false;  //Break loop
				return inserted;  //Return boolean
			}
		}
	}
	return false;
}

//----------------------------- Retrieve ---------------------------------------
// Gets pointer to NodeData of target object, if found point to it
// Preconditions: NodeData exists and is valid
// Postconditions: Returns true or false if found, foundObject set if true
bool BinTree::retrieve(const NodeData &target, NodeData *&foundObject)
{
	bool isFound = false;  //Declare and initialize boolean
	Node *temp = root;  //Make a temporary pointer node
	retrieveHelper(temp, isFound, target, foundObject);  //Call helper method
	return isFound;  //Return boolean
}

//------------------------- displaySideways ------------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

//---------------------------- getHeight ---------------------------------------
// Finds height of target value in tree
// Preconditions: NodeData exists and is valid
// Postconditions: Returns integer value for height
int BinTree::getHeight(const NodeData &target) const
{
	int height = 0;  //Declare and intialize height variable
	getHeightHelper(root, target, height);  //Call recursive helper method
	return height;  //Return integer value
}

//---------------------------bstreeToArray -------------------------------------
// Fills array of NodeData pointers using values from BinTree
// Preconditions: NodeData and NodeData array exists and are valid
// Postconditions: Returns nothing but initializes array of NodeData pointers
void BinTree::bstreeToArray(NodeData *rhs[])
{
	int size = 0;  //Declare and intialize size variable
	if (root != NULL)  //If BinTree exists
	{
		bstreeToArrayHelper(rhs, root, size);  //Call recursive helper method
	}
}

//---------------------------arrayToBSTree -------------------------------------
// Fills BinTree using array of NodeData pointers, sets array pointers to NULL
// Preconditions: NodeData array exists and are valid
// Postconditions: Returns nothing, initializes BinTree with NodeData pointers
void BinTree::arrayToBSTree(NodeData *rhs[])
{
	for (int i = 0; i < 100; i++)  //While going through array
	{
		if (rhs[i] != NULL)  //If something exists in the array
		{
			insert(rhs[i]);  //Place it in the BinTree
			rhs[i] = NULL;  //Sets array pointers to NULL
		}
	}
}

//--------------------------- inorderHelper ------------------------------------
// Called by operator<< to help print out the contents of BinTree in order
// Preconditions: BinTree exists and has valid Nodes
// Postconditions: Contents will be printed out with help of inorder traversal
void BinTree::inorderHelper(Node *temp) const
{
	if (temp == NULL) return;  //Break if node is null

	inorderHelper(temp->left);  //Recursively traverse left
	cout << *temp->data << " ";  //Print node data
	inorderHelper(temp->right);  //Recursively traverse right
}

//------------------------- makeEmptyHelper ------------------------------------
// Called by makeEmpty to help destroy BinTree
// Preconditions: BinTree exists and has valid Nodes
// Postconditions: Root, along with  left and right subtrees, will be destroyed
void BinTree::makeEmptyHelper(Node *temp)
{
	if (temp == NULL)  //If there's nothing there
	{
		return;  //Do nothing
	}

	makeEmptyHelper(temp->left);  //Recursive call for left subtree
	makeEmptyHelper(temp->right);  //Recursive call for right subtree

	delete temp->data;  //Delete Node and NodeData, set to NULL
	temp->data = NULL;
	delete temp;
	temp = NULL;
}

//------------------------- assignmentHelper ------------------------------------
// Called by operator= to help assign value on right hand side to left
// Preconditions: BinTree exists and has valid Nodes
// Postconditions: Returns root of new BinTree, recursively fills left and right
BinTree::Node* BinTree::assignmentHelper(Node *toCopyNode)
{
	bool isNull = false;  //Boolean to keep track of NULL
	isNull = (toCopyNode == NULL);
	if (isNull == true)  //If there's nothing here
	{
		return NULL;  //Do nothing
	}

	Node *newNode = new Node();  //Create a new node

	bool isDataNull = false;  //Boolean to keep track of NULL
	isDataNull = (toCopyNode->data != NULL);
	if (isDataNull == true)  //If space, fill new node with argument value
	{
		newNode->data = new NodeData(*toCopyNode->data);
	}

	newNode->left = assignmentHelper(newNode->left);  //Fill left and right
	newNode->right = assignmentHelper(newNode->right); //with recursive calls

	return newNode;  //Returns node 
}

//------------------------- equalityHelper --------------------------------------
// Called by operator== to help determine if two BinTrees are equal
// Preconditions: BinTree exists and has valid Nodes
// Postconditions: Boolean value will switch to false if data sets don't match
void BinTree::equalityHelper(Node *temp, Node *rhs, bool &areEqual) const
{
	if (*temp->data != *rhs->data)  //If the values don't match
	{
		areEqual = false;  //Set boolean to false and break the loop
	}
	if (temp != NULL && rhs != NULL && areEqual == true) //Not NULL and true
	{
		equalityHelper(root->left, rhs->left, areEqual);  //Check left and right
		equalityHelper(root->right, rhs->right, areEqual); //with recursive calls
	}
}

//------------------------- retrieveHelper --------------------------------------
// Called by retrieve to help recursively go through BinTree
// Preconditions: BinTree exists and is valid
// Postconditions: Will return true if target found and point to it with pointer
void BinTree::retrieveHelper(Node *temp, bool &isFound, const NodeData &target, NodeData *&foundObject) const
{
	if (temp == NULL)  //If nothing 
	{
		return;  //Return
	}
	else if (*temp->data == target)  //If target found
	{
		foundObject = temp->data;  //Set foundObject pointer to point to it in memory
		isFound = true;  //Set boolean value to true
	}
	else if (*temp->data > target)  //If target smaller than temp
	{
		retrieveHelper(temp->left, isFound, target, foundObject);  //Traverse left
	}
	else  //If target larger than temp
	{
		retrieveHelper(temp->right, isFound, target, foundObject);  //Traverse right
	}
}

//------------------------- getHeightHelper --------------------------------------
// Called by getHeight to help recursively go through BinTree
// Preconditions: BinTree exists and is valid
// Postconditions: Will return int value of largest height, reference keeps track
int BinTree::getHeightHelper(Node *temp, const NodeData &target, int &height) const
{
	int largerSubtreeHeight = 0;  //Used to hold larger height of subtrees
	int leftSubtreeHeight = 0;  //Used to hold height of left subtree
	int rightSubtreeHeight = 0;  //Used to hold height of right subtree

	bool leftNull = false;  //Boolean to control left recursive call
	leftNull = (temp->left != NULL);
	if (temp->left != NULL)  //If not NULL, keep traversing
	{
		leftSubtreeHeight = getHeightHelper(temp->left, target, height);
	}

	bool rightNull = false;  //Boolean to control right recursive call
	rightNull = (temp->right != NULL);
	if (temp->right != NULL)  //If not NULL, keep traversing
	{
		rightSubtreeHeight = getHeightHelper(temp->right, target, height);
	}

	if (leftSubtreeHeight > rightSubtreeHeight)  //If one side is larger than the other, increment
	{				   //and set to larger
		largerSubtreeHeight = leftSubtreeHeight + 1;
	}
	else
	{
		largerSubtreeHeight = rightSubtreeHeight + 1;
	}

	if (target == *temp->data)  //If current value of node matches the target
	{
		height = largerSubtreeHeight;  //This is height that needs to be found
	}

	return largerSubtreeHeight;  //Return value
}

//---------------------------- Sideways -------------------------------------
// Helper method for displaySideways
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::sideways(Node* current, int level) const {
	if (current != NULL) {
		level++;
		sideways(current->right, level);

		// indent for readability, 4 spaces per depth level 
		for (int i = level; i >= 0; i--) {
			cout << "    ";
		}

		cout << *current->data << endl;        // display information of object
		sideways(current->left, level);
	}
}

//------------------------- bstreeToArrayHelper --------------------------------------
// Called by  bstreeToArray to help recursively go through BinTree
// Preconditions: BinTree and array of NodeData pointers exists and are valid
// Postconditions: Uses inorder traversal to fill array with NodeData pointers
void BinTree::bstreeToArrayHelper(NodeData *rhs[], Node *temp, int &size)
{
	if (temp == NULL)  //Break if node is null
	{
		return;
	}
	bstreeToArrayHelper(rhs, temp->left, size);  //Recursively traverse left
	rhs[size++] = temp->data;  //Add NodeData pointer to array at index
	bstreeToArrayHelper(rhs, temp->right, size);  //Recursively traverse right
}