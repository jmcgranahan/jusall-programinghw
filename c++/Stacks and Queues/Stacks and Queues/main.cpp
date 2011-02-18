//main.cpp
#include <iostream>
#include "node.h"
#include "stack.h"
#include "queue.h"


using namespace std;

void breakLine()
{
	cout << "===============================================" << endl;
}

int main()
{
	stack<int> myStack;
	queue<int> myQueue;

	for(int i = 0; i < 10; i++)
	{
		cout << "adding " << i+1 << " to the stack" << endl;
		myStack.push(i+1);
	}

	breakLine();

	for(int i = 0; i < 10; i++ )
	{
		cout << "poping from list: " << myStack.pop() << endl;
	}

	breakLine();
	breakLine();

	for(int i = 0; i < 10; i++)
	{
		cout << "adding " << i+1 << " to the queue" << endl;
		myQueue.append(i+1);
	}

	breakLine();

	for(int i = 0; i < 10; i++ )
	{
		cout << "removing from queue: " << myQueue.remove() << endl;
	}

	system("PAUSE");
}