#pragma once
#include <iostream>
#include "hashTask4.h"
#include <list>
#include <vector>
using namespace std;


class HashT4
{
private:
	// member to hold the pointers
	string** data;
	string** apps;
	string** w;
	string** seas;
	//int** y;
	// to keep track which entries have been deleted
	bool* deleted;
	int i = 0;
	// capacity and current size of table
	int capacity, size;
	int collisions = 0;
	int hash(string s);

public:
	HashT4(int s);
	~HashT4();
	HashT4();

	void addItem(string* item, string* ap, string* won, string* season);
	string* removeItem(string* s);
	vector<string>* getItem(string* s);
	int getLength();
	int getCollisons();
	void printTable();
};