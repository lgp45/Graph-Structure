//Graph Structure Compile
#include <iostream>
#include <vector>
#include <map>
#include "Node.h"
using namespace std;
class Graph
{
private:

public:
#pragma region PHASE 4 TEST
	//PHASE 4 TEST STRUCTURE - draws from the initial phase 2 work with understanding of flow in phase 3
	vector<Node> nodes;	//set of nodes on the graph, nodes have one internal link at this time
	vector<Link> links;	//set of lines between nodes
	Graph();
	~Graph();

	//operators
	void InsertNewNode(); //blank undirect nodes, only has an ID + precompiled dest1 link (home)
	void InsertNewNode(int data);	//no initial directed link
	void InsertNewNode(vector<int> dataSet);	//no initial directed link
	void InsertNewNode(int data, int directedLink);	//DIRECTED LINK INCLUDED
	void InsertBlankLink();
	void AddLink(int v1, int v2);	//will check to ensure both nodes exists then create and add a link between
	void AddLinkToNode(int node1, int node2);

	//not implemented - planned if time
	void RemoveNode(int node);
	void RemoveLink(int dest1, int dest2);
	void RemoveLink(Link remove);

	void BuildLinkSets();

	//returns
	Node GetNode(int nodeID);
	Node GetNode(Node node);

	//output
	void OutputNodeInfo(int nodeID);	//output single node info
	void OutputAdjacentGraph();	//output nodes and their adjacent Linked Nodes
	void OutputDirectedGraph(); //output the nodes internal links directed graph

	//alg helpers
	void ClearNodeStates();

	//algs
	void SelectandWrap(int startNode); //go to desired node, then iterate from 0 through til all visited
	void BreadthFirstSearch2(int startNode); //go to desired node, then iterate from 0 through til all visited

	void NodeDepthFirstSearch(int s, int iterator);
	//was yielding errors
	void MultiNodeDepthTraversal(int s, int e, int iterator); //start, end, iterator;

#pragma endregion

};