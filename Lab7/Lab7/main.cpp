#include <iostream>
#include <string>
#include <vector>
#include "Tree.h"
#include "Node.h"


using namespace std;

Tree tree;
Node* Result;

int inData;
vector<int> resultVector;
int position;
int treeSize = 0;
int j;

int intMenu;
int intResult;
bool exitProgram = false;

int main()
{
	do {
		// simple menu that uses switch statement and each case uses different function.
	menu:
		cout << " Select an option: \n 1. Add \n 2. Find \n 3. Remove \n 4. Print Balanced \n 5. EXIT";
		cout << "\n\n Enter: ";
		cin >> intMenu;

		switch (intMenu)
		{
		case 1:
			cout << "\n Enter your new node value: ";
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // this is to make getline work.
			std::cin >> inData;
			tree.Add(inData);

			// these lines below balance the tree after a node has been added
			if (tree.Size(tree.root) == 0)
			{
				cout << "\n Tree is empty. Please add a node.\n";
				break;
			}
			tree.root = tree.buildTree(tree.root); // this line balances the binary tree
			break;
		case 2:
			if (tree.Size(tree.root) == 0)
			{
				cout << "\n Tree is empty. Please add a node.\n";
				break;
			}
			cout << "\n Enter value to find: ";
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // this is to make getline work.
			std::cin >> inData;
			Result = tree.Find(inData);
			if (Result != nullptr)
				cout << "\n Node Data: " << Result->data;
			else
			{
				cout << "\n Node not found \n";
				break;
			}
			if (Result->left != nullptr)
				cout << "\n Node Left: " << Result->left->data;
			else
				cout << "\n Node Left: Empty";
			if (Result->right != nullptr)
				cout << "\n Node Right: " << Result->right->data;
			else
				cout << "\n Node Right: Empty";
			cout << "\n";
			break;
		case 3:
			if (tree.Size(tree.root) == 0)
			{
				cout << "\n Tree is empty. Please add a node.\n";
				break;
			}
			cout << "\n Select value to remove: ";
			//cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // this is to make getline work.
			std::cin >> inData;
			tree.Delete(tree.root, inData);
			cout << " \n Node removed. \n";
			break;
		case 4:
			//print balanced binary tree stuff
			tree.PrintIn2D(tree.root);
			break;
		case 5:
			cout << "\n\n Exiting Program...\n";
			exitProgram = true;
			break;
		default:
			cout << "\n Incorrect option. Please try again.\n\n";
			goto menu;
			break;
		}
		cout << "\n";
	} while (!exitProgram);
}