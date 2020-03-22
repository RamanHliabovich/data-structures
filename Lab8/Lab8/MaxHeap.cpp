#include "MaxHeap.h"

using namespace std;

	// Constructor to initialize an 
	// empty max heap with given maximum 
	// capacity. 
	MaxHeap::MaxHeap(bool test) 
	{
		if (test == false)
		{
			int result;
			cout << " Enter max size of heap (cannot be 0): ";
			cin >> result;
			cout << "\n Size of heap: " << result << "\n\n";
			size = -1;
			maxSize = result;
			for (int i = 0; i < maxSize; i++)
				Heap.push_back(0);
		}
		else
		{
			for (int i = 0; i <= 20010; i++)
				Heap.push_back(0);
			size = -1;
		}
	}

	// Returns position of parent 
	int MaxHeap::parent(int pos)
	{
		return pos / 2;
	}

	void MaxHeap::swap(int fpos, int spos)
	{
		int tmp;
		tmp = Heap[fpos];
		Heap[fpos] = Heap[spos];
		Heap[spos] = tmp;
	}

	// Inserts a new element to max heap 
	void MaxHeap::Insert(int element)
	{
		Heap[++size] = element;

		// Traverse up and fix violated property 
		int current = size;
		while (Heap[current] > Heap[parent(current)]) {
			swap(current, parent(current));
			current = parent(current);
		}
	}

	// finds element and removes. Moves all items down vector.
	int MaxHeap::Remove(int element)
	{
		//int position = 0;
		//for (int i = 0; i <= size; i++)
		//{
		//	if (Heap[i] == element)
		//	{
		//		Heap[i] = 0;
		//		for (int j = position; j <= (size - position)+1; j++)
		//			Heap[j] = Heap[j + 1];
		//		break;
		//	}
		//	position++;
		//}

		std::vector<int>::iterator position = std::find(Heap.begin(), Heap.end(), element);
		Heap.erase(position);
		Heap.push_back(0);
		return element;

		return element;
	}

	// Prints based on placement in vector
	void MaxHeap::PrintHeap()
	{
		cout << "\n !!!!!! '0' represents an empty node in the heap !!!!!!\n";
		cout << "\n Max heap contents :";
		for (int i = 0; i < Heap.size(); ++i)
		{
			cout << " " << Heap.at(i) << " ";
		}
		cout << endl << endl;
	}