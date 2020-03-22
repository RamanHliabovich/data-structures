//#include <iostream>
//#include <string>
//#include "student.h"
//
//using namespace std;
//
//// menu variables
//bool exitProgram = false;
//bool restart = false;
//int intMenu = 1;
//
//// result from functions variables
//int intResult;
//int sizeResult;
//bool boolResult;
//string stringResult;
//
//// variables for passing into student node
//string mNumber;
//string firstName;
//string lastName;
//string birthday;
//string gpa;
//
//// array of strings for Get Item
//vector<string> outStrings;
//
//// Declare node object
//Student myStudent;
//
//int main()
//{
//	// asks for which constructor to use (set max size or default max size of 20)
//	cout << "- Select Option to Start Program - \n 1. Set max size \n 2. Set as default (20) \n Enter: ";
//	cin >> stringResult;
//	if (stringResult == "1")
//	{
//		cout << "Enter max size: ";
//		cin >> intResult;
//		Student myStudent(intResult); // set max size constructor
//	}
//	else
//		Student myStudent; // default constructor
//
//		do {
//			// menu for selecting functions
//			if (intMenu > 0 && intMenu < 10)
//				cout << "\n\n ~~~MENU~~~ \n 1. AddItem \n 2. GetItem \n 3. IsEmpty \n 4. IsFull \n 5. Size \n 6. ClearList \n 7. Exit \n\n Enter: ";
//			else
//				cout << "Invlid Input. Try again: ";
//
//			// only allows integer inputs between 1 and 9
//			while (!(cin >> intMenu)) 
//			{
//				cin.clear();
//				cin.ignore(numeric_limits<streamsize>::max(), '\n');
//				cout << "Invalid input.  Try again: ";
//			}
//
//		switch (intMenu)
//		{
//			case 1:
//				cout << " - Create student parameters - \n Enter M number (integers only): ";
//				cin >> mNumber;
//				cout << " Enter First Name: ";
//				cin >> firstName;
//				cout << " Enter Last Name: ";
//				cin >> lastName;
//				cout << " Enter Birthday: ";
//				cin >> birthday;
//				cout << " Enter GPA: ";
//				cin >> gpa;
//				myStudent.AddItem(mNumber, firstName, lastName, birthday, gpa);
//				break;
//			case 2:
//				try {
//					outStrings.clear();
//					outStrings = myStudent.GetItem();
//					cout << "\n mNumber: " << outStrings[0] << "\n First Name: " << outStrings[1] << "\n Last Name: " << outStrings[2] << "\n Birthday " << outStrings[3] << "\n GPA: " << outStrings[4];
//					cout << "\n\n Student Removed.";
//				}
//				catch (const char* e)
//				{
//					cout << "\n An exception occurred: " << e << "\n";
//				}
//				break;
//			case 3:
//				boolResult = myStudent.IsEmpty();
//				if (boolResult)
//					cout << "\n The list is empty";
//				else
//					cout << "\n The list is not empty";
//				break;
//			case 4:
//				boolResult = myStudent.IsFull();
//				if (boolResult)
//					cout << "\n The list is full";
//				else
//					cout << "\n The list is not full";
//				break;
//			case 5:
//				intResult = myStudent.Size();
//				cout << "\n Size of List: " << intResult;
//				break;
//			case 6:
//				myStudent.ClearList();
//				break;
//			case 7:
//				exitProgram = true;
//				break;
//		}
//	} while (!exitProgram);
//}