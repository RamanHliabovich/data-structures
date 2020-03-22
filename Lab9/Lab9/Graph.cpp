#include <iostream>
#include <cstdlib>
#include <vector>
#include "Node.h"
#include "Graph.h"
#include "Alist.h"
using namespace std;


Graph::Graph(int n)
{
	this->n = n;
	v = new Node* [n];

	for (int i = 0; i <= n; i++)
	{
		v[i] = nullptr;
	}
}


Graph::~Graph()
{
	Node* ptr = new Node;
	// this loop will first delete the every element of the list
	for (int i = 0; i <= n; i++)
	{
		ptr = v[i];
		while (ptr->next != NULL)
		{
			Node* lptr = ptr;
			ptr = ptr->next;
			delete lptr;
		}
	}
	// now delete the list itself
	delete v;
}


void Graph::addEdge(int i, int j)
{
	Node* tempNode = new Node;
	tempNode->val = j;
	tempNode->next = nullptr;
	Node* ptr = v[i];
	//when first node is added
	if (ptr == nullptr)
	{
		v[i] = tempNode;
	}
	else
	{
		while (ptr->next != nullptr)
		{
			ptr = ptr->next;
		}
		ptr->next = tempNode;
	}
	cout << "\n Edge added \n";
}

void Graph::removeEdge(int i, int j)
{
	struct Node* ptr = v[i];
	struct Node* prev = ptr;
	if (ptr == NULL)
	{
		cout << "\n This edge does not exist.";
		return;
	}
	else if (ptr->val == j)
	{
		// check if multiple values. If not then delete whole node so it works when printing
		if (ptr->next == NULL)
		{
			v[i] = NULL;
		}
	}
	while (ptr->val != j)
	{
		prev = ptr;
		ptr = ptr->next;
	}
	prev->next = ptr->next;
	delete ptr;
	cout << "\n Edge Removed. \n";
}

bool Graph::hasEdge(int i, int j)
{
	struct Node* ptr = v[i];
	bool flag = false;
	if (ptr != NULL)
	{
		if (ptr->val == j) // check if first item in list is  j
			return true;
		while (ptr != NULL && ptr->val != j)
		{
			if (ptr->next == NULL) // check if only one item in list (the item we just checked if it is j)
				return false;
			else if (ptr->next->val == j)
				return true;
			else
			ptr = ptr->next; // iterate
		}
	}
	return false;
}

void Graph::inEdges(int i)
{
	Node* head = NULL;
	Node* ptr = NULL;
	vector<int> values;
	values.clear();
	for (int j = 0; j < n; j++) // check for edge pointing at our "i" in its list and add to vector if it is
	{
		if (hasEdge(j, i))
		{
			values.push_back(j);
		}
	}
	cout << "\n Node " << i << " in edge nodes: ";
	if (values.empty())
	{
		cout << "\n No in edges for Node " << i << "\n";
	}
		for (int k = 0; k < values.size(); k++)
			cout << "\n  " << values[k];
	values.clear();
}

// this will return the list as it contain the outedges
void Graph::outEdges(int i)
{
	if (v[i] != NULL)
	{
		struct Node* ptr = v[i];
		cout << "\n Node " << i << " out edge nodes: ";
		while (ptr != NULL)
		{
			cout << "\n  " << ptr->val;
			if (ptr->next != NULL)
				ptr = ptr->next;
			else
				break;
		}
	}
	else
		cout << "\n No out edges for node " << i << "\n";
}



void Graph::printGraph()
{
	for (int i = 0; i < n; ++i)
	{
		cout << "\n Adjacency list of vertex "
			<< i << "\n head ";
		Node* ptr = v[i];
		if (v[i] == NULL)
		{
			continue;
		}
		while (ptr != NULL)
		{
			cout << "-> " << ptr->val;
			ptr = ptr->next;
		}
		printf("\n");
	}
}