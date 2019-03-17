#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <string>

//*****************************************************************
// FILE:      Triangle.h
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  02 MAY 2017
// PURPOSE:   Contains declaration for Triangle class
//*****************************************************************/

using namespace std;

class Triangle : public Shape
{
public:
	Triangle(const string&, int, int);

	void setHeight(int);
	int getHeight() const;

	void setBase(int);
	int getBase() const;

	virtual void print() const;
	virtual double get_area() const;

private:
	int height;
	int base;
};

#endif
