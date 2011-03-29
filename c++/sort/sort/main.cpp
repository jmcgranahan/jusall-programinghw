//main.cpp
#include <iostream>
#include <fstream>
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
	clock_t timeBefore,timeAfter;
	srand(time(NULL));
	fstream file;
	list<int> myFileList;
	

	file.open("NeedToSort.txt");
	if(file.is_open())
	{
		cout << "reading file to list..." << endl;
		while(file.good())
		{
			string line,word;
			getline(file,line);

			for( int i=0; i < line.length(); i++)
			{
				if(line[i] == ',') 
				{
					int sum = 0;
					for(int j = 0; j < word.length(); j++)
						sum += (int)(word[j]-48)*(pow((double)10,(double)word.length()-(j+1))); // multiplys the first digit by the appropriate power of 10
					myFileList.push(sum);
					word = "";
				}
				else
					word.push_back(line[i]);
			}
		}
	}
	else cout << "failed to open file" << endl;

	file.close();

	for(int i = 0; i < myFileList.getLength(); i++)
		cout << myFileList.get(i) << ", ";
	cout << endl;
	
	cout << "list generated... Sorting" << endl;
	myFileList.quickSort();
	
	for(int i = 0; i < myFileList.getLength(); i++)
		cout << myFileList.get(i) << ", ";
	cout << endl;

	cout << "list sorted, writing to Sorted.txt" << endl;
	
	file.open("Sorted.txt");
	if (file.is_open())
	{
		for(int i = 0; i < myFileList.getLength(); i++)
			file << myFileList.get(i) << ",";
		file.close();
	}
	else cout << "failed to open file" << endl;

//=========================================================================================
	while(true)
	{
		int iInput = 0;
		list<int> myList;
		cout << "How many values do you want (pass negitive to quit): ";
		cin >> iInput;
		
		if(iInput < 0) break;

		for(int i = 0; i < iInput; i++)
			myList.append(rand() % 30);

		for(int i = 0; i < myList.getLength(); i++)
			cout << myList.get(i) << ", ";
		cout << endl;
		
		cout << endl << "now sorting the list..." << endl;
		timeBefore = clock();
		myList.quickSort();
		timeAfter = clock();

		for(int i = 0; i < myList.getLength(); i++)
			cout << myList.get(i) << ", ";
		cout << endl << endl << "list sorted in " << (float)(timeAfter-timeBefore)/CLOCKS_PER_SEC << " secconds" << endl;
		system("PAUSE");
	}
}