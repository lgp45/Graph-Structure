#include <vector>
#include "Link.h"
using namespace std;
class Node
{
private:

public:
	int nodeID = 0;
	bool visited = false;
	//any other data we want can also be held in here
	vector<int> data;
	Link* nodeLink = new Link();	//this acts as a kind of directed link per node
	vector<Link> linkSet = *new vector<Link>();
	Node()
	{
		nodeLink->dest1 = this->nodeID;
		
	}
	Node(Node* linkToThis)
	{
		nodeLink->dest1 = this->nodeID;
		nodeLink->dest2 = linkToThis->nodeID;
	}
};