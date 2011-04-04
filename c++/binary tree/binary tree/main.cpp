//main.cpp
#include <iostream>
#include <fstream>
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
	fstream file;
	_tree.Add(7);
	_tree.Add(4);
	_tree.Add(11);
	_tree.Add(2);
	_tree.Add(1);
	_tree.Add(3);
	_tree.Add(6);
	_tree.Add(5);
	_tree.Add(8);
	_tree.Add(14);
	_tree.Add(12);
	_tree.Add(13);
	_tree.Add(9);
	file.open("input.txt");
	_tree.InputFromFile(file);
	 
	_tree.Print();
	/*
	_tree.PrintTransversal();
	
	_tree.Search(4);
	_tree.Search(99);
	_tree.Search(0);
	*/
	system("PAUSE");
}