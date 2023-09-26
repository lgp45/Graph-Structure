// Porter_AdvAlg_Final.cpp

#include "ProjectLibrary.h"
#include <iostream>
#include <vector>

using namespace std;

//Part of Initial testing
#pragma region Initial Test setup --- Deprecated
void AddEdge(vector<int> adj[], int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void PrintGraph(vector<int> adj[], int V)
{
	for (int v = 0; v < V; ++v)
	{
		cout << "\nAdjacency List of Vertex " << v << "\nhead ";
		for (auto x : adj[v])
		{
			cout << "-> " << x;
		}
		printf("\n");
	}
}
#pragma endregion


int main()
{
#pragma region Previous Test Phases --- Deprecated

	//test phase one - initial understanding of the graph structure
	//simple adjaceny list graph -> uses a vector to impose data to nodes with the edge connections being declared

#pragma region ----| Initial Testing
	/*
	const int V = 6;
	vector<int> adj[V];
			//1  2  3		//1 = the container vector to manipulate, 2= the Node to impose to, 3 the data being imposed to the node
	AddEdge(adj, 0, 1);
	AddEdge(adj, 1, 2);
	AddEdge(adj, 2, 2);
	AddEdge(adj, 4, 4);
	AddEdge(adj, 5, 0);
	PrintGraph(adj, V);
	*/
#pragma endregion

	//test phase two - initial implementation of standard structure
#pragma region Test Structure 2
	/*
	vector<int> nodes;	//Vertex
	vector<pair<int, int>> edges; //Edge(Link)
	Graph_Earlier graph = Graph_Earlier(nodes, edges);	//initial dec of the graph
	//begin filling
	graph.AddNode(0);
	graph.AddLink(0, 1);
	*/
#pragma endregion

	//this could work but I needed to rework some of the objects and I felt it was more approachable re-splitting
		//would probably come back and convert to links having a vector of themselves
			//or nodes have their own link vector or graph being vector<pair<Node, vector<link>>>.
					//this would allow for endless link expansion while having links directly paired to their node
#pragma region Test Structure 3
	//Testing Phase 3 - initial attempt at using custom objects 
//test node
	//Node n = new Node();
	//1. whatever int data we want to pass to the newly created node
	//2. the preset edge we want to link the node to, a 0 will link to the Front node.
			//this is intended to allow for free flow for direct jump from node to node
				//rather than singular access of one node at a time
				   //1  2
	//graph.InsertNode(1, 0);
	//graph.InsertNode(2, 0);
	//graph.InsertNode(3, 1);
	//graph.InsertNode(13, 2);	//exceeding the node range does not trigger error yet
	//graph.InsertNode(23, 3);	//exceeding the node range does not trigger error yet
	//graph.InsertNode(113, 4);	//exceeding the node range does not trigger error yet
	//graph.InsertNode(31, 1);	//exceeding the node range does not trigger error yet
#pragma endregion

#pragma endregion

	//CURRENT
	//Testing Phase 4 - Refining the custom object setup into two managed structures that work together
#pragma region Test Structure 4
	
	Graph graph;	//standard object for accessing each of the different setups of phase 4
	
	int choice = 0;
	int exit = 0;
	int useClear;
	bool clear = true;
	cout << "\nUse screen clears? (0=yes, 1=no)  -(ON BY DEFAULT)-";
	cin >> useClear;
	if (useClear == 0)
	{
		clear = true;
	}
	if (useClear == 1)
	{
		clear = false;
	}
	while (exit == 0)
	{
		cout << "\nControl Menu";
		cout << "\n1. Auto Test Run";
		cout << "\n2. Add ";
		cout << "\n3. Search Functions";
		cout << "\n4. Outputs";
		cout << "\nChoice: ";
		cin >> choice;

		//MAIN AUTO TEST
		if (choice == 1)
		{
#pragma region  Adjacency
			//add nodes/vertexs either blank or preset
		//nodes are given a simple sequential int

			graph.InsertNewNode();	//1
			graph.InsertNewNode();  //2
			graph.InsertNewNode();  //3
			graph.InsertNewNode();  //4
			graph.InsertNewNode();  //5

			//link nodes as desired.
			graph.AddLink(0, 1);	//a link between 0 and 1 is added to the links vector
			graph.AddLink(1, 2);
			graph.AddLink(2, 3);
			graph.AddLink(4, 1);
			graph.AddLink(0, 5);	//adds a link between node 0 and node 4 -> nodes do not have require directions
										//this allows offshoots of the main branch

			graph.OutputAdjacentGraph(); //listing of adjacent node link connections
#pragma endregion

#pragma region Operator and Algorithm Use

	//adding new nodes with data and directed node links
			graph.InsertNewNode(12, 0);
			graph.InsertNewNode(12, 1);
			graph.InsertNewNode(12, 2);
			graph.InsertNewNode(12, 3);
			graph.InsertNewNode(12, 4);
			graph.InsertNewNode(12, 5);

			//adding external links - nodes themselves dont know these
			graph.AddLink(0, 2);
			graph.AddLink(0, 3);
			graph.AddLink(0, 4);
			graph.AddLink(5, 5);

			//emplacing node links into interal node link set
			graph.BuildLinkSets(); //this allows internalized link list communication if desired or simply can run off external link set


			graph.OutputDirectedGraph();	//outputs the internal directed link operator in nodes
			graph.OutputAdjacentGraph(); //output the adjacents since new links have been added

			//jump directly to desired node then to FIRST node and sequentially process all UNVISITED adjacent nodes
			cout << "\nBreadth First Search (BFS)...";
			graph.ClearNodeStates();
			graph.BreadthFirstSearch2(1);
			graph.ClearNodeStates();
			graph.BreadthFirstSearch2(4);
			graph.ClearNodeStates();
			graph.BreadthFirstSearch2(7);

			cout << "\n\nDepth First Search";
			graph.ClearNodeStates();
			graph.NodeDepthFirstSearch(5, 0);
			graph.NodeDepthFirstSearch(1, 0);
			graph.NodeDepthFirstSearch(3, 0);

			cout << endl;
#pragma endregion


		}
		//Extended Menu Usage for on the fly testing.
		if (choice == 2)
		{
			if (clear == true)
			{
				system("cls");
			}
			int mod1 = 0;
			cout << "\nAdd / Modify Menu";
			cout << "\n1. Add Link";
			cout << "\n2. Add Blank Node";
			cout << "\n3. Add Node w/ Link";
			cout << "\n4. Compile Links into Nodes";
			cout << "\n5. Back";
			cout << "\nChoice: ";
			cin >> mod1;
			if (mod1 == 1)
			{
				int c1, c2;
				cout << "Node 1 ID: ";
				cin >> c1;
				cout << "Node 2 ID: ";
				cin >> c2;
				graph.AddLink(c1, c2);
			}
			if (mod1 == 2)
			{
				graph.InsertNewNode();
			}
			if (mod1 == 3)
			{
				int nID;
				cout << "\nNode w/ Directed Link";
				cout << "\nNode ID to link directly: ";
				cin >> nID;
				if (nID <= graph.nodes.size())
				{
					graph.InsertNewNode(0, nID);
				}
				else
				{
					cout << "\nNode ID not found within set.";
				}
			}
			if (mod1 == 4)
			{
				graph.BuildLinkSets();
			}
		}
		if (choice == 3)
		{
			if (clear == true)
			{
				system("cls");
			}

			int alg = 0;
			cout << "\nSearch Functionality...";
			cout << "\n1. Breadth First Search (BFS)";
			cout << "\n2. Node Depth First Search - (DFS)";
			cout << "\n3. Back";
			cout << "\nChoice: ";
			cin >> alg;

			if (alg == 1)
			{
				int startNode;
				cout << "\nStarting Node: ";
				cin >> startNode;
				graph.ClearNodeStates();
				graph.BreadthFirstSearch2(startNode);
			}
			if (alg ==2)
			{
				int startNode;
				cout << "Node to Run: ";
				cin >> startNode;
				graph.ClearNodeStates();
				graph.NodeDepthFirstSearch(startNode, 0); //iterator must be zero on first call - recursive
			}
		}
		if (choice == 4)
		{
			if (clear == true)
			{
				system("cls");
			}
			int output;
			cout << "\nOutputs";
			cout << "\n1. Single Node Output";
			cout << "\n2. Directed Graph Output";
			cout << "\n3. Adjacent Node Output";
			cout << "\n4. Back";
			cout << "\nChoice: ";
			cin >> output;
			if (output == 1)
			{
				int n1;
				cout << "\nNode #: ";
				cin >> n1;
				graph.OutputNodeInfo(n1);
			}
			if (output == 2)
			{
				graph.OutputDirectedGraph();
			}
			if (output == 3)
			{
				graph.OutputAdjacentGraph();
			}
		}
	}
	
/*
#pragma region  Adjacency
	//add nodes/vertexs either blank or preset
//nodes are given a simple sequential int

	graph.InsertNewNode();	//1
	graph.InsertNewNode();  //2
	graph.InsertNewNode();  //3
	graph.InsertNewNode();  //4
	graph.InsertNewNode();  //5

	//link nodes as desired.
	graph.AddLink(0, 1);	//a link between 0 and 1 is added to the links vector
	graph.AddLink(1, 2);
	graph.AddLink(2, 3);
	graph.AddLink(4, 1);
	graph.AddLink(0, 5);	//adds a link between node 0 and node 4 -> nodes do not have require directions
								//this allows offshoots of the main branch

	graph.OutputAdjacentGraph(); //listing of adjacent node link connections
#pragma endregion

#pragma region Operator and Algorithm Use

	//adding new nodes with data and directed node links
	graph.InsertNewNode(12, 0);
	graph.InsertNewNode(12, 1);
	graph.InsertNewNode(12, 2);
	graph.InsertNewNode(12, 3);
	graph.InsertNewNode(12, 4);
	graph.InsertNewNode(12, 5);

	//adding external links - nodes themselves dont know these
	graph.AddLink(0, 2);
	graph.AddLink(0, 3);
	graph.AddLink(0, 4);
	graph.AddLink(5, 5);

	//emplacing node links into interal node link set
	graph.BuildLinkSets(); //this allows internalized link list communication if desired or simply can run off external link set


	graph.OutputDirectedGraph();	//outputs the internal directed link operator in nodes
	graph.OutputAdjacentGraph(); //output the adjacents since new links have been added

	//jump directly to desired node then to FIRST node and sequentially process all UNVISITED adjacent nodes
	cout << "\nBreadth First Search (BFS)...";
	graph.BreadthFirstSearch(1);
	graph.BreadthFirstSearch(4);
	graph.BreadthFirstSearch(7);

	cout << "\n\nDepth First Search (DFS)\n";
	graph.DepthFirstSearch(5);
	cout << endl;
	graph.DepthFirstSearch(2);

	cout << "\n\nNode Based DFS";
	graph.NodeDepthFirstSearch(5, 0);
	cout << endl;

	*/

	graph.~Graph();
#pragma endregion

}


//Core structure
	//Graph -> custom object container with vector sets of Nodes and Links
		//Node vector contains vertex points, data and a internal link for directed link attachments
		//Link vector contains slots for two vertex points, enabling free linkage between any node