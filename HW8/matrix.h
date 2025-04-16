/*
	File: matrix.h
	Author: Michael Clugston
	Date: 4/16/2025
	Contains members of the Matrix class used in matrix.cpp
*/

#ifndef MATRIX_H
#define MATRIX_H

#include <vector>

class Matrix {
public:
	Matrix(int rows, int cols); // Constructor
	const Matrix& operator=(const Matrix& rhs); // Overloaded assignment

	int getRows() const;
	int getCols() const;
	int at(int i, int j) const; // Get a specific element
	bool set(int i, int j, int val); // Set a specific element

	Matrix operator+(const Matrix& rhs); // Matrix addition
	Matrix operator*(const int& scalar); // Scalar multiplication (matrix * scalar)
	friend Matrix operator*(int scalar, Matrix& matrix); // Scalar multiplication (scalar * matrix)
	Matrix operator*(const Matrix& rhs); // Matrix multiplication
	Matrix transpose() const; // Transpose

	void printMatrix() const; // Print

private:
	int rows, cols;
	std::vector<std::vector<int>> data;
};
#endif
