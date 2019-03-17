#include "NIUString.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
/***************************************************************
constructor

Use: creates the blank NIUString object

Parameters: none

Returns: nothing
***************************************************************/
NIUString::NIUString()
{
	StringCapacity = 0;
	StringSize = 0;
	Array = nullptr;
}

/***************************************************************
second constructor

Use: sets the blank NIU object to new values from a pointer to a character array

Parameters: const char* other

Returns: nothing
***************************************************************/
NIUString::NIUString(const char* other)
{
	int length = strlen(other);
	StringCapacity = length;
	StringSize = StringCapacity;
	if(StringCapacity>0)
		Array = new char[StringCapacity];
	else
		Array = nullptr;
	for(size_t i = 0; i<StringSize; i++)
	{
		Array[i] = other[i];
	}
}

/***************************************************************
copy constructor

Use: creates a copy of the object passed in

Parameters: const NIUString&

Returns: nothing
***************************************************************/
NIUString::NIUString(const NIUString& other)
{
	StringCapacity = other.StringCapacity;
	StringSize = other.StringCapacity;
	if(StringCapacity > 0)
		Array = new char[StringCapacity];
	else
		Array = nullptr;
	for(size_t i = 0; i < StringSize; i++)
		Array[i] = other.Array[i];
}

/***************************************************************
operator<<

Use: allows you to display object to the screen use cout<<

Parameters: ostream& , NIUString&

Returns: lhs or the prited array
***************************************************************/
ostream& operator<<(ostream& lhs, const NIUString& rhs )
{
	for(size_t i=0; i<rhs.StringSize; i++)
	{
        	lhs <<rhs.Array[i];
	}
        return lhs;
}
/***************************************************************
size()

Use: returns String size

Parameters: none

Returns: string size
***************************************************************/
size_t NIUString::size() const
{
	return StringSize;
}

/***************************************************************
capacity()

Use: returns string capacity

Parameters: none

Returns: string capacity
***************************************************************/
size_t NIUString::capacity() const
{
	return StringCapacity;
}

/***************************************************************
empty()

Use: checks if the array is empty

Parameters: none

Returns: true if empty false if not
***************************************************************/
bool NIUString::empty() const
{
	if(StringCapacity==0)
	return true;
	else
	return false;
}

/***************************************************************
operator=

Use:  overloads the = operator to compare a const char* to and NIU object

Parameters: const char*

Returns: *this
***************************************************************/
NIUString& NIUString::operator=(const char* other)
{

	delete[] Array;
	int length = strlen(other);
	this->StringSize = length;
	this->StringCapacity = StringSize;
	if((StringCapacity == 0))
		Array = nullptr;
	else
		Array = new char[StringCapacity];
	for(size_t i = 0; i < StringSize; i++)
		Array[i] = other[i];
	return *this;
}

/***************************************************************
operator=

Use: overloads the = operator to compare two objects

Parameters: const NIUString&

Returns: *this
***************************************************************/
NIUString& NIUString::operator=(const NIUString& other)
{

	if(this != &other)
	{
		delete[] Array;
		this->StringCapacity = other.StringCapacity;
		this->StringSize = other.StringSize;
		if(StringCapacity > 0)
			Array = new char[StringCapacity];
		else
			Array = nullptr;
		for(size_t i = 0; i < StringSize; i++)
			Array[i] = other.Array[i];
	}
	return *this;
}

/***************************************************************
~NIUString

Use: deletes the allocated array

Parameters: none

Returns: nothing
***************************************************************/
NIUString::~NIUString()
{
	delete[] Array;
}

/***************************************************************
operator[]

Use: overloads the subscript operator to show the positon in the array

Parameters: size_t pos

Returns: Array[pos] or current position in the array
***************************************************************/
const char& NIUString::operator[](size_t pos) const
{
	return Array[pos];
}

/***************************************************************
operator[]

Use: overloads the subscript operator to show the positon in the array

Parameters: size_t pos

Returns: Array[pos] or current position in the array
***************************************************************/
char& NIUString::operator[](size_t pos)
{
	return Array[pos];
}

/***************************************************************
reserve()

Use: adds more memory to the array if it is needed

Parameters: size_t n

Returns: nothing
***************************************************************/
void NIUString::reserve(size_t n)
{
	if(n < StringSize || n == StringCapacity)
		return;

	StringCapacity = n;
	char* Ar;

	if((n = 0))
		Ar = nullptr;
	else
	Ar = new char[n];

	for(size_t i = 0; i < StringSize; i++)
		Ar[i] = Array[i];
	delete[] Array;
	Array = Ar;


}

/***************************************************************
operator==

Use: overloads the == operator to check fo requality of NIU objects

Parameters: const NIUString&

Returns: true or false
***************************************************************/
bool NIUString::operator==(const NIUString& rhs) const
{
	//int length = strlen(rhs);
	if((*this).StringSize != rhs.StringSize)
		return false;
	else
		for(size_t i = 0; i < (*this).StringSize; i++)
		{

			if((*this).Array[i] != rhs.Array[i] )
				return false;
		}
	return true;
}

/***************************************************************
operator==

Use: overloads the == to compare an NIUString object to a const char*

Parameters: const char* rhs

Returns: true or false
***************************************************************/
bool NIUString::operator==(const char* rhs) const
{
	size_t length = strlen(rhs);
	if((*this).StringSize != length)
                return false;
	else
		for(size_t i =0; i <StringSize; i++)
        	{
                	if(Array[i] != rhs[i])
                        	return false;
        	}
        return true;

}

/***************************************************************
operator==

Use: overloads the == operator to compare a const char* to an NIU object

Parameters: const char*, NIUString&

Returns: true or false
***************************************************************/
bool operator==(const char* lhs, const NIUString& rhs)
{
	size_t len1 = strlen(lhs);
	//size_t len2 = strlen(rhs);
	if(len1 != rhs.StringSize)
		return false;
	else
        	for(size_t i =0; i < rhs.StringSize; i++)
        	{
                	if(lhs[i] != rhs[i])
                        	return false;
        	}
        return true;

}

/***************************************************************
clear()

Use: sets the obeject back to null values

Parameters: none

Returns: nothing
***************************************************************/
void NIUString::clear()
{
	StringSize = 0;
	StringCapacity = 0;
	delete[] Array;
	Array = nullptr;
}

