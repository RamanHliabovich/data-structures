#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Student
{
public:

	// node data
	string firstName;
	string lastName;
	long mNum;

	//pointers called next and previous
	Student* head = nullptr;
	Student* last = nullptr;
	Student* next = nullptr;
	Student* prev = nullptr;
	Student* temp = nullptr;
	Student* sort = nullptr;
	Student* rem = nullptr;

	Student();
	Student(string firstName, string lastName, long mNum);

	void printAscending();
	void printDescending();

	void AddItem(string firstName, string lastName, long mNum);

	void Swap(Student* a, Student* b);

	void SortedInsert(Student* head, struct Student* newNode);

	void BubbleSort();

	void InsertionSort();

	void MergeSort();

	void SortedMerge();
};