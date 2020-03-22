#include <iostream>
#include <string>
#include "MaxHeap.h"

using namespace std;

int max_size;
int intMenu;
int value;
int priority;
MaxHeap mh = false;

bool exitProgram = false;

int main()
{
	do {
		cout << " Select an option: \n 1. Insert \n 2. Remove \n 3. Print \n 4. Exit \n\n Enter: ";
		cin >> intMenu;

		switch (intMenu)
		{
			case 1:
			{
				cout << "\n Value(cannot be 0): ";
				cin >> value;
				mh.Insert(value);
				cout << "\n Value added to heap. \n\n";
				break;
			}
			case 2:
			{
				cout << "\n Enter value to remove: ";
				cin >> value;
				value = mh.Remove(value);
				cout << "\n " << value << " has been removed.\n";
				break;
			}
			case 3:
			{
				mh.PrintHeap();
				break;
			}
			case 4:
			{
				exitProgram = true;
				cout << "\n\n Exiting program...";
				break;
			}
		}
	} while (!exitProgram);
}