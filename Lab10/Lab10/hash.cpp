#include <iostream>
#include "hash.h"
#include <string>
using namespace std;


Hash::Hash() 
{
	capacity = 100;
	data = new string * [capacity];
	//y = new int *  [2];
	deleted = new bool[capacity];
	size = 0;

	//y[0] = nullptr;
	//y[1] = nullptr;

	for (int i = 0; i < 100; i++) {
		data[i] = nullptr;
		deleted[i] = false;
	}
}

int Hash::hash(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i];
	}
	return sum % capacity;
}



Hash::Hash(int s) {
	capacity = s;
	data = new string * [capacity];
	deleted = new bool[capacity];
	size = 0; 

	for (int i = 0; i < s; i++) {
		data[i] = nullptr;
		deleted[i] = false;
	}
}

Hash::~Hash() {
	delete[] data;
	delete[] deleted;
}

void Hash::addItem(string* item) {

	//y[i] = x;
	//cout << "TEST: " << y[0] << endl;
	//cout << "TEST: " << y[1] << endl;
	//++i;
	if (item == NULL || getItem(item) != nullptr) {
		++collisions;
		return;
	}
	int index = hash(*item);
	while (data[index] != NULL && !deleted[index]) {
		index = (index + 1) % capacity;
	}

	data[index] = item;
	deleted[index] = false;
	size++;
}

string* Hash::removeItem(string* s) {
	int index = hash(*s);
	int originalLoc = index;
	while (data[index] != NULL) {
		if (*(data[index]) == *s) {
			deleted[index] = true;
			string* result = data[index];
			data[index] = nullptr;
			size--;
			return result;
		}
		index = (index + 1) % capacity;
		if (index == originalLoc) {
			break;
		}
	}
	return nullptr;
}

string* Hash::getItem(string* s) 
{
	int index = hash(*s);
	int originalLoc = index;
	while (data[index] != NULL || deleted[index]) 
	{
		if (data[index] != NULL && *(data[index]) == *s) 
		{
			return data[index];
		}
		index = (index + 1) % capacity;
		if (index == originalLoc) 
		{
			break;
		}
	}
	return nullptr;
}

int Hash::getLength() 
{
	return size;
}

int Hash::getCollisons()
{
	return collisions;
}

void Hash::printTable()
{
	cout << "\n Table: " << endl;
	for (int i = 0; i < 100; ++i)
	{
		if (data[i] == nullptr)
		{
			cout << " " << i << ": " << "nullptr" << endl;
		}
		else
		{
			cout << " " << i << ": " << *data[i] << endl;
		}
	}
}