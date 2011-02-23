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

	/******** Function: default constructor
	Inputs: none
	Output: none
	Description: creates an empty node
	********/
	node(void)
	{
		data = NULL;
		prev = NULL;
		next = NULL;
	}

	/******** Function: Constructor /w data
	Inputs: (type data)
	Output: none
	Description: Creates a node with the passed data
	********/
	node(const type & inputData)
	{
		data = inputData;
		prev = NULL;
		next = NULL;
	}

	/******** Function: Constructor /w data + next pointer
	Inputs: data, NextPointer
	Output: none
	Description: Creates a node with the passed data and pointer to next node
	********/
	node(const type & inputData, node * inputNext)
	{
		data = inputData;
		prev = NULL;
		next = inputNext;
	}

	/******** Function: Constructor /w data + next/prev pointer
	Inputs: data, NextPointer, PrevPointer
	Output: none
	Description: Creates a node with the passed data and pointer to next and previous node
	********/
	node(const type & inputData, node * inputNext, node * inputPrev)
	{
		data = inputData;
		prev = inputPrev;
		next = inputNext;
	}

	~node(void)
	{
	}

	/******** Function: setData 
	Inputs: data
	Output: none
	Description: Sets the nodes data to the input
	********/
	void setData(const type & inputData)
	{
		data = inputData;
	}

	/******** Function: setNext
	Inputs: nextPointer
	Output: none
	Description: Sets the noes next pointer to the input
	********/
	void setNext(node * inputPointer)
	{
		next = inputPointer;
	}

	/******** Function: setPrev
	Inputs: prevPointer
	Output: none
	Description: sets the nodes prevPointer
	********/
	void setPrev(node * inputPointer)
	{
		prev = inputPointer;
	}
	
	//Geters 
	/******** Function: getData
	Inputs: none
	Output: type
	Description: Returns the nodes data
	********/
	type & getData(void)
	{
		return data;
	}

	/******** Function: getNext 
	Inputs: none
	Output: node*
	Description: Returns the nodes next pointer
	********/
	node * getNext(void)
	{
		return next;
	}

	/******** Function: getPrev
	Inputs: none
	Output: node*
	Description: Returns the nodes prev pointer
	********/
	node * getPrev(void)
	{
		return prev;
	}

	//Utilities
	/******** Function: Debug
	Inputs: none
	Output: none
	Description: prints the nodes information for debuging information
	********/
	void print(void)
	{
		cout << "node pointer:" << this << endl;
		cout << "node data:" << this->getData() << endl;
		cout << "node next:" << this->getNext() << endl;
		cout << "node prev:" << this->getPrev() << endl;
	}
};

