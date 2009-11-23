// MyArray.h

// insure that this header file is not included more than once
#pragma once
#ifndef MYARRAY_H_
#define MYARRAY_H_
 
template <class elemType>
class MyArray
{
private:
      int _size; // number of elements the current instance is holding
      int _capacity; // number of elements the current instance can hold
      elemType * list; // ptr to the first element in the array
 
// UTILITY FUNCTION(S)

// MakeRoom
      // doubles _capacity and builds a new list
      //   maintains current data
      void MakeRoom();
public:
 
// Ctors
      MyArray();	// default
      MyArray(int capacity); // initialize to capacity
      //MyArray( MyArray & original); // copy constructor
// Dtor
      ~MyArray();
 
// METHODS
// Add
      // Takes an argument of the templated type and
      // adds it to the end of the list/array
      void Add(const elemType & elem);
// At
      // Takes an int argument
      // Returns a reference to the element at a specified location in this MyArray
      elemType & At(int index);
// Find
      // Takes an argument of the templated type
      // Returns the int index were this element is found
      // Returns -1 if element is not found
      int Find(const elemType & elem);
// Insert
      // Takes an argument of the templated type and
      // An integer index argument
      // Inserts the element at that index in the list/array
      // moving the element currently at that index and all subsequent
      // elements up one index
      void Insert(const elemType & elem, int index);
// RemoveAt
      // Takes an int argument
      // Removes the element at that index in the list/array
      void RemoveAt(int index);
// SetValue
      // Takes an item to assign and an int index to assign it at
      // Assigns the item to the specified index of this MyArray
      void SetValue(const elemType & elem, int index);
// Size
      // Returns the number of elements in this MyArray
      int Size();
// Capacity
	  int Capacity();
 
// OPERATORS
      // = (assignment - takes a MyArray and makes a deep copy)
      //MyArray & operator= (const MyArray & aMyArray);
  
      // [] (read/write char access by index)
            // Returns a reference to the element at that index
            // throws an exception if index is < 0 or >= _length
      elemType & operator[] (int index) const;
 
      // ==, != (boolean relational test operators)
      //  compares arrays for element by element equality
      bool operator== (const MyArray & aMyArray) ;
      bool operator!= (const MyArray & aMyArray) ;
};
#endif