#ifndef SHAPE_H
#define SHAPE_H

#include <string>

//*****************************************************************
// FILE:      Shape.h
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  02 MAY 2017
// PURPOSE:   Contains declaration for Shape class
//*****************************************************************/

using namespace std;

class Shape
{
public:
	Shape(const string&);
	virtual ~Shape();

	void setColor(const string&);
	string getColor() const;

	virtual void print() const;
	virtual double get_area() const = 0;

private:
	string color;	
};

#endif
