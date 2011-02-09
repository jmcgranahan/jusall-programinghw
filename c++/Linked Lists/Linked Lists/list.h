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
	
	node<type> * getTail(void)
	{
		return tail;
	}

	type pop(int index)
	{
		current = head;
		iCurrent = 0;
		while (current && index > 0)
		{
			current = current->getNext();
			index--;
		}
		if( !current )
		{
			cout << "no object at index" << endl;
			return;
		}

		type data = current->getData();
		node<type> * pTemp = current;

		current = pTemp->getNext();
		pTemp->getNext()->setPrev(pTemp->getPrev());
		pTemp->getPrev()->setNext(pTemp->getNext());

		length--;
		delete pTemp;
		return data;
	}

	void remove(int index)
	{
		current = head;
		iCurrent = 0;
		while (current && index > 0)
		{
			current = current->getNext();
			index--;
			iCurrent++;
		}
		if( !current )
		{
			cout << "no objecct at index" << endl;
			return;
		}
		node<type> * pTemp = current;

		current = pTemp->getNext();
		pTemp->getNext()->setPrev(pTemp->getPrev());
		pTemp->getPrev()->setNext(pTemp->getNext());

		length--;
		delete pTemp;
	}

	node<type> * at(int index)
	{
		current = head;
		iCurrent = 0;
		while (current && index > 0)
		{
			current = current->getNext();
			index--;
		}
		if( current )
			return current;
		else 
			cout << "no objecct at index" << endl;
	}

	int search(const type & item)
	{
		current = head;
		iCurrent = 0;
		
		while( current && current->getData() != item )
		{
			iCurrent++;
			current = current->getNext();
		}
		if(current)
			return iCurrent;
		else
			return -1;
	}

	int getLength(void)
	{
		return length;
	}
	
};

