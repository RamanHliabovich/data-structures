#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
#include "Alist.h"
#include "Graph.h"
#include <cstdlib>
using namespace std;

class Graph
{
public:
	struct Node** v;
	int n;

	Graph(int V);
	~Graph();

	void addEdge(int src, int dest);
	void inEdges(int i);
	void removeEdge(int i, int j);
	bool hasEdge(int i, int j);
	void outEdges(int i);
	void printGraph();
};