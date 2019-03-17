
#include <iostream>
#include "Shape.h"

using namespace std;

/***************************************************************
Function: Shape()
Use: initializes shape color
Parameters: col: reference to a const string that contains a shapes color
Returns: nothing
***************************************************************/

Shape::Shape(const string& col) : color(col)
	{
	//empty body
	}

/***************************************************************
Function: ~Shape()
Use: nothing. It's just for show
Parameters: none
Returns: nothing
***************************************************************/

Shape::~Shape()
	{
	}

/***************************************************************
Function: getColor()
Use: accessor for a shapes color
Parameters: none
Returns: color
***************************************************************/

string Shape::getColor() const
	{
	return color;
	}

/***************************************************************
Function: setColor()
Use: sets a shapes color
Parameters: col: reference to a const string that contains a shapes color
Returns: nothing
***************************************************************/

void Shape::setColor(const string& col)
	{
	color = col;
	}

/***************************************************************
Function: print()
Use: print a shapes color
Parameters: none
Returns: nothing
***************************************************************/

void Shape::print() const
	{
	cout << color;
	}
