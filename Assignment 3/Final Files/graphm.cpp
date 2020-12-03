/*
	GRAPHM.CPP
	Author: Chandler Ford
	Date: Feb. 17, 2018
	Last Modified: Feb. 17, 2018
	Description: This is the header file for the GraphM class. This class creates
	an Adjacency Matrix of edge weights and uses Dijkstra's algorithm to find the
	shortest possible path from every node to every other node.
*/

#include "graphm.h"

//--------------------------- Constructor -----------------------------------
// Default constructor for GraphM
// Preconditions: None
// Postconditions: Initializes data member T and to false, infinity, or NULL
GraphM::GraphM()
{
	for (int i = 1; i < MAXNODESM; i++)
	{
		for (int j = 1; j < MAXNODESM; j++)
		{
			C[i][j] = INT_MAX;	//All edges initially set to infinity
			T[i][j].visited = false;  //TableType values initialized
			T[i][j].dist = INT_MAX;
			T[i][j].path = 0;
		}
	}
}

//--------------------------- Destructor ------------------------------------
// Default constructor for GraphM
// Preconditions: GraphM exists and is valid
// Postconditions: Deallocates GraphM
GraphM::~GraphM()
{
	//Not required for Part 1
}

//--------------------------- buildGraph ------------------------------------
// Builds up graph node information and adjacency matrix of edges 
// Preconditions: GraphM exists and is valid
// Postconditions: Inserts names and edges into data and C, respectively
void GraphM::buildGraph(ifstream &istream)
{
	int fromNode = 0;  //Keep track of weights and related nodes
	int toNode = 0;
	int weight = 0;

	istream >> size;  //Read in the size
	string nodeNames;  //Used to take in the stream names
	getline(istream, nodeNames);

	for (int i = 1; i <= size; i++)
	{
		data[i].setData(istream);  //Insert string names into array
	}	

	for (;;)  //Keep going through the file
	{
		if (istream.eof())  //Break if the end is reached
		{
			break;
		}

		istream >> fromNode >> toNode >> weight;  //Read in info

		if (fromNode == 0)  //If next is zero, return
		{
			return;
		}
		else
		{
			insertEdge(fromNode, toNode, weight);  //Insert edges
		}
	}
}

//--------------------------- insertEdge ------------------------------------
// Used to insert an edge into graph between two given nodes
// Preconditions: GraphM exists and is valid
// Postconditions: Inserts edges into specified location in C
void GraphM::insertEdge(int fromNode, int toNode, int weight)
{
	C[fromNode][toNode] = weight;  //Set weight at specified location
}

//--------------------------- removeEdge ------------------------------------
// Used to remove an edge between two given nodes 
// Preconditions: GraphM exists and is valid
// Postconditions: Sets edges to infinity at specfied location in C
void GraphM::removeEdge(int toNode, int fromNode)
{
	C[toNode][fromNode] = INT_MAX;  //INT_MAX represents infinity
}

//------------------------- findShortestPath --------------------------------
// Find the shortest path between every node to every other node in the graph
// Preconditions: GraphM exists and is valid
// Postconditions: TableType T is updated with shortest path information 
void GraphM::findShortestPath()
{
	for (int source = 1; source <= size; source++)
	{
		T[source][source].dist = 0;

		//Finds the shortest distance from source to all other nodes
		for (int i = 1; i <= size; i++)
		{
			//Find v (not visited, shortest distance at this point)
			int shortestDistance = INT_MAX;  //Current shortest distance
			int v = -1;  //For finding v
			
			for (int j = 1; j <= size; j++)  //Loops through to find v
			{
				if(T[source][j].visited == false && T[source][j].dist < shortestDistance)
				{
					shortestDistance = T[source][j].dist;  //Update
					v = j;  //Update
				}
			}

			if (v == -1)  //If not found, break out of loop
			{
				break;
			}

			//Mark v visited
			T[source][v].visited = true;

			//For each w adjacent to v
			for (int w = 1; w <= size; w++)
			{
				//If w is not visited and edge exists
				if (T[source][w].visited == false && C[v][w] < INT_MAX)
				{
					if ((T[source][v].dist + C[v][w]) < T[source][w].dist)  //Find smaller
					{
						T[source][w].dist = (T[source][v].dist + C[v][w]);
					}
					
					if (T[source][w].dist == T[source][v].dist + C[v][w])
					{
						T[source][w].path = v;  //Update path
					}
				}  
			}
		}
	}
}

//---------------------------- displayAll -----------------------------------
// Uses couts to demonstrate that the algorithm works properly
// Preconditions: GraphM exists and is valid
// Postconditions: Information will be displayed to the screen
void GraphM::displayAll()
{
	//Print headers
	cout << "Description" << setw(17) << "From node" << setw(12) << "To node";
	cout << setw(15) << "Dijkstra's" << setw(9) << "Path" << endl;
	for (int i = 1; i <= size; i++)
	{
		cout << data[i] << endl;  //Print names
		for (int j = 1; j <= size; j++)
		{
			if (i != j)  //Node doesn't have a path to itself
			{
				//If edge, print --- instead of INT_MAX
				if (T[i][j].dist == INT_MAX)  
				{
					cout << setw(23) << i << setw(14) << j << setw(14);
					cout << "---" << setw(12) << "---" << endl;
				}
				else
				{
					if (i == T[i][j].path)  //If two nodes in path
					{
						cout << setw(23) << i << setw(14) << j << setw(13);
						cout << T[i][j].dist << setw(11) << T[i][j].path;
						cout << " " << j << " " << endl;  //Print info
					}
					else
					{
						cout << setw(23) << i << setw(14) << j << setw(13);
						cout << T[i][j].dist << setw(11) << i << " ";
						cout << T[i][j].path << " " << j << " " << endl;
					}
				}
			}
		}
	}
	cout << endl;
}

//----------------------------- display -------------------------------------
// Uses couts to display the shortest distance with path info 
// Preconditions: GraphM exists and is valid
// Postconditions: Information will be displayed to the screen
void GraphM::display(int fromNode, int toNode)
{
	if (fromNode == toNode)  //Node doesn't have path to itself
	{
		cout << fromNode << "\t" << toNode << "\t" << "---" << endl;
	}
	if (T[fromNode][toNode].dist == INT_MAX)  //If edge, print --- 
	{
		cout << fromNode << "\t" << toNode << "\t" << "---" << endl;
	}
	else  //If two nodes
	{
		if (fromNode == T[fromNode][toNode].path)
		{
			cout << fromNode << "\t" << toNode << "\t";  //Print info
			cout << T[fromNode][toNode].dist << "\t";
			cout << T[fromNode][toNode].path << " " << toNode << endl;
			cout << data[T[fromNode][toNode].path] << endl;
			cout << data[toNode] << endl;
		}
		else
		{
			cout << fromNode << "\t" << toNode << "\t";  //Print info
			cout << T[fromNode][toNode].dist << "\t" << fromNode << " ";
			cout << T[fromNode][toNode].path << " " << toNode << endl;
			cout << data[fromNode] << endl;
			cout << data[T[fromNode][toNode].path] << endl;
			cout << data[toNode] << endl;

		}
	}
	cout << endl;
}
