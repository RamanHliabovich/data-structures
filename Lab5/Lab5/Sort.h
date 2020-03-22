#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Sort
{
public:
	void Print(int usingArray[], int sizeArray);

	void Bubble(int usingArray[], int sizeArray);

	void Insertion(int usingArray[], int sizeArray);

	void MergeSort(int usingArray[], int left, int right);

	void Merge(int usingArray[], int left, int middle, int right);

	void QuickSort(int usingArray[], int low, int high);

	int Partition(int usingArray[], int low, int high);

	void Swap(int* a, int* b);

	int getMax(int array[], int size);

	void countSort(int usingArray[], int sizeArray);

	void radixCountSort(int usingArray[], int sizeArray, int exp);

	void Radix(int usingArray[], int sizeArray);
};