#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
private:
	string mNumber;
	string firstName;
	string lastName;
	string birthday;
	string gpa;

	bool check;

	bool initiated = false;

	int length = 0;

	int seeCount = 0;

	Student* next = nullptr;

	Student* head;

	Student* temp;

	Student* rem;

	Student* see;

public:
	// Constructor
	Student();

	void NodeStudent(string* mNumber, string* firstName, string* lastName, string* birthday, string* gpa);
	void AddItem(string* mNumber, string* firstName, string* lastName, string* birthday, string* gpa);
	vector<string>* GetItem(string* mNumber);
	bool* IsInList(string* mNumber);
	bool* IsEmpty();
	int* Size();
	vector<string>* SeeNext();
	vector<string>* SeeAt(int* location);
	void Reset();
	void Display();
};