#include "Queue.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <string>
#include <stdexcept>

using namespace std;

/********************************************************************
Function:
Use: 
Parameters: 
Returns: 
********************************************************************/

ostream& operator<<(ostream& lhs, const Queue& rhs)
	{
	size_t current, i;
      
	for (current = rhs.qFront, i = 0; i < rhs.qSize; ++i)
   		{
   		// Print queue element at subscript i
   		lhs << rhs.qAr[current] << ' ';
   
   		// Increment i, wrapping around to front of queue array if necessary     
   		current = (current + 1) % rhs.qCap;
   		}
	return lhs;
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

Queue::Queue()
	{
	qSize = 0;
	qCap = 0;
	qAr = nullptr;
	qFront = 0;
	qBack = qCap-1;
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

Queue::~Queue()
	{
	delete[] qAr;
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

Queue::Queue(const Queue& other)
	{
	qCap = other.qCap;
	qSize = other.qSize;
	qAr = new int[qCap];

	for(size_t i = 0; i < qCap; ++i)
		qAr[i] = other.qAr[i];

	qFront = other.qFront;
	qBack = other.qBack;
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

Queue& Queue::operator=(const Queue& other)
	{
	if(this != &other)
		{
		delete[] qAr;
		this->qSize = other.qSize;
		this->qCap = other.qCap;

		if(qCap > 0)
			qAr = new int[qCap];
		else
			qAr = nullptr;
		}
	for(size_t i = 0; i < qCap; ++i)
		qAr[i] = other.qAr[i];

	qFront = other.qFront;
	qBack = other.qBack;
	return *this;
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

void Queue::clear()
	{
	qSize = 0;
	qCap = 0;
	qFront = 0;
	qBack = qCap-1;
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

size_t Queue::size() const
	{
	return qSize;
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

size_t Queue::capacity() const
	{
	return qCap;
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

bool Queue::empty() const
	{
	if(qSize == 0)
		return true;
	else
		return false;
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

int Queue::front() const
	{
	if(empty())
		throw underflow_error("underflow on front()");
	else
		return qAr[qFront];
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

int Queue::back() const
	{
	if(empty())
                throw underflow_error("underflow on back()");
        else
                return qAr[qBack];

	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

void Queue::push(int newItem)
	{
	if (qSize == qCap)
   		{
   		if (qCap == 0)
      			reserve(1);
   		else
      			reserve(qCap * 2);
   		}

	qBack = (qBack + 1) % qCap;
	qAr[qBack] = newItem;
	++qSize;
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

void Queue::pop()
	{
	if(empty())
                throw underflow_error("underflow on pop()");
        else
		qFront = (qFront + 1)%qCap;
		--qSize;
	}

/********************************************************************
Function:
Use:
Parameters:
Returns:
********************************************************************/

void Queue::reserve(unsigned int n)
	{
	if (n > qCap)
      		{
      		int* tempArray = new int[n];

      		int current = qFront;
      		for (size_t i = 0; i < qSize; i++)
         		{
        		tempArray[i] = qAr[current];
         		current = (current + 1)%qCap;
         		}

      		qCap = n;
      		qFront = 0;
      		qBack = qSize - 1;
      		delete[] qAr;
      		qAr = tempArray;
      		}	
	}
