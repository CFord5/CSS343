/*
	GRAPHM.H
	Author: Chandler Ford
	Date: Feb. 17, 2018
	Last Modified: Feb. 17, 2018
	Description: This is the header file for the GraphM class. This class creates
	an Adjacency Matrix of edge weights and uses Dijkstra's algorithm to find the 
	shortest possible path from every node to every other node.
*/

#include "nodedata.h"
#include "limits.h"
#include <iomanip>
#include <vector>
#pragma once
int const MAXNODESM = 101;  //100 nodes, can't be at index 0

class GraphM
{
public:
	//--------------------------- Constructor -----------------------------------
	// Default constructor for GraphM
	// Preconditions: None
	// Postconditions: Initializes data member T and to false, infinity, or NULL
	GraphM();  
	
	//--------------------------- Destructor ------------------------------------
	// Default constructor for GraphM
	// Preconditions: GraphM exists and is valid
	// Postconditions: Deallocates GraphM
	~GraphM(); 

	//--------------------------- buildGraph ------------------------------------
	// Builds up graph node information and adjacency matrix of edges 
	// Preconditions: GraphM exists and is valid
	// Postconditions: Inserts names and edges into data and C, respectively
	void buildGraph(ifstream &istream);  

	//--------------------------- insertEdge ------------------------------------
	// Used to insert an edge into graph between two given nodes
	// Preconditions: GraphM exists and is valid
	// Postconditions: Inserts edges into specified location in C
	void insertEdge(int toNode, int fromNode, int weight);

	//--------------------------- removeEdge ------------------------------------
	// Used to remove an edge between two given nodes 
	// Preconditions: GraphM exists and is valid
	// Postconditions: Sets edges to infinity at specfied location in C
	void removeEdge(int toNode, int fromNode);	

	//------------------------- findShortestPath --------------------------------
	// Find the shortest path between every node to every other node in the graph
	// Preconditions: GraphM exists and is valid
	// Postconditions: TableType T is updated with shortest path information 
	void findShortestPath(); 

	//---------------------------- displayAll -----------------------------------
	// Uses couts to demonstrate that the algorithm works properly
	// Preconditions: GraphM exists and is valid
	// Postconditions: Information will be displayed to the screen
	void displayAll();  

	//----------------------------- display -------------------------------------
	// Uses couts to display the shortest distance with path info 
	// Preconditions: GraphM exists and is valid
	// Postconditions: Information will be displayed to the screen
	void display(int fromNode, int toNode);  

private:
	struct TableType
	{
		bool visited;  //Whether node has been visited
		int dist;	   //Shortest distance from source known so far
		int path;	   //Previous node in path of minimum distance
	};

	NodeData data[MAXNODESM];			//Data for graph nodes
	int C[MAXNODESM][MAXNODESM];		//Cost array, the adjacency matrix
	int size;							//Number of nodes in the graph
	TableType T[MAXNODESM][MAXNODESM];	//Stores visited, distance, path
};

