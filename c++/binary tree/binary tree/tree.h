//tree.h
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include "node.h"

using namespace std;

#pragma once

template <class type>
class tree
{
public:
	node<type> * root;

	//=================================
	// default constructor
	//	Creates a binary tree class
	//=================================
	tree(void)
	{
		root = NULL;
	}

	//=================================
	// constructor(type data)
	//	Creates a binary tree class with the root initialied to inData.
	//	input: <treetype> data
	//=================================
	tree(const type & inData)
	{
		root = new node(inData);
	}

	//=================================
	// destructor
	//=================================
	~tree(void)
	{
		while(root) 
			Remove(root->getData());
	}

	//=================================
	// Add(type data)
	//	Adds a value to the tree, prints error if value exists.
	//	input: <treetype> data
	//=================================
	void Add(const type & inData)
	{
		if(!root)
		{
			root = new node<type>(inData);
			return;
		}

		node<type> * pTemp = root;

		while(pTemp)
		{
			//========Less========
			if(inData < pTemp->getData())
			{
				if(!pTemp->getLeft())
				{
					pTemp->setLeft(new node<type>(inData));
					pTemp = NULL;
				}
				else
					pTemp = pTemp->getLeft();
			}
			//========More========
			else if(inData > pTemp->getData())
			{
				if(!pTemp->getRight())
				{
					pTemp->setRight(new node<type>(inData));
					pTemp = NULL;
				}
				else
					pTemp = pTemp->getRight();
			}
			//========Already exists========
			else
			{
				cout << "Entry already exists in list and will not be added" << endl;
				pTemp = NULL;
			}
		}
	}

	//=================================
	// Remove(type data)
	//	Removes a value from the tree
	//	input: <treetype> data
	//=================================
	bool Remove(const type & inData)
	{
		if( !root->getLeft() && !root->getRight())
			delete root;

		node<type> * pTemp, * pTempBuffer ;
		pTempBuffer = pTemp = root;
		while( pTemp )
		{
			//========Found========
			if(pTemp->getData() == inData) break; 

			pTempBuffer = pTemp;
			//========Less========
			if(inData < pTemp->getData())
				pTemp = pTemp->getLeft();

			//========More========
			else 
				pTemp = pTemp->getRight();


		}

		if(!pTemp) 
		{
			//cout << "Item not found" << endl;
			return false;
		}

		node<type> * left, * right, * pTemp2;
		left = pTemp->getLeft();
		right = pTemp->getRight();

		if( left && right ) // two children
		{
			int leftDifference, rightDifference;
			leftDifference = pTemp->getData() - pTemp->getLeft()->getData();
			rightDifference = pTemp->getData() - pTemp->getRight()->getData();
			if(leftDifference > rightDifference) // attempt at picking best replacement
			{	
				pTemp2 = pTemp->getLeft();
				pTempBuffer = pTemp;

				while(pTemp2->getRight())
				{
					pTempBuffer = pTemp2;
					pTemp2 = pTemp2->getRight();
				}

				pTemp->setData(pTemp2->getData());
				if(pTempBuffer != pTemp)
					pTempBuffer->setRight(pTemp2->getLeft());
				else 
					pTempBuffer->setLeft(NULL);

				delete pTemp2;
			}

			else {	
				pTemp2 = pTemp->getRight();
				pTempBuffer = pTemp;

				while(pTemp2->getLeft())
				{
					pTempBuffer = pTemp2;
					pTemp2 = pTemp2->getLeft();
				}

				pTemp->setData(pTemp2->getData());
				if(pTempBuffer != pTemp)
					pTempBuffer->setLeft(pTemp2->getRight());
				else 
					pTempBuffer->setRight(NULL);

				delete pTemp2;
			}

			return true;
		}

		else if ( left ) // one smaller child
		{
			if(inData < pTempBuffer->getData())
				pTempBuffer->setLeft(left);

			else 
				pTempBuffer->setRight(left);
		}

		else if ( right ) //  one larger child
		{
			if(inData < pTempBuffer->getData())
				pTempBuffer->setLeft(right);

			else 
				pTempBuffer->setRight(right);
		}

		delete pTemp;

		return true;
	}

	//=================================
	// Search(type data)
	//	Searches for a value in the tree and prints out information
	//	input: <treetype> data
	//	output: bool - true if found
	//=================================
	bool Search(const type & inData)
	{
		node<type> * pTemp, * pTempBuffer ;
		int data;
		pTemp = root;
		data = pTemp->getData();
		while(pTemp && data != inData)
		{
			pTempBuffer = pTemp;

			//========Less========
			if(inData < data)
				pTemp = pTemp->getLeft();

			//========More========
			else
				pTemp = pTemp->getRight();

			if(pTemp) 
				data = pTemp->getData();
		}

		if(!pTemp) 
		{
			cout << inData << " not found in tree, failed at " << pTempBuffer->getData() << " in node: " << pTempBuffer << endl;
			return false;
		}

		cout << "Found: " << data << " in node: " << pTemp << ", with parent: " << pTempBuffer->getData() << " in node: " << pTempBuffer << endl;
		return true;
	}

	//=================================
	// Print
	//	Prints the tree from left to right
	//=================================
	void Print()
	{
		PrintNode(root);
		cout << endl;
	}

	//=================================
	// PrintNode(node * node)
	//	Recursive print function for print(), prints left child, the current node, and the right child
	//	input: node * node
	//=================================
	void PrintNode( node<type> * pInput)
	{
		if(!pInput) return;
		PrintNode(pInput->getLeft());
		cout << " " << pInput->getData();
		PrintNode(pInput->getRight());

	}

	//=================================
	// PrintTraversal
	//	Starts the recursive printing ofthe traversals for the entire tree
	//=================================
	void PrintTraversal()
	{
		PrintTraversal(root);
	}

	//=================================
	// PrintTraversal(node * node)
	//	Recursive print used by PrintTraversal, pringing the current node and the left and the right nodes
	//	input: node * node
	//=================================
	void PrintTraversal(node<type> * pNode)
	{
		if(pNode == NULL) pNode = root;
		cout << "Node: " << pNode->getData();

		if(pNode->getLeft()) 
			cout << " Left: " << pNode->getLeft()->getData();
		if(pNode->getRight())
			cout << " Right: " << pNode->getRight()->getData();
		cout << endl;
		if(pNode->getLeft()) 
			PrintTraversal(pNode->getLeft());
		if(pNode->getRight())
			PrintTraversal(pNode->getRight());
	}

	//=================================
	// InputFromFile(fstream file)
	//	Inputs the information in the file to the tree
	//	input: fstream file
	//=================================
	void InputFromFile( /*ifstream file*/ )
	{			
		/*if(file.is_open())
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
						this->Add(sum);
						word = "";
					}
					else
						word.push_back(line[i]);
				}
			}
			//file.close();
		}
		else cout << "failed to open file" << endl;

		*/
	}

};

