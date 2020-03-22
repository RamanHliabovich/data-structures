#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
#include <string>
using namespace std;


class Tree
{
public:
	class Node* root;
	void PrintIn2Dtool(Node* root, int space);
	void PrintIn2D(Node* root);
	Tree();
	~Tree();
	// class variables
	bool emptyList;
	vector<int> treeResultVector;

	Node* Find(int key);
	int FindR(int key, Node* t);
	void Add(int key);
	Node* Delete(Node* root, int key);
	Node* GetLargestSmaller(Node* temp);
	int Size(Node* root);
	void EmptyTree(Node* root);
	Node* buildTree(Node* root);
	void storeBSTNodes(Node* root, vector<Node*>& nodes);
	Node* buildTreeUtil(vector<Node*>& nodes, int start, int end);

};