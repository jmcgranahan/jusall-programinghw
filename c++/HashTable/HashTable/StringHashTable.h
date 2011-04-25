#pragma once
#include <string>
#include "list.h"

using namespace std;

class StringHashTable
{
	list<string> *Table;
	int size, capacity;

public:
	StringHashTable(void);
	StringHashTable(int capacity);
	~StringHashTable(void);

	int GetSize();
	int Hash(string inString);
	void Add(string inString);
	bool Remove(string inString);
	bool Find(string inString);
	void Print(int numberOfElements = 1);
};

