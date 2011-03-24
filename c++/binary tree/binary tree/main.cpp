//main.cpp
#include <iostream>
#include "node.h"
#include "tree.h"
#include <string>
#include <ctime>

using namespace std;

void breakLine()
{
	cout << "===============================================" << endl;
}

int main()
{
	tree<int> _tree;
	_tree.Add(5);
	_tree.Add(3);
	_tree.Add(7);
	_tree.Add(4);
	_tree.Add(2);
	_tree.Add(6);
	_tree.Add(8);


	_tree.Remove(7);
	system("PAUSE");
}