//node.h
#include <iostream>
#pragma once

template <class type>
class node
{
	type data;
	node * next;
	node * prev;
public:
	node(void)
	{
		data = NULL;
		prev = NULL;
		next = NULL;
	}

	node(const type & inputData)
	{
		data = inputData;
		prev = NULL;
		next = NULL;
	}

	node(const type & inputData, node * inputNext)
	{
		data = inputData;
		prev = NULL;
		next = inputNext;
	}

	node(const type & inputData, node * inputNext, node * inputPrev)
	{
		data = inputData;
		prev = inputPrev;
		next = inputNext;
	}

	~node(void)
	{
		
	}

	//Seters
	void setData(const type & inputData)
	{
		data = inputData;
	}

	void setNext(node * inputPointer)
	{
		next = inputPointer;
	}

	void setPrev(node * inputPointer)
	{
		prev = inputPointer;
	}
	
	//Geters 
	type & getData(void)
	{
		return data;
	}

	node * getNext(void)
	{
		return next;
	}

	node * getPrev(void)
	{
		return prev;
	}

	//Utilities 
	void print(void)
	{
		cout << "node pointer:" << this << endl;
		cout << "node data:" << this->getData() << endl;
		cout << "node next:" << this->getNext() << endl;
		cout << "node prev:" << this->getPrev() << endl;
	}
};

