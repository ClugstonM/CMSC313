/*
    File: matrix.cpp
    Author: Michael Clugston
    Date: 4/16/2025
    Creates a Matrix class housing a 2D vector and functions for matrix operations
*/

#include "matrix.h"
#include <iostream>
#include <vector>
#include <stdexcept>

// Constructor
Matrix::Matrix(int rows, int cols) :
    rows(rows), cols(cols), data(rows, std::vector<int>(cols, 0)) {}

//Overloaded assignment operator
const Matrix& Matrix::operator=(const Matrix& rhs) {
    if (&rhs == this) {
        return *this;
    }

    // Update vars
    rows = rhs.rows;
    cols = rhs.cols;

    // Resize vectors
    data.resize(rhs.rows);
    for (int i = 0; i < rhs.rows; ++i) {
        data[i].resize(rhs.cols);
    }

    // Populate vectors
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            data[i][j] = rhs.data[i][j];
        }
    }

    return *this;
}

int Matrix::getRows() const{
    return rows;
}

int Matrix::getCols() const{ 
    return cols; 
}

// Access the value at a specific index
int Matrix::at(int i, int j) const{
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Index out of range");
    }
    return data[i][j];
}

// Set the value of a specific index
bool Matrix::set(int i, int j, int val) {
    if (i >= rows || j >= cols) {
        throw std::out_of_range("Index out of range");
    }
    data[i][j] = val;
    return true;
}

// Returns the sum of this + rhs
Matrix Matrix::operator+(const Matrix& rhs) {
    if (rows != rhs.rows || cols != rhs.cols) {
        throw std::invalid_argument("Matrix dimensions must be the same for addition");
    }

    int sum = 0;
    Matrix result(rows, cols);
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum = at(i, j) + rhs.at(i, j);
            result.set(i, j, sum);
        }
    }

    return result;
}

// Returns a scaled matrix (rhs scalar)
Matrix Matrix::operator*(const int& scalar){
    Matrix result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.set(i, j, (scalar * data[i][j]));
        }
    }

    return result;
}

// Returns a scaled matrix (lhs scalar)
Matrix operator*(int scalar, Matrix& matrix) {
    return matrix * scalar;
}

// Returns the matrix product of this * rhs
Matrix Matrix::operator*(const Matrix& rhs) {
    if (cols != rhs.rows) {
        throw std::invalid_argument("Invalid dimensions for matrix multiplication");
    }

    Matrix result(rows, rhs.cols);
    int sumOfRow = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < rhs.cols; ++j) {
            for (int k = 0; k < rhs.rows; ++k) {
                sumOfRow += data[i][k] * rhs.data[k][j];
            }
            result.set(i, j, sumOfRow);
            sumOfRow = 0;
        }
    }

    return result;
}

// Returns the transpose of this matrix
Matrix Matrix::transpose() const{
    Matrix result(cols, rows);
    
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.set(j, i, data[i][j]);
        }
    }

    return result;
}
 
// Print matrix in a human-readable format
void Matrix::printMatrix() const {
    for (std::vector<int> i : data) {
        for (int val : i) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
}