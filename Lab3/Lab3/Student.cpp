#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include "Student.h"

using namespace std;

Student::Student() {};

void Student::NodeStudent(string* mNumber, string* firstName, string* lastName, string* birthday, string* gpa)
{
	this->mNumber = *mNumber;
	this->firstName = *firstName;
	this->lastName = *lastName;
	this->birthday = *birthday;
	this->gpa = *gpa;
};

void Student::AddItem(string* mNumber, string* firstName, string* lastName, string* birthday, string* gpa)
{
	temp = head;
	// maybe not Student*
	head = new Student();
	head->NodeStudent(mNumber, firstName, lastName, birthday, gpa);
	head->next = temp;

	length++;
};

vector<string>* Student::GetItem(string* inVal)
{
	if (length == 0)
	{
		throw "List is empty. Please add a value.";
	}
	else
	{
		check = false;

		temp = head;

		// checks if head is item were looking for
		if (temp->mNumber == *inVal)
		{
			rem = temp;
			if (length == 1)
				head = nullptr;
			else
				head = head->next;

			check = true;
		}
		else
		{
			// iterates through every node to check for item
			while (temp->next != nullptr && check != true)
			{
				if (temp->next->mNumber != *inVal)
					temp = temp->next;
				else
				{
					// store item to be returned before deleting
					rem = temp->next;

					// have to set as nullptr instead of temp->next->next
					// even when it is nullptr because it will throw an error.
					if (temp->next->next != nullptr)
						temp->next = temp->next->next;
					else
						temp->next = nullptr;

					check = true;
				}
			}
		}
		// outputs value in vector if found else returns null pointer
		if (check)
		{
			vector<string> RetVal;
			vector<string>* RetVal_p = new vector<string>(4);

			RetVal.push_back(rem->firstName);
			RetVal.push_back(rem->lastName);
			RetVal.push_back(rem->birthday);
			RetVal.push_back(rem->gpa);

			RetVal_p->at(0) = RetVal[0];
			RetVal_p->at(1) = RetVal[1];
			RetVal_p->at(2) = RetVal[2];
			RetVal_p->at(3) = RetVal[3];

			length--;

			//vector<string> *RetVal_p = &RetVal;

			return RetVal_p;
		}
		else
			throw " Null pointer (Item not in list)";
	}
};

bool* Student::IsInList(string* inVal)
{
	if (length == 0)
	{
		throw "List is empty. Please add a value.";
	}
	else if (length == 1)
	{
		if (head->mNumber == *inVal)
			check = true;
		else
			check = false;
	}
	else
	{
		temp = head;

		check = false;

		while (temp != NULL)
		{
			if (temp->mNumber == *inVal)
			{
				check = true;
				break;
			}
			temp = temp->next;
		}
	}
	bool* ret = &check;
	return ret;
};

int* Student::Size()
{
	int* ret = &length;

	return ret;
};

bool* Student::IsEmpty()
{
	bool result;

	if (length == 0)
		result = true;
	else
		result = false;

	bool* ret = &result;

	return ret;
}

vector<string>* Student::SeeNext()
{
	check = false;

	if (length == 0)
		throw "List is empty. Please add a value.";
	else if (!initiated)
	{
		see = head;
		initiated = true;
		check = true;
		seeCount = 1;
	}
	else
	{
		// this needs to be see->next = nullptr but its not working

		if (seeCount >= length)
			throw "Null pointer (end of list)";
		else
		{
			// iterate through the list to our current point in case next item was deleted.
			see = head;
			for (int i = 1; i <= seeCount; i++)
				see = see->next;
			check = true;
			seeCount++;
		}
	}

	if (check)
	{
		vector<string> RetVal;
		vector<string>* RetVal_p = new vector<string>(4);

		RetVal.push_back(see->firstName);
		RetVal.push_back(see->lastName);
		RetVal.push_back(see->birthday);
		RetVal.push_back(see->gpa);

		RetVal_p->at(0) = RetVal[0];
		RetVal_p->at(1) = RetVal[1];
		RetVal_p->at(2) = RetVal[2];
		RetVal_p->at(3) = RetVal[3];

		cout << "\n Student at location: " << seeCount << "\n";

		return RetVal_p;
	}
};

vector<string>* Student::SeeAt(int* location)
{
	if (length == 0)
		throw "List is empty. Please add a value.";
	else if (*location > length || *location < 1)
		throw "Value is not within scope of list";
	else
	{
		initiated = true;
		see = head;
		for (int i = 1; i < *location; i++)
			see = see->next;

		seeCount = *location;
	}
	vector<string> RetVal;
	vector<string>* RetVal_p = new vector<string>(4);

	RetVal.push_back(see->firstName);
	RetVal.push_back(see->lastName);
	RetVal.push_back(see->birthday);
	RetVal.push_back(see->gpa);

	RetVal_p->at(0) = RetVal[0];
	RetVal_p->at(1) = RetVal[1];
	RetVal_p->at(2) = RetVal[2];
	RetVal_p->at(3) = RetVal[3];

	cout << "\n Student at location: " << seeCount << "\n";

	return RetVal_p;
};

void Student::Reset()
{
	initiated = false;
	seeCount = 0;
};

void Student::Display()
{
	temp = head;
	if (length == 0)
		throw "List is empty";
	else
	{
		for (int i = length; i >= 1; i--)
		{
			cout << "\n\n Student #" << i << "\n ****************" << "\n* mNumber: " << temp->mNumber << "\n* First Name: " << temp->firstName <<
				"\n* Last Name: " << temp->lastName << "\n* Birthday: " << temp->birthday << "\n* GPA: " << temp->gpa << "\n ****************";
			temp = temp->next;
		}
		cout << "\n";
	}

	/*
	for (int i = 1; i <= length; i++)
	{
		vector<int> lengths;
		lengths.push_back(temp->mNumber.length());
		lengths.push_back(temp->firstName.length());
		lengths.push_back(temp->lastName.length());

		int myLength;
		int myIndex;
		int tempLength;
		int j;
		for (j = 1; j <= 2; j++)
		{
			if (lengths[j] > lengths[j-1])
			{
				myLength = lengths[j];
				myIndex = j;
			}
		}

		cout << "\n\n Student #" << j << "\n";
		for (i = 0; i < (myLength + 11); i++)
		{
			cout << "*";
		}

		tempLength = (11 + myLength) - lengths[0];*/
}