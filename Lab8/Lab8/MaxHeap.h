#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MaxHeap 
{
public:
	MaxHeap(bool test);

	vector<int> Heap;
	int size;
	int maxSize;

	MaxHeap(int maxsize);
	int parent(int pos);
	int leftChild(int pos);
	int rightChild(int pos);
	bool isLeaf(int pos);
	void swap(int fpos, int spos);
	void MaxHeapify(int pos);
	void Insert(int element);
	int Remove(int element);
	void PrintHeap();
	int extractMax();

};