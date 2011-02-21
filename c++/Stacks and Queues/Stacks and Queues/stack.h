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

	stack(void)
	{
		top = NULL;
		length = 0;
	}

	~stack(void)
	{
		while(top)
		{
			node<type> * pTemp = top;
			top = top->getNext();
			delete pTemp;
		}
	}

	void push(const type & item)
	{
		node<type> * pTemp = top;
		top = new node<type>(item,pTemp);
		length++;
	}

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

	type peak(void)
	{
		if( top ) 
			return top->getData();
		return 0;
	}


	int getLength(void)
	{
		return length;
	}
	
};

