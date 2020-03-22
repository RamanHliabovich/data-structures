#include <iostream>
#include <string>
#include "hashTask3.h"

using namespace std;

string gen_rand_str() 
{
	string s;
	static const char alphanum[] =
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	for (int i = 0; i < 4; ++i) 
	{
		s.push_back(alphanum[rand() % (sizeof(alphanum) - 1)]);
	}

	return s;
}

int main()
{
	int menu1;
	int menu2;
	const int size = 100;
	string item[size];
	bool exit = false;

	for (int i = 0; i < size; ++i)
	{
		item[i] = gen_rand_str();
	}

	//for (int i = 0; i < size; ++i)
	//{
	//	cout << item[i] << endl;
	//}

	cout << "\n Select a Hash table Size: \n 1. 100 \n 2. 200 \n 3. 500  \n\n Enter: ";
	cin >> menu1;

	switch (menu1)
	{
	case 1:
	{
		HashT2 hashTable;
		cout << "\n Select how much letters to use for hashing: \n 1. 1st letter \n 2. first 2 letters \n 3. first 3 letters \n 4. all letters  \n\n Enter: ";
		cin >> menu2;
		switch (menu2)
		{
		case 1:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable.addItem(&item[i], 1);
			}
			cout << "\n Collisions: " << hashTable.getCollisons() << endl;
			break;
		}
		case 2:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable.addItem(&item[i], 2);
			}
			cout << "\n Collisions: " << hashTable.getCollisons() << endl;
			break;
		}
		case 3:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable.addItem(&item[i], 3);
			}
			cout << "\n Collisions: " << hashTable.getCollisons() << endl;
			break;
		}
		case 4:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable.addItem(&item[i], 4);
			}
			cout << "\n Collisions: " << hashTable.getCollisons() << endl;
			break;
		}
		}
		break;
	}
	case 2:
	{
		HashT2 hashTable2(200);
		cout << "\n Select how much letters to use for hashing: \n 1. 1st letter \n 2. first 2 letters \n 3. first 3 letters \n 4. all letters  \n\n Enter: ";
		cin >> menu2;
		switch (menu2)
		{
		case 1:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable2.addItem(&item[i], 1);
			}
			cout << "\n Collisions: " << hashTable2.getCollisons() << endl;
			break;
		}
		case 2:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable2.addItem(&item[i], 2);
			}
			cout << "\n Collisions: " << hashTable2.getCollisons() << endl;
			break;
		}
		case 3:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable2.addItem(&item[i], 3);
			}
			cout << "\n Collisions: " << hashTable2.getCollisons() << endl;
			break;
		}
		case 4:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable2.addItem(&item[i], 4);
			}
			cout << "\n Collisions: " << hashTable2.getCollisons() << endl;
			break;
		}
		}
		break;
	}
	case 3:
	{
		HashT2 hashTable3(500);
		cout << "\n Select how much letters to use for hashing: \n 1. 1st letter \n 2. first 2 letters \n 3. first 3 letters \n 4. all letters  \n\n Enter: ";
		cin >> menu2;
		switch (menu2)
		{
		case 1:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable3.addItem(&item[i], 1);
			}
			cout << "\n Collisions: " << hashTable3.getCollisons() << endl;
			break;
		}
		case 2:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable3.addItem(&item[i], 2);
			}
			cout << "\n Collisions: " << hashTable3.getCollisons() << endl;
			break;
		}
		case 3:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable3.addItem(&item[i], 3);
			}
			cout << "\n Collisions: " << hashTable3.getCollisons() << endl;
			break;
		}
		case 4:
		{
			for (int i = 0; i < size; ++i)
			{
				hashTable3.addItem(&item[i], 4);
			}
			cout << "\n Collisions: " << hashTable3.getCollisons() << endl;
			break;
		}
		}
	}
	}
	
}