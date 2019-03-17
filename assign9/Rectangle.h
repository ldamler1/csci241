#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"
#include <string>

//*****************************************************************
// FILE:      Rectangle.h
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  02 MAY 2017
// PURPOSE:   Contains declaration for Rectangle class
//*****************************************************************/

using namespace std;

class Rectangle : public Shape
{
public:
	Rectangle(const string&, int, int);

	void setWidth(int);
	int getWidth() const;

	void setHeight(int);
	int getHeight() const;

	virtual void print() const;
	virtual double get_area() const;

private:
	int height;
	int width;
};

#endif
