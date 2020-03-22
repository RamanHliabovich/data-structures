#pragma once
#include <iostream>
#include "Tree.h"
#include <string>
using namespace std;


class Node
{
public:
	string data;
	Node* right = nullptr;
	Node* left = nullptr;

	Node();
	Node(string inString);
	
	bool operator ==(const Node& s1);
	bool operator >(const Node& s1);
	bool operator <(const Node& s1);
};