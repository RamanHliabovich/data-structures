#include <iostream>
#include "Queue.h"
using namespace std;

//enters new value in queue
void Queue::Enqueue(char inVal)
{
	if ((end - front) >= 25)
	{
		cout << "The queue is full";
	}
	else
	{
		array[end] = inVal;
		end = (end + 1) % 25;
	}
}
//removes and returnes front value in queue if not empty
char Queue::Dequeue() {
	check = end - front;
	if (check == 0)
	{
		cout << "Nothing to dequeue";
	}
	else
	{
		retVal = array[0];
		for (int i = 0; i < end - 1; i++)
		{
			array[i] = array[i + 1];
		}
		array[end - 1] = '\0';
		end--;
	}
	return retVal;
}
//checks for full queue
void Queue::IsFull()
{
	check = end - front;
	if (check == 25)
	{
		cout << "The queue is full";
	}
	else
	{
		cout << "The queue is not full";
	}
}
//returns queue size
int Queue::Length()
{
	int retVal = end - front;
	return retVal;
}
//returns queue empty status
bool Queue::IsEmpty()
{
	int check = end - front;
	if (check == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}
//cout current queue
void Queue::PrintQueue(char print)
{
	cout << " " << print;
}