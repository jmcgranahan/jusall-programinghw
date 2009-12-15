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
      void MakeRoom(){
		elemType * Temp = new elemType[_capacity];
		for(int i=0; i < _capacity;i++)
			Temp[i] = list[i];
		delete [] list;
		_capacity *= 2;
		list = new elemType[_capacity];
		for(int i=0; i < _capacity/2;i++)
			list[i] = Temp[i];
		delete [] Temp;
}
public:
 
// Ctors
	MyArray(){
		_size = 0;
		_capacity = 16;
		list = new elemType[_capacity];
}// default

	MyArray(int capacity){
		_size = 0;
		_capacity = capacity;
		list = new elemType[_capacity];
	} // initialize to capacity

//MyArray( MyArray & original); // copy constructor
// Dtor
	~MyArray(){delete [] list;}
// METHODS
// Add
// Takes an argument of the templated type and
// adds it to the end of the list/array
	void Add(const elemType & elem){
		elemType temp = elem;
		if (_size >= _capacity)
		{
			MakeRoom();
		}
		list[_size] = temp;
		_size++;
	}
// At
    // Takes an int argument
    // Returns a reference to the element at a specified location in this MyArray
    elemType & At(int index){return list[index];}
// Find
    // Takes an argument of the templated type
    // Returns the int index were this element is found
    // Returns -1 if element is not found
	int Find(const elemType & elem){
		elemType temp = elem;
		for( int i = 0;i < _size; i++)
		{
			if(list[i] == temp)
				return i+1;
		
		}
		return -1;
	}
// Insert
      // Takes an argument of the templated type and
      // An integer index argument
      // Inserts the element at that index in the list/array
      // moving the element currently at that index and all subsequent
      // elements up one index
    void Insert(const elemType & elem, int index){
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
// RemoveAt
      // Takes an int argument
      // Removes the element at that index in the list/array
    void RemoveAt(int index){
	for(int i=index; i < _size-1; i++)
	{
		int j = i+1;
		list[j] = list[i];
	}
	_size--;

}
// SetValue
      // Takes an item to assign and an int index to assign it at
      // Assigns the item to the specified index of this MyArray
    void SetValue(const elemType & elem, int index){list[index-1] = elem;}
// Size
      // Returns the number of elements in this MyArray
    int Size(){return _size;}
// Capacity
	int Capacity(){return _capacity;}

	void WriteOut(const char * fileName)
	{
		ofstream myofile;
		int tempSize = _size;
		myofile.open(fileName, ios::out);

		if(myofile.is_open())
		{
			myofile << tempSize << "\n";

			for (int i = 0; i < _size; i++)
			{
				myofile << this->At(i) << "\n";
			}
			Empty();
			myofile.close();
		}
		else
			cout << "Failed to open" << "\n";

	}
	void WriteIn(const char * fileName)
	{
		ifstream myifile;
		int lines;
		elemType temp;
		myifile.open("data.txt", ios::in);
		if(myifile.is_open())
		{
			myifile >> lines; 
			for(int i=0; i < lines; i++)
			{
				myifile >> temp;
				Add(temp);
			}

		myifile.close();
	}
	else
		cout << "Failed to open" << "\n";
	}

	void Display()
	{
		for (int i = 0; i < _size; i++)
		{
			cout << "[" << i << "] = " << list[i] << "\n";
		}
	}
	void Empty()
	{
		_size = 0;
		delete [] list;
		list = new elemType[_capacity];
	}
 
// OPERATORS
      // = (assignment - takes a MyArray and makes a deep copy)
      //MyArray & operator= (const MyArray & aMyArray);
  
      // [] (read/write char access by index)
            // Returns a reference to the element at that index
            // throws an exception if index is < 0 or >= _length
    elemType & operator[] (int index) const{
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
 
    // ==, != (boolean relational test operators)
      //  compares arrays for element by element equality
    bool operator== (const MyArray & aMyArray){
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
	bool operator!= (const MyArray & aMyArray)
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
};
#endif