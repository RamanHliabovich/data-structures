#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Items.h"

using namespace std;

class Student
{
	// These all should be protected no public (besides functions)
public:
	// student variables for function parameters

	bool check = false;

	bool initiated = false;

	int length = 0;

	int seeCount = 0;

	int maxSize;

	// Constructors
	Student() { maxSize = 20; }
	Student(int inVal) { maxSize = inVal; }

	// Menu functions
	virtual void AddItem(string mNumber, string firstName, string lastName, string birthday, string gpa);
	void AddItem2(string mNumber, string firstName, string lastName, string birthday, string gpa);
	vector<string> GetItem();
	bool IsEmpty();
	bool IsFull();
	int Size();
	void ClearList();
};