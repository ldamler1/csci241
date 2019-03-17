#ifndef NIUSTRING_H
#define NIUSTRING_H

#include <stdlib.h>
#include <fstream>
#include <iostream>
#include <iomanip>

//*****************************************************************
// FILE:      NIUString.h
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  27 MAR 2017
// PURPOSE:   Contains declaration for NIUString class
//*****************************************************************/

using namespace std;

class NIUString
{
friend ostream& operator<<(ostream&, const NIUString&);
friend bool operator==(const char*, const NIUString&);

private:
	char * stringArrayPointer;
	size_t stringSize;
	size_t stringCap;
public:
	NIUString();
	NIUString(const char*);
	NIUString(const NIUString&);
	~NIUString();
	NIUString& operator=(const NIUString&);
	NIUString& operator=(const char*);
	size_t capacity() const;
	size_t size() const;
	bool empty() const;
	void clear();
	void reserve(size_t n);
	bool operator==(const NIUString&) const;
	bool operator==(const char*) const;
	const char& operator[](size_t) const;
	char & operator[](size_t);
};

#endif
