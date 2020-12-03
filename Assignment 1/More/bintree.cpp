#include "bintree.h"

//------------------------------- << ----------------------------------------
//
// 
// Preconditions: 
// Postconditions: 
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
//
// 
// Preconditions: 
// Postconditions: 
BinTree::BinTree()
{
	root = NULL;
}

//------------------------------ Copy ---------------------------------------
// 
// 
// Preconditions: 
// Postconditions:
BinTree::BinTree(const BinTree &toCopy)
{
	this->root = NULL;
	*this = toCopy;
}

//---------------------------- Destructor -----------------------------------
// 
// 
// Preconditions: 
// Postconditions: 
BinTree::~BinTree()
{
	makeEmpty();
}

bool BinTree::isEmpty() const
{
	bool empty = false;
	if (root == NULL)
	{
		empty = true;
	}
	return empty;
}

void BinTree::makeEmpty()
{
	//My Way
	/*if (root == NULL)
	{
		return;
	}

	makeEmptyHelper(root->left);
	makeEmptyHelper(root->right);

	delete root->data;
	root->data = NULL;
	delete root;
	root = NULL;*/

	//Other Way
	Node *current = root;
	if (current != NULL)
	{
		makeEmptyHelper(current);
	}
}

void BinTree::makeEmptyHelper(Node *temp)
{
	//My Way
	/*if (temp == NULL)
	{
		return;
	}

	makeEmptyHelper(temp->left);
	makeEmptyHelper(temp->right);

	delete temp->data;
	temp->data = NULL;
	delete temp;
	temp = NULL;*/

	//Other Way
	if (temp != NULL)
	{
		makeEmptyHelper(temp->left);
		makeEmptyHelper(temp->right);
		delete temp->data;
		temp->data = NULL;
		delete temp;
		temp = NULL;
	}
	this->root = NULL;
	
	//Other other way
	/*if (temp)
	{
		makeEmptyHelper(temp->left);
		makeEmptyHelper(temp->right);
		delete temp;
	}*/
}

BinTree & BinTree::operator=(const BinTree &rhs)
{
	if (this != &rhs)
	{
		makeEmpty();
		root = NULL;
		root = assignmentHelper(rhs.root);
	}
	return *this;
}

BinTree::Node* BinTree::assignmentHelper(Node *toCopyNode)
{
	if (toCopyNode == NULL)
	{
		return NULL;
	}
	Node *newNode = new Node();
	if (toCopyNode->data != NULL)
	{
		newNode->data = (new NodeData(*toCopyNode->data));
	}
	newNode->left = assignmentHelper(newNode->left);
	newNode->right = assignmentHelper(newNode->right);
	return newNode;

	//Newer broken way
	/*if (toCopyNode)
	{
		insert(toCopyNode->data);
		if (toCopyNode->left != NULL)
		{
			assignmentHelper(toCopyNode->left);
		}
		if (toCopyNode->right != NULL)
		{
			assignmentHelper(toCopyNode->right);
		}
	}*/

	//Old broken way
	/*this->insert(toCopyNode->data);

	if (toCopyNode->left != NULL)
	{
		assignmentHelper(toCopyNode->left);
	}
	if (toCopyNode->right != NULL)
	{
		assignmentHelper(toCopyNode->right);
	}*/
}

bool BinTree::operator==(const BinTree &rhs) const
{
	bool areEqual = false;
	if (root == NULL && rhs.root == NULL)
	{
		return true;
	}
	if (root == NULL && rhs.root != NULL)
	{
		return false;
	}
	if (root != NULL && rhs.root == NULL)
	{
		return false;
	}
	/*if (*root->data == *rhs.root->data)
	{
		equalityHelper(root->left, rhs.root->left, areEqual);
		equalityHelper(root->right, rhs.root->right, areEqual);
	}
	else
	{
		areEqual = false;
	}*/
	if (*root->data == *rhs.root->data)
	{
		areEqual = true;
	}
	else
	{
		equalityHelper(root, rhs.root, areEqual);
	}
	return areEqual;
}

bool BinTree::operator!=(const BinTree & rhs) const
{
	return !(*this == rhs);
}

void BinTree::equalityHelper(Node *temp, Node *rhs, bool &areEqual) const
{
	if (*temp->data != *rhs->data)
	{
		areEqual = false;
	}
	if (temp != NULL && rhs != NULL && areEqual == true) 
	{
		equalityHelper(root->left, rhs->left, areEqual);
		equalityHelper(root->right, rhs->right, areEqual);
	}
}

//----------------------------- Insert ---------------------------------------
// 
// 
// Preconditions: 
// Postconditions: 
bool BinTree::insert(NodeData *rhs)
{
	Node *n = new Node;
	n->data = rhs;
	n->left = NULL;
	n->right = NULL;
	Node *temp = root;
	if (root == NULL)
	{
		root = n;
		return true;
	}
	else
	{

		bool inserted = false;
		while(!inserted)
		{
			if (*n->data < *temp->data)
			{
				if (temp->left == NULL)
				{
					temp->left = n;
					inserted = true;
					return inserted;
				}
				else
				{
					temp = temp->left;
				}
			}
			else if (*n->data > *temp->data)
			{
				if (temp->right == NULL)
				{
					temp->right = n;
					inserted = true;
					return inserted;
				}
				else
				{
					temp = temp->right;
				}
			}
			else  //If equal
			{
				inserted = false;
				return inserted;
			}
		}
	}
	return false;
}

//----------------------------- Retrieve ---------------------------------------
// 
// 
// Preconditions: 
// Postconditions: 
bool BinTree::retrieve(const NodeData &target, NodeData *&foundObject)
{
	bool isFound = false;
	Node *temp = root;
	retrieveHelper(temp, isFound, target, foundObject);
	return isFound;
}

//------------------------- displaySideways ---------------------------------
// Displays a binary tree as though you are viewing it from the side;
// hard coded displaying to standard output.
// Preconditions: NONE
// Postconditions: BinTree remains unchanged.
void BinTree::displaySideways() const {
	sideways(root, 0);
}

int BinTree::getHeight(const NodeData &rhs) const
{
	int height = 0;
	getHeightHelper(root, rhs, height);
	return height;
}

void BinTree::bstreeToArray(NodeData *rhs[])
{
	int size = 0;
	if (root != NULL)
	{
		bstreeToArrayHelper(rhs, root, size); 
		//makeEmpty();
	}
}

void BinTree::bstreeToArrayHelper(NodeData *rhs[], Node *temp, int &size)
{
	if (temp == NULL) return;  //Break if node is null
	bstreeToArrayHelper(rhs, temp->left, size);  //Recursively traverse left
	rhs[size++] = temp->data;
	bstreeToArrayHelper(rhs, temp->right, size);  //Recursively traverse right
}

void BinTree::arrayToBSTree(NodeData *rhs[])
{
	for (int i = 0; i < 100; i++)
	{
		if (rhs[i] != NULL)
		{
			insert(rhs[i]);
			rhs[i] = NULL;
		}
	}
}

int BinTree::getHeightHelper(Node *temp, const NodeData &rhs, int &height) const
{
	int left = 0;
	int right = 0;
	int largerHeight = 0;

	if (temp->left != NULL)
	{
		left = getHeightHelper(temp->left, rhs, height);
	}
	if (temp->right != NULL)
	{
		right = getHeightHelper(temp->right, rhs, height);
	}

	if (left > right)
	{
		largerHeight = left + 1;
	}
	else
	{
		largerHeight = right + 1;
	}
	
	if (rhs == *temp->data)
	{
		height = largerHeight;
	}
	return largerHeight;
}

//------------------------- inorderHelper -----------------------------------
// 
// 
// Preconditions: 
// Postconditions: 
void BinTree::inorderHelper(Node *root) const
{
	if (root == NULL) return;  //Break if node is null

	inorderHelper(root->left);  //Recursively traverse left
	cout << *root->data << " ";  //Print node data
	inorderHelper(root->right);  //Recursively traverse right
}

//------------------------- retrieveHelper -----------------------------------
// 
// 
// Preconditions: 
// Postconditions: 
void BinTree::retrieveHelper(Node *temp, bool &isFound, const NodeData &target, NodeData *&foundObject) const
{
	if (temp == NULL)
	{
		return;
	}
	else if (*temp->data == target)  //If found
	{
		foundObject = temp->data;
		isFound = true;
	}
	else if (*temp->data > target)  //If target smaller
	{
		retrieveHelper(temp->left, isFound, target, foundObject);
	}
	else  //If target larger
	{
		retrieveHelper(temp->right, isFound, target, foundObject);
	}
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