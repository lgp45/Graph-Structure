#include "Graph.h"
#include <string>
#include <iterator>
#include <list>

Graph::Graph()
{

}
Graph::~Graph() {
}
#pragma region Phase 4 Testing
//operators
void Graph::InsertNewNode()
{
	Node n = new Node();
	int newID = nodes.size();
	n.nodeID = newID;
	nodes.push_back(n);
}
void Graph::InsertNewNode(int data)
{
	Node n = new Node();
	int newID = nodes.size();
	n.nodeID = newID;
	n.data.push_back(data);
	nodes.push_back(n);
}
void Graph::InsertNewNode(vector<int> dataSet)
{
	Node n = new Node();
	int newID = nodes.size();
	n.nodeID = newID;
	n.data = dataSet;
	nodes.push_back(n);
}
void Graph::InsertNewNode(int dat, int directedLink)
{
	Node n = new Node();
	int newID = nodes.size();
	n.nodeID = newID;
	n.data.push_back(dat);
	n.nodeLink->dest2 = directedLink;
	nodes.push_back(n);
}
void Graph::InsertBlankLink()
{
	links.push_back(Link());
}
void Graph::AddLink(int v1, int v2)
{
	Link l;
	l.dest1 = v1;
	l.dest2 = v2;
	links.push_back(l);
}
void Graph::AddLinkToNode(int node1, int node2)
{
	Link l;
	l.dest1 = node1;
	l.dest2 = node2;
	links.push_back(l);
	nodes[node1].linkSet.push_back(l);
	nodes[node2].linkSet.push_back(l);
}

//returns
Node Graph::GetNode(int nodeID)
{
	return NULL;
}
Node Graph::GetNode(Node node)
{
	return NULL;
}

//output
void Graph::OutputNodeInfo(int nodeNum)
{
	cout << "\nNode (vertex) " << nodes[nodeNum].nodeID << "\t";
	cout << "Links To: ";
	for (int f = 0; f < links.size(); f++)
	{
		if (links[f].dest1 == nodes[nodeNum].nodeID)
		{
			cout << to_string(links[f].dest2) << " ";
		}
		if (links[f].dest2 == nodes[nodeNum].nodeID)
		{
			cout << to_string(links[f].dest1) << " ";
		}
	}
}
void Graph::OutputAdjacentGraph()
{
	cout << "\nNode Adjacency Listing (Non-Directed Nodes)" << endl;
	for (int i = 0; i < nodes.size(); i++)
	{
		cout << "Node (vertex) " << nodes[i].nodeID << "\t";
		cout << "Links To: ";
		for (int f = 0; f < links.size(); f++)
		{
			if (links[f].dest1 == nodes[i].nodeID)
			{
				cout << to_string(links[f].dest2) << " ";
			}
			if (links[f].dest2 == nodes[i].nodeID)
			{
				cout << to_string(links[f].dest1) << " ";
			}
		}
		cout << endl;
	}
}
void Graph::OutputDirectedGraph()
{
	cout << "\nNodes Internal Directed Links - Single Link";
	for (int i = 0; i < nodes.size(); i++)
	{
		cout << "\nNode " << nodes[i].nodeID << "\t";
		cout << "Directed Link: " << nodes[i].nodeLink->dest2;
	}
}

//alg helpers
void Graph::ClearNodeStates()
{
	for (int i = 0; i < nodes.size(); i++)
	{
		nodes[i].visited = false;
		nodes[i].nodeLink->visited = false;
		for (int f = 0; f < nodes[i].linkSet.size(); f++)
		{
			nodes[i].linkSet[f].visited = false;
		}
	}
}


//algs
void Graph::SelectandWrap(int s)
{
	cout << "\nBFS for Node " << to_string(s);
	vector<bool> visited;
	visited.resize(nodes.size(), false);
	//utilize a queue structure to ensure single pass
	vector<int> queue;
	visited[s] = true;
	queue.push_back(s);
	cout << "\nPassthrough: ";
	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		//vector front pop =)  
		if (queue.size() > 0)
		{
			queue.erase(queue.begin());
		}
		//Roll through adjacent ave
		for (auto x : nodes)
		{
			if (!visited[x.nodeID])
			{
				visited[x.nodeID] = true;
				queue.push_back(x.nodeID);
			}
		}
	}
}
void Graph::BreadthFirstSearch2(int s)
{
	cout << "\nBFS for Node " << to_string(s);
	//utilize a queue structure to ensure single pass

	vector<int> queue;
	nodes[s].visited = true;
	queue.push_back(s);

	cout << "\nPassthrough: ";
	while (!queue.empty())
	{
		s = queue.front();
		cout << s << " ";
		//vector front pop =)  
		if (queue.size() > 0)
		{
			queue.erase(queue.begin());
		}
		//Roll through adjacent ave

				for (int f = 0; f < nodes[s].linkSet.size(); f++)
				{
					if (!nodes[s].linkSet[f].visited)
					{
						if (nodes[s].linkSet[f].dest1 == nodes[s].nodeID)
						{
							//nodes[n].visited = true;
							nodes[s].linkSet[f].visited = true;
							if (!nodes[nodes[s].linkSet[f].dest2].visited)
							{
								queue.push_back(nodes[s].linkSet[f].dest2);
								nodes[nodes[s].linkSet[f].dest2].visited = true;
							}
						}
						if (nodes[s].linkSet[f].dest2 == nodes[s].nodeID)
						{
							//nodes[n].visited = true;
							nodes[s].linkSet[f].visited = true;
							if (!nodes[nodes[s].linkSet[f].dest1].visited)
							{
								queue.push_back(nodes[s].linkSet[f].dest1);
								nodes[nodes[s].linkSet[f].dest1].visited = true;
							}
						}
					}
				}
	}
}

void Graph::NodeDepthFirstSearch(int s, int iterator)
{
	if (iterator == 0)
	{
		cout << "\nLink Set for Node " << nodes[s].nodeID << endl;
		cout << nodes[s].nodeID;
	}
	nodes[s].linkSet[iterator].visited = true;
	if (nodes[s].linkSet[iterator].dest1 == nodes[s].nodeID)
	{
		cout << "->" << nodes[s].linkSet[iterator].dest2;
	}
	if (nodes[s].linkSet[iterator].dest2 == nodes[s].nodeID)
	{
		cout << "->" << nodes[s].linkSet[iterator].dest1;
	}
	iterator += 1;
	for (int i = 0; i < nodes[s].linkSet.size(); i++)
	{
		if (!nodes[s].linkSet[i].visited)
		{
			NodeDepthFirstSearch(s, iterator);
		}
	}
}

//builder functions
void Graph::BuildLinkSets()
{
	cout << "\nBuilding link sets...";
	for (int i = 0; i < nodes.size(); i++)
	{
		cout << "\nNode " << to_string(nodes[i].nodeID) << "\t||\t#-of-Links: " << nodes[i].linkSet.size();
		if (!nodes[i].linkSet.empty())
		{
			cout << "\nRebuilding Link Sets...";
		}
		for (auto x : links)
		{
			int d1 = x.dest1;
			int d2 = x.dest2;
			if (d1 == nodes[i].nodeID || d2 == nodes[i].nodeID)
			{
				nodes[i].linkSet.push_back(x);
				cout << "\nLink Added: " << to_string(x.dest1) << " & " << to_string(x.dest2) << " to Node " << nodes[i].nodeID;
			}
		}
		cout << endl;
	}
}
#pragma endregion
