#include <iostream>
#include "hashTask4.h"
#include <string>
#include <vector>
using namespace std;


HashT4::HashT4()
{
	capacity = 100;
	data = new string * [capacity];
	apps = new string * [capacity];
	w = new string * [capacity];
	seas = new string * [capacity];
	deleted = new bool[capacity];
	size = 0;

	for (int i = 0; i < 100; i++) {
		data[i] = nullptr;
		apps[i] = nullptr;
		w[i] = nullptr;
		seas[i] = nullptr;
		deleted[i] = false;
	}
}

int HashT4::hash(string s) {
	int sum = 0;
	for (int i = 0; i < s.length(); i++) {
		sum += s[i];
	}
	return sum % capacity;
}



HashT4::HashT4(int s) {
	capacity = s;
	data = new string * [capacity];
	apps = new string * [capacity];
	w = new string * [capacity];
	seas = new string * [capacity];
	deleted = new bool[capacity];
	size = 0;

	for (int i = 0; i < s; i++) {
		data[i] = nullptr;
		apps[i] = nullptr;
		w[i] = nullptr;
		seas[i] = nullptr;
		deleted[i] = false;
	}
}

HashT4::~HashT4() {
	delete[] data;
	delete[] deleted;
}

void HashT4::addItem(string* item, string* ap, string* won, string* season) {

	//if (item == NULL || getItem(item) != nullptr) {
	//	++collisions;
	//	return;
	//}

	int index = hash(*item);
	while (data[index] != NULL && !deleted[index]) {
		++collisions;
		index = (index + 1) % capacity;
	}

	data[index] = item;
	apps[index] = ap;
	w[index] = won;
	seas[index] = season;
	deleted[index] = false;
	size++;
}

string* HashT4::removeItem(string* s) {
	int index = hash(*s);
	int originalLoc = index;
	while (data[index] != NULL) {
		if (*(data[index]) == *s) {
			deleted[index] = true;
			string* result = data[index];
			data[index] = nullptr;
			apps[index] = nullptr;
			w[index] = nullptr;
			seas[index] = nullptr;
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

vector<string>* HashT4::getItem(string* s)
{
	vector<string> RetVal;
	vector<string>* buffer = new vector<string>(4);
	int index = hash(*s);
	int originalLoc = index;
	while (data[index] != NULL || deleted[index])
	{
		if (data[index] != NULL && *(data[index]) == *s)
		{
			RetVal.push_back(*data[index]);
			RetVal.push_back(*apps[index]);
			RetVal.push_back(*w[index]);
			RetVal.push_back(*seas[index]);
			buffer->at(0) = RetVal[0];
			buffer->at(1) = RetVal[1];
			buffer->at(2) = RetVal[2];
			buffer->at(3) = RetVal[3];
			return buffer;
		}
		index = (index + 1) % capacity;
		if (index == originalLoc)
		{
			break;
		}
	}
	return nullptr;
}

int HashT4::getLength()
{
	return size;
}

int HashT4::getCollisons()
{
	return collisions;
}

void HashT4::printTable()
{
	for (int i = 0; i < 100; ++i)
	{
		if (data[i] == nullptr)
		{
			cout << "nullptr" << endl;
		}
		else
		{
			cout << *data[i] << endl;
		}
	}
}