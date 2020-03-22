#include <iostream>
#include <string.h>
#include <chrono>
#include <vector>
#include <ctime>
#include <stdlib.h>
#include "Sort.h"

using namespace std;

int intResult;

string stringResult;

int sizeArray;

int usingArray[];

bool exitProgram = true;

Sort sort;

// time thing
typedef std::chrono::high_resolution_clock Clock;

int main()
{
	do {
		// ask user for array size to be tested for each algorithm
		cout << "Select an array size: \n 1. 10 \n 2. 100 \n 3. 500 \n 4. 5000 \n 5. 25,000 \n 6. 100,000";
		cout << "\n\n Enter: ";
		cin >> intResult;

		switch (intResult)
		{
		case 1:
			sizeArray = 10;
			break;
		case 2:
			sizeArray = 100;
			break;
		case 3:
			sizeArray = 500;
			break;
		case 4:
			sizeArray = 5000;
			break;
		case 5:
			sizeArray = 25000;
			break;
		case 6:
			sizeArray = 100000;
			break;
		}

		int* usingArray = new int[sizeArray]();
		int* copyArray = new int[sizeArray]();

		cout << "\n Testing...\n";

		// create randomn array to reorder, also creates a copy array to do the actual sorting onto
		srand(time(nullptr));
		for (int i = 0; i < sizeArray; i++)
		{
			usingArray[i] = rand() % (2*sizeArray+1);
			copyArray[i] = usingArray[i];
		}

		//print original unordered array
		cout << "\n Original \n";
		sort.Print(usingArray, sizeArray);
		cout << '\n';

		//get time for bubble sort and using bubble sort function
		auto t1 = Clock::now();
		sort.Bubble(copyArray, sizeArray);
		auto t2 = Clock::now();

		//output bubble time and sorted array
		cout << "\n Bubble Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds \n";
		sort.Print(copyArray, sizeArray);
		cout << '\n';

		//reset "copyArray" back to original array to sort it again using a different algorithm
		for (int i = 0; i < sizeArray; i++)
		{
			copyArray[i] = usingArray[i];
		}
		
		//get time for insertion sort and use insertion sort function
		t1 = Clock::now();
		sort.Insertion(copyArray, sizeArray);
		t2 = Clock::now();

		//output insert time and sorted array
		cout << "\n Insertion Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds \n";
		//sort.Print(copyArray, sizeArray);
		cout << '\n';

		//reset "copyArray" back to original array to sort it again using a different algorithm
		for (int i = 0; i < sizeArray; i++)
		{
			copyArray[i] = usingArray[i];
		}

		//get time for merge sort and use merge sort function
		t1 = Clock::now();
		sort.MergeSort(copyArray, 0, sizeArray-1);
		t2 = Clock::now();

		//output merge time and sorted array
		cout << "\n Merge Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds \n";
		//sort.Print(copyArray, sizeArray);
		cout << '\n';

		//reset "copyArray" back to original array to sort it again using a different algorithm
		for (int i = 0; i < sizeArray; i++)
		{
			copyArray[i] = usingArray[i];
		}

		//get time for quick sort and use quick sort function
		t1 = Clock::now();
		sort.QuickSort(copyArray, 0, sizeArray-1);
		t2 = Clock::now();

		//output quick time and sorted array
		cout << "\n Quick Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds \n";
		//sort.Print(copyArray, sizeArray);
		cout << '\n';

		//reset "copyArray" back to original array to sort it again using a different algorithm
		for (int i = 0; i < sizeArray; i++)
		{
			copyArray[i] = usingArray[i];
		}

		//get time for counting sort and use counting sort function
		t1 = Clock::now();
		sort.countSort(copyArray, sizeArray);
		t2 = Clock::now();

		//output counting time and sorted array
		cout << "\n Count Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds \n";
		sort.Print(copyArray, sizeArray);
		cout << '\n';

		//reset "copyArray" back to original array to sort it again using a different algorithm
		for (int i = 0; i < sizeArray; i++)
		{
			copyArray[i] = usingArray[i];
		}

		//get time for radix sort and use radix sort function
		t1 = Clock::now();
		sort.Radix(copyArray, sizeArray);
		t2 = Clock::now();

		//output radix time and sorted array
		cout << "\n Radix Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds \n";
		//sort.Print(copyArray, sizeArray);
		cout << '\n';

		// exit program or do again
		cout << "\n Test Again?(y/n)";
		cin >> stringResult;
		if (stringResult == "y")
			exitProgram = true;

	} while (exitProgram == true);
}