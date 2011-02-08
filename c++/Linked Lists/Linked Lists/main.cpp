//main.cpp
#include <iostream>
#include "node.h"
#include "list.h"
#include <string>
using namespace std;

void breakLine()
{
	cout << "===============================================" << endl;
}

int main()
{
	/* Node Tests 
	node<string> nAString("test1");
	node<string> * nodeAPointer = &nAString;
	node<string> nBString("test2");
	node<string> * nodeBPointer = &nBString;
	node<string> nCString("test3");
	node<string> * nodeCPointer = &nCString;

	nAString.setNext(nodeBPointer);
	nBString.setPrev(nodeAPointer);
	nBString.setNext(nodeCPointer);
	nCString.setPrev(nodeBPointer);

	cout << "node pointer:" << nodeAPointer << endl;
	cout << "node data:" << nodeAPointer->getData() << endl;
	cout << "node next:" << nodeAPointer->getNext() << endl;
	cout << "node prev:" << nodeAPointer->getPrev() << endl;
	breakLine();
	cout << "node pointer:" << nodeBPointer << endl;
	cout << "node data:" << nodeBPointer->getData() << endl;
	cout << "node next:" << nodeBPointer->getNext() << endl;
	cout << "node prev:" << nodeBPointer->getPrev() << endl;
	breakLine();
	cout << "node pointer:" << nodeCPointer << endl;
	cout << "node data:" << nodeCPointer->getData() << endl;
	cout << "node next:" << nodeCPointer->getNext() << endl;
	cout << "node prev:" << nodeCPointer->getPrev() << endl;
	
	*/
	list<string> myList;
	node<string> * pointerList[10];

	for (int i = 0; i < 5 ; i++)
	{
		string nodeData;
		for (int n = 0 ; n < 5-i ;n++)
		{
			nodeData += "node";
		}
		myList.push(nodeData);
		pointerList[i] = myList.getHead();
	}

	for (int i = 0; i < 5 ; i++)
	{
		string nodeData;
		for (int n = 0 ; n < 5-i ;n++)
		{
			nodeData += "node";
		}
		myList.append(nodeData);
		pointerList[i] = myList.getHead();
	}
	
	for ( int i = 0; i < myList.getLength() ; i++)
	{
		myList.at(i)->print();
		breakLine();
		
	}

	cout << endl << endl << endl;

	myList.insert("OMG INSERT",5);

	for ( int i = 0; i < myList.getLength() ; i++)
	{
		myList.at(i)->print();
		breakLine();
	}

	system("PAUSE");
}