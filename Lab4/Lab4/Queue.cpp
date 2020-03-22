#include <iostream>
#include <string>
#include "Queue.h"

using namespace std;

void Queue::Enqueue(string mNumber, string firstName, string lastName, string birthday, string gpa)
{
	Student::AddItem(mNumber, firstName, lastName, birthday, gpa);
}