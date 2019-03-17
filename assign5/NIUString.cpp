#include "NIUString.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

/********************************************************************
Function: operator<<
Use: used to print out an object
Parameters: lhs: ostream object input
	    rhs: NIUString reference to print out
Returns: lhs
********************************************************************/

ostream& operator<<(ostream& lhs, const NIUString& rhs)
	{
	for(size_t i = 0; i < rhs.stringSize; i++)
		{
		lhs << rhs.stringArrayPointer[i];
		}
	return lhs;
	}

/********************************************************************
Function: operator==
Use: used to compare if a c++ string and c string are equal or not
Parameters: lhs: char array pointer of passed in string for left side
	    rhs: NIUString reference for right side
Returns: true or false
********************************************************************/

bool operator==(const char* lhs, const NIUString& rhs)
	{
	if(strlen(lhs) != rhs.stringSize){return false;}
	else
		{
		for(size_t i = 0; i < rhs.stringSize; i++)
			if(lhs[i] != rhs[i])
				return false;
		}

	return true;
	}

/********************************************************************
Function:NIUString (constructor)
Use: initializes private data memebers
Parameters: none
Returns: nothing
********************************************************************/

NIUString::NIUString()
	{
	stringArrayPointer = nullptr;
	stringCap = 0;
	stringSize = 0;
	}

/********************************************************************
Function: NIUString (second constructor)
Use: sets private data members to valuse of passed in char array pointer
Parameters: other: char array pointer
Returns: nothing
********************************************************************/

NIUString::NIUString(const char* other)
	{
	stringSize = strlen(other);
	stringCap = stringSize;

	if(stringCap == 0){stringArrayPointer = nullptr;}
	else{stringArrayPointer = new char[stringCap];}

	//strncpy(strAr, other, sizeof(other)-1);
	for(size_t i = 0; i < stringSize; i++)
		stringArrayPointer[i] = other[i];
	}

/********************************************************************
Function: NIUString (second constructor for long strings)
Use: same as above but for longer strings
Parameters: other: reference to NIUString array
Returns: nothing
********************************************************************/

NIUString::NIUString(const NIUString& other)
	{
	stringSize = other.stringSize;
	stringCap = other.stringCap;

	if(stringCap == 0){stringArrayPointer = nullptr;}
	else{stringArrayPointer = new char[stringCap];}

	for(size_t i = 0; i < stringSize; i++)
		stringArrayPointer[i] = other.stringArrayPointer[i];
	}

/********************************************************************
Function: ~NIUString (destructor)
Use: calls clear method to destruct allocated object
Parameters: none
Returns: nothing
********************************************************************/

NIUString::~NIUString()
	{
	clear();
	}

/********************************************************************
Function: operator=
Use: assigns object other to this
Parameters: other: NIUString reference to object
Returns: *this
********************************************************************/

NIUString& NIUString::operator=(const NIUString& other)
	{
	if(this != &other)
		{
		delete[] stringArrayPointer;
		this->stringSize = other.stringSize;
                this->stringCap = other.stringCap;
		
		if(stringCap > 0){stringArrayPointer = new char[stringCap];}
		else{stringArrayPointer = nullptr;}
		}

	for(size_t i = 0; i < stringSize; i++)
                stringArrayPointer[i] = other.stringArrayPointer[i];

	return *this;
	}

/********************************************************************
Function: operator=
Use: assigns c string other to NIUString object this
Parameters: other: char array pointer
Returns: *this
********************************************************************/

NIUString& NIUString::operator=(const char* other)
	{
	delete[] stringArrayPointer;
	this->stringSize = strlen(other);
	this->stringCap = stringSize;

	if(stringCap == 0){stringArrayPointer = nullptr;}
	else{stringArrayPointer = new char[stringCap];}

	for(size_t i = 0; i < stringSize; i++)
		stringArrayPointer[i] = other[i];

	return *this;
	}

/********************************************************************
Function: capacity
Use: returns object string capacity
Parameters: none
Returns: stringCap
********************************************************************/

size_t NIUString::capacity() const
	{
	return stringCap;
	}

/********************************************************************
Function: size
Use: returns object string size
Parameters: none
Returns: stringSize
********************************************************************/

size_t NIUString::size() const
	{
	return stringSize;
	}

/********************************************************************
Function: empty
Use: checks of string or array is empty
Parameters: none
Returns: true or false
********************************************************************/

bool NIUString::empty() const
	{
	if(stringSize == 0)
		return true;
	else
		return false;
	}

/********************************************************************
Function: clear
Use: resets private data members and deletes allocated array;
Parameters: none
Returns: nothing
********************************************************************/

void NIUString::clear()
	{
	stringSize = 0;
	stringCap = 0;
	delete[] stringArrayPointer;
	stringArrayPointer = nullptr;
	}

/********************************************************************
Function: reserve
Use: modifies object string capacity
Parameters: n: size_t item to set the capacity to
Returns: nothing
********************************************************************/

void NIUString::reserve(size_t n)
	{
	if(n < stringSize || n == stringCap)
		return;
	stringCap = n;
	char *temp;

	if(stringCap == 0)
		temp = nullptr;
	else
		temp = new char[n];

	for(size_t i = 0; i < stringSize; i++)
		temp[i] = stringArrayPointer[i];
	delete[] stringArrayPointer;
	stringArrayPointer = temp;
	}

/********************************************************************
Function: operator==
Use: checks if strings are equal
Parameters: rhs: NIUString reference containing right hand side
Returns: true or false
********************************************************************/

bool NIUString::operator==(const NIUString& rhs) const
	{
	if((*this).stringSize != rhs.stringSize)
		return false;
	else
		{
		for(size_t i = 0; i < (*this).stringSize; i++)
			{
			if((*this).stringArrayPointer[i] != rhs.stringArrayPointer[i])
				return false;
			}
		}
	return true;
	}

/********************************************************************
Function: operator==
Use: check if string is equal to char array
Parameters: rhs: char array pointer to be compared
Returns: true or false
********************************************************************/

bool NIUString::operator==(const char* rhs) const
	{
	if((*this).stringSize != strlen(rhs))
		return false;
	else
		{
		for(size_t i = 0; i < stringSize; i++)
			{
			if(stringArrayPointer[i] != rhs[i])
				return false;
			}
		}
	return true;
	}

/********************************************************************
Function: operator[]
Use: returns element position in array
Parameters: pos: size_t containing index of array
Returns: stringArrayPointer[pos]
********************************************************************/

const char& NIUString::operator[](size_t pos) const
	{
	return stringArrayPointer[pos];
	}

/********************************************************************
Function: operator[]
Use: returns element position in array
Parameters: pos: size_t containing index of array
Returns: stringArrayPointer[pos]
********************************************************************/

char& NIUString::operator[](size_t pos)
	{
	return stringArrayPointer[pos];
	}

