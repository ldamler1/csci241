/*********************************************************************
   PROGRAM:    Assignment 7
   PROGRAMMER: Damler, Lucas
   LOGON ID:   z1761739
   DUE DATE:   18 APR 2017
   FUNCTION:   This program tests the functionality of the Queue
               class.
*********************************************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdexcept>

using namespace std;

/***************************************************************
Function:
Use:
Parameters:
Returns:
***************************************************************/
template <class T>
struct Node
{
T data;
Node<T>* next;
Node(const T &newData)
	{
	data = newData;
	next = nullptr;
	}

Node(const T &newData, Node<T>* test)
	{
	data = newData;
	next = test;
	}
};

// Forward declaration of the Stack template class
template <class T>
class Stack;

// Forward declaration of the operator<< template function
template <class T>
ostream& operator<<(ostream&, const Stack<T>&);

/***************************************************************
Function: class Stack
Use: contains prototypes for stack class
Parameters: none
Returns: nothing
***************************************************************/

template <class T>
class Stack
{
friend ostream& operator<< <>(ostream&, const Stack<T>&);

private:
	Node<T>* stkTop;
	size_t stkSize;

public:
	Stack();
	~Stack();
	Stack(const Stack<T>&);
	Stack<T>& operator=(const Stack<T>&);
	void clear();
	size_t size() const;
	bool empty() const;
	T& top() const; 
	void push(const T&);
	void pop();
	void copyList(const Stack<T>&);
};

/***************************************************************
Function: Stack (constructor)
Use: initialize stack object
Parameters: none
Returns: nothing
***************************************************************/

template <class T>
Stack<T>::Stack()
	{
	stkTop = nullptr;
	stkSize = 0;
	}

/***************************************************************
Function: ~Stack (destructor)
Use: clears stack object
Parameters: none
Returns: nothing
***************************************************************/

template <class T>
Stack<T>::~Stack()
	{
	clear();
	}

/***************************************************************
Function: Stack (copy constructor)
Use: copy stack object
Parameters: other: reference to const Stack<T> object
Returns: nothing
***************************************************************/

template <class T>
Stack<T>::Stack(const Stack<T>& other)
	{
	stkTop = nullptr;
	copyList(other);
	stkSize = other.stkSize;
	}

/***************************************************************
Function: operator=
Use: assign values to stack objects
Parameters: other: reference to const Stack<T> object
Returns: *this
***************************************************************/

template <class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
	{
	if(this != &other)
		{
		clear();
		copyList(other);
		stkSize = other.stkSize;
		}

	return *this;
	}

/***************************************************************
Function: clear
Use: empties/clears stack object
Parameters: none
Returns: nothing
***************************************************************/

template <class T>
void Stack<T>::clear()
	{
	while(!empty())
		pop();
		--stkSize;
	stkSize = 0;
	stkTop = nullptr;
	}

/***************************************************************
Function: size
Use: accessor to size_t stkSize
Parameters: none
Returns: stkSize
***************************************************************/

template <class T>
size_t Stack<T>::size() const
	{
	return stkSize;
	}

/***************************************************************
Function: empty
Use: checks if stack object is empty
Parameters: none
Returns: true or false
***************************************************************/

template <class T>
bool Stack<T>::empty() const
	{
	if(stkSize == 0)
		return true;
	else
		return false;
	}

/***************************************************************
Function: top
Use: accessor to top item in stack
Parameters: none
Returns: nothing
***************************************************************/

template <class T>
T& Stack<T>::top() const
	{
	if(empty())
		throw underflow_error("underflow on top()");
	else
		return stkTop->data;
	}

/***************************************************************
Function: push
Use: adds new node to top of stack
Parameters: item: a reference to a const template parameter
Returns: nothing
***************************************************************/

template <class T>
void Stack<T>::push(const T& item)
	{
	Node<T> *newNode = new Node<T>(item, stkTop);
	stkTop = newNode;
	stkSize++;
	}

/***************************************************************
Function: pop
Use: removes top node in stack
Parameters: none
Returns: nothing
***************************************************************/

template <class T>
void Stack<T>::pop()
	{
	if(empty())
		throw underflow_error("underflow on pop()");

	Node<T>* delNode = stkTop;
	stkTop = delNode->next;
	delete delNode;
	stkSize--;
	}

/***************************************************************
Function: copyList
Use: copies one stack to another
Parameters: other: reference to a constant template parameter type
Returns: nothing
***************************************************************/

template <class T>
void Stack<T>::copyList(const Stack<T>& other)
	{
	Node<T>* ptr, * newNode, * last = nullptr;
	for(ptr = other.stkTop; ptr != nullptr; ptr = ptr->next)
		{
		newNode = new Node<T>(ptr->data);
		if(last == nullptr)
			stkTop = newNode;
		else
			last->next = newNode;
		last = newNode;
		}
	}

/***************************************************************
Function: operator<<
Use: print out stack object
Parameters: lhs: ostream reference
	    rhs: const refernece to Stack tempalte parameter type
Returns: lhs
***************************************************************/

template <class T>
ostream& operator<<(ostream& lhs, const Stack<T> &rhs)
	{
	Node<T> *ptr;

	for(ptr = rhs.stkTop; ptr != nullptr; ptr = ptr->next)
		{
		lhs << ptr->data << " ";
		}

	return lhs;
	}

#endif
