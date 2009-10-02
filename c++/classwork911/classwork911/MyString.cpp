// MyString.cpp
#include <iostream>
#include "MyString.h"
#include <cstring>

// CONSTRUCTORS

//-----------------------------------------------------
MyString::MyString() //defualt constructor ( no variables)
{
	_capacity = 16;
	_length = 0;

	_string = new char[_capacity + 1];

	_string[0] = '\0'; 
}

//-----------------------------------------------------
MyString::MyString(const char * aCString) // C String variable
{
	int NumCharsToCopy = strlen(aCString);
	if ( NumCharsToCopy < 16)
		_capacity = 16;
	else
		_capacity = NumCharsToCopy;

	_string = new char[_capacity + 1];
	strcpy(_string , aCString);
	_length = NumCharsToCopy;
}
//-----------------------------------------------------
MyString::MyString(int numChars) // int variable 
{
	_capacity = numChars;
	_string = new char[_capacity + 1];
	_string[0] = '\0';
	_length = 0;
}
//-----------------------------------------------------
MyString::MyString(const MyString & original)// MyString variable
{
	_capacity = original._capacity;
	_string = new char [_capacity+1];
	strcpy(_string, original._string);
	_length = original._length;
}
//-----------------------------------------------------
//DECONSTRUCTOR
	
MyString::~MyString()//dealocate dynamic storage
{
	delete [] _string; // OMG DELETE
}

// METHODS
//-----------------------------------------------------
void MyString::Append(const MyString & aMyString)
{
	int MyStringLength = _length + aMyString._length;
	char * _Temp = new char[_capacity + 1];
	strcpy( _Temp, _string);
	char * _Temp2 = new char[aMyString._capacity + 1];
	strcpy( _Temp2, aMyString._string);
		// Did All this Temp Strings because your s4.append(s4) test fouled up elsewise
	if(MyStringLength > _capacity)
	{
		//need more capacity
		_capacity = MyStringLength;
		delete [] _string;
		_string = new char[_capacity + 1];
	}
	strcpy( _string, _Temp);
	delete [] _Temp;
	strcat( _string, _Temp2);
	delete [] _Temp2;
	_length = MyStringLength;

}
//-----------------------------------------------------
void MyString::Append(const char * const aCString)
{
	int StringLength = strlen(aCString);
	int MyStringLength = _length + StringLength;
	char * _Temp = new char[_capacity + 1];
	strcpy( _Temp, _string);

	if(MyStringLength > _capacity)
	{
		
		//need more capacity
		_capacity = MyStringLength;
		delete [] _string;
		_string = new char[_capacity + 1];
	}
	strcpy( _string, _Temp);
	delete [] _Temp;
	strcat( _string, aCString);
	_length = MyStringLength;

}
//-----------------------------------------------------
void MyString::Assign(const MyString & aMyString)
{
	int numCharsToCopy = aMyString._length;

	if(numCharsToCopy > _capacity)
	{
		//need more capacity
		_capacity = numCharsToCopy;
		delete [] _string;
		_string = new char[_capacity + 1];
	}

	strcpy( _string, aMyString._string);
	_length = numCharsToCopy;

}
//-----------------------------------------------------
void MyString::Assign(const char * const aCString)
{
	int numCharsToCopy = strlen(aCString);

	if(numCharsToCopy > _capacity)
	{
		//need more capacity
		_capacity = numCharsToCopy;
		delete [] _string;
		_string = new char[_capacity + 1];
	}

	strcpy( _string, aCString);
	_length = numCharsToCopy;

}
//-----------------------------------------------------
char MyString::At(int index) const
{
	char At = '\0';
	if((index <= _length) && (index != 0)){
		char * Pointer = _string;
		Pointer += index-1;
		At = *Pointer ;
	}
	if(index >= _length){
		std::cout << "error: index longer than MyString length" << std::endl;
	}
	if(index == 0){
		std::cout << "error: index cannot equal 0" << std::endl;
	}
	return At;
}
//-----------------------------------------------------
void MyString::Clear()
{
delete [] _string;
_string = new char[_capacity + 1];
strcpy(_string , "");
_length = 0;
}
//-----------------------------------------------------
void MyString::Clear(int newCapacity)
{
	_capacity = newCapacity;
	delete [] _string;
	_string = new char[_capacity + 1];
	strcpy(_string , "");
	_length = 0;
}
//-----------------------------------------------------
int MyString::Compare(const MyString & aMyString)
{
	int Compare = strncmp(_string,aMyString._string,_length);
	return Compare;
}
//-----------------------------------------------------
bool MyString::Equals(const MyString & aMyString) const
{
	int Compare = strncmp(_string,aMyString._string,_length);
	bool Equal;
	if(Compare == 0){Equal = true;}
	if(Compare != 0){Equal = false;}
	return Equal;

}
//-----------------------------------------------------
bool MyString::Equals(const char * const aCString) const
{
	int Compare = strncmp(_string,aCString,_length);
	bool Equal;
	if(Compare == 0){Equal = true;}
	if(Compare != 0){Equal = false;}
	return Equal;

}
//-----------------------------------------------------
int MyString::Find(const MyString & aMyString) const
{
	int Index;
	char * Pointer;
	Pointer = strstr(_string, aMyString._string);
	if(Pointer == 0){ Index = -1; }
	else{
		Index = Pointer - _string;
	}
	return Index;
}
//-----------------------------------------------------
void MyString::Insert(const MyString & aMyString, int index)
{
	int MyStringLength = _length + aMyString._length;
	char * _Temp = new char[_capacity + 1];
	strncpy( _Temp, _string);

	if(MyStringLength > _capacity)
	{
		//need more capacity
		_capacity = MyStringLength;
		delete [] _string;
		_string = new char[_capacity + 1];
	}
	strncpy( _string, _Temp, index);
	strcat(_string,aMyString._string);

	int TempIndex = index+aMyString.Length-1;
	do{
		TempIndex++;
		_string[TempIndex] = _Temp[TempIndex - index];

		
	}while(TempIndex <= _length+aMyString.Length);

	strcat( _string, _Temp);
	_length = MyStringLength;

}
//-----------------------------------------------------
int MyString::Length(void) const
{
	return _length;

}
//-----------------------------------------------------
void MyString::Replace(int startIndex, int numChars, const MyString & aMyString)
{
	if( startIndex >= _length )
	{
		std::cout << "error: Index larger than MyString length" << std::endl;
	}
	else if( startIndex + numChars > this->Length())
	{
		std::cout << "error: Replacing more charcaters than there are" << std::endl;
	}
	else if(aMyString.Length() < numChars)
	{
		std::cout << "error: Copying more characters than given" << std::endl;
	}
	else 
	{
		for(int i = 0; i < numChars; i++)
		{
			_string[startIndex+i] = aMyString._string[i];
		}
	}
	

}
//-----------------------------------------------------
MyString MyString::SubStr(int startIndex, int numChars) const
{
	MyString m(numChars);
	if( startIndex + numChars > this->Length())
	{
		std::cout << "error: Requesting more charcaters than there are" << std::endl;
	}
	else
	{
		for(int i = 0; i < numChars; i++)
		{
			m._string[i] = _string[startIndex+i];
		}
		m._string[numChars] = '\0';
	}
	return m;
}
//-----------------------------------------------------
MyString MyString::operator= (const MyString & aMyString)
{
	MyString Temp;
	Temp.Assign(aMyString);
	return Temp;
	
}

//-----------------------------------------------------
MyString MyString::operator= (const char *  const aCString)
{
	MyString Temp;
	Temp.Assign(aCString);
	return Temp;
	
}
//-----------------------------------------------------
MyString MyString::operator+ (const MyString & aMyString)
{
	MyString Temp;
	Temp.Assign(*this);
	Temp.Append(aMyString);
	return Temp;
}
//-----------------------------------------------------
MyString MyString::operator+ (const char *  const aCString)
{
	MyString Temp;
	Temp.Assign(*this);
	Temp.Append(aCString);
	return Temp;
}
//-----------------------------------------------------
MyString MyString::operator+= (const MyString & aMyString)
{
	this->Append(aMyString);
	return 0;
}
//-----------------------------------------------------
MyString MyString::operator+= (const char *  const aCString)
{
	this->Append(aCString);
	return 0;
}
//-----------------------------------------------------
char & MyString::operator[] (int index) const
{
	char At;
	if((index <= _length) && (index != 0)){
		char * Pointer = _string;
		Pointer += index - 1;
		At = *Pointer;
		
	}
	if(index >= _length){
		std::cout << "error: index longer than MyString length" << std::endl;
	}
	if(index == 0){
		std::cout << "error: index cannot equal 0" << std::endl;
	}
	return At;
}
//-----------------------------------------------------
bool MyString::operator> (const MyString & aMyString) 
{
	int Compare = strcmp(_string,aMyString._string);
	bool Equal;
	if(Compare > 0){Equal = true;}
	else {Equal = false;}
	return Equal;

}
//-----------------------------------------------------
bool MyString::operator< (const MyString & aMyString) 
{
	int Compare = strcmp(_string,aMyString._string);
	bool Equal;
	if(Compare < 0){Equal = true;}
	else {Equal = false;}
	return Equal;

}
//-----------------------------------------------------
bool MyString::operator>= (const MyString & aMyString) 
{
	int Compare = strcmp(_string,aMyString._string);
	bool Equal;
	if(Compare >= 0){Equal = true;}
	else {Equal = false;}
	return Equal;

}
//-----------------------------------------------------
bool MyString::operator<= (const MyString & aMyString)
{
	int Compare = strcmp(_string,aMyString._string);
	bool Equal;
	if(Compare <= 0){Equal = true;}
	else {Equal = false;}
	return Equal;

}
//-----------------------------------------------------
bool MyString::operator== (const MyString & aMyString) 
{
	int Compare = strcmp(_string,aMyString._string);
	bool Equal;
	if(Compare == 0){Equal = true;}
	else {Equal = false;}
	return Equal;

}
//-----------------------------------------------------
bool MyString::operator!= (const MyString & aMyString) 
{
	int Compare = strcmp(_string,aMyString._string);
	bool Equal;
	if(Compare != 0){Equal = true;}
	else {Equal = false;}
	return Equal;

}
 //-----------------------------------------------------
ostream & operator<< (ostream & os, const MyString & aMyString)
{
	os << aMyString._string ;

	return os;

}
//-----------------------------------------------------
istream & operator>> (istream & is, MyString & aMyString)
{

	char Buffer[80];
	aMyString.Clear();
	if(is.peek() != '\n')
	{
		do
		{
			//79 chars at once woo
			is.get(Buffer,80);
			aMyString.Append(Buffer);
		}while(/*(int)*/ strlen(Buffer) == 79);

	}
	if ( is.peek() == '\n')
	{
		is.get(); // remove trailing nullchar
	}

	return is;


	// old attempt worked mostly...
	//char * _Temp = new char[10000000];
	//
	//is.getline (_Temp,10000000);
	//
	//if(strlen(_Temp) > aMyString._capacity)
	//{
	//	//need more capacity
	//	aMyString._capacity = strlen(_Temp);
	//	delete [] aMyString._string;
	//	aMyString._string = new char[aMyString._capacity + 1];
	//}
	//strcpy(aMyString._string,_Temp);
	//delete [] _Temp;
	//return is;

}
