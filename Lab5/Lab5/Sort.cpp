#include <iostream>
#include <stdio.h> 
#include <string.h>
#include "Sort.h"

// All functions pass in the asked for array and returns the reordered one. Time is recorded in main

using namespace std;

void Sort::Print(int usingArray[], int sizeArray)
{
	for (int i = 0; i < sizeArray; i++) 
	{
		if (i == 0)
		{
			cout << " " << usingArray[i] << " ";
		}
		else 
		{
			cout << usingArray[i] << " ";
		}
	}
}

void Sort::Bubble(int usingArray[], int sizeArray)
{
	int i, j;

	for (i = 0; i < sizeArray - 1; i++)
	{
		// Last i elements are already in place    
		for (j = 0; j < sizeArray - i - 1; j++)
		{
			if (usingArray[j] > usingArray[j + 1])
			{
				Swap(&usingArray[j], &usingArray[j + 1]);
			}
		}
	}
	/*cout << "\n Bubble \n";
	Print(usingArray, sizeArray);*/
};

void Sort::Insertion(int usingArray[], int sizeArray)
{
	int i, key, j;

	for (i = 1; i < sizeArray; i++)
	{
		key = usingArray[i];
		j = i - 1;

		/* Move elements of usingArray[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && usingArray[j] > key)
		{
			usingArray[j + 1] = usingArray[j];
			j = j - 1;
		}
		usingArray[j + 1] = key;
	}

	/*cout << "\n Insertion \n ";
	Print(usingArray, sizeArray);*/
};

void Sort::MergeSort(int usingArray[], int left, int right)
{
	if (left < right)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int middle = left + (right - left) / 2;

		// Sort first and second halves 
		MergeSort(usingArray, left, middle);
		MergeSort(usingArray, middle + 1, right);

		Merge(usingArray, left, middle, right);
	}
}

void Sort::Merge(int usingArray[], int left, int middle, int right)
{
	int i;
	int j;
	int k;
	int n1 = middle - left + 1;
	int n2 = right - middle;

	/* create temp arrays */
	int* L;
	L = new int[n1];
	int* R;
	R = new int[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = usingArray[left + i];
	for (j = 0; j < n2; j++)
		R[j] = usingArray[middle + 1 + j];

	/* Merge the temp arrays back into usingArray[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = left; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			usingArray[k] = L[i];
			i++;
		}
		else
		{
			usingArray[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		usingArray[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		usingArray[k] = R[j];
		j++;
		k++;
	}
};

/* Quick Sort Functions */

/* The main function that implements QuickSort
 usingArray[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void Sort::QuickSort(int usingArray[], int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, usingArray[p] is now
		   at right place */
		int pi = Partition(usingArray, low, high);

		// Separately sort elements before 
		// partition and after partition 
		QuickSort(usingArray, low, pi - 1);
		QuickSort(usingArray, pi + 1, high);
	}
}

// A utility function to swap two elements 
void Sort::Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

/* This function takes last element as pivot, places
   the pivot element at its correct position in sorted
	array, and places all smaller (smaller than pivot)
   to left of pivot and all greater elements to right
   of pivot */
int Sort::Partition(int usingArray[], int low, int high)
{
	int pivot = usingArray[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (usingArray[j] <= pivot)
		{
			i++;    // increment index of smaller element 
			Swap(&usingArray[i], &usingArray[j]);
		}
	}
	Swap(&usingArray[i + 1], &usingArray[high]);
	return (i + 1);
}

int Sort::getMax(int array[], int size)
{
	int max = array[0];
	for (int i = 1; i <= size; i++) 
	{
		if (array[i] > max)
		{
			max = array[i];
		}
	}
	return max; //the max element from the array
}

void Sort::countSort(int copyArray[], int sizeArray)
{
	int index = 0;
	int *outputArray = new int[sizeArray + 1] ();

	int max = getMax(copyArray, sizeArray);

	int* count = new int[max + 1] (); //create count array (max+1 number of elements)

	for (int i = 1; i <= sizeArray; i++)
	{
		count[copyArray[i-1]]++;     //increase number count in count array.
	}
	for (int i = 1; i <= max; i++)
	{
		count[i] += count[i - 1];     //find cumulative frequency
	}
	for (int i = sizeArray; i >= 1; i--) 
	{
		index = copyArray[i-1];
		outputArray[count[index]-1] = copyArray[i-1];
		count[index] -= 1; //decrease count for same numbers
	}
	for (int i = 0; i <= sizeArray; i++) 
	{
		copyArray[i] = outputArray[i]; //store output array to main array
	}
};


//this countSort is used for the radix sort
void Sort::radixCountSort(int usingArray[], int sizeArray, int exp)
{
	int *output = new int[sizeArray]; // output array 
	int i;
	int count[10] = { 0 };

	// Store count of occurrences in count[] 
	for (i = 0; i < sizeArray; i++)
		count[(usingArray[i] / exp) % 10]++;

	// Change count[i] so that count[i] now contains actual 
	//  position of this digit in output[] 
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	// Build the output array 
	for (i = sizeArray - 1; i >= 0; i--)
	{
		output[count[(usingArray[i] / exp) % 10] - 1] = usingArray[i];
		count[(usingArray[i] / exp) % 10]--;
	}

	// Copy the output array to usingArray[], so that usingArray[] now 
	// contains sorted numbers according to current digit 
	for (i = 0; i < sizeArray; i++)
		usingArray[i] = output[i];
}

void Sort::Radix(int usingArray[], int sizeArray)
{
	// Find the maximum number to know number of digits
		int m = getMax(usingArray, sizeArray);

	// Do countSort sort for every digit. Note that instead 
	// of passing digit number, exp is passed. exp is 10^i 
	// where i is current digit number 
		for (int i = 1; m / i > 0; i *= 10)
		{
			radixCountSort(usingArray, sizeArray, i);
		}
};