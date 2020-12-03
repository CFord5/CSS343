/*
	GRAPHL.CPP
	Author: Chandler Ford
	Date: Feb. 17, 2018
	Last Modified: Feb. 17, 2018
	Description: This is the implementation file for the GraphL class. This class creates
	an Adjacency List containing NodeData pointers to location names and additional
	nodes to store edges.
*/

#include "graphl.h"

//--------------------------- Constructor -----------------------------------
// Default constructor for GraphL
// Preconditions: NodeData exists
// Postconditions: All GraphNodes will be marked unvisited and set to NULL
GraphL::GraphL()
{
	size = 0;
	for (int i = 0; i < MAXNODESL; i++)
	{
		arrayOfGraphNodes[i].data = NULL;		//Set data members to NULL or false
		arrayOfGraphNodes[i].edgeHead = NULL;
		arrayOfGraphNodes[i].visited = false;
	}
}

//--------------------------- Destructor -----------------------------------
// Default destructor for GraphL
// Preconditions: GraphL object exists and is valid
// Postconditions: GraphL contents will be deallocated
GraphL::~GraphL() 
{
	for (int i = 1; i <= size; i++)
	{
		if (arrayOfGraphNodes[i].edgeHead != NULL)  //If edges exist
		{
			while (arrayOfGraphNodes[i].edgeHead != NULL)  //While edges
			{											   //edges exist
				EdgeNode *temp = arrayOfGraphNodes[i].edgeHead->nextEdge;
				delete arrayOfGraphNodes[i].edgeHead;  //Delete allocated
				arrayOfGraphNodes[i].edgeHead = temp;  //edges
			}
		}
		delete arrayOfGraphNodes[i].data;  //Delete allocated names
	}
}

//--------------------------- buildGraph -----------------------------------
// Build up graph node information and adjacency list of edges between each
// node reading from a data file
// Preconditions: GraphL object exists and is valid
// Postconditions: Fills arrayOfGraphNodes and linked list of edgeNodes
void GraphL::buildGraph(ifstream & istream)
{
	int fromNode = 0;  //Keep track of which nodes the edge is between
	int toNode = 0;

	istream >> size;  //Read in the size from the file
	
	string nodeNames;  //Use getline to read in the names of the nodes
	getline(istream, nodeNames);

	for (int i = 1; i <= size; i++)  //Create a new NodeData for each name
	{
		NodeData *newNodeData = new NodeData;
		newNodeData->setData(istream);				//Set this new NodeData
		arrayOfGraphNodes[i].data = newNodeData;	//as the GraphNode data
	}

	for (;;)  //Keep going through the file
	{
		if (istream.eof())  //Break if the end is reached
		{
			break;
		}

		istream >> fromNode >> toNode;  //Read in the two numbers per line

		if (fromNode == 0)  //If the number is zero break out 
		{
			return;
		}
		else
		{
			if (arrayOfGraphNodes[fromNode].edgeHead == NULL)  //If there are no edges currently
			{
				EdgeNode *newEdgeHead = new EdgeNode;  //Make a new edgeNode
				newEdgeHead->adjGraphNode = toNode;  //Set the value to the connected Node
				newEdgeHead->nextEdge = NULL;
				arrayOfGraphNodes[fromNode].edgeHead = newEdgeHead;  //Set equal to edgeHead
			}
			else  //If there already is an edgeHead
			{
				EdgeNode *temp = arrayOfGraphNodes[fromNode].edgeHead;  //Make a temp node
				EdgeNode *newEdgeHead = new EdgeNode;  //Make a new edgeNode
				newEdgeHead->adjGraphNode = toNode;  //Set the value to the connected Node
				arrayOfGraphNodes[fromNode].edgeHead = newEdgeHead;  //Set equal to edgeHead
				arrayOfGraphNodes[fromNode].edgeHead->nextEdge = temp;  //Move old edgeHead back
			}
		}
	}
}

//--------------------------- displayGraph --------------------------------
// Display each node information and edge in the graph
// Preconditions: om a data file
// Preconditions: GraphL object exists and is valid
// Postconditions: Formatted text of the different edges between nodes
void GraphL::displayGraph()
{
	cout << endl;  //Spacing
	cout << endl;
	cout << "Graph:" << endl;
	for (int i = 1; i <= size; i++)  
	{
		cout << "Node " << i << "\t\t" << *arrayOfGraphNodes[i].data << endl;  //Print names
		if (arrayOfGraphNodes[i].edgeHead != NULL)  //If they have edges
		{
			EdgeNode *temp = arrayOfGraphNodes[i].edgeHead;  //Make a temp
			while (temp != NULL)  //Loop through and print edges
			{  
				cout << "   " << "edge " << " " << i << " " << temp->adjGraphNode << endl;
				temp = temp->nextEdge;
			}
		}
	}
	cout << endl;
}

//--------------------------- depthFirstSearch -----------------------------
// Makes a depth-first search and displays each node in depth-first order
// Preconditions: GraphL object exists and is valid, dfs exists and is valid
// Postconditions: Will print out the depth-first path
void GraphL::depthFirstSearch()
{
	cout << "Depth-first ordering: ";  //Print
	//Mark all not visited, done in constructor
	for (int v = 1; v <= size; v++)
	{
		if (arrayOfGraphNodes[v].visited == false)
		{
			dfs(v);  //Call helper function
		}
	}
}

//--------------------------- dfs ------------------------------------------
// Utility function for depthFirstSearch
// Preconditions: GraphL object exists and is valid
// Postconditions: Will print out the depth-first path
void GraphL::dfs(int v)
{
	//Mark v visited
	arrayOfGraphNodes[v].visited = true;

	//Do whatever with v (print it out)
	cout << v << " ";

	//For each w adjacent to v
	if (arrayOfGraphNodes[v].edgeHead != NULL)  //If there are edges
	{
		EdgeNode *temp = arrayOfGraphNodes[v].edgeHead;  //Make a temp
		if (arrayOfGraphNodes[temp->adjGraphNode].visited == false)
		{
			dfs(temp->adjGraphNode);  //Recursively call
		}
	}
}
