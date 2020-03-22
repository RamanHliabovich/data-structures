#include <iostream>
#include <string>
#include "Student.h"
#include "Queue.h"
#include "Stack.h"

using namespace std;

// menu variables
bool exitProgram = false;
bool restart = false;
int intMenu = 1;

// result from functions variables
int intResult;
int sizeResult;
bool boolResult;
bool isStack;
string stringResult;

// variables for passing into student node
string mNumber;
string firstName;
string lastName;
string birthday;
string gpa;

Stack myStack;

int main()
{
	// asks for which constructor to use (set max size or default max size of 20)
	//cout << "- Select Option to Start Program - \n 1. Set max size \n 2. Set as default (20) \n Enter: ";
	//cin >> stringResult;
	//if (stringResult == "1")
	//{
	//	cout << "Enter max size: ";
	//	cin >> intResult;
	//	Student myStudent(intResult); // set max size constructor
	//}

	// asks user if they want stack or queue
	cout << "\n- Select Type of List - \n 1. Stack \n 2. Queue \n Enter: ";
	cin >> stringResult;
	if (stringResult == "1")
	{
		isStack = true;
	}
	else
	{
		isStack = false;
	}

	do {
		// menu for selecting functions
		if (intMenu > 0 && intMenu < 10)
			cout << "\n\n ~~~MENU~~~ \n 1. AddItem \n 2. GetItem \n 3. IsEmpty \n 4. IsFull \n 5. Size \n 6. ClearList \n 7. Exit \n\n Enter: ";
		else
			cout << "Invlid Input. Try again: ";

		// only allows integer inputs between 1 and 9
		while (!(cin >> intMenu))
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}

		switch (intMenu)
		{
		case 1:
			cout << " - Create student parameters - \n Enter M number (integers only): ";
			cin >> mNumber;
			cout << " Enter First Name: ";
			cin >> firstName;
			cout << " Enter Last Name: ";
			cin >> lastName;
			cout << " Enter Birthday: ";
			cin >> birthday;
			cout << " Enter GPA: ";
			cin >> gpa;
			if (isStack)
			{
				myStack.push(mNumber, firstName, lastName, birthday, gpa);
			}
			else
			{
				myStack.push(mNumber, firstName, lastName, birthday, gpa);
			}

			break;
		case 2:
			boolResult = myStack.IsEmpty();
				if (boolResult)
					cout << "\n The list is empty";
				else
					cout << "\n The list is not empty";
			break;
		}

	} while (!exitProgram);
}
