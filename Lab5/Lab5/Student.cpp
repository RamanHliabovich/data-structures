// ignore deprecate error for string compare function
# if defined(_MSC_VER)
# ifndef _CRT_SECURE_NO_DEPRECATE
# define _CRT_SECURE_NO_DEPRECATE (1)
# endif
# pragma warning(disable : 4996)
# endif

#include <iostream>
#include <string>
#include <stdexcept>
#include <string.h>
#include "Student.h"
using namespace std;

Student::Student() {}

Student::Student(string firstName, string lastName, long mNum)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->mNum = mNum;
}

void Student::printAscending()
{
	cout << "\n Traversal in forward direction \n";

	while (head != nullptr)
	{
		cout << "**********************\n";
		cout << "* First Name: " << head->firstName << endl;
		cout << "*  Last Name: " << head->lastName << endl;
		cout << "*    Mnumber: M" << head->mNum << endl;
		cout << "**********************\n\n";
		head = head->next;
	}
}

void Student::printDescending()
{
	Student* lastStudent;
	cout << "\n Traversal in reverse direction \n";

	while (last != nullptr)
	{
		cout << "**********************\n";
		cout << "* First Name: " << last->firstName << endl;
		cout << "*  Last Name: " << last->lastName << endl;
		cout << "*    Mnumber: M" << last->mNum << endl;
		cout << "**********************\n\n";
		last = last->prev;
	}
}

void Student::AddItem(string firstName, string lastName, long mNum)
{
	Student* temp = new Student(firstName, lastName, mNum);

	if (head == nullptr)
	{
		head = last = temp;
		head->next = nullptr;
	}
	else
	{
		temp->next = head;
		head->prev = temp;
		head = temp;
	}
}

/* function to swap data of two nodes a and b*/
void Student::Swap(Student* a, Student* b)
{
	int intSet;
	string stringSet;

	intSet = a->mNum;
	a->mNum = b->mNum;
	b->mNum = intSet;

	stringSet = a->firstName;
	a->firstName = b->firstName;
	b->firstName = stringSet;

	stringSet = a->lastName;
	a->lastName = b->lastName;
	b->lastName = stringSet;
}

void Student::BubbleSort()
{
	int swapped, i;
	Student* check;
	Student* nullPointer = nullptr;

	/* Checking for empty list */
	if (head == nullptr)
		return;
	do
	{
		swapped = 0;
		temp = head;

		while (temp->next != nullPointer)
		{
			if (temp->mNum > temp->next->mNum)
			{
				Swap(temp, temp->next);
				swapped = 1;
			}
			temp = temp->next;
		}
		temp = nullPointer;
	} while (swapped);
}

void Student::InsertionSort()
{
	int swapped, i;
	struct Student* check;
	struct Student* nullPointer = nullptr;
	char a;
	char b;
	int result;

	/* Checking for empty list */
	if (head == NULL)
		return;

	do
	{
		swapped = 0;
		temp = head;

		while (temp->next != nullPointer)
		{
			a = temp->firstName.front();
			b = temp->next->firstName.front();

			i = 1;
			while (a == b)
			{
				a = temp->firstName.at(i);
				b = temp->next->firstName.at(i);
				i++;
			}

			const char* c = &a;
			const char* d = &b;
			result = strcmpi(c, d);

			if (result > 0)
			{
				Swap(temp, temp->next);
				swapped = 1;
			}
			temp = temp->next;
		}
		temp = nullPointer;
	} while (swapped);
}

void Student::SortedInsert(Student* head, Student* newNode)
{
	Student* current;

	// if list is empty 
	if (head == nullptr)
		head = newNode;

	// if the node is to be inserted at the beginning 
	// of the doubly linked list 
	else if (head->mNum >= newNode->mNum) {
		swap(newNode, head);
		newNode->next = head;
		newNode->next->prev = newNode;
		head = newNode;
	}

	else {
		current = head;

		// locate the node after which the new node 
		// is to be inserted 
		while (current->next != nullptr && current->next->mNum < newNode->mNum)
		{
			current = current->next;
		}

		/*Make the appropriate links */

		newNode->next = current->next;

		// if the new node is not inserted 
		// at the end of the list 
		if (current->next != nullptr)
			newNode->next->prev = newNode;

		current->next = newNode;
		newNode->prev = current;
	}
}

void Student::MergeSort()
{
	int swapped, i;
	struct Student* check;
	struct Student* nullPointer = nullptr;
	char a;
	char b;
	int result;

	/* Checking for empty list */
	if (head == NULL)
		return;

	do
	{
		swapped = 0;
		temp = head;

		while (temp->next != nullPointer)
		{
			a = temp->lastName.front();
			b = temp->next->lastName.front();

			i = 1;
			while (a == b)
			{
				a = temp->lastName.at(i);
				b = temp->next->lastName.at(i);
				i++;
			}

			const char* c = &a;
			const char* d = &b;
			result = strcmpi(c, d);

			if (result > 0)
			{
				Swap(temp, temp->next);
				swapped = 1;
			}
			temp = temp->next;
		}
		temp = nullPointer;
	} while (swapped);
}
