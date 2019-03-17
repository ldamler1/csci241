#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include <string>

//*****************************************************************
// FILE:      Circle.h
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  02 MAY 2017
// PURPOSE:   Contains declaration for Circle class
//*****************************************************************/

using namespace std;

class Circle : public Shape
{
public:
	Circle(const string&, int);

	void setRadius(int);
	int getRadius() const;

	virtual void print() const;
	virtual double get_area() const;

private:
	int radius;
};

#endif
