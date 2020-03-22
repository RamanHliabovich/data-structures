#include <iostream>
#include <string.h>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "Student.h"
using namespace std;

bool exitProgram = false;
int direction;

int sortMethod;

static const char alphanum[] =
"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
"abcdefghijklmnopqrstuvwxyz";

int stringLength = sizeof(alphanum) - 1;

char genRandom()
{
	return alphanum[rand() % stringLength];
}

string firstName;
string lastName;
long mNum;

long mnumArray[50];
string firstArray[50];
string lastArray[50];

Student student;

int main()
{
	do {

		//creates the unordered list of 50 Students and their data
		cout << " Seeding list... \n";
		for (int i = 0; i < 50; ++i)
		{
			firstName = "";
			lastName = "";
			mNum = NULL;

			//generate MNumber
			mNum = rand() % (99999999 - 00000001 + 1) + 00000001;

			//generate last name
			for (unsigned int i = 0; i < 8; ++i)
			{
				lastName += genRandom();
			}

			//generate first name
			for (unsigned int i = 0; i < 8; ++i)
			{
				firstName += genRandom();
			}
			student.AddItem(firstName, lastName, mNum);
		}
		cout << " List seeded! \n";

		sortMenu:

		// get linked list as array to be sorted

		//input for the algorithm of choice
		cout << "\n Which sorting algorithm would you like to use?" << endl;
		cout << " 1. Bubble Sort (mNum) " << endl;
		cout << " 2. Insertion Sort (first name) " << endl;
		cout << " 3. Merge Sort (last name) " << endl;
		cout << "\n Enter: ";
		cin >> sortMethod;

		switch (sortMethod)
		{
		case 1:
			student.BubbleSort();
			break;
		case 2:
			cout << "Sorting first name alphabetically.\n\n";
			student.InsertionSort();
			break;
		case 3:
			cout << "Sorting last name alphabetically.\n\n";
			student.MergeSort();
			break;
		default:
			cout << "\n Invalid input, try again.";
			goto sortMenu;
			break;
		}

		printMenu:

		//input for the ascending or descending order
		cout << "\n Which direction would you like the list to be ordered in?" << endl;
		cout << " 1. Ascending \n 2. Descending \n\n Enter: ";
		cin >> direction;

		switch (direction)
		{
			case 1: 
				student.printAscending();
				break;
			case 2:
				student.printDescending();
				break;
			default:
				cout << "\n Invalid input, try again.";
				goto printMenu;
				break;
		}

		cout << "Enter any key to exit...";
		cin >> sortMethod;
		exitProgram = true;
	} while (!exitProgram);
}