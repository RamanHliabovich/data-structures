#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class Queue : public Student
{
public: 
	void Enqueue(string mNumber, string firstName, string lastName, string birthday, string gpa);
};