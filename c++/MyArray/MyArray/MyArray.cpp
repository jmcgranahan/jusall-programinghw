//MyArray.cpp
#include <iostream>
#include "MyArray.h"

template <class elemType>
void MyArray<elemType>::MakeRoom()
{
	elemType * Temp = new elemType[_capacity];
	for(int i=0; i <= _capacity;i++)
		Temp[i] = list[i];
	delete [] list;
	_capacity *= 2;
	list = new elemType[_capacity];
	for(int i=0; i <= _capacity/2;i++)
		list[i] = Temp[i];
	delete [] Temp;
}

 
// Ctors
template <class elemType>
MyArray<elemType>::MyArray()
{
	_size = 0;
	_capacity = 16;
	list = new elemType[_capacity];
}
template <class elemType>
MyArray<elemType>::MyArray(int capacity)
{
	_size = 0;
	_capacity = capacity;
	list = new elemType[_capacity];
}
//MyArray( MyArray & original); // copy constructor
// Dtor
template <class elemType>
MyArray<elemType>::~MyArray()
{
	delete [] list;
}
 
// METHODS
template <class elemType>
void MyArray<elemType>::Add(const elemType & elem)
{
	if (_size >= _capacity)
	{
		MakeRoom();
	}
	list[_size] = elem;
	_size++;
	
}

template <class elemType>
elemType & MyArray<elemType>::At(int index)
{
	index--;
	return list[index];
}

template <class elemType>
int MyArray<elemType>::Find(const elemType & elem)
{
	elemType temp = elem;
	for( int i = 0;i < _size; i++)
	{
		if(list[i] == temp)
			return i+1;
		
	}
	return -1;
}

template <class elemType>
void MyArray<elemType>::Insert(const elemType & elem, int index)
{
	if (_size+1 >= _capacity)
	{
		MakeRoom();
	}

	elemType * Temp = new elemType[_capacity];
	
	for(int i=0; i <= _size ;i++)
		Temp[i] = list[i];
	
	
	for(int i=0; i < index ;i++)
		list[i] = Temp[i];
	
	list[index] = elem;


	for(int i = index;i < _capacity; i++)
	{
		int j = i+1;
		list[j] = Temp[i];	 
	}
	delete [] Temp;
	_size++;
}

template <class elemType>
void MyArray<elemType>::RemoveAt(int index)
{
	for(int i=index; i < _size; i++)
	{
		int j = i+1;
		list[i] = list[j];
	}
	_size--;

}

template <class elemType>
void MyArray<elemType>::SetValue(const elemType & elem, int index)
{
	list[index-1] = elem;
}
template <class elemType>
int MyArray<elemType>::Size()
{
	return _size;
}

template <class elemType>
int MyArray<elemType>::Capacity()
{
	return _capacity;
}
 
// OPERATORS
//template <class elemType>
//MyArray & MyArray<elemType>::operator= (const MyArray & aMyArray)
//{
///
//	_size = aMyArray.Size();
//	_capacity = aMyArray.Capacity();
//	delete [] list;
//	list = new elemType[_capacity];
//	MyArray<elemType> temp;
//	for(int i = 0; i < _size; i++)
//	{
//		list[i] = aMyArray.At[i+1];
//		temp.Add(aMyArray.At[i+1])
//	}
//	return temp;
//
//
//}

template <class elemType>
elemType & MyArray<elemType>::operator[] (int index) const
{
	if((index < _size) && (index >= 0)){	
		return list[index];
	}
	else if(index > _size){
		std::cout << "error: index longer than MyArray length" << std::endl;
		return list[0];
	}
	else if(index < 0){
		std::cout << "error: index cannot be less than 0" << std::endl;
		return list[0];
	}
}
 
template <class elemType>
bool MyArray<elemType>::operator== (const MyArray & aMyArray)
{
	if( _size != aMyArray.Size())
		return false;
	else
	{
		for(int i = 0; i < _size; i++)
			if( list[i] != aMyArray.At(i+1))
				return false;
	}
	return true;

}

template <class elemType>
bool MyArray<elemType>::operator!= (const MyArray & aMyArray)
{
	if( _size != aMyArray.Size())
		return true;
	else
	{
		for(int i = 0; i < _size; i++)
			if( list[i] != aMyArray.At(i+1))
				return true;
	}
	return false;
}
