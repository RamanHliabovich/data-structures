#include <iostream>
#include <cstdlib>
#include "Graph.h"
using namespace std;

int menuResult;
bool exitProgram = false;
bool menuBool;
int i;
int j;
int maxSize = 50;

int main()
{
	Graph graph = maxSize;

	cout << "Creating graph of state boundries...";

	graph.addEdge(1, 2);
	graph.addEdge(1, 5);
	graph.addEdge(2, 1);
	graph.addEdge(2, 3);
	graph.addEdge(2, 4);
	graph.addEdge(2, 5);
	graph.addEdge(3, 2);
	graph.addEdge(3, 4);
	graph.addEdge(3, 9);
	graph.addEdge(4, 2);
	graph.addEdge(4, 3);
	graph.addEdge(4, 5);
	graph.addEdge(4, 8);
	graph.addEdge(4, 9);
	graph.addEdge(5, 1);
	graph.addEdge(5, 2);
	graph.addEdge(5, 3);
	graph.addEdge(5, 4);
	graph.addEdge(5, 6);
	graph.addEdge(5, 7);
	graph.addEdge(5, 8);
	graph.addEdge(6, 5);
	graph.addEdge(6, 7);
	graph.addEdge(6, 16);
	graph.addEdge(6, 17);
	graph.addEdge(7, 5);
	graph.addEdge(7, 6);
	graph.addEdge(7, 8);
	graph.addEdge(7, 10);
	graph.addEdge(7, 15);
	graph.addEdge(7, 16);
	graph.addEdge(7, 17);
	graph.addEdge(8, 4);
	graph.addEdge(8, 5);
	graph.addEdge(8, 7);
	graph.addEdge(8, 9);
	graph.addEdge(8, 10);
	graph.addEdge(8, 11);
	graph.addEdge(9, 3);
	graph.addEdge(9, 4);
	graph.addEdge(9, 8);
	graph.addEdge(9, 10);
	graph.addEdge(9, 11);
	graph.addEdge(10, 7);
	graph.addEdge(10, 8);
	graph.addEdge(10, 9);
	graph.addEdge(10, 11);
	graph.addEdge(10, 12);
	graph.addEdge(10, 13);
	graph.addEdge(10, 14);
	graph.addEdge(10, 15);
	graph.addEdge(11, 9);
	graph.addEdge(11, 8);
	graph.addEdge(11, 10);
	graph.addEdge(11, 13);
	graph.addEdge(11, 12);
	graph.addEdge(12, 11);
	graph.addEdge(12, 13);
	graph.addEdge(12, 21);
	graph.addEdge(12, 22);
	graph.addEdge(13, 10);
	graph.addEdge(13, 11);
	graph.addEdge(13, 12);
	graph.addEdge(13, 14);
	graph.addEdge(13, 20);
	graph.addEdge(13, 21);
	graph.addEdge(14, 10);
	graph.addEdge(14, 15);
	graph.addEdge(14, 20);
	graph.addEdge(14, 13);
	graph.addEdge(15, 7);
	graph.addEdge(15, 16);
	graph.addEdge(15, 19);
	graph.addEdge(15, 20);
	graph.addEdge(15, 14);
	graph.addEdge(15, 10);
	graph.addEdge(16, 7);
	graph.addEdge(16, 18);
	graph.addEdge(16, 6);
	graph.addEdge(16, 17);
	graph.addEdge(16, 19);
	graph.addEdge(16, 15);
	graph.addEdge(17, 6);
	graph.addEdge(17, 16);
	graph.addEdge(17, 18);
	graph.addEdge(18, 17);
	graph.addEdge(18, 34);
	graph.addEdge(18, 19);
	graph.addEdge(19, 20);
	graph.addEdge(19, 15);
	graph.addEdge(19, 16);
	graph.addEdge(19, 18);
	graph.addEdge(19, 34);
	graph.addEdge(19, 33);
	graph.addEdge(20, 15);
	graph.addEdge(20, 19);
	graph.addEdge(20, 33);
	graph.addEdge(20, 20);
	graph.addEdge(20, 14);
	graph.addEdge(21, 20);
	graph.addEdge(21, 12);
	graph.addEdge(21, 22);
	graph.addEdge(21, 23);
	graph.addEdge(21, 31);
	graph.addEdge(22, 23);
	graph.addEdge(22, 21);
	graph.addEdge(22, 12);
	graph.addEdge(23, 22);
	graph.addEdge(23, 21);
	graph.addEdge(23, 31);
	graph.addEdge(23, 24);
	graph.addEdge(24, 23);
	graph.addEdge(24, 31);
	graph.addEdge(24, 26);
	graph.addEdge(25, 24);
	graph.addEdge(25, 26);
	graph.addEdge(26, 24);
	graph.addEdge(26, 31);
	graph.addEdge(26, 27);
	graph.addEdge(26, 25);
	graph.addEdge(27, 28);
	graph.addEdge(27, 26);
	graph.addEdge(28, 29);
	graph.addEdge(28, 31);
	graph.addEdge(28, 27);
	graph.addEdge(29, 48);
	graph.addEdge(29, 30);
	graph.addEdge(29, 32);
	graph.addEdge(29, 31);
	graph.addEdge(29, 28);
	graph.addEdge(30, 37);
	graph.addEdge(30, 38);
	graph.addEdge(30, 48);
	graph.addEdge(30, 29);
	graph.addEdge(30, 32);
	graph.addEdge(31, 32);
	graph.addEdge(31, 29);
	graph.addEdge(31, 28);
	graph.addEdge(31, 26);
	graph.addEdge(31, 24);
	graph.addEdge(31, 23);
	graph.addEdge(31, 21);
	graph.addEdge(31, 20);
	graph.addEdge(31, 32);
	graph.addEdge(32, 35);
	graph.addEdge(32, 37);
	graph.addEdge(32, 30);
	graph.addEdge(32, 29);
	graph.addEdge(32, 31);
	graph.addEdge(32, 20);
	graph.addEdge(32, 33);
	graph.addEdge(33, 34);
	graph.addEdge(33, 19);
	graph.addEdge(33, 20);
	graph.addEdge(33, 32);
	graph.addEdge(33, 35);
	graph.addEdge(34, 18);
	graph.addEdge(34, 19);
	graph.addEdge(34, 33);
	graph.addEdge(34, 36);
	graph.addEdge(35, 36);
	graph.addEdge(35, 37);
	graph.addEdge(35, 32);
	graph.addEdge(35, 33);
	graph.addEdge(36, 37);
	graph.addEdge(36, 35);
	graph.addEdge(36, 34);
	graph.addEdge(37, 36);
	graph.addEdge(37, 35);
	graph.addEdge(37, 32);
	graph.addEdge(37, 30);
	graph.addEdge(37, 38);
	graph.addEdge(38, 39);
	graph.addEdge(38, 37);
	graph.addEdge(38, 48);
	graph.addEdge(38, 30);
	graph.addEdge(38, 46);
	graph.addEdge(38, 47);
	graph.addEdge(39, 40);
	graph.addEdge(39, 43);
	graph.addEdge(39, 45);
	graph.addEdge(39, 46);
	graph.addEdge(39, 38);
	graph.addEdge(40, 39);
	graph.addEdge(40, 41);
	graph.addEdge(40, 43);
	graph.addEdge(41, 40);
	graph.addEdge(41, 42);
	graph.addEdge(41, 43);
	graph.addEdge(42, 41);
	graph.addEdge(43, 41);
	graph.addEdge(43, 40);
	graph.addEdge(43, 39);
	graph.addEdge(43, 44);
	graph.addEdge(43, 45);
	graph.addEdge(44, 43);
	graph.addEdge(44, 45);
	graph.addEdge(45, 39);
	graph.addEdge(45, 43);
	graph.addEdge(45, 44);
	graph.addEdge(46, 38);
	graph.addEdge(46, 39);
	graph.addEdge(46, 47);
	graph.addEdge(47, 46);
	graph.addEdge(47, 38);
	graph.addEdge(47, 48);
	graph.addEdge(48, 47);
	graph.addEdge(48, 38);
	graph.addEdge(48, 30);
	graph.addEdge(48, 29);
	graph.addEdge(49, 0);
	graph.addEdge(50, 0);

	cout << "\n Done! \n";

	do
	{
		cout << "\n Select an option: \n 1. Find an edge \n 2. Find the out edges of a vertices \n 3. Find the in edges of a vertices \n 4. Exit \n\n Enter: ";
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
				menuBool = graph.hasEdge(i, j);
				if (menuBool)
					cout << "\n This edge exists. \n";
				else
					cout << "\n This edge does not exist \n";
				break;
			}
			case 2:
			{
				cout << "\n Enter i: ";
				cin >> i;
				if (i > maxSize || i < 0)
				{
					cout << "\n Outside of parameters \n";
					break;
				}
				graph.outEdges(i);
				cout << "\n";
				break;
			}

			case 3:
			{
				cout << "\n Enter i: ";
				cin >> i;
				if (i > maxSize || i < 0)
				{
					cout << "\n Outside of parameters \n";
					break;
				}
				graph.inEdges(i);
				cout << "\n";
				break;
			}
			case 4:
			{
				exitProgram = true;
				break;
			}
		}
	}
	while (!exitProgram);
}