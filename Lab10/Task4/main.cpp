#include <iostream>
#include <fstream>
#include <string>
#include "hashTask4.h"
using namespace std;

int main()
{
	ifstream inFile;

	int i = 0;
	string garbage;
	string team;
	string apps;
	string won;
	string seasons;
	inFile.open("file2.csv");
	if (inFile.is_open()) {
		cout << "File has been opened" << endl;
		cout << "Loading data..." << endl;
	}
	else {
		cout << "NO FILE HAS BEEN OPENED" << endl;
	}

	string tstr[31];
	string astr[31];
	string wstr[31];
	string sstr[31];

	while (!inFile.eof()) {
		getline(inFile, garbage, ',');
		getline(inFile, team, ',');
		getline(inFile, apps, ',');
		getline(inFile, won, ',');
		inFile >> seasons;
		//cout << team << endl;
		//cout << "apps: " << apps << endl;
		//cout << "won: " << won << endl;
		//cout << "seasons: " << seasons << endl << endl;
		tstr[i] = team;
		astr[i] = apps;
		wstr[i] = won;
		sstr[i] = seasons;
		++i;
	}
	inFile.close();


	//for (int i = 0; i < 31; ++i)
	//{
	//	cout << "team: " << tstr[i] << endl;
	//	cout << "apps: " << astr[i] << endl;
	//	cout << "won: " << wstr[i] << endl;
	//	cout << "seasons: " << sstr[i] << endl << endl;
	//}

	//for (int i = 1; i < 31; ++i)
	//{
	//	cout << i << ": " << tstr[i] << endl;
	//}

	bool exit = false;
	int menu;
	int x;
	string buf;
	HashT4 hashTable;

	for (int i = 1; i < 31; ++i)
	{
		hashTable.addItem(&tstr[i], &astr[i], &wstr[i], &sstr[i]);
	}

	do
	{
		cout << "\n Select an option: \n 1. Search Team \n 2. Exit \n\n Enter: ";
		cin >> menu;
		switch (menu)
		{

		case 1:
		{
			cout << "\n Search Team: ";
			cin.ignore(cin.rdbuf()->in_avail());
			getline(cin,buf);
			vector<string>* v_stringResult = hashTable.getItem(&buf);

			cout << "\n Searching Team...\n";

			cout << "\n Team Name: " << v_stringResult->at(0) 
				<< "\n Appearances: " << v_stringResult->at(1) 
				<< "\n Won: " << v_stringResult->at(2) 
				<< "\n Seasons: " << v_stringResult->at(3) << endl;

			cout << "\n Collisions: " << hashTable.getCollisons() << endl;

			break;
		}
		case 2:
		{
			exit = true;
			break;
		}
		case 3:
		{
			hashTable.printTable();
		}
		}

	} while (!exit);

	return 0;
}