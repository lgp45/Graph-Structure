#include "Graph_Earlier.h"
#include <string>

Graph_Earlier::~Graph_Earlier() {
}

bool Graph_Earlier::IsLinkWalkable()
{
	//table of angle degrees of each node
	vector<int> deg(vertexNode.size());
	//compounded deg of all edgeLinks
	for (auto e : edgeLink)
	{
		deg[e.first]++;
		deg[e.second]++;
	}
	//count Odd #
	int countOdds = 0;
	for (auto d : deg)
	{
		if (d % 2 == 1)
		{
			countOdds++;
		}
	}
	return (countOdds == 0 || countOdds == 2);
}

void Graph_Earlier::OutputGraph()
{

}

void Graph_Earlier::AddNode(int newNodeID)
{
	vertexNode.push_back(newNodeID);
}
void Graph_Earlier::AddLink(int nodeID1, int nodeID2)
{
	pair<int, int>& p = *new pair<int, int>;
	p.first = nodeID1;
	p.second = nodeID2;
	//Links denote NODEID to NODEID - this linkage will allow direct node to node traversal
	edgeLink.push_back(p);
}
void Graph_Earlier::AddLinkNode(int nodeID, int nodeID2)
{
	pair<int, int>& p = *new pair<int, int>;
}

void Graph_Earlier::UpdateGraph()
{

}


//custom object set
/*
void Graph::InsertNode(int dataToAdd, int linkTo)
{
	int newID = graph.size();
	pair<Node, vector<Link>> &p = *new pair<Node, vector<Link>>;
	p.first = new Node();
	p.first.nodeID = newID;
	p.first.data->push_back(dataToAdd);
	p.first.nodeLink->dest2 = linkTo;
	p.second = vector<Link>();	//establish a blanked vector set of links that are attri
	p.second.push_back(*p.first.nodeLink);
	graph.push_back(p);
}
*/
