#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

class Stack : public Student
{
public:
	void push(string mNumber, string firstName, string lastName, string birthday, string gpa);
};
