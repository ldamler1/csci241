#ifndef QUEUE_H
#define QUEUE_H

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <iomanip>

//*****************************************************************
// FILE:      Queue.h
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  11 APR 2017
// PURPOSE:   Contains declaration for Queue class
//*****************************************************************/

using namespace std;

class Queue
{
friend ostream& operator<<(ostream&, const Queue&);

private:
	int * qAr;
	size_t qCap;
	size_t qSize;
	int qFront;
	int qBack;
public:
	Queue();
	~Queue();
	Queue(const Queue&);
	Queue& operator=(const Queue&);
	void clear();
	size_t size() const;
	size_t capacity() const;
	bool empty() const;
	int front() const;
	int back() const;
	void push(int);
	void pop();
	void reserve(unsigned int);
};

#endif
