#include <iostream>
#include <cstdlib>
#include "Graph.h"
using namespace std;

int menuResult;
bool exitProgram = false;
bool menuBool;
int i;
int j;
int maxSize;

int main()
{
	cout << "Enter max size of graph (only be able to enter values 0 to your answer): ";
	cin >> maxSize;
	Graph graph = maxSize;
	do
	{
		cout << "\n Select an option: \n 1. Add Edge \n 2. Remove Edge \n 3. Find Edge \n 4. Find Out Edge of a Vertice \n 5. Find In Edge of a Vertice \n 6. Exit \n 7. Print (Ignore) \n\n Enter: ";
		cin >> menuResult;

		switch (menuResult)
		{
			case 1:
			{
				cout << "\n Enter i: ";
				cin >> i;
				cout << "\n Enter j: ";
				cin >> j;
				if (i > maxSize || i < 0 || j > maxSize || j < 0)
				{
					cout << "\n Outside of parameters \n";
					break;
				}
				graph.addEdge(i, j);
				break;
			}
			case 2:
			{
				cout << "\n Enter i: ";
				cin >> i;
				cout << "\n Enter j: ";
				cin >> j;
				if (i > maxSize || i < 0 || j > maxSize || j < 0)
				{
					cout << "\n Outside of parameters \n";
					break;
				}
				graph.removeEdge(i, j);
				break;
			}
			case 3:
			{
				cout << "\n Enter i: ";
				cin >> i;
				cout << "\n Enter j: ";
				cin >> j;
				if (i > maxSize || i < 0 || j > maxSize || j < 0)
				{
					cout << "\n Outside of parameters \n";
					break;
				}
				menuBool = graph.hasEdge(i, j);
				if (menuBool)
					cout << "\n This edge exists. \n";
				else
					cout << "\n This edge does not exist \n";
				break;
			}
			case 4:
			{
				cout << "\n Enter i: ";
				cin >> i;
				if (i > maxSize || i < 0)
				{
					cout << "\n Outside of parameters \n";
					break;
				}
				graph.outEdges(i);
				break;
			}

			case 5:
			{
				cout << "\n Enter i: ";
				cin >> i;
				if (i > maxSize || i < 0)
				{
					cout << "\n Outside of parameters \n";
					break;
				}
				graph.inEdges(i);
				break;
			}
			case 6:
			{
				exitProgram = true;
				break;
			}
			case 7:
			{
				graph.printGraph();
				break;
			}
		}
	} while (!exitProgram);
}