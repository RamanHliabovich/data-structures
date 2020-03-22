#include <iostream>
#include "Node.h"
#include <vector>
using namespace std;

Node::Node()
{
	this->data = NULL;
}

// constructor
Node::Node(int inData)
{
	this->data = inData;
}

// overloaded operators
//bool Node::operator==(const Node& s1)
//{
//	if (this->data == s1.data)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Node::operator>(const Node& s1)
//{
//	if (this->data > s1.data)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}
//
//bool Node::operator<(const Node& s1)
//{
//	if (this->data < s1.data)
//	{
//		return true;
//	}
//	else
//	{
//		return false;
//	}
//}