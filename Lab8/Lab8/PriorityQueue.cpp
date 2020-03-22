#include "PriorityQueue.h"

using namespace std;

void PriorityQueue::Insert(int data)
{
	if (head == NULL)
	{
		head = NewNode(data);
	}
	else
	{
		Node* start = head;

		// Create new Node 
		Node* temp = NewNode(data);

		// Special Case: The head of list has lesser 
		// priority than new node. So insert new 
		// node before head node and change head node. 
		if (head->data < data) {

			// Insert New Node before head 
			temp->next = head;
			head = temp;
		}
		else {

			// Traverse the list and find a 
			// position to insert new node 
			while (start->next != NULL &&
				start->next->data > data) {
				start = start->next;
			}

			// Either at the ends of the list 
			// or at required position 
			temp->next = start->next;
			start->next = temp;
		}
	}
}

int PriorityQueue::Remove()
{
	int data = head->data;

	Node* temp = head;
	head = head->next;
	free(temp);

	return data;
}

void PriorityQueue::PrintQueue()
{
	Node* temp = head;
	cout << "  ";
	while (temp->next != NULL)
	{
		cout << temp->data << "  ";
		temp = temp->next;
	}
	cout << temp->data << "\n";
}

PriorityQueue::Node* PriorityQueue::NewNode(int data)
{
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;
	temp->next = NULL;
	
	return temp;
}