//queue.h
#include "node.h"
#include <iostream>
#pragma once

template <class type>
class queue
{
	node<type> * front;
	node<type> * back;
	int length;

public:

	queue(void)
	{
		back = NULL;
		front = NULL;
		length = 0;
	}

	~queue(void)
	{
		while(front)
		{
			node<type> * pTemp = front;
			front = back->getPrev();
			delete pTemp;
		}
	}

	void append(const type & item)
	{
		node<type> * pTemp = back;
		back = new node<type>(item);
		if(pTemp) 
			pTemp->setPrev(back);
		else
			front = back;
		length++;
	}

	type remove(void)
	{
		if( !front )
			return 0;
		node<type> * pTemp = front;
		front = pTemp->getPrev();
		type data = pTemp->getData();

		length--;
		delete pTemp;
		return data;
	}

	type peak(void)
	{
		if( front )
			return front->getData();
		return 0;
	}

	int getLength(void)
	{
		return length;
	}

	void print(void)
	{
		while( length )
			cout << remove() ;
		cout << endl;
	}
	
};

