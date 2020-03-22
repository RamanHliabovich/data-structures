#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Student.h"

char charInVal;
int intInVal;

using namespace std;

// adds an item to the end of the list for queue
void Student::AddItem(string mNumber, string firstName, string lastName, string birthday, string gpa)
{
	if (length >= maxSize)
		cout << "\n List is full. Cannot add another item.";
	else
	{
		temp = new Student();
		temp->Items::NodeStudent(mNumber, firstName, lastName, birthday, gpa);
		temp->next = nullptr;

		if (head == nullptr)
		{
			head = temp;
			tail = temp;
		}
		else
		{
			tail->next = temp;
			tail = tail->next;
		}
		length++;

		cout << "\n Student added. \n";
	}
};

// add item to the front of the list for the stack
void Student::AddItem2(string mNumber, string firstName, string lastName, string birthday, string gpa)
{
	if (length >= maxSize)
		cout << "\n List is full. Cannot add another item.";
	else
	{
		temp = head;
		head = new Student();
		head->Items::NodeStudent(mNumber, firstName, lastName, birthday, gpa);
		head->next = temp;

		length++;

		cout << "\n Student Added. \n";
	}
}

// removes the first item in the list and returns it to user
vector<string> Student::GetItem()
{
	if (Student::length == 0)
	{
		throw "List is empty. Please add a value.";
	}
	else
	{
		temp = head;
		head = head->next;

		// create string vector to output student node data
		vector<string> RetVal;

		RetVal.push_back(temp->mNumber);
		RetVal.push_back(temp->firstName);
		RetVal.push_back(temp->lastName);
		RetVal.push_back(temp->birthday);
		RetVal.push_back(temp->gpa);

		// set as null so there are no memory leaks
		temp = nullptr;

		length--;

		return RetVal;
	}
};

int Student::Size()
{
	return Student::length;
};

bool Student::IsEmpty()
{
	if (length == 0)
		return true;
	else
		return false;
}

bool Student::IsFull()
{
	if (length >= maxSize)
		return true;
	else
		return false;
}

// iterates through list and deletes all memory leaks
void Student::ClearList()
{
	if (length == 0)
		cout << "\n List is empty. Please add an item.";
	else
	{
		// delete head first
		temp = head;
		head = nullptr;

		// delete each node in list
		for (int i = 1; i < length; i++)
		{
			rem = temp->next;
			temp->next = nullptr;
			temp = rem;
		}
		// clear memory leak
		temp = nullptr;
		rem = nullptr;
		length = 0;

		cout << "\n List has been cleared.";
	}
}