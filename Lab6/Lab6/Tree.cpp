#include <iostream>
#include "Node.h"
#include "Tree.h"
using namespace std;

Node* Tree::Find(string key)
{
	Node* temp = root; // start at root which is beginning of the tree
	while (temp != nullptr && temp->data != key)
	{
		if (key > temp->data)
		{
			temp = temp->right;
		}
		else
		{
			temp = temp->left;
		}
	}
	return temp;
}

/* this is a recursive version of the find function, use either one you want
int Tree::FindR(string key, Node* t) //
{
	if (t == nullptr) throw "Not Found!";

	if (t->data == key) return t->data;

	if (t->data < key) return FindR(key, t->left);

	return FindR(key, t->left);
}
*/

void Tree::Add(string key) // if the data you are adding is equal to the root than you can choose to put it either right or left, professor zimmer said it doesn't matter
{
	if (emptyList)
	{
		root = nullptr;
		emptyList = false;
	}

	Node* temp = root;

	if (temp == nullptr)
	{
		root = new Node;
		root->data = key;
		root->left = nullptr;
		root->right = nullptr;
		return;
	}

	Node* temp2 = temp; // set temp2 equal to temp which sets it equal to the root because temp is pointing to root
	while (temp != nullptr)
	{
		temp2 = temp;
		if (key == temp->data)
		{
			return;
		}
		if (key > temp->data)
		{
			temp = temp->right;
		}
		else
		{
			temp = temp->left;
		}
	}
	if (temp2->data > key)
	{
		temp2->left = new Node;
		temp2->left->data = key;
		temp2->left->left = nullptr;
		temp2->left->right = nullptr;
	}
	else
	{
		temp2->right = new Node;
		temp2->right->data = key;
		temp2->right->left = nullptr;
		temp2->right->right = nullptr;
	}
}


Node* Tree::Delete(Node* root, string key)
{
	if (root == nullptr) throw "Emptry tree Error"; // handles tree is empty case
	if (Find(key) == nullptr) throw "Value not in tree Error"; // handles the not in tree condition

	if (root == NULL) return root;
	else if (root->data > key) root->left = Delete(root->left, key);
	else if (root->data < key) root->right = Delete(root->right, key);
	else
	{
		//when the node to be deleted is found
		//Four possibilities

		//case1: When the node to be deleted has no children
		if (root->left == NULL && root->right == NULL)
		{
			delete root;
			root = NULL;
		}
		//case2: When the node to be deleted has ONLY LEFT child
		else if (root->right == NULL)
		{
			Node* temp = root;
			root = root->left;
			delete temp;
		}
		//case3: When the node to be deleted has ONLY RIGHT child
		else if (root->left == NULL)
		{
			Node* temp = root;
			root = root->right;
			delete temp;
		}
		//case4: When the node to be deleted has TWO children
		else
		{
			Node* maxNode = GetLargestSmaller(root->left);//finding the maximum in LEFT sub-tree
			root->data = maxNode->data; //Overwriting the root node with MAX-LEFT
			root->left = Delete(root->left, maxNode->data);//deleted the MAX-LEFT node
		}
		return root;
	}
}


Node* Tree::GetLargestSmaller(Node* tempAdd)// go to the left once in the tree and then go all the way down right till you hit a null pointer and return that last value
{
	
	// temp is still equal to root so set temp equal to one node to the lower left and set temp2 equal to the lower right of the node temp is set equal to
	Node* traverse = tempAdd;

	if (traverse->left == nullptr)
	{
		return traverse;
	}
	traverse = traverse->left;

	if (traverse->right == nullptr)
	{
		return traverse;
	}
	else
	{
		while (traverse->right != nullptr)
		{
			if (traverse->data < traverse->right->data) // while the temp data value is less than the one to the lower 
			{
				traverse = traverse->right;
			}
			else
			{
				return traverse;
			}
		}
		if (traverse->right == nullptr)
		{
			return traverse;
		}
	}
}

// returns size based on null root/emptyList bool
int Tree::Size(Node* root)
{
	if (root == NULL || emptyList == true)
	{
		return 0;
	}
	else
	{
		return(Size(root->left) + 1 + Size(root->right));
	}
}

// display data ascending
vector<string> Tree::GetAllAscendingStart(Node* root)
{
	treeResultVector.clear();
	GetAllAscending(root);
	return treeResultVector;
}

void Tree::GetAllAscending(Node* root)
{
	if (root != NULL)
	{
		GetAllAscending(root->left);
		treeResultVector.push_back(root->data);
		GetAllAscending(root->right);
	}
}

// display data descending
vector<string> Tree::GetAllDescendingStart(Node* root)
{
	treeResultVector.clear();
	GetAllAscending(root);
	return treeResultVector;
}

void Tree::GetAllDescending(Node* root)
{
	if (root != NULL)
	{
		GetAllDescending(root->right);
		treeResultVector.push_back(root->data);
		GetAllDescending(root->left);
	}
}

// removes the root and all nodes connected to it
void Tree::EmptyTree(Node* root) {
	if (root != NULL)
	{
		EmptyTree(root->left);
		EmptyTree(root->right);
		delete(root);
		//if (root->left != NULL)
			//root->left = NULL;
		//if (root->right != NULL)
			//root->right = NULL;
		//root = NULL;
	}
	emptyList = true;
}

// constructors
Tree::Tree() {};


Tree::~Tree()
{
	EmptyTree(root);
}