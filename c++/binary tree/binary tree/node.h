//node.h
#include <iostream>
#pragma once

template <class type>
class node
{
	type data;
	node * left;
	node * right;
public:
	node(void)
	{
		data = NULL;
		right = NULL;
		left = NULL;
	}

	node(const type & inputData)
	{
		data = inputData;
		right = NULL;
		left = NULL;
	}

	~node(void)
	{
	}

	//Seters
	void setData(const type & inputData)
	{
		data = inputData;
	}

	void setLeft(node * inputPointer)
	{
		left = inputPointer;
	}

	void setRight(node * inputPointer)
	{
		right = inputPointer;
	}
	
	//Geters 
	type & getData(void)
	{
		return data;
	}

	node * getLeft(void)
	{
		return left;
	}

	node * getRight(void)
	{
		return right;
	}

	//Utilities 
	void print(void)
	{
		cout << "node pointer:" << this << endl;
		cout << "node data:" << this->getData() << endl;
		cout << "node left:" << this->getleft() << endl;
		cout << "node right:" << this->getright() << endl;
	}
};

