#pragma once
#include <iostream>
#include "Tree.h"
#include <vector>
#include <string>
using namespace std;


class Node
{
public:
	int data;
	Node* right = nullptr;
	Node* left = nullptr;

	Node();
	Node(int inData);

	/*bool operator ==(const Node& s1);
	bool operator >(const Node& s1);
	bool operator <(const Node& s1);*/
};