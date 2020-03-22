#pragma once
#include <iostream>
#include "hash.h"
using namespace std;


class Hash
{
private:
	// member to hold the pointers
	string** data;
	//int** y;
	// to keep track which entries have been deleted
	bool* deleted;
	int i = 0;
	// capacity and current size of table
	int capacity, size;
	int collisions = 0;
	int hash(string s);

public:
	Hash(int s);
	~Hash();
	Hash();

	void addItem(string* item);
	string* removeItem(string* s);
	string* getItem(string* s);
	int getLength();
	int getCollisons();
	void printTable();
};