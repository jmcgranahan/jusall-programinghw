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
	ifstream file;
	bool run = true;

	while(run)
	{
		int choice;
		cout << "do you want to..\n";
		cout << "1. Add a value to the tree\n";
		cout << "2. Delete a value from the tree\n";
		cout << "3. Search for a value in the tree\n";
		cout << "4. View all traversals\n";
		cout << "5. Print Tree\n";
		cout << "6. Empty Tree\n";
		cout << "7. Input from File\n";
		cout << "0. Exit\n";

		cin >> choice;

		if( choice == 0 ) 
			run = false;

		else if( choice == 1 )
		{
			cout << "What value do you want to add?: ";
			cin >> choice;
			_tree.Add(choice);
			cout << endl << "Added " << choice << " to the list\n";
			_tree.Print();
		}

		else if( choice == 2 )
		{
			cout << "What value do you want to remove?: ";
			cin >> choice;
			if(_tree.Remove(choice))
				cout << endl << "Removed " << choice << " from the list\n";
			else
				cout << choice << " was not found in the tree\n";
			_tree.Print();
		}

		else if( choice == 3 )
		{
			cout << "What value do you want to search for?: ";
			cin >> choice;
			cout << endl;
			_tree.Search(choice);
		}

		else if( choice == 4 )
			_tree.PrintTraversal();

		else if( choice == 5 )
			_tree.Print();

		else if( choice == 6 )
		{
			while(_tree.root)
				_tree.Remove(_tree.root->getData());
		}

		else if( choice == 7 )
		{
			file.open("input.txt");
			if(file.is_open())
				_tree.InputFromFile();
			/*else
				cout << "couldn't open file\n";
				
			cout << "weird problem with function\n";
			file.close();*/
		}
		
		else
			cout << "0-7 please\n";
	
}

	//system("PAUSE");
};