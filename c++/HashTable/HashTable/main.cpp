//main.cpp
#include <iostream>
#include <fstream>
#include "StringHashTable.h"
#include "list.h"
#include <string>
#include <ctime>
#include <random>

using namespace std;

void BreakLine()
{
	cout << "===============================================" << endl;
}

int main()
{
	clock_t timeBefore,timeAfter;
	srand(time(NULL));


	StringHashTable Table(100000);
	list<string> list;


	cout << "Hash testing" << endl;
	cout << Table.Hash("test") << endl;
	cout << Table.Hash("tset") << endl;
	cout << Table.Hash("sett") << endl;
	cout << Table.Hash("ttse") << endl;
	cout << Table.Hash("ttes") << endl;
	BreakLine();
	cout << Table.Hash("god") << endl;
	cout << Table.Hash("dog") << endl;
	cout << Table.Hash("odg") << endl;
	cout << Table.Hash("ogd") << endl;
	cout << Table.Hash("gdo") << endl;
	cout << Table.Hash("dgo") << endl;
	BreakLine();
	BreakLine();
	cout << "initializing table...\n";
	for ( int i = 0; i < 75000; i++)
	{
		int stringLength = rand() % 10 +5;
		string randomString;
		
		for ( int j = 0; j < stringLength; j++)
			randomString +=(char) (rand() % 94)+33;
		
		//cout << "Adding \"" << randomString << "\" to the table hashed to " << Table.Hash(randomString) << endl;
		Table.Add(randomString);
		list.append(randomString);
	}
	
	cout << "starting search" << endl;
	timeBefore = clock();
	for(int i = 0; i < 75000; i++)
	{
		if( !Table.Find(list.get(i)))
		{
			cout << "BREAK! DIDN'T FIND " << list.get(i) << endl;
			break;
		}
	}
	timeAfter = clock();

	cout << "found all elements in " << (float)(timeAfter-timeBefore)/CLOCKS_PER_SEC  << "s\n";

	//Table.Print(3);

	system("PAUSE");
}