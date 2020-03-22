#pragma once

#include <iostream>
#include <string>

using namespace std;

class PriorityQueue
{
public:
	typedef struct Node
	{
		int data;

		struct Node* next;

	};
	Node* head;

	Node* NewNode(int data);

	void Insert(int data);
	int Remove();
	void PrintQueue();
};