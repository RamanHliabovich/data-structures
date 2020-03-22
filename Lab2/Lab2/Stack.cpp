//Developer: Sean Sliter & Raman Hliabovich
#include <iostream>
#include "Stack.h"
using namespace std;


//checks if the stack is empty
bool Stack::empty()
{

	if (topVal == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//adds value to the top of the stack
void Stack::push(char inVal)
{
	if (topVal >= 25)
	{
		throw "stack is full";
	}
	else
	{
		data[topVal] = inVal;
		topVal++;
	}
}

//returns value from the stack
char Stack::pop()
{
	if (topVal <= 0)
	{
		throw "Stack Overflow";
	}
	else
	{
		outVal = data[topVal - 1];
		topVal--;

		return outVal;
	}
}

//returns item on the top of the stack without removing it
char Stack::top()
{
	if (topVal != 0)
	{
		return data[topVal - 1];
	}
	else
	{
		cout << "The stack is empty ";
		return NULL;
	}
}

//returns an int indicating the number of items in the stack
int Stack::length()
{
	return topVal;
}

void Stack::PrintStack(char message)
{
	cout << " " << message;
}