//node.h
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

	node(const type & inputData, node * inputPrev, node * inputNext)
	{
		data = inputData;
		prev = inputPrev;
		next = inputNext;
	}

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

	~node(void)
	{
	}
};

