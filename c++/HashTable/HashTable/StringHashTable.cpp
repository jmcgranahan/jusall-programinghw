#include "StringHashTable.h"
#include <string>
#include "list.h"

using namespace std;

StringHashTable::StringHashTable()
{
	Table = new list<string>[10];
	size = 0;
}

StringHashTable::StringHashTable(int inSize)
{
	capacity = inSize;
	Table = new list<string>[capacity];
	size = 0;
}

StringHashTable::~StringHashTable(void)
{
	delete [] Table;
}

int StringHashTable::GetSize(void)
{
	return size;
}

int StringHashTable::Hash(string inString)
{
	int hash = 1;
	for ( int i = 0; i < inString.length(); i++)
	{  
		hash += inString[i] * (42 * (i+1));
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	return hash % capacity;
}

void StringHashTable::Add(string inString)
{
	Table[ Hash(inString) ].append(inString);
	size++;
}

bool StringHashTable::Remove(string inString)
{
	int hash = Hash(inString);
	for ( int i = 0; i < Table[hash].getLength(); i++)
		if(Table[hash].get(i) == inString)
		{
			Table[hash].remove(i);
			size--;
			return true;
		}
	return false;
}

bool StringHashTable::Find(string inString)
{
	int hash = Hash(inString);
	for ( int i = 0; i < Table[hash].getLength(); i++)
		if(Table[hash].get(i) == inString)
			return true;
	return false;
}

void StringHashTable::Print(int numberOfElements )
{
	int elements = 0 ;
	for(int i = 0; i < capacity;i++)
	{
		if( Table[i].getLength() > numberOfElements)
		{
			cout << "hash: " << i;
			for(int j = 0; j < Table[i].getLength(); j++)
			{
				cout << " Element: " << Table[i].get(j);
				elements++;
			}
			cout << endl;
		}
	}
	cout << elements << endl;
}