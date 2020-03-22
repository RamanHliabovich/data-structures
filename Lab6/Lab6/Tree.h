#pragma once
#include <iostream>
#include <vector>
#include "Node.h"
#include <string>
using namespace std;


class Tree
{
public:
	class Node* root = nullptr;
	Tree();
	~Tree();

	// class variables
	bool emptyList = false;
	vector<string> treeResultVector;

	Node* Find(string key);
	string FindR(string key, Node* t);
	void Add(string key);
	Node* Delete(Node* root, string key);
	Node* GetLargestSmaller(Node* temp);
	int Size(Node* root);
	vector<string> GetAllAscendingStart(Node* root);
	vector<string> GetAllDescendingStart(Node* root);
	void GetAllAscending(Node* root);
	void GetAllDescending(Node* root);
	void EmptyTree(Node* root);
};