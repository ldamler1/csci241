/*********************************************************************
   PROGRAM:    CSCI 241 Assignment 9
   PROGRAMMER: Damler, Lucas
   LOGON ID:   z1761739
   DUE DATE:   02 MAY 2017
   FUNCTION:   This program tests the functionality of the Shape, Circle, 
               Rectangle, and Triange classes
*********************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <vector>

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"

using std::cout;
using std::endl;
using std::fixed;
using std::setprecision;
using std::vector;
using std::string;

int main()
	{
	cout << fixed << setprecision(3);

	//Create vector object
	vector<Shape *> shapes;

	//Fill vector
	shapes.push_back(new Circle("green", 10));
	shapes.push_back(new Rectangle("red", 6, 8));
	shapes.push_back(new Triangle("yellow", 8, 4));
	shapes.push_back(new Triangle("black", 4, 10));
	shapes.push_back(new Circle("orange", 5));
	shapes.push_back(new Rectangle("blue", 7, 3));

	cout << "Printing all shapes...\n\n";

	for(int i = 0; i < (int)shapes.size(); i++)
		{
		shapes[i]->print();
		cout << endl;
		}

	cout << "\nPrinting only triangles...\n\n";

	for(int i = 0; i < (int)shapes.size(); i++)
                {
		Triangle *triPtr = dynamic_cast<Triangle *>(shapes[i]);
		if(triPtr != 0)
			{
			triPtr->print();
			cout << endl;
			}
                }

	//Delete objects in vector
	for(unsigned int i = 0; i < shapes.size(); ++i)
		{
		delete shapes[i];
		}
	cout << endl;

	return 0;
	}
