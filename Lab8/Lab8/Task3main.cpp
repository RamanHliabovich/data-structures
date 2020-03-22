#include <iostream>
#include <string>
#include <algorithm>
#include <chrono>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <time.h>
#include "MaxHeap.h"
#include "PriorityQueue.h"

using namespace std;

// menu statements
int intMenu1;
int intMenu2;
bool skip = false;
typedef std::chrono::high_resolution_clock Clock;
bool exitProgram = false;

// using variables
int testSize;
PriorityQueue pq;
MaxHeap mh = true;

// vector pass random array into test functions
vector<int> test;

using namespace std;

int main()
{
	do {
		if (!skip)
		{
			menu:
			cout << " Select an option: \n 1. PriorityQueue \n 2. Max Heap \n 3. Exit \n\n Enter: ";
			cin >> intMenu1;

			cout << "\n Select amount to test: \n 1. 500 \n 2. 1000 \n 3. 2000 \n 4. 5000 \n 5. 20000 \n\n Enter: ";
			cin >> intMenu2;

			if (intMenu2 == 1)
			{
				testSize = 500;
			}
			if (intMenu2 == 2)
			{
				testSize = 1000;
			}
			if (intMenu2 == 3)
			{
				testSize = 2000;
			}
			if (intMenu2 == 4)
			{
				testSize = 5000;
			}
			if (intMenu2 == 5)
			{
				testSize = 20000;
			}

			//create random unique vector of testSize
			srand(unsigned(time(0)));

			for (int i = 1; i <= testSize; i++)
				test.push_back(i);

			random_shuffle(test.begin(), test.end());
		}
		else
		{
			cout << "\n\n Select another test(w/ same array): \n 1. PriorityQueue \n 2. Max Heap \n 3. Exit \n 4. Reset Array/Menu \n\n Enter: ";
			cin >> intMenu1;
		}

		switch (intMenu1)
		{
			case 1:
			{
				auto t1 = Clock::now();
				for (int i = 1; i <= testSize; i++)
					pq.Insert(i);
				auto t2 = Clock::now();

				auto t3 = Clock::now();
				for (int i = 1; i <= testSize; i++)
					pq.Remove();
				auto t4 = Clock::now();

				cout << "\n\n PRIORITY QUEUE RESULTS      SIZE: " << testSize;

				cout << "\n\n Insert Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t2 - t1).count() << " nanoseconds" << std::endl;
				cout << "\n Delete Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t4 - t3).count() << " nanoseconds" << std::endl;
				break;

			}
			case 2:
			{
				auto t5 = Clock::now();
				for (int i = 1; i <= testSize; i++)
					mh.Insert(i);
				auto t6 = Clock::now();

				auto t7 = Clock::now();
				for (int i = 1; i <= testSize; i++)
					mh.Remove(i);
				auto t8 = Clock::now();

				cout << "\n\n MAX HEAP RESULTS      SIZE: " << testSize;

				cout << "\n\n Insert Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t6 - t5).count() << " nanoseconds" << std::endl;
				cout << "\n Delete Time: " << std::chrono::duration_cast<std::chrono::nanoseconds>(t8 - t7).count() << " nanoseconds" << std::endl;
				break;
			}
			case 3:
			{
				exitProgram = true;
				cout << "\n\n Exiting program...";
				break;
			}
			case 4:
			{
				cout << "\n";
				goto menu;
			}
		}
		skip = true;
	} while (!exitProgram);
}