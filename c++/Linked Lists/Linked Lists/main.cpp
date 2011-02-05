//main.cpp
#include <iostream>
#include "node.h"
#include <string>
using namespace std;

int main()
{
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
	cout << "===============================================" << endl;
	cout << "node pointer:" << nodeBPointer << endl;
	cout << "node data:" << nodeBPointer->getData() << endl;
	cout << "node next:" << nodeBPointer->getNext() << endl;
	cout << "node prev:" << nodeBPointer->getPrev() << endl;
	cout << "===============================================" << endl;
	cout << "node pointer:" << nodeCPointer << endl;
	cout << "node data:" << nodeCPointer->getData() << endl;
	cout << "node next:" << nodeCPointer->getNext() << endl;
	cout << "node prev:" << nodeCPointer->getPrev() << endl;
	system("PAUSE");
}