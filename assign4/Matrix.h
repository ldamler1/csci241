#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <iomanip>
#include <fstream>

//*****************************************************************
// FILE:      Matrix.h
// AUTHOR:    Damler, Lucas
// LOGON ID:  z1761739
// DUE DATE:  07 MAR 2017
// PURPOSE:   Contains declaration for Matrix class
//*****************************************************************/

using namespace std;

class Matrix{
	friend ostream& operator<<(ostream & ,const Matrix &);
	friend Matrix operator*(int, const Matrix &);

	private:
		int matrixArray[2][2];
	public:
		Matrix();
		Matrix(int[2][2]);
		int determinant()const;
		Matrix operator+(const Matrix&) const;
		Matrix operator*(int) const;
		Matrix operator*(const Matrix&) const;
		bool operator==(const Matrix&) const;
		bool operator!=(const Matrix&) const;
};

#endif
