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


	for (int i = 0; i < 1500 ; i++)
	{
		string nodeData;
		for (int n = 0 ; n < i ;n++)
		{
			nodeData += ".";
		}
		myList.push(nodeData);
	}


	
	myList.insert("OMG INSERT",5);
	
	
	/*
	for ( int i = 0; i < myList.getLength() ; i++)
	{
		myList.at(i)->print();
		breakLine();
	}
	*/
	
	cout << "searching for OMG INSERT returned: " << myList.search("OMG INSERT") << endl;
	myList.remove(6);
	cout << "searching for OMG INSERT returned: " << myList.search("OMG INSERT") << endl;


	system("PAUSE");
}