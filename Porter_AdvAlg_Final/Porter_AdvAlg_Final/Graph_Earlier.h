//Graph Structure Compile
#include <iostream>
#include <vector>
#include "Node.h"
using namespace std;
class Graph_Earlier
{
private:

public:
#pragma region PHASE 2 TEST --- Deprecated
	//PHASE 2 TEST STRUCTURE

	//containers
	vector<int> vertexNode;
	//edgeLink contains two nodeIDs showing its connection points
	vector<pair<int, int>> edgeLink;

	//constructor
	Graph_Earlier(vector<int>& vertex, vector<pair<int, int>>& edge)
		: vertexNode(vertex), edgeLink(edge) {};
	~Graph_Earlier();

	//operators
	bool IsLinkWalkable();
	void OutputGraph();
	void AddNode(int newNodeID);	//we can have nodes without links
	void AddLink(int nodeID1, int nodeID2);	//we cant have links without nodes, links require atleast 1 node at all times
	void AddLinkNode(int nodeId, int nodeId2);
	void UpdateGraph();

#pragma endregion

#pragma region PHASE 3 TEST--- Deprecated
	//a attempt at using custom objects with easily extendable nodes
	vector<pair<Node, vector<Link>>> graph;	//structure testing
	void InsertNode(int dataToAdd, int linkTo);
#pragma endregion
};