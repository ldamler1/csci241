
//*****************************************************************
// FILE:      Matrix.cpp
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  09 MAR 2017
// PURPOSE:   Implementaion file for Matrix class
//*****************************************************************/

#include "Matrix.h"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

/********************************************************************
Function: Monkey
Use: 
Parameters: ostream& lhs: refrence to ostream object
	    Matrix& rhs: refrence to Matrix array of elements
Returns: lhs
********************************************************************/

ostream& operator<<(ostream& lhs, const Matrix& rhs){
	lhs <<"[[" << rhs.matrixArray[0][0] << " , " << rhs.matrixArray[0][1] << "] , [" << rhs.matrixArray[1][0] << " , " << rhs.matrixArray[1][1] <<"]]";
	return lhs;
}

/********************************************************************
Function: operator*
Use: used to multiply elements in array object an int
Parameters: lhs: int to multiply array by
	    Matrix&: reference to array object
Returns: prod
********************************************************************/

Matrix operator*(int lhs, const Matrix& rhs){
	Matrix prod;

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			prod.matrixArray[i][j] = rhs.matrixArray[i][j] * lhs;
		}
	}
	return prod;
}

/********************************************************************
Function: Matrix (default contructor)
Use: creates 2d array object with values
Parameters: none
Returns: nothing
********************************************************************/

Matrix::Matrix(){
	matrixArray[0][0] = 1;
	matrixArray[0][1] = 0;
	matrixArray[1][0] = 0;
	matrixArray[1][1] = 1;
}

/********************************************************************
Function: Matrix (constructor)
Use: initializes array with passed in values
Parameters: matrixArrayTheSecondComing: passed in array containing values for matrixArray
Returns: nothing
********************************************************************/

Matrix::Matrix(int matrixArrayTheSecondComing[2][2]){
	for(int i = 0; i < 2; i++){
		for(int j =0; j < 2; j++){
			matrixArray[i][j] = matrixArrayTheSecondComing[i][j];
		}
	}
}

/********************************************************************
Function: determinant
Use: calcs determinant values of array
Parameters: none
Returns: x
********************************************************************/

int Matrix::determinant() const{
	int x = matrixArray[0][0] * matrixArray[1][1] - matrixArray[0][1] * matrixArray[1][0];
	return x;
}

/********************************************************************
Function: operator+
Use: overloads addition operator to add matricies together
Parameters: Matrix& rhs: contains reference to Matrix object
Returns: add
********************************************************************/

Matrix Matrix::operator+(const Matrix& rhs) const{
	Matrix add;
	int i, j;
	for(i = 0; i < 2; i++){
                for(j =0; j < 2; j++){
                        add.matrixArray[i][j] = matrixArray[i][j] + rhs.matrixArray[i][j];
                }
        }
	return add;
}

/********************************************************************
Function: operator*
Use: overloads multiplication operator to multiply matrix objects
Parameters: rhs: int to contain passed i nvalues to multiply by
Returns: product
********************************************************************/

Matrix Matrix::operator*(int rhs) const{
	Matrix product;
	int i, j;
	for(i = 0; i < 2; i++){
                for(j =0; j < 2; j++){
                        product.matrixArray[i][j] = matrixArray[i][j] * rhs;
                }
        }
	return product;
}

/********************************************************************
Function: operator*
Use: used to multiply two object arrays
Parameters: Matrix& rhs: cointains reference to an array
Returns: result
********************************************************************/

Matrix Matrix::operator*(const Matrix& rhs) const{
	Matrix result;
	result.matrixArray[0][0] = matrixArray[0][0] * rhs.matrixArray[0][0] + matrixArray[0][1] * rhs.matrixArray[1][0];
	result.matrixArray[0][1] = matrixArray[0][0] * rhs.matrixArray[0][1] + matrixArray[0][1] * rhs.matrixArray[1][1];
	result.matrixArray[1][0] = matrixArray[1][0] * rhs.matrixArray[0][0] + matrixArray[1][1] * rhs.matrixArray[1][0];
	result.matrixArray[1][1] = matrixArray[1][0] * rhs.matrixArray[0][1] + matrixArray[1][1] * rhs.matrixArray[1][1];

	return result;
}

/********************************************************************
Function: operator==
Use: used to compare two array objects
Parameters: Matrix& rhs: reference to array of elements
Returns: true/false
********************************************************************/

bool Matrix::operator==(const Matrix& rhs) const{
	if(matrixArray[0][0] == rhs.matrixArray[0][0] && matrixArray[0][1] == rhs.matrixArray[0][1] && matrixArray[1][0] == rhs.matrixArray[1][0] && matrixArray[1][1] == rhs.matrixArray[1][1]){
		return true;
	}
	else{
		return false;
	}
}

/********************************************************************
Function: operator!=
Use: used to compare array objects if they are not equal
Parameters: Matrix& rhs: reference to array of elements
Returns: true/false
********************************************************************/

bool Matrix::operator!=(const Matrix& rhs) const{
	if(rhs == *this){
		return false;
	}
	else{
		return true;
	}
}
