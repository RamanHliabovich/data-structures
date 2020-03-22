// Developer: Sean Sliter
#pragma once
#include <iostream>
using namespace std;

class Stack
{
private:
	char data[25] = "";
	int topVal = 0;
	int outVal;
	bool emptyIndicator;
	bool flag = true;
public:
	//checks if the stack is empty
	bool empty();

	//adds value to the top of the stack
	void push(char inVal);

	//returns value from the stack
	char pop();

	//returns item on the top of the stack without removing it
	char top();

	//returns an int indicating the number of items in the stack
	int length();

	void PrintStack(char message);
};
