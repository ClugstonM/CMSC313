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
	const Matrix& operator=(const Matrix& rhs); // Overloaded assignment operator

	int getRows() const;
	int getCols() const;
	double at(int i, int j) const; // Get a specific element
	bool set(int i, int j, double val); // Set a specific element

	Matrix operator+(const Matrix& rhs); // Matrix addition
	Matrix operator-(const Matrix& rhs); // Matrix subtraction
	Matrix operator*(const double& scalar); // Scalar multiplication (matrix * scalar)
	friend Matrix operator*(double scalar, Matrix& matrix); // Scalar multiplication (scalar * matrix)
	Matrix operator*(const Matrix& rhs); // Matrix multiplication
	Matrix transpose() const; // Transpose
	
	void printMatrix() const; // Print

private:
        int rows, cols;
        std::vector<std::vector<double>> data;
};
#endif
