#include "StringHashTable.h"
#include <string>
#include "list.h"

using namespace std;

//=================================
// default constructor
//	Creates a hash table with 100 elements 
//=================================
StringHashTable::StringHashTable()
{
	Table = new list<string>[100];
	size = 0;
}

//=================================
// Constructuor w/ specified size
//	input: int Size
//	Creats a table of inputed size
//=================================
StringHashTable::StringHashTable(int inSize)
{
	capacity = inSize;
	Table = new list<string>[capacity];
	size = 0;
}

//=================================
// Destructor
//	
//=================================
StringHashTable::~StringHashTable(void)
{
	delete [] Table;
}

//=================================
// GetSize
//	output: int Size
//	Returns the size of the table
//=================================
int StringHashTable::GetSize(void)
{
	return size;
}

//=================================
// Hash
//	input: string key
//	output: int hash
// Returns the hash value of the input string
//=================================
int StringHashTable::Hash(string inString)
{
	int hash = 1;
	for ( unsigned int i = 0; i < inString.length(); i++)
	{  
		hash += inString[i] * (13 * (i+1));
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}
	return hash % capacity;
}

//=================================
// Add
//	Input: string value
// Adds the input string to the table
//=================================
void StringHashTable::Add(string inString)
{
	Table[ Hash(inString) ].append(inString);
	size++;
}

//=================================
// Remove
//	input: string value
//  output: bool removed
// Atempts to remove the value from the table, if no value was found, returns false
//=================================
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

//=================================
// Find
//	input: string value
//	Output: bool Found
// Finds the vlaue in the bool, false if not found.
//=================================
bool StringHashTable::Find(string inString)
{
	int hash = Hash(inString);

	for ( int i = 0; i < Table[hash].getLength(); i++)
		if(Table[hash].get(i) == inString)
			return true;

	return false;
}

//=================================
// Print
//	input: int Number of elements per hash needed to print, defaults to 0
// Prints out the table, an input value will make it so there has to be atleast that many to be printed out ( collision detection )
//=================================
void StringHashTable::Print(int numberOfElements )
{
	int elements = 0 ;
	for(int i = 0; i < capacity;i++)
	{
		if( Table[i].getLength() >= numberOfElements)
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