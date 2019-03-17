#include <iostream>
#include <string>
#include "Circle.h"
#include <math.h>

using namespace std;

/***************************************************************
Function: Circle()
Use: initializes circle radius
Parameters: col: reference to a const string that contains a shapes color
            rad: int of circles radius
Returns: nothing
***************************************************************/

Circle::Circle(const string& col, int rad) : Shape(col)
	{
	setRadius(rad);
	}

/***************************************************************
Function: setRadius()
Use: sets the ciecles radius
Parameters: rad: int of circles radius
Returns: nothing
***************************************************************/

void Circle::setRadius(int rad)
	{
	radius = (rad < 0) ? 0 : rad;
	}

/***************************************************************
Function: getRadius()
Use: accessor for circles radius
Parameters: none
Returns: radius
***************************************************************/

int Circle::getRadius() const
	{
	return radius;
	}

/***************************************************************
Function: get_area();
Use: calculates radius of circles
Parameters: none
Returns: radius of circle
***************************************************************/

double Circle::get_area() const
	{
	return  M_PI*(pow(radius,2));
	}

/***************************************************************
Function: print()
Use: calls print method then prints circle radius and area
Parameters: none
Returns: nothing
***************************************************************/

void Circle::print() const
	{
	Shape::print();
	cout << " Circle, radius " << radius << ", area " << get_area();
	}
