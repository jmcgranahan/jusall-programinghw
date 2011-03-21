//main.cpp
#include <iostream>
#include "node.h"
#include "list.h"
#include <string>
#include <ctime>

using namespace std;

void breakLine()
{
	cout << "===============================================" << endl;
}

int main()
{

	
	list<int> myList2;
	int iInput = 0;
	clock_t timeBefore,timeAfter;
	srand(time(NULL));

	while(iInput >= 0)
	{
		list<int> myList;
		cout << "How many values do you want: ";
		cin >> iInput;

		for(int i = 0; i < iInput; i++)
			myList.append(rand() % 30);

		for(int i = 0; i < myList.getLength(); i++)
			cout << myList.get(i) << ", ";
		cout << endl;
		/*
		for(int i = 0; i < iInput; i++)
			myList2.append(rand() % 30);


		for(int i = 0; i < myList.getLength(); i++)
			cout << myList.get(i) << ", ";
		cout << endl;
		for(int i = 0; i < myList2.getLength(); i++)
			cout << myList2.get(i) << ", ";
		cout << endl;

		list<int> buffer;
		
		buffer.cat(&myList,31,&myList2);

		for(int i = 0; i < buffer.getLength(); i++)
			cout << buffer.get(i) << ", ";
		cout << endl;
		for(int i = 0; i < myList.getLength(); i++)
			cout << myList.get(i) << ", ";
		cout << endl;
		for(int i = 0; i < myList2.getLength(); i++)
			cout << myList2.get(i) << ", ";
		cout << endl;
		*/
		
		cout << endl << "now sorting the list..." << endl;
		timeBefore = clock();
		myList.quickSort();
		timeAfter = clock();

		for(int i = 0; i < myList.getLength(); i++)
			cout << myList.get(i) << ", ";
		cout << endl << endl << "list sorted in " << (float)(timeAfter-timeBefore)/CLOCKS_PER_SEC << " secconds" << endl;
		system("PAUSE");
	}
}