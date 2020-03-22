#include <iostream>
#include "hashTask3.h"
#include <string>
using namespace std;


HashT2::HashT2()
{
	capacity = 100;
	data = new string * [capacity];
	deleted = new bool[capacity];
	size = 0;

	for (int i = 0; i < 100; i++) {
		data[i] = nullptr;
		deleted[i] = false;
	}
}

int HashT2::hash(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i];
	}
	return sum % capacity;
}

int HashT2::hash3(string s) {
	int sum = 0;
	for (int i = 0; i < 3; i++) {
		sum += s[i];
	}
	return sum % capacity;
}

int HashT2::hash2(string s) {
	int sum = 0;
	for (int i = 0; i < 2; i++) {
		sum += s[i];
	}
	return sum % capacity;
}

int HashT2::hash1(string s) {
	int sum = 0;
	for (int i = 0; i < 1; i++) {
		sum += s[i];
	}
	return sum % capacity;
}

HashT2::HashT2(int s) {
	capacity = s;
	data = new string * [capacity];
	deleted = new bool[capacity];
	size = 0;

	for (int i = 0; i < s; i++) {
		data[i] = nullptr;
		deleted[i] = false;
	}
}

HashT2::~HashT2() {
	delete[] data;
	delete[] deleted;
}

void HashT2::addItem(string* item, int ver) {

	if (item == NULL || getItem(item) != nullptr) {
		return;
	}

	int index;

	if (ver == 4)
	{
		index = hash(*item);
	}
	else if (ver == 3)
	{
		index = hash3(*item);
	}
	else if (ver == 2)
	{
		index = hash2(*item);
	}
	else if (ver == 1)
	{
		index = hash1(*item);
	}
	else
	{
		index = hash(*item);
	}

	while (data[index] != NULL && !deleted[index]) 
	{
		++collisions;
		index = (index + 1) % capacity;
	}

	data[index] = item;
	deleted[index] = false;
	size++;
}

string* HashT2::removeItem(string* s) {
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

string* HashT2::getItem(string* s)
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

int HashT2::getLength()
{
	return size;
}

int HashT2::getCollisons()
{
	return collisions;
}

void HashT2::printTable()
{
	for (int i = 0; i < capacity; ++i)
	{
		if (data[i] == nullptr)
		{
			cout << " nullptr" << endl;
		}
		else
		{
			cout << " " << *data[i] << endl;
		}
		
	}
}
