#include <iostream>
#include "Node.h"
#include "Tree.h"
#include <string>
using namespace std;

Node::Node() {}

// constructor
Node::Node(string inString)
{
	this->data = inString;
}

// overloaded operators
bool Node::operator==(const Node& s1)
{
	if (this->data == s1.data)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Node::operator>(const Node& s1)
{
	if (this->data > s1.data)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Node::operator<(const Node& s1)
{
	if (this->data < s1.data)
	{
		return true;
	}
	else
	{
		return false;
	}
}
