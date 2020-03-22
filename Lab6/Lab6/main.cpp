#include <iostream>
#include <string>
#include "Tree.h"
#include "Node.h"
using namespace std;

Tree tree;
Node* Result;

string inString;
vector<string> resultVector;
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
		cout << " Select an option: \n 1. Insert \n 2. Find \n 3. Size \n 4. GetAllAscending \n 5. GetAllDescending \n 6. EmptyTree \n 7. Remove \n 8. EXIT";
		cout << "\n\n Enter: ";
		cin >> intMenu;

		switch (intMenu)
		{
		case 1: 
			cout << "\n Enter your new node value: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // this is to make getline work.
			getline(std::cin, inString);
			tree.Add(inString);
			break;
		case 2:
			if (tree.Size(tree.root) == 0)
			{
				cout << "\n Tree is empty. Please add a node.\n";
				break;
			}
			cout << "\n Enter value to find: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // this is to make getline work.
			getline(std::cin, inString);
			Result = tree.Find(inString);
			if (Result != NULL)
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
			if (tree.root == NULL)
			{
				cout << "\n List is empty\n";
				break;
			}
			intResult = tree.Size(tree.root);
			cout << "\n Size of Tree: " << intResult << "\n";
			break;
		case 4:
			if (tree.Size(tree.root) == 0)
			{
				cout << "\n Tree is empty. Please add a node.\n";
				break;
			}
			resultVector = tree.GetAllAscendingStart(tree.root);
			cout << "\n";
			for (int i = 0; i < tree.Size(tree.root); i++)
			{
				cout << " " << i + 1 << ". " << resultVector[i] << "\n";
			}
			tree.treeResultVector.clear();
			resultVector.clear();
			break;
		case 5:
			if (tree.Size(tree.root) == 0)
			{
				cout << "\n Tree is empty. Please add a node.\n";
				break;
			}
			resultVector = tree.GetAllDescendingStart(tree.root);
			cout << "\n";
			j = 1;
			for (int i = tree.Size(tree.root); i > 0; i--)
			{
				cout << " " << j << ". " << resultVector[i-1] << "\n";
				j++;
			}
			tree.treeResultVector.clear();
			resultVector.clear();
			break;
		case 6:
			if (tree.Size(tree.root) == 0)
			{
				cout << "\n Tree already empty.\n";
				break;
			}
			tree.EmptyTree(tree.root);
			cout << "\n Tree Emptied \n";
			break;
		case 7:
			if (tree.Size(tree.root) == 0)
			{
				cout << "\n Tree is empty. Please add a node.\n";
				break;
			}
			cout << "\n Select value to remove: ";
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // this is to make getline work.
			getline(std::cin, inString);
			tree.Delete(tree.root, inString);
			cout << " \n Node removed. \n";
			break;
		case 8:
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
