#include <iostream>
#include "Tree.h"
#include <vector>
#include "Node.h"
#include <queue>
#define count 10
using namespace std;



Node* Tree::Find(int key)
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

//this is a recursive version of the find function, use either one you want
int Tree::FindR(int key, Node* t) //
{
	if (t == nullptr) throw "Not Found!";
	if (t->data == key) return t->data;
	if (t->data < key) return FindR(key, t->left);
	return FindR(key, t->left);
}


void Tree::Add(int key) // if the data you are adding is equal to the root than you can choose to put it either right or left, professor zimmer said it doesn't matter
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


//Node* Tree::Delete(Node* root, int key)
//{
//	if (root == nullptr) throw "Emptry tree Error"; // handles tree is empty case
//	if (Find(key) == nullptr) throw "Value not in tree Error"; // handles the not in tree condition
//
//	if (root == nullptr) return root;
//	else if (root->data > key) root->left = Delete(root->left, key);
//	else if (root->data < key) root->right = Delete(root->right, key);
//	else
//	{
//		//when the node to be deleted is found
//		//Four possibilities
//
//		//case1: When the node to be deleted has no children
//		if (root->left == nullptr && root->right == nullptr)
//		{
//			delete root;
//			root = nullptr;
//		}
//		//case2: When the node to be deleted has ONLY LEFT child
//		else if (root->right == nullptr)
//		{
//			Node* temp = root;
//			root = root->left;
//			delete temp;
//		}
//		//case3: When the node to be deleted has ONLY RIGHT child
//		else if (root->left == nullptr)
//		{
//			Node* temp = root;
//			root = root->right;
//			delete temp;
//		}
//		//case4: When the node to be deleted has TWO children
//		else
//		{
//			Node* maxNode = GetLargestSmaller(root->left);//finding the maximum in LEFT sub-tree
//			root->data = maxNode->data; //Overwriting the root node with MAX-LEFT
//			root->left = Delete(root->left, maxNode->data);//deleted the MAX-LEFT node
//		}
//		return root;
//	}
//}


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
	if (root == nullptr || emptyList == true)
	{
		return 0;
	}
	else
	{
		return(Size(root->left) + 1 + Size(root->right));
	}
}



// removes the root and all nodes connected to it
void Tree::EmptyTree(Node* root) {
	if (root != nullptr)
	{
		EmptyTree(root->left);
		EmptyTree(root->right);
		delete(root);
	}
	emptyList = true;
}



 //This functions converts an unbalanced BST to a balanced BST 
Node* Tree::buildTree(Node* root)
{
	// Store nodes of given BST in sorted order 
	vector<Node*> nodes;
	storeBSTNodes(root, nodes);

	// Constucts BST from nodes[] 
	int n = Tree::Size(root);
	return buildTreeUtil(nodes, 0, n - 1);
}


/* This function traverse the skewed binary tree and
   stores its nodes pointers in vector nodes[] */
void Tree::storeBSTNodes(Node* root, vector<Node*>& nodes)
{
	// Base case 
	if (root == nullptr)
		return;

	// Store nodes in Inorder (which is sorted 
	// order for BST) 
	storeBSTNodes(root->left, nodes);
	nodes.push_back(root);
	storeBSTNodes(root->right, nodes);
}

/* Recursive function to construct binary tree */
Node* Tree::buildTreeUtil(vector<Node*>& nodes, int start, int end)
{
	// base case 
	if (start > end)
		return nullptr;

	/* Get the middle element and make it root */
	int mid = (start + end) / 2;
	Node* root = nodes[mid];

	/* Using index in Inorder traversal, construct
	   left and right subtress */
	root->left = buildTreeUtil(nodes, start, mid - 1);
	root->right = buildTreeUtil(nodes, mid + 1, end);
	return root;
}





// Function to print binary tree in 2D  
// It does reverse inorder traversal  
void Tree::PrintIn2Dtool(Node* root, int space)
{
	// Base case  
	if (root == nullptr)
	{
		return;
	}
		

	space += count;// Increase distance between levels
	if (root->right != nullptr)
	{
		PrintIn2Dtool(root->right, space);// Process right child first
	}
		  

	// Print current node after space count  
	cout << endl;
	for (int i = count; i < space; i++)
		cout << " ";
	cout << root->data << "\n";

	// Process left child  
	if (root->left != nullptr)
	{
		PrintIn2Dtool(root->left, space);
	}
	
}

// Wrapper over print2DUtil()  
void Tree::PrintIn2D(Node* root)
{
	// Pass initial space count as 0  
	PrintIn2Dtool(root, 0);
}


/* Given a binary search tree and a key, this function deletes the key
   and returns the new root */
Node* Tree::Delete(Node* node, int k)
{
	// Base case 
	if (node == NULL)
		return node;

	// Recursive calls for ancestors of 
	// node to be deleted 
	if (node->data > k) {
		node->left = Delete(node->left, k);
		return node;
	}
	else if (node->data < k) {
		node->right = Delete(node->right, k);
		return node;
	}

	// We reach here when root is the node 
	// to be deleted. 

	// If one of the children is empty 
	if (node->left == NULL) {
		Node* temp = node->right;
		delete node;
		return temp;
	}
	else if (node->right == NULL) {
		Node* temp = node->left;
		delete node;
		return temp;
	}

	// If both children exist 
	else {

		if (k == this->root->data)// head case
		{
			Node* succParent = node->right;

			// Find successor 
			Node* succ = node->right;
			while (succ->left != NULL) {
				succParent = succ;
				succ = succ->left;
			}

			// Delete successor.  Since successor 
			// is always left child of its parent 
			// we can safely make successor's right 
			// right child as left of its parent. 
			succParent->left = succ->right;

			// Copy Successor Data to root 
			node->data = succ->data;

			// Delete Successor and return root 
			delete succ;
			succ = nullptr;
			return node;

		}
		else// two child not the head case
		{
			Node* succParent = root;

			// Find successor 
			Node* succ = root->right;
			while (succ->left != NULL) {
				succParent = succ;
				succ = succ->left;
			}

			// Delete successor. Since successor is always left child of its parent 
			// we can safely make successor's right right child as left of its parent. 
			succParent->left = succ->right;

			// Copy Successor Data to root 
			root->data = succ->data;

			// Delete Successor and return root 
			delete succ;
			succ = nullptr;
			return root;
		}
		
	}
}



// constructors
Tree::Tree() 
{
	this->root = nullptr;
	this->emptyList = false;
};


Tree::~Tree()
{
	EmptyTree(root);
}