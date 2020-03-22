#include <iostream>
#include <string>
#include "student.h"

using namespace std;

string in_mNumber;
string in_firstName;
string in_lastName;
string in_birthday;
string in_gpa;

int main()
{
	// menu variables
	bool exit = false;
	bool restart = false;
	int intMenu = 1;

	// result from functions variables
	int intResult;
	int sizeResult;
	bool boolResult;
	string stringResult;

	// Declare node object
	Student myStudent;

	do {
		// menu for selecting functions
		if (intMenu > 0 && intMenu < 10)
			cout << "\n ~~~MENU~~~ \n 1. AddItem \n 2. GetItem \n 3. IsInList \n 4. IsEmpty \n 5. Size \n 6. SeeNext \n 7. SeeAt \n 8. Reset \n 9. Display\n 10. EXIT\n\n Enter: ";
		else
			cout << "Invlid Input. Try again: ";

		// only allows integer inputs between 1 and 9
		while (!(cin >> intMenu)) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input.  Try again: ";
		}

		switch (intMenu)
		{
		case 1:
			cout << " - Create student parameters - \n Enter M number (integers only): ";
			cin >> in_mNumber;
			cout << " Enter First Name: ";
			cin >> in_firstName;
			cout << " Enter Last Name: ";
			cin >> in_lastName;
			cout << " Enter Birthday: ";
			cin >> in_birthday;
			cout << " Enter GPA: ";
			cin >> in_gpa;

			myStudent.AddItem(&in_mNumber, &in_firstName, &in_lastName, &in_birthday, &in_gpa);
			cout << "\n Student added. \n\n";
			break;
		case 2:
			cout << "Enter student to remove (mNUmber w/ no M): ";
			cin >> stringResult;
			try
			{
				vector<string>* v_stringResult = myStudent.GetItem(&stringResult);
				cout << "\n First Name: " << v_stringResult->at(0) << "\n Last Name: " << v_stringResult->at(1) << "\n Birthday: " << v_stringResult->at(2) << "\n GPA: " << v_stringResult->at(3);
				cout << "\n\n Student removed.\n\n";
			}
			catch (const char* e)
			{
				cout << "\n An exception occurred: " << e << "\n";
			}
			break;
		case 3:
			cout << "Enter mNumber (no M): ";
			cin >> stringResult;
			try
			{
				boolResult = *myStudent.IsInList(&stringResult);
				if (boolResult)
					cout << "\n The student is in the list.\n";
				else
					cout << "\n The student is not in the list.\n";
			}
			catch (const char* e)
			{
				cout << "\n An exception occurred: " << e << "\n";
			}
			break;
		case 4:
			boolResult = *myStudent.IsEmpty();
			if (boolResult)
				cout << "\n The list is empty\n";
			else
				cout << "\n The list is not empty\n";
			break;
		case 5:
			sizeResult = *myStudent.Size();

			cout << "\n Size of list: " << sizeResult << "\n";
			break;
		case 6:
			try
			{
				vector<string>* v_stringResult = myStudent.SeeNext();
				cout << "\n First Name: " << v_stringResult->at(0) << "\n Last Name: " << v_stringResult->at(1) << "\n Birthday: " << v_stringResult->at(2) << "\n GPA: " << v_stringResult->at(3) << "\n";
			}
			catch (const char* e) {
				cout << "\n An exception occurred: " << e << "\n";
			}
			break;
		case 7:
			try
			{
				cout << "\n Select location (1-Size of List): ";
				cin >> intResult;
				vector<string>* v_stringResult = myStudent.SeeAt(&intResult);
				cout << "\n First Name: " << v_stringResult->at(0) << "\n Last Name: " << v_stringResult->at(1) << "\n Birthday: " << v_stringResult->at(2) << "\n GPA: " << v_stringResult->at(3) << "\n";
			}
			catch (const char* e) {
				cout << "\n An exception occurred: " << e << "\n";
			}
			break;
		case 8:
			myStudent.Reset();
			cout << "\n See Value set to head\n";
			break;
		case 9:
			try {
				myStudent.Display();
			}
			catch (const char* e) {
				cout << "\n An exception occurred: " << e << "\n";
			}
			break;
		case 10:
			exit = true;
			break;
		default:
			break;
		}
	} while (!exit);
	cout << "\n\n Exiting Program...";
	return 0;
}
