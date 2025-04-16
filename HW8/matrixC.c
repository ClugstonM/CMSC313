/*
	File: matrixC.c
	Author: Michael Clugston
	Date: 4/16/2025
	Uses functions with 1D arrays to perform matrix operations
*/

#include <stdio.h>
#include <stdlib.h>

// Matrix is represented in one long array
int* mallocMatrix(int rows, int cols) {
	int* output = malloc(rows * cols * sizeof(int));
	return output;
}

// Retrieve a specific index of a matrix
int matrixGet(int* matrix, int rows, int cols, int row, int col) {
	return matrix[cols * row + col];
}

// Set a specific index of a matrix
void matrixSet(int* matrix, int rows, int cols, int row, int col, int val) {
	matrix[cols * row + col] = val;
}

// Returns the transpose of a matrix
int* transpose(int* matrix, int rows, int cols) {

	int* output = malloc(rows * cols * sizeof(int));

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			matrixSet(output, cols, rows, j, i, matrixGet(matrix, rows, cols, i, j));
		}
	}

	return output;
}

// Returns a scaled matrix
int* scalarMultiply(int* matrix, int rows, int cols, int scalar) {
	int* output = malloc(rows * cols * sizeof(int));
	
	for (int i = 0; i < rows * cols; i++) {
		output[i] = matrix[i] * scalar;
	}

	return output;
}

// Returns the sum of two matrices
// Sizes of matrices must be identical
int* matrixAdd(int* matrix1, int* matrix2, int rows, int cols) {
	int* output = malloc(rows * cols * sizeof(int));
	
	for (int i = 0; i < rows * cols; i++) {
		output[i] = matrix1[i] + matrix2[i];
	}

	return output;
}

// Returns the matrix product of two matrices
// #cols of matrix1 must equal #rows of matrix2
int* matrixMultiply(int* matrix1, int rows1, int cols1, int* matrix2, int rows2, int cols2) {
	if (cols1 != rows2) {
		return NULL;
	}

	int* output = malloc(rows1 * cols2 * sizeof(int));
	int sumOfRow = 0;

	for (int i = 0; i < rows1; i++) {
		for (int j = 0; j < cols2; j++) {
			for (int k = 0; k < rows2; k++) {
				sumOfRow += matrixGet(matrix1, rows1, cols1, i, k) * matrixGet(matrix2, rows2, cols2, k, j);
			}
			matrixSet(output, rows1, cols2, i, j, sumOfRow);
			sumOfRow = 0;
		}
	}

	return output;
}

// Prints the matrix in a human-readable format
void printMatrix(int* matrix, int rows, int cols) {
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d ", matrixGet(matrix, rows, cols, i, j));
		}
		printf("\n");
	}
}