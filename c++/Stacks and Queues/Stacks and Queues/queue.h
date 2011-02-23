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
	/******** Function: Constructor
	Inputs: none
	Output: none
	Description: Creates a new queue 
	********/
	queue(void)
	{
		back = NULL;
		front = NULL;
		length = 0;
	}
	
	/******** Function: Destructor
	Inputs: none
	Output: none
	Description: deletes queue 
	********/
	~queue(void)
	{
		while(front)
		{
			node<type> * pTemp = front;
			front = back->getPrev();
			delete pTemp;
		}
	}

	/******** Function: append
	Inputs: type data
	Output: none
	Description: adds the passed item to the end of the queue 
	********/
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

	/******** Function: remove
	Inputs: none
	Output: type
	Description: returns and removes the front item from the queue 
	********/
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

	/******** Function: peak
	Inputs: none
	Output: type
	Description: returns the value at the front of the queue without removing it 
	********/
	type peak(void)
	{
		if( front )
			return front->getData();
		return 0;
	}

	/******** Function: getLength
	Inputs: none
	Output: int
	Description: returns the length of the queue 
	********/
	int getLength(void)
	{
		return length;
	}

	/******** Function: print
	Inputs: none
	Output: none
	Description: prints out the queue.. by removing.. so don't use it...
	********/
	void print(void)
	{
		while( length )
			cout << remove() ;
		cout << endl;
	}
	
};

