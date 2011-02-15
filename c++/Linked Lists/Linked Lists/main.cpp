//main.cpp
#include <iostream>
#include "node.h"
#include "list.h"
#include <string>\
#include <ctime>

using namespace std;

void breakLine()
{
	cout << "===============================================" << endl;
}

int main()
{

	list<int> myList;
	int iInput;
	cout << "welcome to the josephus solver. Please enter the number of people in the group: ";
	cin >> iInput;

	for(int i = 0; i < iInput; i++)
		myList.append(i);

	for(int i = 0; i < myList.getLength(); i++)
		cout << myList.get(i) << ", ";

	cout << endl;

	cout << "And how many people to we skip?: ";
	cin >> iInput;

	for(int i = iInput-1; myList.getLength() > 1; i += iInput-1)
	{
		i = i % myList.getLength();
		cout << "killing " << myList.pop(i) << endl;
	}

	cout << "last alive: " << myList.pop(0) << endl;

	system("PAUSE");
}