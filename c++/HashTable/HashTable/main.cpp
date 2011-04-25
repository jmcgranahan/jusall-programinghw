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
	int const NUM_OF_STRINGS = 1000000; 
	int const SIZE_OF_TABLE  = 1000000; // Why Not?

	clock_t timeBefore,timeAfter;
	srand((unsigned int)time(NULL));


	StringHashTable Table(SIZE_OF_TABLE);
	list<string> list;


	cout << "Hash testing" << endl;
	cout << "hasing test:" << Table.Hash("test") << endl;
	cout << "hasing tset:" << Table.Hash("tset") << endl;
	cout << "hasing sett:" << Table.Hash("sett") << endl;
	cout << "hasing ttse:" << Table.Hash("ttse") << endl;
	cout << "hasing ttes:" << Table.Hash("ttes") << endl;
	BreakLine();
	cout << "hasing god:" << Table.Hash("god") << endl;
	cout << "hasing dog:" << Table.Hash("dog") << endl;
	cout << "hasing odg:" << Table.Hash("odg") << endl;
	cout << "hasing ogd:" << Table.Hash("ogd") << endl;
	cout << "hasing gdo:" << Table.Hash("gdo") << endl;
	cout << "hasing dgo:" << Table.Hash("dgo") << endl;
	BreakLine();
	cout << "hasing ab:" << Table.Hash("ab") << endl;
	cout << "hasing ba:" << Table.Hash("ba") << endl;
	BreakLine();
	BreakLine();


	cout << "initializing table...\n";

	for ( int i = 0; i < NUM_OF_STRINGS; i++)
	{
		int stringLength = 10;//rand() % 10 +5;
		string randomString;
		
		for ( int j = 0; j < stringLength; j++)
			randomString +=(char) (rand() % 94)+33;
		
		//cout << "Adding \"" << randomString << "\" to the table hashed to " << Table.Hash(randomString) << endl;
		Table.Add(randomString);
		list.append(randomString);
	}
	
	cout << "starting search" << endl;

	timeBefore = clock();
	for(int i = 0; i < NUM_OF_STRINGS; i++)
	{
		if( !Table.Find(list.get(i)))
		{
			cout << "BREAK! DIDN'T FIND " << list.get(i) << endl;
			break;
		}
	}
	timeAfter = clock();

	cout << "found all elements in " << (float)(timeAfter-timeBefore)/CLOCKS_PER_SEC  << "s\n";

	//Table.Print();

	system("PAUSE");
}