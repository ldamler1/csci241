#include <iostream>
#include <string>
#include "Rectangle.h"
#include <math.h>

using namespace std;

/***************************************************************
Function: Rectangle()
Use: initializes width and height
Parameters: col: reference to a const string that contains a shapes color
	    w: int of rectangle width
	    h: int of rectangle height
Returns: nothing
***************************************************************/

Rectangle::Rectangle(const string& color, int w, int h) :
 Shape(color)
	{
	setWidth(w);
	setHeight(h);
	}

/***************************************************************
Function: getWidth()
Use: accessor for rectangle width
Parameters: none
Returns: width
***************************************************************/

int Rectangle::getWidth() const
	{
	return width;
	}

/***************************************************************
Function: setWidth()
Use: sets rectangle width 
Parameters: w: int of rectangle width
Returns: nothing
***************************************************************/

void Rectangle::setWidth(int w)
	{
	width = (w < 0) ? 0 : w;
	}

/***************************************************************
Function: getHeight()
Use: accessor of rectangle height
Parameters: none
Returns: height
***************************************************************/

int Rectangle::getHeight() const
        {
        return height;
        }

/***************************************************************
Function: setHeight()
Use: sets rectangle height
Parameters: h: int of rectangle height
Returns: nothing
***************************************************************/

void Rectangle::setHeight(int h)
        {
        height = (h < 0) ? 0 : h;
        }

/***************************************************************
Function: get_area()
Use: calculates rectangle area
Parameters: none
Returns: rectangle area
***************************************************************/

double Rectangle::get_area() const
	{
	return width*height;
	}

/***************************************************************
Function: print()
Use: calls print method then prints rectangle height, width, and area
Parameters: none
Returns: nothing
***************************************************************/

void Rectangle::print() const
	{
	Shape::print();
	cout << " rectangle, height " << height << ", width " << width << ", area " << get_area();
	}
