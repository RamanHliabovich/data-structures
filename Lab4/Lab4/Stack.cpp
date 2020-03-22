//Developer: Sean Sliter & Raman Hliabovich
#include <iostream>
#include "Stack.h"
using namespace std;

//adds value to the top of the stack
void Stack::push(string mNumber, string firstName, string lastName, string birthday, string gpa)
{
	Student::AddItem2(mNumber, firstName, lastName, birthday, gpa);
}