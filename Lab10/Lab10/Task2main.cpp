#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int main()
{
	bool exit = false;
	int menu;
	int x;
	string buf;
	string item[100];
	Hash hashTable;
	int i = 0;

	do
	{
		cout << "\n Select an option: \n 1. Add Item \n 2. Remove Item \n 3. Get Item \n 4. Get length \n 5. Print Table \n\n Enter: ";
		cin >> menu;
		switch (menu)
		{
		case 1:
		{
			cout << "\n Enter Item: ";
			cin >> buf;
			item[i] = buf;
			hashTable.addItem(&item[i]);
			cout << "\n Item added.\n";
			++i;
			/*hashTable.printTable();*/
			break;
		}
		case 2:
		{
			cout << "\n Enter Item to remove: ";
			cin >> buf;
			string* rem_item = hashTable.removeItem(&buf);
			if (rem_item == nullptr)
			{
				cout << "\n Item is not in list. \n ";
				break;
			}
			cout << "\n Item removed: " << *rem_item << endl;
			break;
		}
		case 3:
		{
			cout << "\n Enter Item to Get: ";
			cin >> buf;
			cout << "\n Pointer of item: " << hashTable.getItem(&buf);
			break;
		}
		case 4:
		{
			cout << "\n Number of Items in table: " << hashTable.getLength() << endl;
			break;
		}
		case 5:
		{
			hashTable.printTable();
			break;
		}
		case 6:
		{
			exit = true;
			break;
		}
		}

	} while (!exit);
}