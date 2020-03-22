#pragma once
#pragma once
#include <iostream>
#include "hashTask3.h"
using namespace std;


class HashT2
{
private:
	// member to hold the pointers
	string** data;

	// to keep track which entries have been deleted
	bool* deleted;

	// capacity and current size of table
	int capacity, size;
	int collisions = 0;
	int hash(string s);
	int hash3(string s);
	int hash2(string s);
	int hash1(string s);

public:
	HashT2(int s);
	~HashT2();
	HashT2();

	void addItem(string* item, int ver);
	string* removeItem(string* s);
	string* getItem(string* s);
	int getLength();
	int getCollisons();
	void printTable();
};