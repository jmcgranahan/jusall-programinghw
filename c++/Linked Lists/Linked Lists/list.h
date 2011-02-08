//list.h
#include "node.h"
#include <iostream>
#pragma once

template <class type>
class list
{
	node<type> * head;
	node<type> * tail;
	node<type> * current;
	int iCurrent, length;

public:

	list(void)
	{
		head = NULL;
		tail = NULL;
		current = NULL;
		iCurrent = 0;
		length = 0;
	}

	~list(void)
	{
		while(head)
		{
			node<type> * pTemp = head;
			head = head->getNext();
			delete pTemp;
		}
	}

	void push(const type & item)
	{
		node<type> * pTemp = head;
		head = new node<type>(item,pTemp);
		if(pTemp)
			pTemp->setPrev(head);
		else
			tail = head;
		current = head;
		iCurrent = 0;
		length++;
	}

	void append(const type & item)
	{
		node<type> * pTemp = tail;
		tail = new node<type>(item);
		tail->setPrev(pTemp);
		if(pTemp)
			pTemp->setNext(tail);
		else
			head = tail;
		current = tail;
		iCurrent = length;
		length++;
	}

	void insert(const type & item,int index)
	{
		current = head;
		iCurrent = 0;

		if(index >= length)
			this->append(item);
		else if(index == 0)
			this->push(item);
		else
		{
			while( iCurrent < index )
			{
				iCurrent++;
				current = current->getNext();
			}
			node<type>* pBefore = current->getPrev();
			node<type>* newNode = new node<type>(item,current,pBefore);
		
			if(pBefore)
				pBefore->setNext(newNode);
			current->setPrev(newNode);
			current = newNode;			
		}
	}

	node<type> * getHead(void)
	{
		return head;
	}

	node<type> * at(int i)
	{
		current = head;
		while (i > 0)
		{
			current = current->getNext();
			i--;
		}
		return current;
	}

	int getLength(void)
	{
		return length;
	}

	
};

