#include <iostream>
#include <string>
#include <vector>

using namespace std;

// container for node data
struct Items
{
public:
	// needs to be in public so its accessable by queue
	string mNumber;
	string firstName;
	string lastName;
	string birthday;
	string gpa;

	// node pointers
	Items* head = nullptr;

	Items* temp = nullptr;

	Items* rem = nullptr;

	Items* tail = nullptr;

	Items* next = nullptr;

	// sets data passed in to the temp node (see student.cpp - AddItem function)
	void NodeStudent(string mNumber, string firstName, string lastName, string birthday, string gpa)
	{
		this->mNumber = mNumber;
		this->firstName = firstName;
		this->lastName = lastName;
		this->birthday = birthday;
		this->gpa = gpa;
	};
};