#include <iostream>
#include <string>
#include "Triangle.h"

using namespace std;

/***************************************************************
Function: Triangle()
Use: initialize triangle base and height
Parameters: col: reference to a const string that contains a shapes color
	    h: int of triangle height
	    b: int of triangle base
Returns: nothing
***************************************************************/

Triangle::Triangle(const string& color, int h, int b) :
 Shape(color)
	{
	setHeight(h);
	setBase(b);
	}

/***************************************************************
Function: setHeight()
Use: sets triangle height
Parameters: h: int of triangles height
Returns: nothing
***************************************************************/

void Triangle::setHeight(int h)
	{
	height = (h < 0) ? 0 : h;
	}

/***************************************************************
Function: getHeight()
Use: accessor for triangle height
Parameters: none
Returns: height
***************************************************************/

int Triangle::getHeight() const
        {
        return height;
        }

/***************************************************************
Function: setBase()
Use: sets base of triangle
Parameters: b: int of triangle base
Returns: nothing
***************************************************************/

void Triangle::setBase(int b)
        {
        base = (b < 0) ? 0 : b;
        }

/***************************************************************
Function: getBase()
Use: accessor for triangles base
Parameters: none
Returns: base
***************************************************************/

int Triangle::getBase() const
        {
        return base;
        }

/***************************************************************
Function: get_area()
Use: calculates area of a triangle
Parameters: none
Returns: area of a triangle
***************************************************************/

double Triangle::get_area() const
	{
	return (base*height)/2;
	}

/***************************************************************
Function: print()
Use: calls print method then prints triangle base, height, and area
Parameters: none
Returns: nothing
***************************************************************/

void Triangle::print() const
	{
	Shape::print();
	cout << " triangle, height " << height << ", base " << base << ", area " << get_area();
	}
