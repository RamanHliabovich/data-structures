//  Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include <string>

using namespace std;
/* Variables for tests
int result;

int inVal;

int outVal;

int check;
*/

int main()
{
	string message;

	Stack myStack;
	Queue myQueue;
	bool flag;
	char buffer;

	do
	{
	start:
		cout << "Enter a message you want to transmit:" << endl;
		cin.ignore(cin.rdbuf()->in_avail());
		getline(cin, message);

		if (message.length() > 25)
		{
			cout << "Please enter less than 25 characters \n";
			goto start;
		}

		// Inputs message into queue big endian
		for (int i = message.length() - 1; i >= 0; i--)
		{
			myQueue.Enqueue(message.at(i));
		}
		
		//Coverts big endian to little endian
		cout << "My queue contains: ";
		while (!myQueue.IsEmpty())
		{
			buffer = myQueue.Dequeue();
			myQueue.PrintQueue(buffer);
			myStack.push(buffer);
		}
		cout << '\n';

		//Prints out stack contents in stack container
		int i = 0;
		cout << "My stack contains: ";
		while (!myStack.empty())
		{
			message.at(i) = myStack.top();
			myStack.PrintStack(message.at(i));
			myStack.pop();
			i++;
		}

		//prints out transformed message
		cout << endl;
		cout << "Transformed message: " << message << endl;

		//asks user for another message
		char yes_no;
		cout << endl << endl;
		cout << "Do you want to send another message (y/n)?: ";
		cin >> yes_no;


		if (yes_no == 'y')
		{
			flag = true;
		}
		else
		{
			flag = false;
		}

	} while (flag == true);

	/* QUEUE TEST

		menu:

	cout << "\n 1. Enqueue \n 2. Dequeue \n 3. Length \n 4. IsFull \n 5. IsEmpty \n Enter: ";

	cin >> result;

	switch (result)
	{
	case 1:
		cout << "Enter input value: ";
		cin >> inVal;
		queue.Enqueue(inVal);
		cout << "Value queued";

		goto menu;

	case 2:
		check = queue.Length();
		if (check == 0)
		{
			cout << "Nothing to dequeue";
		}
		else
		{
			outVal = queue.Dequeue();
			cout << outVal << " was dequeued";
		}

		goto menu;
	case 3:
		outVal = queue.Length();
		cout << "The lenght of the queue is " << outVal;
		goto menu;
	case 4:
		queue.IsFull();
		goto menu;

	case 5:
		queue.IsEmpty();
		goto menu;
	}
	*/

	/* STACK TEST

	menu:

cout << "\n 1. Push \n 2. Pop \n 3. Empty \n 4. Top \n 5. Length \n Enter: ";

cin >> result;

switch (result)
{
case 1:
	cout << "\n Enter value to push: ";
	cin >> inVal;
	stack.push(inVal);

	cout << "\n Value " << inVal << " pushed";
	goto menu;
case 2:
	outVal = stack.pop();
	if (outVal == 7337448)
	{
		cout << "\n Stack Overflow";
	}
	else
	{
		cout << outVal << " was popped";

	}
	goto menu;
case 3:
	stack.empty();

	goto menu;
case 4:
	outVal = stack.top();

	goto menu;
case 5:
	outVal = stack.length();

	cout << "The length is " << outVal;

	goto menu;
}
	*/
}
