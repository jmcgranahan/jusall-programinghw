//list.h
#include "node.h"
#include <iostream>
#pragma once

template <class type>
class list
{
	node<type> * head; // pointer to first object in list
	node<type> * tail; // ... last object in list
	node<type> * current; // current pointer
	int iCurrent, length; // current pointers position in the list and length of the list

public:
	
	// dafualt construtor
	list(void)
	{
		head = NULL;
		tail = NULL;
		current = NULL;
		iCurrent = 0;
		length = 0;
	}

	// deconstructor 
	~list(void)
	{
		while(head)
		{
			node<type> * pTemp = head;
			head = head->getNext();
			delete pTemp;
		}
	}

	// create a new node with the input data to the head of the list.
	void push(const type & item)
	{
		node<type> * pTemp = head; // dont loose head
		head = new node<type>(item,pTemp); // create new head
		if(pTemp) // incase list was empty
			pTemp->setPrev(head);
		else
			tail = head;
		current = head;
		iCurrent = 0;
		length++;
	}

	//create a new node with the input data to the tail of the list
	void append(const type & item)
	{
		node<type> * pTemp = tail; // dont loose tail
		tail = new node<type>(item);
		tail->setPrev(pTemp);
		if(pTemp) // incase list was empty
			pTemp->setNext(tail);
		else
			head = tail;
		current = tail;
		iCurrent = length;
		length++;
	}

	// insert a node storing the given item at the specified index
	void insert(const type & item,int index)
	{
		
		if(index >= length) // checks for front or end of lists inserts - skip searching to it.
			this->append(item);
		else if(index == 0)
			this->push(item);
		else
		{
			get(index); // move current to index

			node<type>* pBefore = current->getPrev();
			node<type>* newNode = new node<type>(item,current,pBefore);
		
			if(pBefore)
				pBefore->setNext(newNode);
			current->setPrev(newNode);
			current = newNode;
			length++;
		}
	}

	//return data stored in the head of the list
	type getHead(void)
	{
		return head->getData();
	}
	
	//return data stored in the tail of the list
	type getTail(void)
	{
		return tail->getData();
	}
	
	//return data stored in the node at index, used often to move current to a specific index
	type get(int index)
	{
		int distFromTail, distFromCurr;
		
		distFromCurr = abs(iCurrent-index);
		distFromTail = abs (length-index);
		
		if( index < distFromCurr && index < distFromTail)		// determins the closest known pointer to the index
		{
			current = head;
			iCurrent = 0;
		}
		else if( distFromTail < distFromCurr)					// ..and moves current pointer to it
		{
			current = tail;
			iCurrent = length-1;
		}

		while (current && iCurrent != index) // walk through list
		{
			if( index > iCurrent)
			{
				current = current->getNext();
				iCurrent++;
			}
			else
			{
				current = current->getPrev();
				iCurrent--;
			}
		}
		
		if( current )
			return current->getData();
		
		cout << "no object at index" << endl;
		return NULL;
	}

	// removes the indexed node from the list, returning the data stored there
	type pop(int index)
	{
		get(index);

		if( current )
		{
			type data = current->getData();
			node<type> * pTemp = current;

			if(head == tail)
			{
				current = tail = head = NULL;
				iCurrent = 0;
			}

			else if( current == tail )
			{
				current = tail = pTemp->getPrev();
				current->setNext(NULL);
				iCurrent--;
			}

			else if( current == head)
			{
				current = head = pTemp->getNext();
				current->setPrev(NULL);
			}
			else
			{
				current = current->getNext();
				current->setPrev(pTemp->getPrev());
				current->getPrev()->setNext(pTemp->getNext());
			}

			length--;
			delete pTemp;
			return data;
		}
		cout << "No value at index\n";
		return NULL;
	}

	//remove the indexed node from the list, no return 
	void remove(int index)
	{
		pop(index); // because re-writing is wasteful
	}

	//searches the list for a node containing data, then returns the index of that node.
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

	//return list length
	int getLength(void)
	{
		return length;
	}

	//cat - add the passed list to the end of this list
	// inputs: List to cat
	//  
	void cat(list<type> * inputList)
	{
		int inputLength = inputList->getLength();
		for(int i = 0; i < inputLength; i++)
		{
			type buffer = inputList->get(i);
			this->append(buffer);
		}
	}
	
	//cat - adds the passed lists to the end of this list
	// inputs: first list, and seccond list
	//  
	void cat( list<type> * firstList,  list<type> * seccondList)
	{
		this->cat(firstList);
		this->cat(seccondList);
	}

	//cat - adds the passed list, value, list, to the end of this list
	// inputs: first list, pivot value ( for quick sort), and seccond list
	//  
	void cat(list<type> * firstList, type pivotValue, list<type> * seccondList)
	{
		this->cat(firstList);
		this->append(pivotValue);
		this->cat(seccondList);
	}

	//quickSort - sort the stack using the quicksort method
	//
	void quickSort(void)
	{
		list<type> smaller,larger;
		type pivot = pop((int)length/2);

		while(length > 0)
		{
				int currentValue = pop(0);

				if (currentValue < pivot)
					smaller.append(currentValue);
				else
					larger.append(currentValue);
		}

		this->cat(recursiveSort(&smaller), pivot, recursiveSort(&larger)) ; 
	}

	//recursiveSort - recursive sorting for quicksort
	//inputs: list pointer to list to sort.
	//outputs: list pointer to sorted list
	//
	list<type> * recursiveSort(list<type> * inputList)
	{
		if( inputList->getLength() <= 1 )
			return inputList;

		list<type> smaller,larger;
		type pivot = inputList->pop((int)inputList->getLength()/2);

		while(inputList->getLength() > 0)
		{
				int currentValue = inputList->pop(0);

				if (currentValue < pivot)
					smaller.append(currentValue);
				else
					larger.append(currentValue);
		}

		list<type> * buffer = new list<type>();
		buffer->cat(recursiveSort(&smaller), pivot, recursiveSort(&larger));
		return buffer;
	}
};

