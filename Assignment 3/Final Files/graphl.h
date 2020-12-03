/*
	GRAPHL.H
	Author: Chandler Ford
	Date: Feb. 17, 2018
	Last Modified: Feb. 17, 2018
	Description: This is the header file for the GraphL class. This class creates
	an Adjacency List containing NodeData pointers to location names and additional
	nodes to store edges.
*/

#include "nodedata.h"
#pragma once
int const MAXNODESL = 101;  //100 nodes, can't be at index 0

class GraphL
{
public:
	//--------------------------- Constructor -----------------------------------
	// Default constructor for GraphL
	// Preconditions: NodeData exists
	// Postconditions: All GraphNodes will be marked unvisited and set to NULL
	GraphL();

	//--------------------------- Destructor -----------------------------------
	// Default destructor for GraphL
	// Preconditions: GraphL object exists and is valid
	// Postconditions: GraphL contents will be deallocated
	~GraphL();

	//--------------------------- buildGraph -----------------------------------
	// Build up graph node information and adjacency list of edges between each
	// node reading from a data file
	// Preconditions: GraphL object exists and is valid
	// Postconditions: Fills arrayOfGraphNodes and linked list of edgeNodes
	void buildGraph(ifstream &istream); 

	//--------------------------- displayGraph -----------------------------------
	// Display each node information and edge in the graph
	// Preconditions: om a data file
	// Preconditions: GraphL object exists and is valid
	// Postconditions: Formatted text of the different edges between nodes
	void displayGraph();  

	//--------------------------- depthFirstSearch -------------------------------
	// Makes a depth-first search and displays each node in depth-first order
	// Preconditions: GraphL object exists and is valid, dfs exists and is valid
	// Postconditions: Will print out the depth-first path
	void depthFirstSearch();   
private:
	struct EdgeNode;  //Forward reference for the compiler
	struct GraphNode
	{
		EdgeNode *edgeHead; //Head of list of edges
		NodeData *data;  //Data information about each node (name)
		bool visited;
	};
	struct EdgeNode
	{
		int adjGraphNode;  //Subscript of the adjacent GraphNodes
		EdgeNode *nextEdge;
	};
	GraphNode arrayOfGraphNodes[MAXNODESL];  //Array of GraphNodes
	int size;  //Number of nodes

	//--------------------------- dfs --------------------------------------------
	// Utility function for depthFirstSearch
	// Preconditions: GraphL object exists and is valid
	// Postconditions: Will print out the depth-first path
	void dfs(int v);  
};

