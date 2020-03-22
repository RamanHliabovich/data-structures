#include <iostream>
#include <string>
#include "PriorityQueue.h"

using namespace std;

int intMenu;
int value;
int priority;
PriorityQueue pq;

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
			cout << "\n Value: ";
			cin >> value;
			pq.Insert(value);
			cout << "\n Value added to queue. \n\n";
			break;
		}
		case 2:
		{
			value = pq.Remove();
			cout << "\n " << value << " has been removed.\n";
			break;
		}
		case 3:
		{
			pq.PrintQueue();
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