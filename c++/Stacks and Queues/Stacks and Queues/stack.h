//stack.h
#include "node.h"
#include <iostream>
#pragma once

template <class type>
class stack
{
	node<type> * top;
	int length;

public:
	/******** Function: Constructor
	Inputs: none
	Output: none 
	Description: Creates a new stack
	********/
	stack(void)
	{
		top = NULL;
		length = 0;
	}

	/******** Function: Destructor
	Inputs: none
	Output: none
	Description: Deletes the stack
	********/
	~stack(void)
	{
		while(top)
		{
			node<type> * pTemp = top;
			top = top->getNext();
			delete pTemp;
		}
	}

	/******** Function: push
	Inputs: type data
	Output: none
	Description: adds the passed data to the top of the stack
	********/
	void push(const type & item)
	{
		node<type> * pTemp = top;
		top = new node<type>(item,pTemp);
		length++;
	}

	/******** Function: pop
	Inputs: none
	Output: type
	Description: Remove the top of the stack and returns the data 
	********/
	type pop(void)
	{
		if( !top )
			return 0;
		node<type> * pTemp = top;
		top = pTemp->getNext();
		type data = pTemp->getData();

		length--;
		delete pTemp;
		return data;
	}

	/******** Function: peak
	Inputs: none
	Output: type
	Description: Returns the top without removing it
	********/
	type peak(void)
	{
		if( top ) 
			return top->getData();
		return 0;
	}

	/******** Function: getLength
	Inputs: none
	Output: int
	Description: returns the length of the stack
	********/
	int getLength(void)
	{
		return length;
	}
	
};

