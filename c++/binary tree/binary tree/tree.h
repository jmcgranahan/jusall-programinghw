//tree.h
#include <iostream>
#include "node.h"
#pragma once

template <class type>
class tree
{
public:
	node<type> * root;


	tree(void)
	{
		root = NULL;
	}

	tree(const type & inData)
	{
		root = new node(inData);
	}

	~tree(void)
	{
	}

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

	bool Remove(const type & inData)
	{
		node<type> * pTemp, * pTempBuffer ;
		pTemp = root;

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
			cout << "Item not found" << endl;
			return false;
		}

		node<type> * left, * right, * pTemp2;
		left = pTemp->getLeft();
		right = pTemp->getRight();

		if( left && right ) 
		{
			if((pTemp->getData() - pTemp->getLeft()->getData()) > (pTemp->getData() - pTemp->getRight()->getData()))
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

		else if ( left )
		{
			if(inData < pTempBuffer->getData())
				pTempBuffer->setLeft(left);
			
			else 
				pTempBuffer->setRight(left);
		}

		else if ( right )
		{
			if(inData < pTempBuffer->getData())
				pTempBuffer->setLeft(right);
			
			else 
				pTempBuffer->setRight(right);
		}

		delete pTemp;

		return true;
	}

	void Print()
	{
		PrintNode(root);
	}

	void PrintNode( node<type> * pInput)
	{
		if(!pInput) return;
		PrintNode(pInput->getLeft());
		cout << " " << pInput->getData();
		PrintNode(pInput->getRight());
		
	}
};

