#pragma once
#include <iostream>
using namespace std;

class Queue
{
private:
	int check = 0;
	int front = 0;
	int end = 0;
	char array[25];
	char retVal;

public:
	void Enqueue(char inVal);

	char Dequeue();

	void IsFull();

	int Length();

	bool IsEmpty();

	void PrintQueue(char print);
};